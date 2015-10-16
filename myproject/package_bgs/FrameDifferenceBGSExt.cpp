#include "FrameDifferenceBGS.h"
#include "FrameDifferenceBGSExt.h"

namespace bgslibrary {
	/*FrameDifferenceBGSExt::FrameDifferenceBGSExt()
	{
		//FrameDifferenceBGS::FrameDifferenceBGS();
		std::cout << "FrameDifferenceBGSExt()" << std::endl;
	}

	FrameDifferenceBGSExt::~FrameDifferenceBGSExt()
	{
		FrameDifferenceBGS::~FrameDifferenceBGS();
	}*/
	void FrameDifferenceBGSExt::process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel)
	{
	  if(img_input.empty())
		return;

	  loadConfig();

	  if(firstTime)
		saveConfig();

	  if(img_input_prev.empty())
	  {
		img_input.copyTo(img_input_prev);
		return;
	  }

	  cv::absdiff(img_input_prev, img_input, img_foreground);

	  if(img_foreground.channels() == 3)
		cv::cvtColor(img_foreground, img_foreground, CV_BGR2GRAY);

	  if(enableThreshold)
		cv::threshold(img_foreground, img_foreground, threshold, 255, cv::THRESH_BINARY);

	  if(showOutput)
		//cv::imshow("Frame Difference", img_foreground);

	  img_foreground.copyTo(img_output);

	  img_input.copyTo(img_input_prev);

	  firstTime = false;
	}
}