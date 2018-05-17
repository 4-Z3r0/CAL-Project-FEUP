#pragma once
#include <string>
#include "Stay.h"
#include "InterestPoint.h"

class City {
private:
	std::vector<Stay> stays;
	std::string name;
	std::pair<int,int> coordinates;
	std::vector<InterestPoint> interestPoints;
	int index;
public:
	City();
	City(std::string name);
	City(std::string name, std::pair<int,int> coordinates, int index);
	std::string getName() const;
	int getIndex()  const;
	std::vector<Stay> getStays() const;
	std::pair<int, int> getCoordinates();
	void addStay(Stay stay);
	void addInterestPoint(InterestPoint intpoint);
	std::vector<InterestPoint> getInterestPoints();
	friend bool operator==(City& c1, const City& c2);
	friend std::ostream& operator<<(std::ostream& out, City& c);
	friend bool operator<(const City& c1, const City& c2);
};
