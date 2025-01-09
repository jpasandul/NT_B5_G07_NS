// interfaces/ICameraDevice.hpp
#pragma once
#include <opencv2/opencv.hpp>

class ICameraDevice {
public:
    virtual ~ICameraDevice() = default;
    virtual void initialize(int deviceId = 0) = 0;
    virtual cv::Mat captureFrame() = 0;
    virtual bool isInitialized() const = 0;
    virtual void release() = 0;
};