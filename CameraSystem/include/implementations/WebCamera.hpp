// implementations/WebCamera.hpp
#pragma once
#include "../interfaces/ICameraDevice.hpp"
#include <stdexcept>

class WebCamera : public ICameraDevice {
private:
    cv::VideoCapture camera;
    bool initialized;

    void checkCamera() const {
        if (!camera.isOpened()) {
            throw std::runtime_error("Camera is not accessible");
        }
    }

public:
    WebCamera() : initialized(false) {}
    
    ~WebCamera() {
        if (initialized) {
            release();
        }
    }

    void initialize(int deviceId = 0) override {
        camera.open(deviceId);
        checkCamera();
        initialized = true;
    }

    cv::Mat captureFrame() override {
        checkCamera();
        cv::Mat frame;
        camera >> frame;
        if (frame.empty()) {
            throw std::runtime_error("Failed to capture frame");
        }
        return frame;
    }

    bool isInitialized() const override {
        return initialized;
    }

    void release() override {
        if (initialized) {
            camera.release();
            initialized = false;
        }
    }
};