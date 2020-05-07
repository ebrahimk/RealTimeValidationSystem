## Collins Aerospace Real Time Camera Validation ##

[![TravisCI build](https://img.shields.io/travis/ebrahimk/RealTimeValidationSystem/develop?logo=travis)](https://travis-ci.org/ebrahimk/RealTimeValidationSystem/jobs/652818303)
![Project Size](https://img.shields.io/github/repo-size/ebrahimk/RealTimeValidationSystem)

## Description

This repository houses all of the code for a real time camera validation system, commissioned by Collins Aerospace. The purpose of this system is to create a device capable of validating firmware processed video streams. The device accomplishes this by receiving two video channels, one channel is the raw data captured by the CMOS sensor of a camera, the second channel is the downstream, post-processed data output by the cameras firmware. The device intelligently analyzes and compares these two channels and detect in real time, image translation, frozen images, and blank video buffers. 

To sythesize controlled image distotion, this proof of concept is composed of two blocks, a corruption and a comparison unit implemented on Raspberry Pi's. One Raspberry Pi is responsible for capture a image frames, producing a replicate of the captured frame, applying corruption filters to a single copy of the frame, then compressing, serializing and sending the data over 1GB Ethernet. The comparison unit captures incoming data, deserializes, and decompresses the packet, then compares the two frames using OpenCV. 
The system is highly scalable and capable of operating on frames of varying resolution. To facilitate easy user interaction a web interface allows users to dynamically configure the behavior of the distortion filters. 

Click on the link below to watch the Winter Term progress video for project clarification and demonstration. 9:00 to 18:00 contains a live demonstration of the system. 

[Overall Winter Term 2020 Progress Report and Demonstation Video](https://www.youtube.com/watch?v=pyvXuuFmpZ0&feature=youtu.be) <br />  
[Comparison Checkoff Video](https://drive.google.com/open?id=1pylhmhnjO0uEq5NIw5-g-shSKpQun7DU) <br />  
[Discoloration Checkoff Video](https://drive.google.com/open?id=1mIcHFHDTPOEd2GzW5WtJtH32ZUPtFWR7) <br />  
[Freeze Checkoff Video](https://drive.google.com/open?id=1lA7PFuj8vIQ1MmO_ykbCSoEnBfT3-1wl) <br />  


## Design 

![Block Diagram](https://github.com/ebrahimk/RealTimeValidationSystem/blob/develop/.photos/blockDiagram.png)

The bottleneck of the system is the 1GB Ethernet connection, which struggles to process the large amount of data contained in high-resolution/high-fps video streams. 
To optimize performance, the processes responsible for image processing on both the corruption and comparison units are written using OpenCV’s C++ API. The programs spawn multiple threads which communicate over a set of shared queues. Unique threads are responsible for reading and writing over the TCP socket, deserializing and serializing captured data, and also displaying captured frames to the user. The corruption unit comes equipped with an extra thread which opens and maintains a socket for interprocess communication with the web interface. 

## Known Issues

In its current state the program can detect and diagnose all forms of distortion the corruption unit is capable of introducing. Due to the compression and serialization of frames occuring at the same time, the comparison unit looses diagnostic accuracy when detecting image translation. The program reports pixels shifts approxiamtley 10 pixels off the true shift amount. This issue is currently being researched. 

Furthermore, due to the low processing power of the Raspberry Pi's and 1GB Ethernet bottleneck, distortion introduced for less than 20ms go undetected by the system. 

## Installation

Hardware required to set up system:
 - Raspberry Pi's x2
 - Ethernet cable x1
 - micro USB to HDMI adapter x2
 - Raspberry Pi Camera x1 

To set up a working system both raspberry Pi's require OpenCV, ZeroMQ, and Protobuf Library as well as each libraries dependencies.

To download all library dependencies:
```bash
  $ sudo apt-get update -y
  $ sudo apt-get install build-essential
  $ sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
  $ sudo apt-get install libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
  $ sudo apt-get install -y autoconf automake libtool wget make g++ unzip
```

To download and install the latest version of the Protocol Buffer Library run:
```bash
  $ wget https://github.com/protocolbuffers/protobuf/releases/download/v3.11.4/protobuf-cpp-3.11.4.tar.gz
  $ tar -xzvf protobuf-cpp-3.11.4.tar.gz
  $ pushd protobuf-3.11.4
  $./configure && make && sudo make install && sudo ldconfig
  $ popd
```

To download and install the latest version of ZeroMQ for C++ run:
```bash
  $sudo apt-get install libzmq3-dev
```

To download and install OpenCV version 2.0.0 run:
```bash
  $ mkdir opencv && pushd opencv
  $ git clone https://github.com/opencv/opencv.git
  $ git clone https://github.com/opencv/opencv_contrib.git
  $ mkdir build && cd build
  $ cmake -D CMAKE_BUILD_TYPE=Release -DCMAKE_EXTRA_MODULES_PATH=../opencv_contrib/module/ -D CMAKE_INSTALL_PREFIX=/usr/local ../opencv -DBUILD_opencv_java=OFF -DBUILD_opencv_python2=OFF -DBUILD_opencv_python3=OFF
  $ make -j7 && sudo make install && popd 
```

To compile the Corruption and Comparison unit and generate the protocol buffer serialization code run:
```bash
  $ pushd Corruption && cmake .
  $ protoc -I=./ --cpp_out=./proto ./packet.proto
  $ make -j7 && popd
  $ pushd Corruption && cmake .
  $ protoc -I=./ --cpp_out=./proto ./packet.proto
  $ make -j7 && popd
```

To install Node.js for the web UI run: 
```bash
  $ sudo apt-get install -y nodejs
  $ npm install zeromq
```
Please refer to the Travis yaml file for and build related clarification.

## Setup

1. Connect both Raspberry Pi's to external monitors using the micro USB to HDMI adapter
2. Connect Raspberry Pi's with the Ethernet cord
3. Manually configure statis IP addresses for both Raspberry Pi's using the Network Manager Utility
4. On the Comparison Raspberry Pi, in RealTimeValidationSystem/Comparator/ run:
```bash
    $./compare [PORT_NUM]
```
5. On the Corruption Raspberry Pi, in RealTimeValidationSystem/Corruption/ run:
```bash
    $./corrupt [STATIC_IP_OF_COMPARISON_UNIT] [PORT_NUM]
    $ cd ../WEB_UI/node server.js
```
6. Open GUI.html in the browser of your choice
7. Enter "localhost:8000" in the "Hostname" text entry of the HTML form
8. Hit the "submit" button to send commands to the corruption unit and watch the distortion display on the comparison unit and get detected. 

## Relevant Files and Directory Structure

* <strong>Corruption/</strong> contains all code used by the C++ program of the corruption unit. 
  * <strong>filters/</strong> contains the three different corruption filters applied to image frames
  * <strong>proto/</strong> protobuf generated serialization C++ code
  * <strong>socket/</strong> C++ TCP socket library
  * <strong>main.cpp</strong> main corruption C++ program

* <strong>Comparator/</strong> contains all code used by the C++ program of the corruption unit. 
  * <strong>proto/</strong> protobuf generated serialization C++ code
  * <strong>socket/</strong> C++ TCP socket library
  * <strong>Compare.cpp/hpp</strong> C++ implementation and header file for comparator class

* <strong>WEB_UI/</strong> contains all code used by the C++ program of the corruption unit. 
  * <strong>GUI.html</strong> web html page
  * <strong>server.js</strong> node.js server file

## Unit Testing

We use Catch2 as a C++ unit testing framework. The real time validation system has an extensive set of dependecies which must be built from source. This process is time consuming (~1 hour) as can be seen in the Travis build logs. To streamline testing we have a Raspian Open Virtual Appliance (.ova) hosted in Google Drive with all of the dependencies configured and built that can be run in any virtualization software, we use Oracle VirtualBox. Unit testing in this fashion allows for users who wish to test the software to run unit test regardless of their machine type (OSX, Linux, Windows) and provides freedom to test hardware facing code in a more realistic enviroment (Raspbian). Virtual machines images are generally large files, when you are done running the tests you can simply delete the VM and the image file. 

1. Download the .ova file here from the Google Drive (~5GB): https://drive.google.com/open?id=1OR6Gr0TDE0axxpTZr0i-9V4qwfllgYbj
2. Download Oracle VirtualBox here for your respective machine type: https://www.virtualbox.org/wiki/Downloads
3. Open Oracle VirtualBox and click "Tools"
4. Click "Import" 
<strong>IMPORTANT NOTES:</strong> 
* <mark> ou must have at least 6GB of available space after downloading the .ova file to import the appliance successfully. </mark>
* <mark> If you receive an error "Could not start the machine RealTimeValidationSystem because the following physical network interfaces were not found..." click "Change Network Settings". You do not need a network connection to run the testing suite. </mark>
5. Navigate to and select "RealTimeValidationSystem.ova" then select "continue"
6. Click "import", this import process will take several minutes
7. Select the VM and click "start"
8. When prompted enter the password as "osboxes.org"
9. open a terminal and type and enter the following commands
```bash 
 $ cd ~/RealTimeValidationSystem
```
10. To build and start the unit test suite run:
```bash 
 $ ./test.sh
```

This command will build and execute the unit test suite for both the corruption and comparison units. The terminal will display logs of exactly what each unit test is testing and a synopsis of the testing results. Windows will display source and corrupted videos/images in real time to visualize the inner workings of the software. Enjoy! 

## Authors

* **Kamron Ebrahimi** 
* **Pu Huang** 
* **Dafei Du** 