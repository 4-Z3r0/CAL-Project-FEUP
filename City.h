#pragma once
#include <string>

using namespace std;

class City {
private:
	string name;
public:
	City(string name);
	string getName() const;
	friend bool operator==(City& c1, const City& c2);
};
