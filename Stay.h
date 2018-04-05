#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "Graph.h"
#include "City.h"
#include "Date.h"


//Represents a day spent in a city.

class Stay 
{
private:
	Date date;
	City city;
	float price;
public:
	Stay(Date date,City city,float price);
	float getPrice() const;
	City getCity() const;
	Date getDate() const;
	void setDate(Date date);
	void setCity(City city);
	void setPrice(float price);

	
};
