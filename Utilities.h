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




template<class T>
void printVec(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}
