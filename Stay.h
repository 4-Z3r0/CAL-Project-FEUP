#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Vertex.h"
#include"Edge.h"



//Represents a day spent in a city.
//Has an vector of Flights if the customer wishes to leave the city in this day.
//If the customer whiches to stay in the city one more day the is an EdgeStay for the next day (Stay).
//This class is considered an invisible Vertex since it will not be shown. 

class Stay : public Vertex
{
private:
	Edge nextStay;
};
