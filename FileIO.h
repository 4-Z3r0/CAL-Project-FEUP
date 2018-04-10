#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Graph.h"
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


Graph<City> getGraph1FromFile(vector<City> &cities)
{
	Graph<City> g;
	ifstream g1;
	pair<int, string> p;
	Vertex<City>* v;
	string s;
	int size;
	City temp;

	g1.open("Graph1.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!")
				break;
			temp = City(s);
			g.addVertex(temp);
			cities.push_back(temp);
		}
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

Graph<City> getGraph2FromFile(vector<City> &cities)
{
	Graph<City> g;
	ifstream g1;
	int price;
	vector<int> pricesVec;
	Vertex<City>* v;
	string s;
	int size;
	City temp;

	g1.open("Graph2.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!")
				break;
			temp = City(s);
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
		while (s != "<Stays>"  && getline(g1, s))
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
		unsigned int i = 0;
		getline(g1, s);
		while (s != "<Close>"  && getline(g1, s))
		{
			if (s != "!")
			{
				cities.at(i).addStay(Stay(s));
			}
			else
			{
				i++;
			}
		}
		g1.close();
	}
	else {
		cout << "ERRO\n";
	}
	return g;
}