#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "Date.h"


//Represents a day spent in a city.

class Stay 
{
private:



	Date date;
	string cityName;
	double price;
public:
	Stay() {};
	Stay(Date date,string cityName,float price);
	double getPrice() const;
	string getCity() const;
	Date getDate() const;
	void setDate(Date date);
	void setCity(string cityName);
	void setPrice(double price);
	friend bool operator==(Stay& c1, const Stay& c2);
	friend ostream& operator<<(ostream& out, Stay& c);
	friend bool operator<(const Stay& c1, const Stay& c2);

	
};
