#pragma once
#include <string>

using namespace std;

class City {
private:

	string name;
public:
	City(string name);
	City();
	string getName() const;
	friend bool operator==(City& c1, const City& c2);
	friend ostream& operator<<(ostream& out, City& c);
	friend bool operator<(const City& c1, const City& c2);
};
