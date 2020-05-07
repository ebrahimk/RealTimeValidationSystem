#include "Compare.hpp"

Compare::Compare() {}

int Compare::run(cv::Mat *frame, cv::Mat *dframe, cv::Mat *out) {
  /* Check if the two images are identical */
  if (!_isCorrupt(frame, dframe))
	  return 0;

  /* Check for all  white */
  if (_isWhite(dframe)) {
    output_ui(*out, false, true, false, 0, 0);
    std::cout << "All white detected" << std::endl;
    std::cout << "image colors: " << m_shade << std::endl;
    return 1;
  }

  /* Check for frozen */
  if (_isFrozen(dframe)) {
    output_ui(*out, false, false, true, 0, 0);
    std::cout << "Frozen frames detected" << std::endl;
    return 2;
  }

  /* Check for translation */
  if (_isTranslated(dframe)) {
    output_ui(*out, true, false, false, 0, 0);
    std::cout << "TX detected: " << std::endl;
    std::cout << "right shift: " << m_rs << std::endl;
    std::cout << "left shift: " << m_ls << std::endl;
    std::cout << "top shift: " << m_ts << std::endl;
    std::cout << "bot shift: " << m_bs << std::endl;
    return 3; 
  }
  
  // some other type of distortion occured!
  return -1; 
}

/*
 * Perform index wise comparison to determine if the two matrices are identical,
 * if not we know corruption of some type was introduced
 */
bool Compare::_identical(cv::Mat *a, cv::Mat *b) {
  if (a->rows != b->rows || a->cols != b->cols)
    return false;
  cv::Vec3b *d_row, *row;
  for (int j = 0; j < a->rows; ++j) {
    d_row = a->ptr<cv::Vec3b>(j);
    row = b->ptr<cv::Vec3b>(j);
    for (int i = 0; i < a->cols; ++i) {
      if (d_row[i][0] != row[i][0] || d_row[i][1] != row[i][1] ||
          d_row[i][2] != row[i][2])
        return false;
    }
  }
  return true;
}

/*
 * Checks if the two frames are identical, maintains a copy of the previously
 * received frame for diagnosing freeze distortion.
 */
bool Compare::_isCorrupt(cv::Mat *dframe, cv::Mat *frame) {
  if (!_identical(dframe, frame))
    return true;
  m_prev = frame->clone();
  return false;
}

/*
 * Index wise comparison. Grabs the first RGB vector of the 2D image matrix,
 * produces a new image matrix populated entirely with the RGB values read from
 * the first cell Checks if the new image is identical to the corrupted frame.
 */
bool Compare::_isWhite(cv::Mat *dframe) {
  cv::Vec3b rgb = dframe->at<cv::Vec3b>(0, 0);
  cv::Size sz = dframe->size();
  cv::Mat test(sz.height, sz.width, CV_8UC3, rgb);
  if (!_identical(dframe, &test))
    return false;
  m_shade = rgb;
  return true;
}

/*
 * Index wise comparison with the saved reference to the previously read frame.
 * If the two are identical then we know freeze distortion was applied.
 */
bool Compare::_isFrozen(cv::Mat *dframe) {
  if (!_identical(dframe, &m_prev))
    return false;
  return true;
}

/*
 * Index wise comparison. Read from the left right, top and bottom for identical
 * RGB cells to determine the offset of the translation.
 */
bool Compare::_isTranslated(cv::Mat *dframe) {
  m_ls = 0;
  m_rs = dframe->cols - 1;
  m_ts = 0;
  m_bs = dframe->rows - 1;
  while (_colEmpty(dframe, m_ls))
    m_ls++;
  while (_colEmpty(dframe, m_rs)) {
    m_rs--;
  }
  m_rs -= dframe->cols - 1;
  while (_rowEmpty(dframe, m_ts))
    m_ts++;
  while (_rowEmpty(dframe, m_bs)) {
    m_bs--;
  }
  m_bs -= dframe->rows - 1;
  if(m_ls == 0 && m_rs == dframe->cols-1 && m_ts == 0 && m_bs == dframe->rows-1)
    return false;
  return true; 
}

bool Compare::_colEmpty(cv::Mat *a, int i) {
  cv::Vec3b *row;
  cv::Vec3b *rgb = a->ptr<cv::Vec3b>(0);
  for (int j = 0; j < a->rows; ++j) {
    row = a->ptr<cv::Vec3b>(j);
    if (row[i][0] != rgb[i][0] || row[i][1] != rgb[i][1] ||
        row[i][2] != rgb[i][2])
      return false;
  }
  return true;
}

bool Compare::_rowEmpty(cv::Mat *a, int i) {
  cv::Vec3b *rgb = a->ptr<cv::Vec3b>(i);
  cv::Vec3b *row = a->ptr<cv::Vec3b>(i);
  for (int j = 0; j < a->cols; ++j) {
    if (row[j][0] != rgb[0][0] || row[j][1] != rgb[0][1] ||
        row[j][2] != rgb[0][2])
      return false;
  }
  return true;
}

void Compare::output_ui(cv::Mat &img, bool shift_detect, bool noise_detect,
                        bool freeze_detect, float fps, int frame_num) {
  if (img.empty()) {
	  std::cout << "Empty Image" << std::endl;
    return;
  }

  cv::Point warning = cv::Point(50, 50);
  cv::Scalar color = cv::Scalar(0, 0, 255);
  int thickness = 2;
  int font_size = 1;
  int font = cv::FONT_HERSHEY_COMPLEX_SMALL;
  int text_x = 50;
  int text_y = 100;
  int width1 = img.cols;
  int height1 = img.rows;

  putText(img, "FPS:", cv::Point(50, 380), font, font_size, cv::Scalar(0, 0, 0),
          thickness, 8, false);
  putText(img, std::to_string(fps), cv::Point(160, 380), font, font_size,
          cv::Scalar(0, 0, 0), thickness, 8, false);
  putText(img, std::to_string(width1), cv::Point(50, 430), font, font_size,
          cv::Scalar(0, 0, 0), thickness, 8, false);
  putText(img, "x", cv::Point(130, 430), font, font_size, cv::Scalar(0, 0, 0),
          thickness, 8, false);
  putText(img, std::to_string(height1), cv::Point(160, 430), font, font_size,
          cv::Scalar(0, 0, 0), thickness, 8, false);
  putText(img, std::to_string(frame_num), cv::Point(550, 50), font, 1, cv::Scalar(0, 0, 0),
          4, 8, false);
  if (shift_detect || noise_detect || freeze_detect) {
    putText(img, "Warning:", warning, font, font_size, color, thickness, 8,
            false);
    rectangle(img, cv::Point(0, 0), cv::Point(640, 480), color, 20);
  } else {
    return;
  }
  if (shift_detect) {
    putText(img, "Video Shift", cv::Point(text_x, text_y), font, font_size,
            color, thickness, 8, false);
    text_y = text_y + 50;
  }
  if (noise_detect) {
    putText(img, "Discolor", cv::Point(text_x, text_y), font, font_size,
            color, thickness, 8, false);
    text_y = text_y + 50;
  }
  if (freeze_detect) {
    putText(img, "Frozen", cv::Point(text_x, text_y), font, font_size, color,
            thickness, 8, false);
    text_y = text_y + 50;
  }
}
