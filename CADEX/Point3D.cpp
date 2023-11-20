#include "Point3D.h"

Point3D::Point3D(double x, double y, double z) : _x(x), _y(y), _z(z){}

double Point3D::GetX() {
	return _x;
}

double Point3D::GetY() {
	return _y;
}

double Point3D::GetZ() {
	return _z;
}