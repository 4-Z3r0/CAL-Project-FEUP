#include "City.h"

//HELLO

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


