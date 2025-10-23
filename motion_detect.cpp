#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    VideoCapture cap(0);
    if (!cap.isOpened()) 
    {
        cerr << "Error: Could not open camera" << endl;
        return -1;
    }

    Mat frame, gray, prevGray, diffFrame, thresh;
    vector<vector<Point>> contours;

    cap >> frame;
    if (frame.empty()) 
    {
        cerr << "Error: Empty frame" << endl;
        return -1;
    }
    cvtColor(frame, prevGray, COLOR_BGR2GRAY);
    GaussianBlur(prevGray, prevGray, Size(21, 21), 0);

    while (true) 
    {
        cap >> frame;
        if (frame.empty())
            break;


        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(21, 21), 0);
        absdiff(prevGray, gray, diffFrame);
	threshold(diffFrame, thresh, 25, 255, THRESH_BINARY);
        dilate(thresh, thresh, Mat(), Point(-1,-1), 2);
        findContours(thresh, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        for (const auto& contour : contours) 
        {
            if (contourArea(contour) < 500)
                continue;
            Rect boundingBox = boundingRect(contour);
            rectangle(frame, boundingBox, Scalar(0, 255, 0), 2);
        }
        imshow("Motion Detection", frame);
        prevGray = gray.clone();

        if (waitKey(30) == 27) 
        {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
