#pragma once

#include "Curve3D.h"

class Circle : public Curve3D
{
public:
	Circle(double radius);
	Point3D GetPoint(double t) const override;
	Vector3D GetDerivative(double t) const override;
	bool IsValid() const override;
	double GetRadius();
private:
	double _radius;
};