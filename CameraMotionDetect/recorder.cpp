#include "recorder.h"

void Recorder::record(cv::Mat& imgFrame, const std::vector<Blob>& blobs)
{
	int deskFreeSize = getDeskFreeSize();
	if (deskFreeSize < 1400) {
		std::cout << "Error. Not enough disk space" << std::endl;
		return;
	}

	// Check Record or not 
	if (blobs.size() > 0)
	{
		if (WasRecording == false)
		{
			WasRecording = true;
			FILENAME = "video_" + getName() + ".mp4";
			//int ex = cv::VideoWriter::fourcc('P', 'I', 'M', '1'); 
			//int ex = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');	// XVID 
			//int ex = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
			int ex = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
			writeVideo.open(FILENAME, ex, framRate, imgSize, true);
			std::cout << "filename is : " << FILENAME << std::endl;
		}
		// 15 sec
		remainTime = RecordLength * CLOCKS_PER_SEC;
	}

	// Record 
	if (remainTime > 0)
	{
		std::cout << "Recording ... " << float(remainTime) / CLOCKS_PER_SEC << " sec left" << std::endl;
		double FPS = 1.0 / (clock() - time0) * CLOCKS_PER_SEC;
		std::cout << "--FILENAME = " << FILENAME << std::endl;
		std::cout << "--deskFreeSize = " << deskFreeSize << std::endl;
		std::cout << "--FPS = " << FPS << std::endl;
		drawFPSonImage(FPS, imgFrame);
		writeVideo.write(imgFrame);
		//
		remainTime = remainTime - (clock() - time0);
	}
	else
	{
		if (WasRecording == true)
		{
			WasRecording = false;
			writeVideo.release();
		}
		remainTime = 0;
	}

	// get time 
	time0 = clock();
}

std::string Recorder::getName()
{
	time_t ttime = time(0);
	//std::cout << "Seconds from 01/01/1990 : " << ttime << std::endl;

	struct tm local_time;

#ifdef RASPBERRYPI
	localtime_r(&ttime, &local_time);
#else
	localtime_s(&local_time, &ttime);
#endif

	std::string month = std::to_string(1 + local_time.tm_mon);
	if ((1 + local_time.tm_mon) < 10) month = "0" + month;

	std::string day = std::to_string(0 + local_time.tm_mday);
	if ((0 + local_time.tm_mday) < 10) day = "0" + day;

	std::string hour = std::to_string(0 + local_time.tm_hour);
	if ((0 + local_time.tm_hour) < 10) hour = "0" + hour;

	std::string min = std::to_string(0 + local_time.tm_min);
	if ((0 + local_time.tm_min) < 10) min = "0" + min;

	std::string sec = std::to_string(0 + local_time.tm_sec);
	if ((0 + local_time.tm_sec) < 10) sec = "0" + sec;

	std::string date_time =
		std::to_string(1900 + local_time.tm_year) + month + day + "_"
		+ hour + "_" + min + "_" + sec;

	std::cout << "In getName(). date time = " << date_time << std::endl;

	return date_time;
}

void Recorder::drawFPSonImage(double fps, cv::Mat& imgFrame)
{
	std::string text = "fps:" + std::to_string((int)fps);
	int intFontFace = cv::FONT_HERSHEY_SIMPLEX;
	double dblFontScale = (imgFrame.rows * imgFrame.cols) / pow(500, 2);
	int intFontThickness = (int)std::round(dblFontScale * 1.25);
	cv::Size textSize = cv::getTextSize(
		text,
		intFontFace,
		dblFontScale,
		intFontFace,
		0);
	cv::Point ptTextTopLeftPosition;
	ptTextTopLeftPosition.x = 5;
	ptTextTopLeftPosition.y = (int)((double)textSize.height * 1.25);
	cv::putText(imgFrame, text, ptTextTopLeftPosition, intFontFace, dblFontScale, cv::Scalar(0, 255, 0), intFontThickness);
}

#ifdef RASPBERRYPI

int Recorder::getDeskFreeSize()
{
	struct statvfs deskInfo;
	statvfs("/home/pi/projects/LinuxDeskInfo", &deskInfo);
	int deskFreeSize = deskInfo.f_bsize * deskInfo.f_bfree / 1024 / 1024;
	//std::cout << "Block Size (Bytes) : " << deskInfo.f_bsize << std::endl;
	//std::cout << "Total Blocks : " << deskInfo.f_blocks << std::endl;
	//std::cout << "Free Block : " << deskInfo.f_bfree << std::endl;
	//std::cout << "Free Desk Size (MB) : " << deskFreeSize << std::endl;
	return deskFreeSize;
}

#else

inline int Recorder::getDeskFreeSize() { return 1500; }

#endif // RASPBERRYPI
