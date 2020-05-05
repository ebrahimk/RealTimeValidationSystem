#include <iostream>
#include <opencv2/opencv.hpp>
#include <cstdio>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../filters/Distortion.hpp"
#include "../filters/Freeze.hpp"
#include "../filters/Translate.hpp"
#include "../filters/White.hpp"

#define FRAME_HEIGHT 480
#define FRAME_WIDTH 640

using namespace std;
using namespace cv;

TEST_CASE("translation filter can work in all directions", "[filter]" ){
	
  	Freeze freeze(100);
  	White white(50, 255, FRAME_HEIGHT, FRAME_WIDTH);
  	Translate translate(50, FRAME_HEIGHT, FRAME_WIDTH, 15, 15);

	namedWindow("Image", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);

	Mat bird = imread("./photo/bird.jpeg");
	Mat lake = imread("./photo/lake.jpeg");
	Mat coast = imread("./photo/coast.jpeg");
	
	Mat dup = bird.clone(); 
	//imshow("Image", dup);
	
	Mat* dframe = &bird;

	vector<string> cmd;
       	cmd.insert(cmd.end(), {"3","1","1000","30","30"});	
	translate.update(cmd);

	vector<int> compression_param;
	compression_param.push_back(IMWRITE_JPEG_QUALITY);	
	compression_param.push_back(100);
	
	SECTION("Pixel shift left"){
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx1.jpeg");
		imshow("Corrupt", bird);	
		imshow("Image", bird_tx1);
		cout<<" Press any key to continue... " <<endl;
		waitKey(0);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}
}

