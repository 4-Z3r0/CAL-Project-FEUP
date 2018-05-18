#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "graphviewer.h"
#include "Graph.h"
#include "Utilities.h"
//This file will be used to implement read/write functions to file.

using namespace std;

pair<int, string> StringSeparator(string s)
{
	string temp;
	int i;
	pair<int, string> p;
	stringstream ss(s);

	ss >> temp;
	p.second = temp;

	ss >> temp;

	ss >> temp;
	i = stoi(temp);
	p.first = i;

	return p;

}
pair<int, int> coordinates(string s)
{
	string temp;
	int i;
	pair<int, int> p;
	stringstream ss(s);

	ss >> temp;
	p.first = stoi(temp);

	ss >> temp;

	ss >> temp;
	p.second = stoi(temp);

	return p;

}
void addMultipleVertices(Graph<City> &g, Vertex<City>* v, vector<int> &prices)
{
	int count = 1;
	int sizeV = g.getNumVertex();
	while (prices.size() != 0)
	{
		g.addEdge(v->getInfo(), g.getVertexSet().at(sizeV - count)->getInfo(), prices.back());
		g.addEdge(g.getVertexSet().at(sizeV - count)->getInfo(), v->getInfo(), prices.back());
		prices.pop_back();
		count++;
	}
}
void loadGraph1PointsOfInterest(vector<City> &cities) {
	ifstream g1;
	string s;
	int idx = 0;
	InterestPoint temp;
	g1.open("InterestPoints1.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!") {
				idx++;
			}
			temp = InterestPoint(s);
			cities.at(idx).addInterestPoint(temp);
			
		}
		g1.close();

	}

}

Graph<City> getGraph1FromFile(vector<City> &cities)
{
	cities.clear();
	Graph<City> g;
	ifstream g1;
	pair<int, string> p;
	Vertex<City>* v;

	string s, c, name;
	int size, counter = 0;
	City temp;

	g1.open("Graph1.txt");

	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!")
				break;

			name = s.substr(0,s.find_first_of(';'));
			c = s.substr(s.find_first_of(';')+1);
			temp = City(name, coordinates(c), counter);
			counter++;


			g.addVertex(temp);
			cities.push_back(temp);

		}
		counter = 0;
		while (s != "<Close>" && getline(g1, s))
		{
			p = StringSeparator(s);
			v = g.findVertex(City(p.second));
			size = p.first;

			for (int i = 0; i < size; i++)
			{
				getline(g1, s);
				p = StringSeparator(s);

				g.addEdge(v->getInfo(), City(p.second), p.first);

			}
			getline(g1, s);
		}
		g1.close();
	}
	else {
		cout << "ERRO\n";
	}
	return g;
}
void loadGraph2PointsOfInterest(vector<City> &cities) {
	ifstream g1;
	string s;
	int idx = 0;
	InterestPoint temp;
	g1.open("InterestPoints2.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!") {
				idx++;
			}
			temp = InterestPoint(s);
			cities.at(idx).addInterestPoint(temp);

		}
		g1.close();

	}
}
Graph<City> getGraph2FromFile(vector<City> &cities)
{
	cities.clear();
	Graph<City> g;
	ifstream g1;
	int price;
	vector<int> pricesVec;
	Vertex<City>* v;
	string s, name, c;
	int size, counter = 0;
	City temp;

	g1.open("Graph2.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!")
				break;
			name = s.substr(0,s.find_first_of(';'));
			c = s.substr(s.find_first_of(';')+1);
			temp = City(name, coordinates(c), counter);
			counter++;

			unsigned int i = 0;
			getline(g1, s);
			while (s != "<Next>"  && getline(g1, s))
			{
				if (s != "!")
				{
					temp.addStay(Stay(s));
				}
			}
			g.addVertex(temp);
			cities.push_back(temp);
		}
		getline(g1, s);
		v = g.findVertex(City(s));
		while (s != "<Close>"  && getline(g1, s))
		{
			if (s != "")
			{
				price = stoi(s);
				pricesVec.push_back(price);
			}
			else
			{
				addMultipleVertices(g, v, pricesVec);
				getline(g1, s);
				v = g.findVertex(City(s));
			}
		}
		g1.close();
	}
	else {
		cout << "ERRO\n";
	}
	return g;
}
