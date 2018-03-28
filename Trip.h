#pragma once
#include <string>

using namespace std;

class Trip {
private:
	int price;
	float timeOfTravel;
public:
	Trip(int price, float timeOfTravel);
	int getPrice() const;
	float getTimeOfTravel() const;
};