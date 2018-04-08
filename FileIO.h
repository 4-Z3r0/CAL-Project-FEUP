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



Graph<City> getGraph1FromFile()
{
	Graph<City> g;
	ifstream g1;
	pair<int, string> p;
	Vertex<City>* v;
	string s;
	int size; 

	g1.open("Graph1.txt");
	if (g1.is_open())
	{
		while (getline(g1, s))
		{
			if (s == "!")
				break;
			g.addVertex(City(s));
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