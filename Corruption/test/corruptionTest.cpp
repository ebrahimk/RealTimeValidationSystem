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
#define TRANSLATE 3
#define FREEZE 1
#define WHITE 2

using namespace std;
using namespace cv;

TEST_CASE("translation filter can work in all directions", "[filter]" ){
  	Translate translate(50, FRAME_HEIGHT, FRAME_WIDTH, 15, 15);

	namedWindow("Image", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);

	Mat bird = imread("./photo/bird.jpeg");
	
	Mat dup = bird.clone(); 
	Mat* dframe = &bird;

	vector<string> cmd;
	vector<int> compression_param;
	compression_param.push_back(IMWRITE_JPEG_QUALITY);	
	compression_param.push_back(100);
	
	imshow("Image", dup);

	SECTION("Pixel shift right 30px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","30","0"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");	
		Mat bird_tx1 = imread("./photo/bird_tx1.jpeg");
		imshow("Corrupt", bird);
		cout<<"Pixel shift right 30px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}
	SECTION("Pixel shift left 30px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","-30","0"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx2.jpeg");
		imshow("Corrupt", bird);	
		cout<<"Pixel shift left 30px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}

	SECTION("Pixel shift bottom 60px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","0","-60"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx3.jpeg");
		imshow("Corrupt", bird);	
		cout<<"Pixel shift bottom 60px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}

	SECTION("Pixel shift top 100px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","0","100"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx4.jpeg");
		imshow("Corrupt", bird);	
		cout<<"Pixel shift top 100px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}

	SECTION("Pixel shift top 20px and left 30px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","30","20"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx5.jpeg");
		imshow("Corrupt", bird);	
		cout<<"Pixel shift top 20px and left 30px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}

	SECTION("Pixel shift top 80px and right 10px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","-10","80"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx6.jpeg");
		imshow("Corrupt", bird);	
		cout<<"Pixel shift top 80px and right 10px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}
	SECTION("Pixel shift bottom 20px and left 5px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","5","20"});	
		translate.update(cmd);
		translate.run(dframe);
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");
		Mat bird_tx1 = imread("./photo/bird_tx7.jpeg");
		imshow("Corrupt", bird);		
		cout<<"Pixel shift bottom 20px and left 5px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird.begin<uchar>(),bird.end<uchar>(),bird_tx1.begin<uchar>()));	
	}
	SECTION("Pixel shift bottom 100px and right 150px"){		
       		cmd.insert(cmd.end(), {"3","1","1000","-150","100"});	
		translate.update(cmd);
		translate.run(dframe);
		
		imwrite("test.jpeg",bird,compression_param);
		bird = imread("test.jpeg");
		remove("test.jpeg");

		Mat bird_tx1 = imread("./photo/bird_tx8.jpeg");
		imshow("Corrupt", *dframe);		
		cout<<"Pixel shift bottom 100px and right 150px" <<endl;
		waitKey(1000);
		REQUIRE(equal(bird_tx1.begin<uchar>(),bird_tx1.end<uchar>(),dframe->begin<uchar>()));	
	}
}

TEST_CASE("All White filter can apply 8-bit shading", "[filter]" ){
  	
	White white(50, 255, FRAME_HEIGHT, FRAME_WIDTH);
	namedWindow("Image", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);

	Mat lake = imread("./photo/lake.jpeg");	

	Mat dup = lake.clone(); 
	Mat* dframe = &lake;

	vector<string> cmd;
	
	vector<int> compression_param;
	compression_param.push_back(IMWRITE_JPEG_QUALITY);	
	compression_param.push_back(100);

	imshow("Image", dup);

	SECTION("255"){			
		cmd.insert(cmd.end(), {"2","1","1000","255"});	
		white.update(cmd);
		white.run(dframe);
		Mat test = imread("./photo/lake_255.jpeg");
		imshow("Corrupt", *dframe);
		cout<<"white shade [255]" <<endl;
		waitKey(500);
		REQUIRE(equal(test.begin<uchar>(),test.end<uchar>(),dframe->begin<uchar>()));	
	}

	SECTION("180"){			
		cmd.insert(cmd.end(), {"2","1","1000","180"});	
		white.update(cmd);
		white.run(dframe);
		Mat test = imread("./photo/lake_180.jpeg");
		imshow("Corrupt", *dframe);
		cout<<"white shade [180]" <<endl;
		waitKey(500);
		REQUIRE(equal(test.begin<uchar>(),test.end<uchar>(), dframe->begin<uchar>()));	
	}

	SECTION("100"){			
		cmd.insert(cmd.end(), {"2","1","1000","100"});	
		white.update(cmd);
		white.run(dframe);
		Mat test = imread("./photo/lake_100.jpeg");
		imshow("Corrupt", *dframe);
		cout<<"white shade [100]" <<endl;
		waitKey(500);
		REQUIRE(equal(test.begin<uchar>(),test.end<uchar>(), dframe->begin<uchar>()));	
	}
	
	SECTION("50"){			
		cmd.insert(cmd.end(), {"2","1","1000","50"});	
		white.update(cmd);
		white.run(dframe);
		Mat test = imread("./photo/lake_50.jpeg");
		imshow("Corrupt", *dframe);
		cout<<"white shade [50]" <<endl;
		waitKey(500);
		REQUIRE(equal(test.begin<uchar>(),test.end<uchar>(),dframe->begin<uchar>()));	
	}

	SECTION("0"){		
		cmd.insert(cmd.end(), {"2","1","1000","0"});	
		white.update(cmd);
		white.run(dframe);
		Mat test = imread("./photo/lake_0.jpeg");
		imshow("Corrupt", *dframe);
		cout<<"white shade [0]" <<endl;
		waitKey(500);
		REQUIRE(equal(test.begin<uchar>(),test.end<uchar>(),dframe->begin<uchar>()));	
	}
}

TEST_CASE("Freeze filter, causes video feed to halt", "[filter]" ){	
	namedWindow("Image", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	Freeze freeze(1000); 
	VideoCapture cap("./photo/test_video.mp4");	
	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);

	vector<string> cmd;
	Mat frame, dup;
	Mat* dframe; 

	SECTION("Freeze"){
		cout << "Applying freeze distortion halfway through video" <<endl;
		cmd.insert(cmd.end(), {"1","1","1000"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			imshow("Image", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(equal(dup.begin<uchar>(),dup.end<uchar>(),dframe->begin<uchar>()));	
	}
}
