#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include <fstream>
#include <iostream>
#include <string>
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "Transform.h"
using namespace std;
DepthCamera::DepthCamera()
{
	fileName = "";
}
DepthCamera::~DepthCamera()
{

}
void DepthCamera::setFileName(const string& fileName)
{
	this->fileName = fileName;
}
string DepthCamera::getFileName() const 
{
	return fileName;
}
PointCloud DepthCamera::capture() {
	ifstream inFile;
	int count = 0;
	double data;
	Point *Points = new Point;
	PointCloud PC;
	inFile.open(this->getFileName(), ios::in);
	if (!inFile)
	{
		cout << "Dosya Acilmadi.";
	}
	else
	{
		Point p;
		while (inFile)
		{
			inFile >> data;
			inFile >> data;
			inFile >> data;
			count++;
		}
		inFile.close();
		inFile.open(this->getFileName(), ios::in);

		Points = new Point[count];
		count = 0;
		while (inFile)
		{
			inFile >> data;
			p.setX(data);
			inFile >> data;
			p.setY(data);
			inFile >> data;
			p.setZ(data);
			Points[count] = p;
			count++;
		}
		inFile.close();
		PC.setPointNumb(count);
		PC.setPoints(Points);
	}
	return PC;
}
