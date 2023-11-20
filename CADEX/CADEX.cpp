#include "Ellipse.h"
#include "Circle.h"
#include "Helix.h"

#define PI 3.141592
#define CircleType 0
#define EllipseType 1
#define HelixType 2

void ShowCurveName(int typeOfCurve) {
	std::cout << "Type of curve: ";

	switch (typeOfCurve)
	{
	case CircleType:
		std::cout << "Circle\n";
		break;
	case EllipseType:
		std::cout << "Ellipse\n";
		break;
	case HelixType:
		std::cout << "Helix\n";
		break;
	default:
		break;
	}
}

int main() {
	int amountOfCurves = 5;
	double factor = 4;
	double sumOfRadii = 0;

	std::vector<std::unique_ptr<Curve3D>> curves;
	std::list<Circle*> circles;
	std::queue<int> curveIDs;

	for (int i = 0; i < amountOfCurves; i++)
	{
		int typeOfCurve = rand() % 3;

		if (typeOfCurve == CircleType) {
			double radius = (rand() % 20) + 1;

			curves.push_back(std::make_unique<Circle>(radius));
		}
		else if (typeOfCurve == EllipseType) {
			double majorRadius = (rand() % 20) + 1;
			double minorRadius = (rand() % 20) + 1;

			curves.push_back(std::make_unique<Ellipse>(majorRadius, minorRadius));
		}
		else if (typeOfCurve == HelixType) {
			double radius = (rand() % 10) + 1;
			double step = (rand() % 20) + 1;

			curves.push_back(std::make_unique<Helix>(radius, step));
		}

		curveIDs.push(typeOfCurve);
	}

	std::cout << "Coordinates of point and derivatives at PI/" << factor << ":\n\n";

	for (const auto& curve : curves) {
		if (curve->IsValid() == false) continue;

		double t = PI / factor;
		Point3D point = curve->GetPoint(t);
		Vector3D derivative = curve->GetDerivative(t);
		
		ShowCurveName(curveIDs.front());
		std::cout << "Point: (" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")\n"
			<< "Derivative: (" << derivative.GetX() << ", " << derivative.GetY() << ", " << derivative.GetZ() << ")\n\n";

		curveIDs.pop();
	}

	for (const auto& curve : curves) {
		if (dynamic_cast<Circle*>(curve.get()) != nullptr){
			circles.push_back(static_cast<Circle*>(curve.get()));
		}
	}

	circles.sort([](Circle* firstCircle, Circle* secondCircle) {
		return firstCircle->GetRadius() < secondCircle->GetRadius();
	});

	for (const auto& circle : circles) {
		sumOfRadii += circle->GetRadius();
	}

	std::cout << "Sum of radii of circles equals: " << sumOfRadii << "\n";

	return 0;
}