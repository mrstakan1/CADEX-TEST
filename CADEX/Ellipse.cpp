#include "Ellipse.h"

Ellipse::Ellipse(double majorRadius, double minorRadius) : _majorRadius(majorRadius), _minorRadius(minorRadius) {}

Point3D Ellipse::GetPoint(double t) const
{
    double x = _majorRadius * cos(t);
    double y = _minorRadius * sin(t);
    double z = 0.0;

    return Point3D(x, y, z);
}

Vector3D Ellipse::GetDerivative(double t) const
{
    double dx = -_majorRadius * sin(t);
    double dy = _minorRadius * cos(t);
    double dz = 0.0;

    return Vector3D(dx, dy, dz);
}

bool Ellipse::IsValid() const
{
    return _majorRadius > 0.0 && _minorRadius > 0.0;
}
