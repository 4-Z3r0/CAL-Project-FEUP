#pragma once
#include "Graph.h"


/********************** Edge  ****************************/


class Edge {
	Vertex * dest;      // destination vertex
	Trip weight;         // edge weight
public:
	Edge(Vertex *d, Trip w);
	friend class Graph;
	friend class Vertex;
};


Edge::Edge(Vertex *d, Trip w) : dest(d), weight(w) {}
