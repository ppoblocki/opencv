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
	Mat dist = imread("MiI-MapaG³êbokoœci.png");
	Mat ball = imread("MiI-Obszar.png");

	double avgDist = 0;
	int nDist = 0;

	for (int i = 0; i < ball.rows; i++) {
		for (int j = 0; j < ball.cols; j++) {
			Vec3b ballPx = ball.at<Vec3b>(i, j);
			uchar distPx = dist.at<uchar>(i, j);

			// Skip pixels not in ball.
			if (ballPx != Vec3b(255, 255, 255))
				continue;
			
			avgDist += distPx;
			nDist++;
		}
	}

	avgDist /= nDist;

	std::ofstream out("MiI-SredniaOdleglosc.txt");
	out << avgDist;
	out.close();

	return 0;
}