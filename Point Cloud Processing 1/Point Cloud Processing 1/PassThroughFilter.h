#pragma once
#include"PointCloud.h"
#include"DepthCamera.h"

class PassThroughFilter
{
private:
	double upperLimitX;/*!< X noktasi icin en yuksek limit */
	double lowerLimitX;/*!< X noktasi icin en dusuk limit */
	double upperLimitY;/*!< Y noktasi icin en yuksek limit */
	double lowerLimitY;/*!< Y noktasi icin en dusuk limit */
	double upperLimitZ;/*!< Z noktasi icin en yuksek limit */
	double lowerLimitZ;/*!< Z noktasi icin en dusuk limit */
public:
	PassThroughFilter();
	~PassThroughFilter();
	void setUpperLimitX(double upperLimitX);
	double getUpperLimitX(); 
	void setLowerLimitX(double LowerLimitX);
	double getLowerLimitX();
	void setUpperLimitY(double upperLimitY);
	double getUpperLimitY();
	void setLowerLimitY(double LowerLimitY);
	double getLowerLimitY();
	void setUpperLimitZ(double upperLimitZ);
	double getUpperLimitZ();
	void setLowerLimitZ(double LowerLimitZ);
	double getLowerLimitZ();
	void filter(PointCloud& pc);
};