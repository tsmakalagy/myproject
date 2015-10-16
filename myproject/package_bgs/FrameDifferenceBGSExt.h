#include <iostream>
#include <opencv2/opencv.hpp>

namespace bgslibrary
{
	class FrameDifferenceBGSExt: public FrameDifferenceBGS
	{
		public:
			void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);
	  	
	};
}