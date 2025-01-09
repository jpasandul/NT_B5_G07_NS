# 📸 Camera System

A modular C++ camera system using Raspberry Pi/Webcam for face recognition and attendance tracking.

## 🚀 Features
- Real-time camera feed display
- Image preprocessing pipeline
- Face detection and recognition (coming soon)
- Local storage capabilities
- Azure cloud integration (planned)

## 🛠️ Tech Stack
- C++17
- OpenCV
- CMake
- Raspberry Pi Camera/Webcam

## 📦 Installation
```bash
# Clone repository
git clone https://github.com/yourusername/CameraSystem.git

# Create build directory
mkdir build && cd build

# Build project
cmake ..
make
```

## 🏃‍♂️ Running
```bash
./bin/CameraSystem
```

## 🔑 Controls
- `C` - Capture image
- `Q` - Quit application

## 🏗️ Architecture
- Modular design following SOLID principles
- Chain of responsibility for image processing
- Interface-based component abstraction

## 📁 Project Structure
```
CameraSystem/
├── include/
│   ├── interfaces/         # Abstract interfaces
│   ├── implementations/    # Concrete implementations
├── src/                    # Source files
├── build/                  # Build output
└── CMakeLists.txt         # Build configuration
```

## 📝 License
MIT License

## ✨ Contributors
- Your Name (@yourusername)