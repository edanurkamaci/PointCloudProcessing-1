#include "Point.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "Transform.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudRecorder.h"
#include <iostream>

int main()
{
	DepthCamera DC1, DC2;
	PointCloud PC1, PC2, PC3;
	RadiusOutlierFilter ROF;
	PassThroughFilter PTF1,PTF2;
	PointCloudRecorder PCRDN1,PCRDN2, PCRDR1, PCRDR2,PCRDTF1,PCRDTF2, PCRDL1,PCRDL2;
	Transform T1, T2;

	DC1.setFileName("camera1.txt");
	DC2.setFileName("camera2.txt");

	PC1 = DC1.capture();
	PC2 = DC2.capture();
	
	PCRDN1.setfileName("OUTPUT-N1");
	PCRDN1.save(PC1);
	PCRDN2.setfileName("OUTPUT-N2");
	PCRDN2.save(PC2);

	ROF.setRadius(25);
	ROF.filter(PC1);
	ROF.filter(PC2);
	
	PCRDR1.setfileName("OUTPUT-R1");
	PCRDR1.save(PC1);

	PCRDR2.setfileName("OUTPUT-R2");
	PCRDR2.save(PC2);
	
	//FOR CAMERA1
	PTF1.setLowerLimitX(0);
	PTF1.setUpperLimitX(400);
	PTF1.setLowerLimitY(0);
	PTF1.setUpperLimitY(400);
	PTF1.setLowerLimitZ(-45);
	PTF1.setUpperLimitZ(45);
	PTF1.filter(PC1);

	PCRDTF1.setfileName("OUTPUT-TF1");
	PCRDTF1.save(PC1);

	T1.setTrans(100, 500, 50);
	T1.setAngles(0, 0, -90);
	T1.setRotation(T1.getAngles());
	T1.setTranslation(T1.getTrans());

	PC1=T1.doTransform(PC1);

	PCRDL1.setfileName("OUTPUT-L1");
	PCRDL1.save(PC1);

	//FOR CAMERA2
	PTF2.setLowerLimitX(0);
	PTF2.setUpperLimitX(500);
	PTF2.setLowerLimitY(0);
	PTF2.setUpperLimitY(500);
	PTF2.setLowerLimitZ(-45);
	PTF2.setUpperLimitZ(45);
	PTF2.filter(PC2);

	PCRDTF2.setfileName("OUTPUT-TF2");
	PCRDTF2.save(PC2);

	T2.setTrans(550, 150, 50);
	T2.setAngles(0, 0, 90);
	T2.setRotation(T2.getAngles());
	T2.setTranslation(T2.getTrans());
	
	PC2 = T2.doTransform(PC2);

	PCRDL2.setfileName("OUTPUT-L2");
	PCRDL2.save(PC2);

	Point *P1 = new Point[PC1.getPointNumb()];
	Point *P2 = new Point[PC1.getPointNumb()];

	P1 = PC1.getPoints();
	P2 = PC2.getPoints();

	//P1+P2 ------> GIVES ME ERROR ---- I COULD NOT FIGURE IT OUT
	

	cout << endl << endl;
	system("pause");
	return 0;
}

