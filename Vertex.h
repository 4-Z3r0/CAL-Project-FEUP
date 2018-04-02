#include "Edge.h"
#include "Stay.h"
#include "Graph.h"

class Vertex {
	City info;                // contents
	vector<Edge> adj;  // outgoing edges
	vector<Stay *> l;
	bool visited;          // auxiliary field
	double dist = 0;
	Vertex *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool processing = false;
	void addEdge(Vertex *dest, Trip w);

public:
	Vertex(City in);
	bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
	City getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};




