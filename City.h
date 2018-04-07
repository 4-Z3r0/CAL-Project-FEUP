#pragma once
#include <string>
#include "Stay.h"
using namespace std;

class City {
private:
	vector<Stay> stays;
	string name;
public:
	City(string name);
	City();
	string getName() const;
	vector<Stay> getStays() const;
	void addStay(Stay stay);
	friend bool operator==(City& c1, const City& c2);
	friend ostream& operator<<(ostream& out, City& c);
	friend bool operator<(const City& c1, const City& c2);
};
