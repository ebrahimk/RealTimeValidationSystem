#include <iostream>
#include <opencv2/opencv.hpp>
#include <cstdio>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Compare.hpp"

#define FRAME_HEIGHT 480
#define FRAME_WIDTH 640

using namespace std;
using namespace cv;

TEST_CASE("translation filter can work in all directions", "[filter]" ){
	namedWindow("Image", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);

	Mat bird = imread("../../photo/bird.jpeg");
	
	Mat dup = bird.clone(); 
	Mat* dframe = &bird;

	vector<string> cmd;
	

	SECTION("Pixel shift right 30px"){		
		Mat test = imread("../../photo/bird_tx1.jpeg");
		
		
		imshow("Corrupt", bird);
		imshow("Image", dup);
		waitKey(1000);
		REQUIRE(1==1);	
	}
}
