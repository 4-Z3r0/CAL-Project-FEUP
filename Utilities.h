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
		cout << "ERROR!\n";
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
void printStaysRoute(vector<Stay> stays,Stay firstValidStay) {
	bool firstStay = false;
	for (unsigned int i = 0; i < stays.size() - 1; i++) {
		if (stays.at(i).getCity() != firstValidStay.getCity()) {
			if (!firstStay) {
				cout << "Leave " << stays.at(i -1).getCity() << " on " << stays.at(i-1).getDate() << endl;
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
						graph.addEdge(stays.at(j), cities.at(i + 1).getStays().at(j + 1), stays.at(j).getPrice());
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
	printStaysRoute(stays,firstValidStay);

}

template<class T>
void printVec(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}


