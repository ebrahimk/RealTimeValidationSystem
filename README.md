## Collins Aerospace Real Time Camera Validation ##

[![TravisCI build](https://img.shields.io/travis/ebrahimk/RealTimeValidationSystem/develop?logo=travis)](https://travis-ci.org/ebrahimk/RealTimeValidationSystem/jobs/652818303)
![Project Size](https://img.shields.io/github/repo-size/ebrahimk/RealTimeValidationSystem)

## Description

This repository houses all of the code for a real time camera validation system, commissioned by Collins Aerospace. The purpose of this system is to create a device capable of validating firmware processed video streams. The device accomplishes this by receiving two video channels, one channel is the raw data captured by the CMOS sensor of a camera, the second channel is the downstream, post-processed data output by the cameras firmware. The device intelligently analyzes and compares these two channels and detect in real time, image translation, frozen images, and blank video buffers. 

To sythesize controlled image distotion, this proof of concept is composed of two blocks, a corruption and a comparison unit implemented on Raspberry Pi's. One Raspberry Pi is responsible for capture a image frames, producing a replicate of the captured frame, applying corruption filters to a single copy of the frame, then compressing, serializing and sending the data over 1GB Ethernet. The comparison unit captures incoming data, deserializes, and decompresses the packet, then compares the two frames using OpenCV. 
The system is highly scalable and capable of operating on frames of varying resolution. To facilitate easy user interaction a web interface allows users to dynamically configure the behavior of the distortion filters. 
 

## Design 

![Block Diagram](https://github.com/ebrahimk/RealTimeValidationSystem/blob/develop/.photos/blockDiagram.png)

The bottleneck of the system is the 1GB Ethernet connection, which struggles to process the large amount of data contained in high-resolution/high-fps video streams. 
To optimize performance, the processes responsible for image processing on both the corruption and comparison units are written using OpenCV’s C++ API. The programs spawn multiple threads which communicate over a set of shared queues. Unique threads are responsible for reading and writing over the TCP socket, deserializing and serializing captured data, and also displaying captured frames to the user. The corruption unit comes equipped with an extra thread which opens and maintains a socket for interprocess communication with the web interface. 

## Known Issues

In its current state the program can detect and diagnose all forms of distortion the corruption unit is capable of introducing. Due to the compression and serialization of frames occuring at the same time, the comparison unit looses diagnostic accuracy when detecting image translation. The program reports pixels shifts approxiamtley 10 pixels off the true shift amount. This issue is currently being researched. 

## Authors

* **Kamron Ebrahimi** 
* **Pu Huang** 
* **Dafei Du** 
