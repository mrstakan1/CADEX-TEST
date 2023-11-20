#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <memory>
#include <string>
#include <queue>

#include "Point3D.h"
#include "Vector3D.h"

class Curve3D
{
public:
	virtual Point3D GetPoint(double t) const = 0;
	virtual Vector3D GetDerivative(double t) const = 0;
	virtual ~Curve3D() {}
	virtual bool IsValid() const = 0;
};