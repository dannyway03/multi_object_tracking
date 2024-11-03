#pragma once
#include "Detector.hpp"

class YoloV5 : public Detector{
	  cv::dnn::Net net_;
      float score_threshold_ = 0.5;
      float nms_threshold_ = 0.4;


public:
    YoloV5(const std::vector<std::string>& classNames,
 	    std::string modelConfiguration, 
        std::string modelBinary, 
        float confidenceThreshold = 0.25,
        size_t network_width = 640,
        size_t network_height = 640); 
	std::vector<Detection> run_detection(const cv::Mat& frame) override;
    cv::Mat preprocess_img(const cv::Mat& img);
    cv::Rect get_rect(const cv::Size& imgSize, const std::vector<float>& bbox);
};