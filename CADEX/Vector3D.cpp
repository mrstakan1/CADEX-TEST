#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

double Vector3D::GetX() {
	return _x;
}

double Vector3D::GetY() {
	return _y;
}

double Vector3D::GetZ() {
	return _z;
}