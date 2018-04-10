#include "Stay.h"

string Stay::getCity() const {
	return cityName;
}

Date Stay::getDate() const {
	return date;
}

Stay::Stay(Date date, string cityName, float price)
{
	this->date = date;
	this->cityName = cityName;
	this->price = price;
}
Stay::Stay(string s) {
	istringstream stayStream(s);
	char aux;
	int year, month, day;
	stayStream >> year >> aux >> month >> aux >> day >> aux >> this->cityName >> aux >> this->price;
	this->date = Date(year, month, day);
}

double Stay::getPrice() const {
	return price;
}

void Stay::setCity(string cityName) {
	this->cityName = cityName;
}

void Stay::setDate(Date date) {
	this->date = date;
}

void Stay::setPrice(double price) {
	this->price = price;
}

bool operator==(Stay & c1, const Stay & c2)
{
	return (c1.cityName == c2.cityName && c1.date == c2.date && c1.price == c2.price);
}

bool operator<(const Stay & c1, const Stay & c2)
{
	return c1.date < c2.date;
}
