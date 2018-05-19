#pragma once
#include"Graph.h"
#include "City.h"
#include "SSearch.h"
#include<fstream>
#include<cmath>
#include<set>

using namespace std;

template<class T>
Graph<T> makeCompleteGraph(int numVertex)
{
	Graph<T> graph;
	for (int i = 0; i < numVertex; i++)
	{
		graph.addVertex('A' + i);
	}
	for (int i = 0; i < numVertex - 1; i++)
	{
		for (int j = i + 1; j < numVertex; j++)
		{
			int r = rand() % numVertex + 1;
			graph.addEdge(('A' + i), ('A' + j), (int)pow(r, 2));
			graph.addEdge(('A' + j), ('A' + i), (int)pow(r, 2));
		}
	}
	return graph;
}


Graph<City> makeCGraphFromVertices(vector<City> vertices)
{
	Graph<City> graph;
	for (auto it = vertices.begin(); it != vertices.end(); it++)
	{
		graph.addVertex(*it);
	}
	for (int i = 0; i < vertices.size() - 1; i++)
	{
		for (int j = i + 1; j < vertices.size(); j++)
		{
			int r = rand() % vertices.size() + 1;
			graph.addEdge(vertices.at(i), vertices.at(j), (int)pow(r, 2));
			graph.addEdge(vertices.at(j), vertices.at(i), (int)pow(r, 2));
		}
	}
	return graph;
}

Graph<City> makeCGraphFromVertices(vector<City> vertices, vector<Trip> trips)
{
	if (pow(vertices.size(), 2) == trips.size()) {
		cout << "ERROR1!\n";
	}
	Graph<City> graph;
	for (auto it = vertices.begin(); it != vertices.end(); it++)
	{
		graph.addVertex(*it);
	}
	for (int i = 0; i < vertices.size() - 1; i++)
	{
		for (int j = i + 1; j < vertices.size(); j++)
		{
			int r = rand() % vertices.size() + 1;
			graph.addEdge(vertices.at(i), vertices.at(j), (int)pow(r, 2));
			graph.addEdge(vertices.at(j), vertices.at(i), (int)pow(r, 2));
		}
	}
	return graph;
}
void printStaysRoute(vector<Stay> stays, Stay firstValidStay) {
	bool firstStay = false;
	for (unsigned int i = 0; i < stays.size() - 1; i++) {
		if (stays.at(i).getCity() != firstValidStay.getCity()) {
			if (!firstStay) {
				cout << "Leave " << stays.at(i - 1).getCity() << " on " << stays.at(i - 1).getDate() << endl;
				firstStay = true;
			}
			cout << "On " << stays.at(i).getDate() << " stay in " << stays.at(i).getCity() << " for the cost of " << stays.at(i).getPrice() << endl;
		}
	}

}

void getCheapestStays(vector<City> cities, Date start, Date end) {

	Graph<Stay> graph;
	int visitDay = 0;
	Stay firstValidStay;
	bool firstValid = false;
	//Adding all the Vertex to the graph that can be reached
	for (unsigned int i = 0; i < cities.size(); i++) {
		vector<Stay> stays = cities.at(i).getStays();
		unsigned int unreachableDays = visitDay;
		for (unsigned int j = 0; j < stays.size(); j++) {
			if ((start < stays.at(j).getDate() || start == stays.at(j).getDate()) && (stays.at(j).getDate() < end || stays.at(j).getDate() == end)) {
				if (!firstValid) {
					firstValidStay = stays.at(j);
					firstValid = true;
				}
				if (unreachableDays > 0) {
					unreachableDays--;
				}
				else {
					graph.addVertex(stays.at(j));
				}

			}

		}
		visitDay++;
	}
	Stay EndOfJourney(end, "EndOfJourney", 0);
	graph.addVertex(EndOfJourney);
	visitDay = 0;
	//Adding all the Edges between the Vertex's that represent the cost of stay
	for (unsigned int i = 0; i < cities.size(); i++) {
		vector<Stay> stays = cities.at(i).getStays();
		unsigned int unreachableDays = visitDay;
		for (unsigned int j = 0; j < stays.size(); j++) {
			if ((start < stays.at(j).getDate() || start == stays.at(j).getDate()) && (stays.at(j).getDate() < end || stays.at(j).getDate() == end)) {
				if (unreachableDays > 0) {
					unreachableDays--;
				}
				else {
					if (i == 0 && j < stays.size() - 1) {
						graph.addEdge(stays.at(j), stays.at(j + 1), 0);
					}
					if (i < cities.size() - 1) {
						graph.addEdge(stays.at(j), cities.at(i + 1).getStays().at(j + 1), cities.at(i + 1).getStays().at(j + 1).getPrice());
					}
					else {
						graph.addEdge(stays.at(j), EndOfJourney, 0);
					}

				}

			}

		}
		visitDay++;
	}
	graph.dijkstraShortestPath(firstValidStay);
	vector<Stay> stays = graph.getPath(firstValidStay, EndOfJourney);
	printStaysRoute(stays, firstValidStay);

}

