#pragma once
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "MutablePriorityQueue.h"
#include "City.h"
#include "Trip.h"
#include "Vertex.h"

using namespace std;

#define INF std::numeric_limits<double>::max()
/*************************** Graph  **************************/


class Graph {
	vector<Vertex *> vertexSet;    // vertex set

public:
	Vertex *findVertex(const City &in) const;
	bool addVertex(const City &in);
	bool addEdge(const City &sourc, const City &dest, Trip w);
	int getNumVertex() const;
	vector<Vertex *> getVertexSet() const;

	// Fp05 - single source
	void showShortestPath(City &origin, City &dest);
	Vertex * initSingleSource(const City &origin);
	bool relax(Vertex *v, Vertex *w, Trip weight);
	void dijkstraShortestPath(const City &s);
	void dijkstraShortestPathOld(const City &s);
	void unweightedShortestPath(const City &s);
	void bellmanFordShortestPath(const City &s);
	vector<City> getPath(const City &origin, const City &dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<City> getfloydWarshallPath(const City &origin, const City &dest) const;

};

