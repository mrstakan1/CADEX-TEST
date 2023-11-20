#include "Circle.h"

Circle::Circle(double radius) : _radius(radius) {}

Point3D Circle::GetPoint(double t) const
{
    double x = _radius * cos(t);
    double y = _radius * sin(t);
    double z = 0.0;

    return Point3D(x, y, z);
}

Vector3D Circle::GetDerivative(double t) const
{
    double dx = -_radius * sin(t);
    double dy = _radius * cos(t);
    double dz = 0.0;

    return Vector3D(dx, dy, dz);
}

bool Circle::IsValid() const
{
    return _radius > 0.0;
}

double Circle::GetRadius()
{
    return _radius;
}