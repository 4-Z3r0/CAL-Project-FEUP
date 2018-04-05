#include "Stay.h"

City Stay::getCity() const {
	return city;
}

Date Stay::getDate() const {
	return date;
}

float Stay::getPrice() const {
	return price;
}

void Stay::setCity(City city) {
	this->city = city;
}

void Stay::setDate(Date date) {
	this->date = date;
}

void Stay::setPrice(float price) {
	this->price = price;
}
