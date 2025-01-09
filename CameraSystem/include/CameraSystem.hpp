// CameraSystem.hpp
#pragma once
#include <memory>
#include "interfaces/ICameraDevice.hpp"
#include "interfaces/IImageProcessor.hpp"
#include "interfaces/IDisplayManager.hpp"
#include "interfaces/IImageStorage.hpp"

class CameraSystem {
private:
    std::unique_ptr<ICameraDevice> camera;
    std::shared_ptr<IImageProcessor> processor;
    std::unique_ptr<IDisplayManager> display;
    std::unique_ptr<IImageStorage> storage;
    bool initialized;

public:
    CameraSystem(
        std::unique_ptr<ICameraDevice> cam,
        std::shared_ptr<IImageProcessor> proc,
        std::unique_ptr<IDisplayManager> disp,
        std::unique_ptr<IImageStorage> stor
    ) : camera(std::move(cam)),
        processor(std::move(proc)),
        display(std::move(disp)),
        storage(std::move(stor)),
        initialized(false) {}

    void initialize(int cameraId = 0) {
        camera->initialize(cameraId);
        display->initialize("Camera Feed");
        initialized = true;
    }

    void run() {
        if (!initialized) {
            throw std::runtime_error("System not initialized");
        }

        int imageCount = 0;
        std::cout << "Press 'c' to capture an image or 'q' to quit" << std::endl;

        while (true) {
            try {
                cv::Mat frame = camera->captureFrame();
                display->display(frame);

                if (display->checkKey('c')) {
                    cv::Mat processed = processor->process(frame);
                    std::string identifier = "image_" + std::to_string(++imageCount);
                    storage->save(processed, identifier);
                    std::cout << "Image captured: " << identifier << std::endl;
                }

                if (display->checkKey('q')) {
                    break;
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error during capture: " << e.what() << std::endl;
                break;
            }
        }
    }

    ~CameraSystem() {
        if (initialized) {
            camera->release();
            display->cleanup();
        }
    }
};