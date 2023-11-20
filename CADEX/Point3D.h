#pragma once

class Point3D
{
public:
	Point3D(double x, double y, double z);
	double GetX();
	double GetY();
	double GetZ();
private:
	double _x;
	double _y;
	double _z;
};