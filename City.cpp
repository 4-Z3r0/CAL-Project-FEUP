#include "City.h"



City::City()
{
	this->name = "NULL_CITY";
}

City::City(string name) {
	this->name = name;
}

string City::getName() const {
	return name;
}

vector<Stay> City::getStays() const
{
	return stays;
}

void City::addStay(Stay stay)
{
	stays.push_back(stay);
}

bool operator==(City & c1, const City & c2) {
	return c1.getName() == c2.getName();
}

ostream& operator<<(ostream& out, City& c)
{
	out << c.getName() << endl;
	return out;
}

bool operator<(const City& c1, const City& c2)
{
	return c1.getName() < c2.getName();
}


