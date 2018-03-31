#include "Vertex.h"

//--------- Vertex -----

Vertex::Vertex(City in) : info(in) {}

/*
* Auxiliary function to add an outgoing edge to a vertex (this),
* with a given destination vertex (d) and edge weight (w).
*/

void Vertex::addEdge(Vertex *d, Trip w) {
	adj.push_back(Edge(d, w));
}


bool Vertex::operator<(Vertex & vertex) const {
	return this->dist < vertex.dist;
}


City Vertex::getInfo() const {
	return this->info;
}


double Vertex::getDist() const {
	return this->dist;
}


Vertex *Vertex::getPath() const {
	return this->path;
}

