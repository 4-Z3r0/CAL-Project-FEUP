#pragma once
#include <string>
#include "Stay.h"


class City {
private:
	std::vector<Stay> stays;
	std::string name;
public:
	City(std::string name);
	City();
	std::string getName() const;
	std::vector<Stay> getStays() const;
	void addStay(Stay stay);
	friend bool operator==(City& c1, const City& c2);
	friend std::ostream& operator<<(std::ostream& out, City& c);
	friend bool operator<(const City& c1, const City& c2);
};
