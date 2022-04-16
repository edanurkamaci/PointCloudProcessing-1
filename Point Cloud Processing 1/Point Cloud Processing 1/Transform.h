#pragma once
#include "PointCloud.h"

class Transform
{
private:
	double *angles=new double[3];
	double *trans=new double[3];
	double **transMatrix=new double*[4];
	double **rotationMatrix= new double*[3];
	int count;
public:
	Transform();
	~Transform();
	
	void setAngles(double, double, double);
	void setTrans(double, double, double);
	double *getAngles();
	double *getTrans();
	void setRotation(double ang[]);
	void setTranslation(double tr[]);
	Point doTransform(Point p);
	Point* doTransform(Point* lp);
	PointCloud doTransform(PointCloud pc);
};
