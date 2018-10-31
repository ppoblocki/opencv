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
	Mat img = imread("pileczka_L.png");
    
	Mat edges = img.clone();
	Canny(img, edges, 150, 450);
	imwrite("MiI-Kontur.png", edges);

	Mat filled = edges.clone();
	cvtColor(edges, filled, CV_GRAY2RGB);
	floodFill(filled, Point(700, 400), CV_RGB(255, 255, 255));
	floodFill(filled, Point(0, 0), CV_RGB(0, 255, 0));
	imwrite("MiI-Obszar.png", filled);

    return 0;
}