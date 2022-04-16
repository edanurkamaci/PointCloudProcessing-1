#include "PointCloudRecorder.h"
#include "PointCloud.h"

PointCloudRecorder::PointCloudRecorder() 
{
	fileName = "";
}
PointCloudRecorder::~PointCloudRecorder() 
{
	
}
void PointCloudRecorder::setfileName(string fileName)
{
	this->fileName = fileName;
}
string PointCloudRecorder::getfileName() 
{
	return this->fileName;
}
bool PointCloudRecorder::save(const PointCloud &PC) 
{
	int size = PC.getPointNumb(),count=0;
	ofstream outFile;
	Point* P = new Point[size];
	P = PC.getPoints();
	outFile.open(fileName + ".txt", ios::out | ios::app);

	if (outFile) 
	{
		cout << "The file was opened. " << endl;
		for (int i=0 ; i < size ; i++ )
		{
			if (!(P[i].getX() == 0 && P[i].getY() == 0 && P[i].getZ() == 0))
			{
				outFile << P[i].getX() << " " << P[i].getY() << " " << P[i].getZ() << endl;
				count++;
			}
		}
		cout << count<<endl;
		return 1;
	}
	else {
		cout << "Error opening file. " << endl;
		return 0;
	}
	outFile.close();
}