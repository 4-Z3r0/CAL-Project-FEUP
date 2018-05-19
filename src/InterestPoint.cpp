#include "InterestPoint.h"

InterestPoint::InterestPoint(string name) {
	this->name = name;
}

InterestPoint::InterestPoint() {
	this->name = "Monumento";
}

void InterestPoint::setName(string name)
{
	this->name = name;
}
