#include "PointCloud.h"
#include "Point.h"

class RadiusOutlierFilter 
{
private:
	double radius;
public:
	
	RadiusOutlierFilter();
	~RadiusOutlierFilter();
	void setRadius(double);
	double getRadius() const;
	void filter(PointCloud& PC);
};