#include "Transform.h"
#include <math.h>
#include<iostream>
using namespace std;

Transform::Transform()
{
	count = 0;
	angles[3] = { 0 };
	trans[3] = {0};

	for (int i = 0; i < 4; i++)
		transMatrix[i] = new double[4];
	for (int i = 0; i < 3; i++)
		rotationMatrix[i] = new double[3];

}
Transform::~Transform()
{
	
}
void Transform::setAngles(double ang1, double ang2, double ang3)
{
	angles[0] = ang1;
	angles[1] = ang2;
	angles[2] = ang3;
}

void Transform::setTrans(double transX, double transY, double transZ)
{
	trans[0] = transX;
	trans[1] = transY;
	trans[2] = transZ;
}
double *Transform::getAngles()
{
	return angles;
}
double *Transform::getTrans()
{
	return trans;
}
void Transform::setRotation(double ang[])
{
	rotationMatrix[0][0] = cos(ang[2])*cos(ang[1]);
	rotationMatrix[0][1] = (cos(ang[2])*sin(ang[1])*sin(ang[0])) - (sin(ang[2])*cos(ang[0]));
	rotationMatrix[0][2] = (cos(ang[2])*sin(ang[1])*cos(ang[0])) + (sin(ang[2])*sin(ang[0]));
	rotationMatrix[1][0] = sin(ang[2])*cos(ang[1]);
	rotationMatrix[1][1] = (sin(ang[2])*sin(ang[1])*sin(ang[0])) + (cos(ang[2])*cos(ang[0]));
	rotationMatrix[1][2] = (sin(ang[2])*sin(ang[1])*cos(ang[0])) - (cos(ang[2])*sin(ang[0]));
	rotationMatrix[2][0] = -sin(ang[1]);
	rotationMatrix[2][1] = cos(ang[1])*sin(ang[0]);
	rotationMatrix[2][2] = cos(ang[1])*cos(ang[0]);

}
void Transform::setTranslation(double tr[])
{
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix[x][y] = rotationMatrix[x][y];
		}
	}
	this->transMatrix[3][0] = 0;
	this->transMatrix[3][1] = 0;
	this->transMatrix[3][2] = 0;
	this->transMatrix[3][3] = 1;
	this->transMatrix[0][3] = tr[0];
	this->transMatrix[1][3] = tr[1];
	this->transMatrix[2][3] = tr[2];
}
Point Transform::doTransform(Point p)
{
	Point Transpoint;
	double sum = 0;
	double result[4][1], point[4][1];
	point[0][0] = p.getX();
	point[1][0] = p.getY();
	point[2][0] = p.getZ();
	point[3][0] = 1;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 4; k++) {
				sum += (transMatrix[i][k] * point[k][j]);
			}
			result[i][j] = sum;
			sum = 0;
		}
	}

	Transpoint.setX(result[0][0]);
	Transpoint.setY(result[1][0]);
	Transpoint.setZ(result[2][0]);

	return Transpoint;
}
Point* Transform::doTransform(Point* lp)
{
	Point* transformedList=new Point[5000];

	while(1)
	{
		if ((lp[count].getX() < 1000 && lp[count].getX() > -1000) && (lp[count].getY() < 1000 && lp[count].getY() > -1000) && (lp[count].getZ() < 1000 && lp[count].getZ() > -1000))
			transformedList[count] = doTransform(lp[count]);
		else
			break;
		count++;
	}
	Point* TransformedL = new Point[count];
	
	for (int i = 0; i < count; i++)
	{
		TransformedL[i] = transformedList[i];
	}
	delete []transformedList;

	return TransformedL;
}

PointCloud Transform::doTransform(PointCloud pc)
{
	PointCloud Transpointcloud;
	Point *P= new Point[pc.getPointNumb()];
	P = pc.getPoints();
	Transpointcloud.setPoints(doTransform(P));
	Transpointcloud.setPointNumb(count);

	return Transpointcloud;
}