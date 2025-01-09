// implementations/ImageProcessorChain.hpp
#pragma once
#include "../interfaces/IImageProcessor.hpp"

class BaseImageProcessor : public IImageProcessor {
protected:
    std::shared_ptr<IImageProcessor> nextProcessor;

public:
    void setNext(std::shared_ptr<IImageProcessor> next) override {
        nextProcessor = next;
    }

    cv::Mat process(const cv::Mat& input) override {
        cv::Mat processed = processImpl(input);
        if (nextProcessor) {
            return nextProcessor->process(processed);
        }
        return processed;
    }

    virtual cv::Mat processImpl(const cv::Mat& input) = 0;
};

class ResizeProcessor : public BaseImageProcessor {
private:
    cv::Size targetSize;

public:
    ResizeProcessor(int width = 640, int height = 480) 
        : targetSize(width, height) {}

    cv::Mat processImpl(const cv::Mat& input) override {
        cv::Mat resized;
        cv::resize(input, resized, targetSize);
        return resized;
    }
};

class GrayscaleProcessor : public BaseImageProcessor {
public:
    cv::Mat processImpl(const cv::Mat& input) override {
        cv::Mat grayscale;
        cv::cvtColor(input, grayscale, cv::COLOR_BGR2GRAY);
        return grayscale;
    }
};

class ContrastEnhancer : public BaseImageProcessor {
public:
    cv::Mat processImpl(const cv::Mat& input) override {
        cv::Mat enhanced;
        cv::equalizeHist(input, enhanced);
        return enhanced;
    }
};

class NoiseReducer : public BaseImageProcessor {
private:
    int kernelSize;

public:
    NoiseReducer(int kSize = 5) : kernelSize(kSize) {}

    cv::Mat processImpl(const cv::Mat& input) override {
        cv::Mat denoised;
        cv::GaussianBlur(input, denoised, cv::Size(kernelSize, kernelSize), 0);
        return denoised;
    }
};