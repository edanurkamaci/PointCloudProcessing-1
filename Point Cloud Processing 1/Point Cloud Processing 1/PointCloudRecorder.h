#pragma once
#include "PointCloud.h"
#include "Point.h"
#include "DepthCamera.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

class PointCloudRecorder 
{
private:
	string fileName;
public:
	PointCloudRecorder();
	~PointCloudRecorder();

	void setfileName(string fileName);
	string getfileName();
	bool save(const PointCloud &PC);
};