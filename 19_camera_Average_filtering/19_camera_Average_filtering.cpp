// 19_camera_Average_filtering.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()  //均值滤波
{
	VideoCapture cap(0);
	double scale = 0.5;

	while (1)
	{
		cv::Mat frame;
		cv::Mat hsvMat;
		cv::Mat blurMat;
		cv::Mat GaussianBlurMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		blur(rFrame, blurMat, Size(3, 3),Point(-1,-1));//均值滤波
		GaussianBlur(rFrame, GaussianBlurMat, Size(3, 3),1,0);

		cv::imshow("blur: in the Average filtering", blurMat);
		cv::imshow("GaussianBlur: in the Average filtering", GaussianBlurMat);
		cv::imshow("frame", rFrame);

		waitKey(30);
	}
}

