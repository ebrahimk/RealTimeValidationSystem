## Collins Aerospace Real Time Camera Validation ##

[![TravisCI build](https://img.shields.io/travis/ebrahimk/RealTimeValidationSystem/develop?logo=travis)](https://travis-ci.org/ebrahimk/RealTimeValidationSystem/jobs/652818303)
![Project Size](https://img.shields.io/github/repo-size/ebrahimk/RealTimeValidationSystem)

## Description

This repository houses all of the code for a real time camera validation system, commissioned by Collins Aerospace. The project is developed on two Raspberry Pi's connected via ethernet. The purpose of this system is to create a device capable of validating firmware processed video streams. The device accomplishes this by receiving two video channels, one channel is the raw data captured by the CMOS sensor of a camera, the second channel is the downstream, post-processed data output by the cameras firmware. The device intelligently analyzes and compares these two channels and detect in real time, image translation, frozen images, and blank video buffers. 

### Prerequisites

This project requires the following libraries:
- OpenCV (>= 2.0)
- ZeroMQ
- Protocol Buffers
- cmake

## Built With

* [cmake](https://cmake.org/) - build tool


## Authors

* **Kamron Ebrahimi** - [Github](https://github.com/ebrahimk)
* **Pu Huang**  - [Github](https://github.com/huangpujj)
* **Dafei Du** - *Initial work* - 


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
