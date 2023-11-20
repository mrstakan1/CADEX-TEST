#pragma once

#include "Curve3D.h"

class Ellipse : public Curve3D
{
public:
	Ellipse(double majorRadius, double minorRadius);
	Point3D GetPoint(double t) const override;
	Vector3D GetDerivative(double t) const override;
	bool IsValid() const override;

private:
	double _majorRadius;
	double _minorRadius;
};