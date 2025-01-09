// interfaces/IDisplayManager.hpp
#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class IDisplayManager {
public:
    virtual ~IDisplayManager() = default;
    virtual void initialize(const std::string& windowName) = 0;
    virtual void display(const cv::Mat& frame) = 0;
    virtual void cleanup() = 0;
    virtual bool checkKey(char key) = 0;
};