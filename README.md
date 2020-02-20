## Collins Aerospace Real Time Camera Validation ##

[![TravisCI build](https://img.shields.io/travis/ebrahimk/RealTimeValidationSystem/develop?logo=travis)](https://travis-ci.org/ebrahimk/RealTimeValidationSystem/jobs/652818303)
![Project Size](https://img.shields.io/github/repo-size/ebrahimk/RealTimeValidationSystem)

## Description

This repository houses all of the code for a real time camera validation system, commissioned by Collins Aerospace. The purpose of this system is to create a device capable of validating firmware processed video streams. The device accomplishes this by receiving two video channels, one channel is the raw data captured by the CMOS sensor of a camera, the second channel is the downstream, post-processed data output by the cameras firmware. The device intelligently analyzes and compares these two channels and detect in real time, image translation, frozen images, and blank video buffers. 

To sythesize controlled image distotion, this proof of concept is composed of two blocks, a corruption and a comparison unit implemented on Raspberry Pi's. One Raspberry Pi is responsible for capture a image frames, producing a replicate of the captured frame, applying corruption filters to a single copy of the frame, then compressing, serializing and sending the data over 1GB Ethernet. The comparison unit captures incoming data, deserializes, and decompresses the packet, then compares the two frames using OpenCV. 
The system is highly scalable and capable of operating on frames of varying resolution. To facilitate easy user interaction a web interface allows users to dynamically configure the behavior of the distortion filters. 
 

## Design 



## Authors

* **Kamron Ebrahimi** 
* **Pu Huang** 
* **Dafei Du** 


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
