/*
*  stereo_match.cpp
*  calibration
*
*  Created by Victor  Eruhimov on 1/18/10.
*  Copyright 2010 Argus Corp. All rights reserved.
*
*/

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace cv;

int main(int argc, char** argv)
{
	Mat dist = imread("MiI-MapaGłębokości.png");
	Mat ball = imread("MiI-Obszar.png");

	int nBallPixels = 0;
	for (int i = 0; i < ball.rows; i++) {
		for (int j = 0; j < ball.cols; j++) {
			if (ball.at<Vec3b>(i, j) == Vec3b(255, 255, 255))
				nBallPixels++;
		}
	}

	double avgDist;
	std::ifstream in("MiI-SredniaOdleglosc.txt");
	in >> avgDist;
	in.close();

	double diameterPx = 2 * sqrt((double)nBallPixels / 3.141592);
	double diameterCm = 0.001 * avgDist * diameterPx;

	std::cout << diameterCm << std::endl;

	return 0;
}