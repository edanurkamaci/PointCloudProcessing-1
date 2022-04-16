#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include "Point.h"
#include <iostream>
using namespace std;

class PointCloud
{
private:
	Point* points;
	int pointNumber;
public:
	PointCloud();
	void setPoints(Point*);
	void setPointNumb(const int &);
	Point* getPoints() const;
	int getPointNumb() const;
	PointCloud operator+(Point*);
	PointCloud operator=(PointCloud*);
	~PointCloud();

};
#endif // !POINTCLOUD_H
