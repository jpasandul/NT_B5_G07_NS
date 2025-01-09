// interfaces/IImageStorage.hpp
#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class IImageStorage {
public:
    virtual ~IImageStorage() = default;
    virtual void save(const cv::Mat& image, const std::string& identifier) = 0;
    virtual cv::Mat load(const std::string& identifier) = 0;
};