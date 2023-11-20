#pragma once

#include "Curve3D.h"

class Helix : public Curve3D
{
public:
	Helix(double radius, double step);
	Point3D GetPoint(double t) const override;
	Vector3D GetDerivative(double t) const override;
	bool IsValid() const override;

private:
	double _radius;
	double _step;
};