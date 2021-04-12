#include <opencv2/core/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	Mat frame;
	//--- VIDEO CAPTURE INIT
	VideoCapture cap;
	//open the default camera using default API
	cap.open(0);
	//check if cap is opened
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera.\n";
		return -1;
	}
	//--- Grab and Write Loop
	cout << "Start grabbing" << endl
		<< "Press any key to terminate" << endl;
	for (;;) {
		//wait for a new frame from the camera and store it into frame.
		cap.read(frame);
		//check if we succeeded
		if(frame.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}
		Mat frame1 = frame.clone();
		//show live and wait for a key with timeout long enough to show the images
		imshow("Live", frame);
		if (waitKey(5) >= 0)
			break;

	}
	//Camera automatically deletes on stop.
	return 0;
}
