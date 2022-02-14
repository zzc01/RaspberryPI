#pragma once

#ifndef RECORDERCPP
#define RECORDERCPP

#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

#ifdef RASPBERRYPI 
#include <sys/statvfs.h>
#endif 

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "blob.h"


class Recorder
{
public:
	Recorder(cv::Size imgSize)
	{
		this->imgSize = imgSize;
		time0 = clock();
		RecordLength = 5; 
		framRate = 7;
		WasRecording = false; 
		remainTime = 0; 
	}

private:
	int framRate; 
	cv::Size imgSize;
	clock_t time0;
	int RecordLength;
	bool WasRecording;
	int remainTime;
	cv::VideoWriter writeVideo;
	std::string FILENAME;

public:
	void record(cv::Mat& imgFrame, const std::vector<Blob>& blobs);
	std::string getName(); 
	void drawFPSonImage(double fps, cv::Mat& imgFrame);
	int getDeskFreeSize();

};

#endif 



