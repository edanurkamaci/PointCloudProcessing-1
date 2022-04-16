#include "PointCloud.h"

PointCloud::PointCloud()
{
	pointNumber=0;
	Point* points = new Point;
}
PointCloud::~PointCloud()
{
}
void PointCloud::setPoints(Point* p) 
{
	this->points = new Point[this->pointNumber];
	this->points = p;
}
void PointCloud::setPointNumb(const int &a)
{
	pointNumber = a;
}
Point* PointCloud::getPoints() const
{
	return this->points;
}
int PointCloud::getPointNumb () const
{
	return this->pointNumber;
}
PointCloud PointCloud::operator+(Point*PC) 
{
	Point* p1, *p2, *tmp = {0};
	PointCloud C;
	int count = 0;
	p1 = this->getPoints();
	p2 = PC;
	int j = 0;
	
	while (1)
	{
		if ((PC[count].getX() < 5000 && PC[count].getX() > -5000) && (PC[count].getY() < 5000 && PC[count].getY() > -5000) && (PC[count].getZ() < 5000 && PC[count].getZ() > -5000))
			count++;
		else
			break;
	}

	for (int i = 0; i < this->getPointNumb() + count; i++) {
		if (i < this->getPointNumb())
		{
			tmp[i]=p1[i];
		}
		else
		{
			tmp[i] = p2[i - this->getPointNumb()];
		}
	}
	C.setPointNumb(this->getPointNumb() + count);
	C.setPoints(tmp);
	return C;
}
PointCloud PointCloud::operator=(PointCloud *PC)
{

	for (int i = 0; i < this->getPointNumb(); i++)
		PC->points[i] = this->points[i];
	return *PC;
}