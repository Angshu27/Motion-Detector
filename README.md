# Motion-Detector
This project implements a simple real-time motion detection system using OpenCV and C++. It captures video from your webcam, detects motion by analyzing frame differences, and highlights moving areas with bounding boxes.

**Features**
Captures live video from the default webcam.
Detects motion by comparing consecutive frames.
Applies Gaussian blur and thresholding for noise reduction.
Highlights moving objects with green rectangles.
Exits cleanly when the ESC key is pressed.

**Prerequisites**
Ubuntu (or Linux with OpenCV installed)
OpenCV development libraries (libopencv-dev)
A webcam connected to your system
C++ compiler (g++)

**Installation on Ubuntu**
Install OpenCV on Ubuntu:
sudo apt update
sudo apt install libopencv-dev

**For Windows**
Download and install OpenCV prebuilt Windows binaries
Set environment variables:
Add OpenCV bin directory (e.g., C:\opencv\build\x64\vc15\bin) to your PATH.
Configure your compiler (Visual Studio or MinGW) to include OpenCV headers and libraries.
Compile with Visual Studio:
Create a new C++ console project.
Add main.cpp.
Configure project properties to include OpenCV include and lib directories.
Link against necessary OpenCV .lib files (e.g., opencv_world451.lib).
Or compile with MinGW (example):
g++ main.cpp -o motion_detection -IC:/opencv/build/include -LC:/opencv/build/x64/mingw/lib -lopencv_core451 -lopencv_imgproc451 -lopencv_highgui451 -lopencv_videoio451


**Usage**
Clone or download the project source code.
Place an image named test.jpg in the project directory for testing (optional).
Compile the code:
g++ main.cpp -o motion_detection `pkg-config --cflags --libs opencv4`
Run the executable:
./motion_detection
A window titled Motion Detection will open showing the live video feed with motion highlighted.
Press ESC to exit the program.

**Code Overview**
VideoCapture opens the webcam.
Frames are converted to grayscale and blurred.
Frame differences are computed using absdiff.
Thresholding and dilation isolate moving regions.
Contours of moving areas are detected and filtered by size.
Green rectangles are drawn around significant motion.
The processed video feed is displayed in real-time.

**Troubleshooting**
If the camera does not open, ensure no other application is using it.
Make sure OpenCV is installed properly.
If pkg-config command fails, try replacing opencv4 with opencv in the compile command.
Adjust contour area threshold (currently 500) to tune motion sensitivity.

**License**
This project is open source and free to use for educational and personal purposes.

**Author**
Angshuman Barman (Angshu27)
