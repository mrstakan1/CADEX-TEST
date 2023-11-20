#include "Helix.h"

Helix::Helix(double radius, double step) : _radius(radius), _step(step) {}

Point3D Helix::GetPoint(double t) const
{
	double x = _radius * cos(t);
	double y = _radius * sin(t);
	double z = _step * t;
	return Point3D(x, y, z);
}

Vector3D Helix::GetDerivative(double t) const
{
	double dx = -_radius * sin(t);
	double dy = _radius * cos(t);
	double dz = _step;
	return Vector3D(dx, dy, dz);
}

bool Helix::IsValid() const
{
	return _step > 0 && _radius > 0;
}