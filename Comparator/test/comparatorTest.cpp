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
	namedWindow("Normal", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);

	Compare comparator; 
	
	Mat bird = imread("../../photo/bird.jpeg");
	
	SECTION("no shift"){		
		Mat corrupt = imread("../../photo/bird.jpeg");	
		comparator.run(&bird, &corrupt);
		imshow("Corrupt", corrupt);
		imshow("Normal", bird);
		waitKey(2000);
		REQUIRE(1==1);	
	}

	SECTION("Pixel shift right 30px"){		
		Mat corrupt = imread("../../photo/bird_tx1.jpeg");	
		comparator.run(&bird, &corrupt);
		imshow("Corrupt", corrupt);
		imshow("Normal", bird);
		waitKey(2000);
		REQUIRE(1==1);	
	}
}
