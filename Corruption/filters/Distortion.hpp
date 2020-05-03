#ifndef _DISTORTION_H_
#define _DISTORTION_H_

#include <chrono>
#include <opencv2/opencv.hpp>

/*
 * Distortion virtual base class.
 * All distortion filters inherit from the class.
 * This class provides the scaffolding for timing operations
 * so filter are only intoduced for the specified duration. 
 */
class Distortion {
public:
  Distortion(int dur);
  virtual void run(cv::Mat *&frame) = 0;
  void setTime(int dur);
  void activate();
  virtual void update(std::vector<std::string> cmd) = 0;

protected:
  void startTimer();
  bool isActive();
  void takeTime();
  int m_dur; // in ms
  bool m_on;
  std::chrono::system_clock::time_point m_start;
  std::chrono::system_clock::time_point m_end;
};

#endif // _DISTORTION_H_