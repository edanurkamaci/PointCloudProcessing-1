#include "RadiusOutlierFilter.h"
RadiusOutlierFilter::RadiusOutlierFilter()
{
	radius = 0;
}
RadiusOutlierFilter::~RadiusOutlierFilter()
{

}
void RadiusOutlierFilter::setRadius(double _radius)
{
	radius = _radius;
}
double RadiusOutlierFilter::getRadius() const
{
	return this->radius;
}
void RadiusOutlierFilter::filter(PointCloud& PC)
{
	Point* str1 = new Point[PC.getPointNumb()];
	Point* str2 = new Point[PC.getPointNumb()];
	int count = 0;
	str1 = PC.getPoints();
	
	int i = 0, j = 0;
	for (int i=0 ; i < PC.getPointNumb() ; i++)
	{
		for (int j = 0; j < PC.getPointNumb(); j++)
		{
			if (str1[i].distance(str1[j]) < getRadius() && !(str1[i] == str1[j]))
			{
				str2[count]=str1[i];
				count++;
				break;
			}
		}
	}
	PC.setPointNumb(count);
	PC.setPoints(str2);
}