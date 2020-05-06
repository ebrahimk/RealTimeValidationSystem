#include <iostream>
#include <opencv2/opencv.hpp>
#include <cstdio>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../../Corruption/filters/Distortion.hpp"
#include "../../Corruption/filters/Freeze.hpp"
#include "../../Corruption/filters/Translate.hpp"
#include "../../Corruption/filters/White.hpp"
#include "../Compare.hpp"

#define FRAME_HEIGHT 480
#define FRAME_WIDTH 640

using namespace std;
using namespace cv;

TEST_CASE("translation filter can work in all directions", "[filter]" ){	
  	Translate translate(1000, FRAME_HEIGHT, FRAME_WIDTH, 15, 15);
	namedWindow("Normal", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup;
	Mat* dframe; 
	bool caught = false; 

	SECTION("translation"){			
		cout << "Applying 50px/100px translate distortion halfway through video" <<endl;
		cmd.insert(cmd.end(), {"3","1","1000","50","100"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			if(comparator.run(&dup, &frame) == 3)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("translation"){			
		cout << "Applying 1px/0px left translation distortion halfway through video" <<endl;
		cmd.insert(cmd.end(), {"3","1","1000","1","0"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			if(comparator.run(&dup, &frame) == 3)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}
	SECTION("translation"){			
		cout << "Applying -90px/-70px translate distortion for 100ms halfway through video" <<endl;
		cmd.insert(cmd.end(), {"3","1","100","-90","-70"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			if(comparator.run(&dup, &frame) == 3)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}

TEST_CASE("Teting All white filter", "[filter]" ){	
	White white(1000, 255, FRAME_HEIGHT, FRAME_WIDTH); 	

	namedWindow("Normal", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup;
	Mat* dframe; 
	bool caught = false; 

	SECTION("white"){			
		cout << "Applying All White 255" <<endl;
		cmd.insert(cmd.end(), {"2","1","500","255"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			if(comparator.run(&dup, dframe) == 1)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying All White 180" <<endl;
		cmd.insert(cmd.end(), {"2","1","500","180"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			if(comparator.run(&dup, dframe) == 1)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}
	SECTION("white"){			
		cout << "Applying All White 50" <<endl;
		cmd.insert(cmd.end(), {"2","1","500","50"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			if(comparator.run(&dup, dframe) == 1)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying All White 0 " <<endl;
		cmd.insert(cmd.end(), {"2","1","500","0"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			if(comparator.run(&dup, dframe) == 1)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}

TEST_CASE("Testing Freeze Detection", "[filter]" ){	
	Freeze freeze(1000); 	

	namedWindow("Normal", WINDOW_AUTOSIZE);	
	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup;
	Mat* dframe; 
	bool caught = false; 

	SECTION("white"){			
		cout << "Applying Freeze 1 second" <<endl;
		cmd.insert(cmd.end(), {"1","1","1000"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			if(comparator.run(&dup, dframe) == 2)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying Freeze 1/2 second (500ms)" <<endl;
		cmd.insert(cmd.end(), {"1","1","500"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			if(comparator.run(&dup, dframe) == 2)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying Freeze 1/10 second (100ms)" <<endl;
		cmd.insert(cmd.end(), {"1","1","100"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			if(comparator.run(&dup, dframe) == 2)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying Freeze 1/20  second (50ms)" <<endl;
		cmd.insert(cmd.end(), {"1","1","50"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			if(comparator.run(&dup, dframe) == 2)
			   caught = true; 
			imshow("Normal", dup); 
			imshow("Corrupt", *dframe);	
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}
