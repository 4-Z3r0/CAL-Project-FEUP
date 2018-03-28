#include "Trip.h"

Trip::Trip(int price, float timeOfTravel)
{
	this->price = price;
	this->timeOfTravel = timeOfTravel;
}

int Trip::getPrice() const
{
	return price;
}

float Trip::getTimeOfTravel() const
{
	return timeOfTravel;
}
