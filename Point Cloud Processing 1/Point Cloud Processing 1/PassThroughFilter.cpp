#include"PassThroughFilter.h"
#include<iostream>
#include"PointCloud.h"
#include"DepthCamera.h"
using namespace std;

PassThroughFilter::PassThroughFilter()
{
	upperLimitX = 0;
	lowerLimitX = 0;
	upperLimitY = 0;
	lowerLimitY = 0;
	upperLimitZ = 0;
	lowerLimitZ = 0;
}
PassThroughFilter::~PassThroughFilter()
{
}
void PassThroughFilter::setUpperLimitX(double upperLimitX)
{
	this->upperLimitX = upperLimitX;
}
double PassThroughFilter::getUpperLimitX()
{
	return upperLimitX;
}
void PassThroughFilter::setLowerLimitX(double LowerLimitX)
{
	this->lowerLimitX = LowerLimitX;
}
double PassThroughFilter::getLowerLimitX()
{
	return lowerLimitX;
}
void PassThroughFilter::setUpperLimitY(double upperLimitY)
{
	this->upperLimitY = upperLimitY;
}
double PassThroughFilter::getUpperLimitY()
{
	return upperLimitY;
}
void PassThroughFilter::setLowerLimitY(double LowerLimitY)
{
	this->lowerLimitY = LowerLimitY;
}
double PassThroughFilter::getLowerLimitY()
{
	return lowerLimitY;
}
void PassThroughFilter::setUpperLimitZ(double upperLimitZ)
{
	this->upperLimitZ = upperLimitZ;
}
double PassThroughFilter::getUpperLimitZ()
{
	return upperLimitZ;
}
void PassThroughFilter::setLowerLimitZ(double LowerLimitZ)
{
	this->lowerLimitZ = LowerLimitZ;
}
double PassThroughFilter::getLowerLimitZ()
{
	return lowerLimitZ;
}

void PassThroughFilter::filter(PointCloud& PC) {
	int counter = 0;
	Point* str1 = new Point[PC.getPointNumb()];
    Point* str2 = new Point[PC.getPointNumb()];
	str1 = PC.getPoints();

	for (int i = 0 ; i < PC.getPointNumb() ; i++)
	{

		if ((str1[i].getX() <= getUpperLimitX() && str1[i].getX() >= getLowerLimitX()) && 
			((str1[i].getY() <= getUpperLimitY() && str1[i].getY() >= getLowerLimitY())) &&
			(str1[i].getZ() <= getUpperLimitZ() && str1[i].getZ() >= getLowerLimitZ()))
		{
			str2[i]=str1[i];
			counter++;
		}
	}
	PC.setPoints(str2);
	PC.setPointNumb(counter);
}