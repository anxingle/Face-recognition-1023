#ifndef FACERETRIEVE_VIDEO_H
#define FACERETRIEVE_VIDEO_H

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <mmsystem.h>
#include <direct.h>
using namespace std;

 typedef struct{
       int top;
	   int bottom;
	   int left;
	   int right;
}Coord;  //车牌检测识别结果保存

#ifdef __cplusplus
extern "C"
{
#endif

bool InitializeRecognizer();
bool Load_Template(IplImage *roiimg, Coord *face_coord, CvMat *Template_feature);
bool Face_detection(IplImage *roiimg, float detect_ratio, Coord *face_coord, IplImage *cropface);
bool Recognize(CvMat ** Suspect_feature, int Suspect_ImageNumber, IplImage *cropface, float *distance);
void CloseRecognizer();
	
#ifdef __cplusplus
}
#endif

#endif