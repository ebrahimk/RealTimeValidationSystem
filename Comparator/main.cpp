/************************************************
 * Corruption Unit OPENCV Program
 * Contributors: Kamron Ebrahimi, Pu Huang, Dafei Du
 ************************************************/

#include "Compare.hpp"
#include "proto/packet.pb.h"
#include "socket/PracticalSocket.h"
#include "socket/config.h"
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include <queue>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <zmq.hpp>

#define BUF_LEN 65540 // Larger than maximum UDP packet size

using packet::FramePacket;
void *handleEthernet(void *threadid);
void *handleComparison(void *threadid);
bool ReadXBytes(int socket, unsigned int x, void *buffer);

/*
 * my IP, "192.168.1.122"
 * build prtocol buffer libraries from template .proto file
 * protoc -I=./ --cpp_out=./proto ./packet.proto
 * ./corrupt 192.168.1.124 6666
 */

/* Declare mutexs for resource sharing between queues */
std::mutex mtx, mtx2;

/* Declare queues for pipelined image processing */
std::queue<std::string> ethernet_serial_queue;
std::queue<FramePacket> serial_compare_queue;

/* Comparison object */
Compare comparator;

int main(int argc, char *argv[]) {

  /* Test for correct number of arguments */
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <Server Port>" << endl;
    exit(1);
  }

  /* open the TCP socket */
  TCPServerSocket serverSock(atoi(argv[1]));
  TCPSocket *sock = serverSock.accept();
  sock->getForeignAddress();
  sock->getForeignPort();

  /* declare and start execution threads */
  pthread_t ethernetHandler;
  pthread_t compareHandler;
  pthread_create(&compareHandler, NULL, handleComparison, (void *)1);
  pthread_create(&ethernetHandler, NULL, handleEthernet, (void *)2);

  /*
   * Wait for incoming data across the wire. We receive the total number of
   * bytes for the incoming packet, then read bytes until we reach the total.
   */
  int recvMsgSize;
  char buf[BUF_LEN];
  string read_data;
  while (1) {
    /* Block until receive an incoming message length from the corruption unit
     */
    do {
      recvMsgSize = sock->recv(buf, BUF_LEN);
    } while (recvMsgSize > sizeof(int));
    int length = ((int *)buf)[0];
    cout << "length: " << length << endl;

    /* Create a character array to store the incoming packet */
    char *buffer = NULL;
    buffer = new char[length];

    /* Read bytes equal to the incoming packet size */
    if (ReadXBytes(sock->sockDesc, length, (void *)buffer)) {

      /* Copy binary data to a string for easy handling */
      for (int i = 0; i < length; i++)
        read_data += buffer[i];

      /*
       * Push string into the ethernet_serial_queue for deserialization thread
       * to handle.
       */
      mtx.lock();
      ethernet_serial_queue.push(read_data);
      mtx.unlock();
      dat.clear();
    }

    delete[] buffer;
  } // while

  return 0;
}

/* Read bytes from the socket equal to the value of 'x' */
bool ReadXBytes(int socket, unsigned int x, void *buffer) {
  int bytesRead = 0;
  int result;
  while (bytesRead < x) {
    result = read(socket, buffer + bytesRead, x - bytesRead);
    if (result < 1)
      break;
    bytesRead += result;
  }
  return true;
}

/* Pulls read packets from the queue and deserializes them */
void *handleEthernet(void *threadid) {
  while (1) {
    string ser_data;
    bool dat = false;

    /* Check if data is avaialble in the queue, if so pop the data */
    mtx.lock();
    if (!ethernet_serial_queue.empty()) {
      ser_data = ethernet_serial_queue.front();
      ethernet_serial_queue.pop();
      dat = true;
    }
    mtx.unlock();

    /* Deserialize the data and push to the next queue for image comparison */
    if (dat) {
      FramePacket packet;
      if (packet.ParseFromString(ser_data)) {
        mtx2.lock();
        serial_compare_queue.push(packet);
        mtx2.unlock();
      } else
        cout << "failed to deserialize data" << endl;

      ser_data.clear();
    }
  } // while
}

/* Recreates original compressed image frames, and performs comparison algorithm
 */
void *handleComparison(void *threadid) {

  while (1) {
    FramePacket packet;
    bool dat = false;
    mtx2.lock();
    if (!serial_compare_queue.empty()) {
      packet = serial_compare_queue.front();
      serial_compare_queue.pop();
      dat = true;
    }
    mtx2.unlock();

    if (dat) {
      cv::Mat rawA, rawB;

      /* Allocate the iamge container based of the dimensions  */
      rawA.create(packet.rows(), packet.cols(), packet.elt_type());
      rawB.create(packet.rowsb(), packet.colsb(), packet.elt_type());

      /* Copy the data over for the corrupted and uncorrupted frames  */
      std::copy(reinterpret_cast<unsigned char *>(
                    const_cast<char *>(packet.mat_dataa().data())),
                reinterpret_cast<unsigned char *>(
                    const_cast<char *>(packet.mat_dataa().data()) +
                    packet.elt_sizea()),
                rawA.data);

      std::copy(reinterpret_cast<unsigned char *>(
                    const_cast<char *>(packet.mat_datab().data())),
                reinterpret_cast<unsigned char *>(
                    const_cast<char *>(packet.mat_datab().data()) +
                    packet.elt_sizeb()),
                rawB.data);

      /* Decompress and compare the two images */
      try {
        cv::Mat frameA = imdecode(rawA, cv::IMREAD_COLOR);
        cv::Mat frameB = imdecode(rawB, cv::IMREAD_COLOR);
        cv::imshow("Normal", frameA);
        cv::imshow("Corrupt", frameB);
        cv::waitKey(1);
        comparator.run(&frameA, &frameB);
      } catch (cv::Exception &e) {
        cout << "error decompressing the image" << endl;
      }
    }
  }
}
