// interfaces/IImageProcessor.hpp
#pragma once
#include <opencv2/opencv.hpp>
#include <memory>

class IImageProcessor {
public:
    virtual ~IImageProcessor() = default;
    virtual cv::Mat process(const cv::Mat& input) = 0;
    virtual void setNext(std::shared_ptr<IImageProcessor> next) = 0;
};