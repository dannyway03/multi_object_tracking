#pragma once
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <filesystem>

#include "Detection.hpp"

class Detector{
protected:	
	std::vector<std::string> classNames_; 
  	std::string modelConfiguration_;
  	std::string modelBinary_; 
	float confidenceThreshold_; 	  
  	size_t network_width_;
  	size_t network_height_;	
public:
	Detector(){}

    virtual ~Detector(){};

	Detector(const Detector& d){
		classNames_ = d.classNames_;
		modelConfiguration_ = d.modelConfiguration_;
  		modelBinary_ = d.modelBinary_; 
		confidenceThreshold_ = d.confidenceThreshold_;  
		network_width_ = d.network_width_;
  		network_height_ = d.network_height_;	
	}
	Detector(Detector&& d){
		classNames_ = d.classNames_;
		modelConfiguration_ = d.modelConfiguration_;
  		modelBinary_ = d.modelBinary_; 
		confidenceThreshold_ = d.confidenceThreshold_;    
		network_width_ = d.network_width_;
  		network_height_ = d.network_height_;			
	}

	Detector(const std::vector<std::string>& classes, 
	const std::string& modelConfiguration,
	const std::string& modelBinary,
	float confidenceThreshold, 
  	size_t network_width,
  	size_t network_height		
	) : classNames_{classes}, 
		modelConfiguration_{modelConfiguration},
		modelBinary_{modelBinary},
		confidenceThreshold_{confidenceThreshold},
		network_width_ {network_width},
  		network_height_ {network_height}		 
	{

	}

    virtual std::vector<Detection> run_detection(const cv::Mat& frame) = 0;

};