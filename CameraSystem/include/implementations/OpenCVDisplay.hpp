// implementations/OpenCVDisplay.hpp
#pragma once
#include "../interfaces/IDisplayManager.hpp"

class OpenCVDisplay : public IDisplayManager {
private:
    std::string windowName;
    bool initialized;

public:
    OpenCVDisplay() : initialized(false) {}

    void initialize(const std::string& name) override {
        windowName = name;
        cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
        initialized = true;
    }

    void display(const cv::Mat& frame) override {
        if (!initialized) {
            throw std::runtime_error("Display not initialized");
        }
        cv::imshow(windowName, frame);
    }

    void cleanup() override {
        if (initialized) {
            cv::destroyWindow(windowName);
            initialized = false;
        }
    }

    bool checkKey(char key) override {
        return cv::waitKey(1) == static_cast<int>(key);
    }
};