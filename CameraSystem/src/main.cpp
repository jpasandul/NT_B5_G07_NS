// main.cpp
#include "CameraSystem.hpp"
#include "implementations/WebCamera.hpp"
#include "implementations/ImageProcessorChain.hpp"
#include "implementations/OpenCVDisplay.hpp"
#include "implementations/LocalFileStorage.hpp"

int main() {
    try {
        // Create processing pipeline
        auto resizer = std::make_shared<ResizeProcessor>();
        auto grayscale = std::make_shared<GrayscaleProcessor>();
        auto contrast = std::make_shared<ContrastEnhancer>();
        auto noiseReducer = std::make_shared<NoiseReducer>();

        // Chain processors
        resizer->setNext(grayscale);
        grayscale->setNext(contrast);
        contrast->setNext(noiseReducer);

        // Create system components
        auto camera = std::make_unique<WebCamera>();
        auto display = std::make_unique<OpenCVDisplay>();
        auto storage = std::make_unique<LocalFileStorage>();

        // Create and run system
        CameraSystem system(
            std::move(camera),
            resizer,
            std::move(display),
            std::move(storage)
        );

        system.initialize();
        system.run();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}