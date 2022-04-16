#ifndef DEPTHCAMERA_H
#define DEPTHCAMERA_H
#include "PointCloud.h"

class DepthCamera:public PointCloud
{
private:
	string fileName;
public:
	DepthCamera();
	~DepthCamera();
	void setFileName(const string&);
	string getFileName()const;
	PointCloud capture();
};
#endif // !DEPTHCAMERA_H
