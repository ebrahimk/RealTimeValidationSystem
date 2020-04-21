/*************************************************
 * Corruption Unit OPENCV Program
 * Contributors: Kamron Ebrahimi
 ************************************************/

#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include <queue>
#include <sched.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <zmq.hpp>
#include "Compare.hpp"
#include "filters/Distortion.hpp"
#include "filters/Freeze.hpp"
#include "filters/Translate.hpp"
#include "filters/White.hpp"
#include "proto/packet.pb.h"
#include "socket/PracticalSocket.h"
#include "socket/config.h"


using packet::FramePacket;

// "192.168.1.122"
// build prtocol buffer libraries from template .proto file
// protoc -I=./ --cpp_out=./proto ./packet.proto
// ./corrupt 192.168.1.124 6666

enum distortion { FREEZE, WHITE, SHIFT };
enum distortion type;
std::mutex mtx;
cv::Mat *dframe; // of type CV_8UC3
std::vector<Distortion *> dis(3);

void *handleIPC(void *threadid);
void *handleEthernet(void *threadid);
void dispatch(std::vector<std::string> cmd);

int main(int argc, char *argv[]) {
  if ((argc < 3) || (argc > 3)) { // Test for correct number of arguments
    cerr << "Usage: " << argv[0] << " <Server> <Server Port>\n";
    exit(1);
  }

  std::string servAddress = argv[1]; // First arg: server address
  TCPSocket sock(servAddress, atoi(argv[2]));

  type = SHIFT;
  std::string window = "corrupt";
  std::string window2 = "normal";

  Freeze freeze(100);
  White white(50, 255, FRAME_HEIGHT, FRAME_WIDTH);
  Translate translate(50, FRAME_HEIGHT, FRAME_WIDTH, 15, 15);
  Compare comparator;

  dis[0] = &freeze;
  dis[1] = &white;
  dis[2] = &translate;

  // spawn the IPC socket thread
  pthread_t ipcHandler;
  pthread_create(&ipcHandler, NULL, handleIPC, (void *)1);

  try {
    int jpegqual = ENCODE_QUALITY; // Compression Parameter

    cv::Mat frame, dup, cp1, cp2;

    cv::VideoCapture cap(0); // Grab the camera
    if (!cap.isOpened()) {
      cerr << "OpenCV Failed to open camera";
      exit(1);
    }

    // clock_t last_cycle = clock();
    while (1) {
      cap >> frame;
      dup = frame.clone();
      dframe = &frame;
      mtx.lock();
      dis[type]->run(dframe);
      mtx.unlock();

      // compress the frames
      std::vector<uchar> compImgA, compImgB;
      std::vector<int> compression_params;
      compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
      compression_params.push_back(jpegqual);
      cv::imencode(".jpg", dup, compImgA, compression_params);
      cv::imencode(".jpg", *dframe, compImgB, compression_params);

      // init the packet
      FramePacket packet;
      std::string serial_dat;
      packet.set_rows(dup.rows);
      packet.set_cols(dup.cols);
      packet.set_rowsb(dframe->rows);
      packet.set_colsb(dframe->cols);
      packet.set_elt_type(dframe->type());
      packet.set_elt_sizea(compImgA.size());
      packet.set_elt_sizeb(compImgB.size());
      packet.set_mat_dataa(compImgA.data(), compImgA.size());
      packet.set_mat_datab(compImgB.data(), compImgB.size());

      // serialize the packet
      if (!packet.SerializeToString(&serial_dat))
        std::cout << "failed to serialize data" << std::endl;

      int total_pack = 1 + (serial_dat.size() - 1) / PACK_SIZE;
      int ibuf[1];
      ibuf[0] = serial_dat.size();
      std::cout << "sending " << serial_dat.size() << std::endl;
      sock.send(ibuf, sizeof(int));
      for (int i = 0; i < total_pack; i++)
        sock.send(&serial_dat[i * PACK_SIZE], PACK_SIZE);
    }

  } catch (SocketException &e) {
    cerr << e.what() << endl;
    exit(1);
  }

  return 0;
}

void *handleIPC(void *threadid) {
  //  Prepare our context and socket
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);
  socket.bind("tcp://*:5555");

  while (true) {
    zmq::message_t request;
    //  Wait for next request from client
    socket.recv(&request);

    // process the data input
    std::string cmd_str =
        std::string(static_cast<char *>(request.data()), request.size());
    std::cout << cmd_str << std::endl;
    std::stringstream ss(cmd_str);
    std::vector<std::string> cmd;
    while (ss.good()) {
      std::string substr;
      getline(ss, substr, ',');
      cmd.push_back(substr);
    }
    for (int i = 0; i < cmd.size(); i++)
      std::cout << cmd.at(i) << ' ';

    // lock the mutex and update the filter
    mtx.lock();
    dispatch(cmd);
    mtx.unlock();

    //  Send reply back to client
    zmq::message_t reply(3);
    memcpy(reply.data(), "ACK", 3);
    socket.send(reply);
  }
}

// Format (use .join(',') method on a dynamically constructed list object) to
// produce these commands Freeze:   ['1', '1/0', 'dur(ms)'] White:    ['2',
// '1/0', 'dur(ms)', 'shade(0-255)'] Translate ['3', '1/0', 'dur(ms)',
// 'x_offset', 'y_offset'] Introduce better error handling here!
void dispatch(std::vector<std::string> cmd) {
  switch (stoi(cmd[0], nullptr)) {
  case 1:
    type = FREEZE;
    dis[type]->update(cmd);
    break;
  case 2:
    type = WHITE;
    dis[type]->update(cmd);
    break;
  case 3:
    type = SHIFT;
    dis[type]->update(cmd);
    break;
  }
}
