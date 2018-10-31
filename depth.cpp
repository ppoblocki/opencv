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

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread("MiI-MapaRozbieznosci-Skalibrowana.png");

	Mat depth = 4800.0 / img;
	imwrite("MiI-MapaG³êbokoœci.png", depth);

	return 0;
}