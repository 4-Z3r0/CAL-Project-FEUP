#include "City.h"

//HELLO
City::City(string name) {
	this->name = name;
}

string City::getName() const {
	return name;
}

bool operator==(City & c1, const City & c2) {
	return c1.getName() == c2.getName();
}
