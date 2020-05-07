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
	namedWindow("Corrupt", WINDOW_AUTOSIZE);	
	namedWindow("Normal", WINDOW_AUTOSIZE);	
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup, out;
	Mat* dframe; 
	bool caught = false; 

	SECTION("translation 50/100 @ 1000"){			
		cout << "Applying 50px/100px translation for 1000ms" <<endl;
		cmd.insert(cmd.end(), {"3","1","1000","50","100"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, &frame, &out) == 3)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("translation 22/-90 @ 500"){			
		cout << "Applying 1px/0px translation for 500ms" <<endl;
		cmd.insert(cmd.end(), {"3","1","500","22","-90"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, &frame, &out) == 3)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("translation -20/-70 @ 100"){			
		cout << "Applying -20px/-1px translation for 100ms" <<endl;
		cmd.insert(cmd.end(), {"3","1","100","-20","-70"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, &frame, &out) == 3)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("translation -1/0 @ 30"){			
		cout << "Applying -60px/5px translation for 30ms" <<endl;
		cmd.insert(cmd.end(), {"3","1","30","-1","0"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				translate.update(cmd);
			translate.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, &frame, &out) == 3)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}


TEST_CASE("Testing All White filter", "[filter]" ){	
	White white(1000, 255, FRAME_HEIGHT, FRAME_WIDTH); 	

	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	namedWindow("Normal", WINDOW_AUTOSIZE);	
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup, out;
	Mat* dframe; 
	bool caught = false; 

	SECTION("white"){			
		cout << "Applying All White 255 for 1000 ms" <<endl;
		cmd.insert(cmd.end(), {"2","1","1000","255"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 1)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying All White 127 for 500 ms" <<endl;
		cmd.insert(cmd.end(), {"2","1","500","127"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 1)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying All White 64 for 100 ms" <<endl;
		cmd.insert(cmd.end(), {"2","1","100","64"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 1)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("white"){			
		cout << "Applying All White 0 for 30 ms" <<endl;
		cmd.insert(cmd.end(), {"2","1","30","0"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				white.update(cmd);
			white.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 1)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}

TEST_CASE("Testing Freeze Detection", "[filter]" ){	
	Freeze freeze(1000); 	

	namedWindow("Corrupt", WINDOW_AUTOSIZE);
	namedWindow("Normal", WINDOW_AUTOSIZE);	
	Compare comparator; 
	
	VideoCapture cap("../../photo/test_video.mp4");	
	int frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
	vector<string> cmd;
	Mat frame, dup, out;
	Mat* dframe; 
	bool caught = false; 

	SECTION("freeze 1"){			
		cout << "Applying Freeze 1 second (1000ms)" <<endl;
		cmd.insert(cmd.end(), {"1","1","1000"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 2)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("freeze 1/2"){			
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
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 2)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("freeze 1/10"){			
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
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 2)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}

	SECTION("freeze 1/20"){			
		cout << "Applying Freeze  1/33 second (30ms)" <<endl;
		cmd.insert(cmd.end(), {"1","1","30"});	
		for(int i = 0; i < frame_count; i++){		
			cap >> frame; 
			resize(frame,frame,Size(frame.cols/2,frame.rows/2));	
			dframe = &frame;
		       	dup = frame.clone();
			if(i == frame_count/2)
				freeze.update(cmd);
			freeze.run(dframe);
			out = dframe->clone();
			if(comparator.run(&dup, dframe, &out) == 2)
			   caught = true; 	
			imshow("Corrupt", out);	
			imshow("Normal", dup); 
			waitKey(1); 
		}
		REQUIRE(caught);
	}
}