City findCity(vector<City>  const cities, string name) {
	City city;
	for (unsigned int i = 0; i < cities.size(); i++) {
		if (cities.at(i).getName() == name) {
			return cities.at(i);
		}
	}
	cout << "There is no City with that Name \n";
	return city;

}

void printVec(vector<City> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).getName() != "NULLCITY") {
			cout << " --> " << v.at(i);
		}

	}
}


string checkString(string s1) {
	getline(cin, s1);

	while (cin.fail())
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, s1);
	}
	return s1;
}

City getOrigin(Graph <City> const graph, vector<City> const cities) {
	string cityname;
	cout << "Name of the City you will leave from : " << endl;
	cityname = checkString(cityname);
	City city = findCity(cities, cityname);
	return city;

}


City getArrival(Graph <City> const graph, vector<City> const cities) {
	string cityname;
	cout << "Name of the City you want to travel to: " << endl;
	cityname = checkString(cityname);
	City city = findCity(cities, cityname);
	return city;

}

set<City> getSet(Graph <City> &graph, vector<City> &cities) {
	set<City> citiesToVisit;
	printVec(cities);
	cout << "Which cities do you want to Visit? (0 to stop) \n";
	string answer;
	answer = checkString(answer);
	citiesToVisit.insert(findCity(cities, answer));

	while (answer != "0") {
		cout << "Which cities do you want to Visit? (0 to stop) \n";
		answer = checkString(answer);
		if (answer == "0") {
			return citiesToVisit;
		}
		citiesToVisit.insert(findCity(cities, answer));
	}
	return citiesToVisit;
}
Date getStartDate() {
	string input;
	cout << "Insert the lower limit of the date you wish to travel (yyyy/mm/dd) \n";
	input = checkString(input);
	return Date(input);
}

Date getEndDate() {
	string input;
	cout << "Insert the upper limit of the date you wish to travel (yyyy/mm/dd) \n";
	input = checkString(input);
	return Date(input);
}
void filterCities(vector<City> &cities) {
	for (unsigned int i = 0; i < cities.size(); i++) {
		if (cities.at(i).getName() == "NULLCITY") {
			cities.erase(cities.begin() + i);
		}
	}
}

/* 
*@brief Checks the file for the list of points of interest(poi) given as argument
*@param poi points of interest the user wants to visit
*@param cities Cities available for visit
*@param aproxRes vector where the poi given and the aproximates solutions will be stored in pairs
*@return the set of cities where there were found one or more poi
*/
set<City> POIfromFile(vector<string> poi, vector<City> const &cities, vector<pair<string, string>> &aproxRes)
{
	ifstream g1;
	string s;

	string text = "";
	int min = 4;
	int index = 0;
	set<City> vecRet;
	bool flag = false;

	aproxRes.empty();

	g1.open("InterestPoints2.txt");

	if (g1.is_open())
	{
		for (size_t i = 0; i < poi.size(); i++)
		{
			while (getline(g1, s))
			{
			
				if (EditDistance(poi.at(i), s) < min && EditDistance(poi.at(i), s) != 0 && s != "!")
					aproxRes.push_back(pair<string, string>(poi.at(i), s));
				if (EditDistance(poi.at(i), s) == 0)
					flag = true;

				if (s == "!") {
					if (kmpMatcher(text, poi.at(i)) > 0 && flag)
					{
						if (vecRet.find(cities.at(index)) == vecRet.end())
							vecRet.emplace(cities.at(index));
					}
					text.clear();
					index++;
					flag = false;
				}
				text.append(s);
				text.append(" ");
			}
			g1.clear();
			g1.seekg(0, ios::beg);
			index = 0;
		}
	}
	g1.close();

	return vecRet;
}

/*
*@brief prints de contents of a vector of pairs (first : second)
*@param vecP the vector of pairs whose contents will be printed.
*/
void printPair(vector<pair<string, string>> vecP)
{
	for (size_t i = 0; i < vecP.size(); i++)
	{
		cout << vecP.at(i).first << " : " << vecP.at(i).second << endl;
	}
}

vector<string> readInputPoi() {
	vector<string> poi;
	string answer;
	while (answer != "0") {
		cout << "What other Point of Interest would you like to visit? (0 to stop) \n";
		answer = checkString(answer);
		if (answer != "0")
		{
			poi.push_back(answer);
		}
	
	}
	return poi;

}

City readFirstCity(vector<City> &cities) {
	string answer;
	vector<string> poi;
	vector<pair<string, string>> aproxVec;
	set<City> setCities;

	cout << "What is the first destination you would like to visit? \n";
	cin.ignore(1000, '\n');
	answer = checkString(answer);
	poi.push_back(answer);

	setCities = POIfromFile(poi, cities, aproxVec);

	set<City>::iterator it = setCities.begin();
	return *it;

}