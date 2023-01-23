#include <thread>
#include "stag/Stag.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./program <camera_index>" << std::endl;
		return -1;
	}
	auto debug = argc == 3;

	if (debug) cv::namedWindow("Camera Feed");

    auto stag = new Stag(11);
	cv::VideoCapture cap(atoi(argv[1]));
	if (!cap.isOpened()) {
		std::cout << "Error opening camera" << std::endl;
		return -1;
	}

	cv::Mat frame;
	cv::Mat gray;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			std::cout << "Error reading frame from camera" << std::endl;
			break;
		}

		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
		stag->detectMarkers(gray);
		if (debug) cv::imshow("Camera Feed", stag->drawMarkers());

		std::vector<Marker> markers = stag->getMarkerList();
		if (markers.size() > 0) {
			std::cout << "[";
			for (int i = 0; i < markers.size(); i++) {
				auto marker = markers[i];
				if (i > 0) std::cout << ",";
				std::cout << "{\"id\":" << marker.id << ",\"points\":[";
				for (int j = 0; j < marker.corners.size(); j++) {
					auto corner = marker.corners[j];
					std::cout << "[" << corner.x << "," << corner.y << "]";
					if (j < marker.corners.size() - 1)
						std::cout << ",";
				}
				std::cout << "]}";
			}
			std::cout << "]" << std::endl;
		}

		if (debug) {
			if (cv::waitKey(10) >= 0) return 0;
		}
	}
}
