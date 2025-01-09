// implementations/LocalFileStorage.hpp
#pragma once
#include "../interfaces/IImageStorage.hpp"
#include <filesystem>

class LocalFileStorage : public IImageStorage {
private:
    std::string baseDirectory;

public:
    LocalFileStorage(const std::string& directory = "./captured_images/") 
        : baseDirectory(directory) {
        std::filesystem::create_directories(baseDirectory);
    }

    void save(const cv::Mat& image, const std::string& identifier) override {
        std::string fullPath = baseDirectory + identifier + ".jpg";
        if (!cv::imwrite(fullPath, image)) {
            throw std::runtime_error("Failed to save image: " + fullPath);
        }
    }

    cv::Mat load(const std::string& identifier) override {
        std::string fullPath = baseDirectory + identifier + ".jpg";
        cv::Mat image = cv::imread(fullPath);
        if (image.empty()) {
            throw std::runtime_error("Failed to load image: " + fullPath);
        }
        return image;
    }
};