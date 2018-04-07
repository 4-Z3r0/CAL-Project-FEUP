#include"Graph.h"
#include<cmath>

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
			graph.addEdge(('A' + i), ('A' + j), Trip((int)pow(r, 2), (float)1));
			graph.addEdge(('A' + j), ('A' + i), Trip((int)pow(r, 2), (float)1));
		}
	}
	return graph;
}


//NOT TESTED
Graph<City> makeCGraphFromVertices(vector<City> vertices)
{
	Graph<City> graph;
	for (auto it = vertices.begin(); it != vertices.end(); it++)
	{
		graph.addVertex(it->getName());
	}
	for (int i = 0; i < vertices.size() - 1; i++)
	{
		for (int j = i + 1; j < vertices.size(); j++)
		{
			int r = rand() % vertices.size() + 1;
			graph.addEdge(vertices.at(i), vertices.at(j), Trip((int)pow(r, 2), (float)1));
			graph.addEdge(vertices.at(j), vertices.at(i), Trip((int)pow(r, 2), (float)1));
		}
	}
	return graph;
}

Graph<City> makeCGraphFromVertices(vector<City> vertices, vector<Trip> trips)
{
	if (pow(vertices.size(), 2) == trips.size()) {

	}
	Graph<City> graph;
	for (auto it = vertices.begin(); it != vertices.end(); it++)
	{
		graph.addVertex(it->getName());
	}
	for (int i = 0; i < vertices.size() - 1; i++)
	{
		for (int j = i + 1; j < vertices.size(); j++)
		{
			int r = rand() % vertices.size() + 1;
			graph.addEdge(vertices.at(i), vertices.at(j), Trip((int)pow(r, 2), (float)1));
			graph.addEdge(vertices.at(j), vertices.at(i), Trip((int)pow(r, 2), (float)1));
		}
	}
	return graph;
}


void getCheapestStays(vector<City> cities, Date start, Date end) {

	Graph<Stay> graph;
	int visitDay = 0;
	//Adding all the Vertex to the graph that can be reached
	for (unsigned int i=0; i < cities.size(); i++) {
		vector<Stay> stays = cities.at(i).getStays();
		unsigned int j = visitDay;
		unsigned int unreachableDays = visitDay;
		for (; j < stays.size(); j++) {
			if ((start < stays.at(j).getDate() || start == stays.at(j).getDate()) && (stays.at(j).getDate() < end || stays.at(j).getDate() == end)) {
				if (unreachableDays < 0) {
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
	//Adding all the Edges between the Vertex's that represent the cost of stay
	for (unsigned int i = 0; i < cities.size(); i++) {
		vector<Stay> stays = cities.at(i).getStays();
		unsigned int j = visitDay;
		unsigned int unreachableDays = visitDay;
		for (; j < stays.size(); j++) {
			if ((start < stays.at(j).getDate() || start == stays.at(j).getDate()) && (stays.at(j).getDate() < end || stays.at(j).getDate() == end)) {
				if (unreachableDays < 0) {
					unreachableDays--;
				}
				else {
					if (i == 0 && j < stays.size() - 1) {
						graph.addEdge(stays.at(i), stays.at(i + 1), Trip(0,1));
					}
					if (i < cities.size() - 1) {
						graph.addEdge(stays.at(i),cities.at(i+1).getStays().at(j+1) , Trip(stays.at(i).getPrice(), 1));
					}
					else {
						graph.addEdge(stays.at(i), EndOfJourney, Trip(0,1));
					}
					
				}

			}

		}
		visitDay++;
	}
	//graph.dijkstraShortestPath(cities.at(0).getStays().at(0));
	//graph.getPath(cities.at(0).getStays().at(0), EndOfJourney);
}

template<class T>
void printVec(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}


