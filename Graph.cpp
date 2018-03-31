#include "Graph.h"
#include "Vertex.h"

int Graph::getNumVertex() const {
	return vertexSet.size();
}


vector<Vertex *> Graph::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const City &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

bool Graph::addVertex(const City &in) {
	if (findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex(in));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */

bool Graph::addEdge(const City &sourc, const City &dest, Trip w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;

	v1->addEdge(v2, w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

inline void Graph::showShortestPath(City & origin, City & dest)
{
	vector<City> path;
	dijkstraShortestPath(origin);

	path = getPath(origin, dest);
	for (unsigned int i = 0; i < path.size(); i++) {
		cout << path.at(i).getName() << "--->";
	}
	cout << "Trip Costs: " << findVertex(dest)->getDist() << endl;
}


/**
 * Initializes single-source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */

Vertex * Graph::initSingleSource(const City &origin) {
	for (auto v : vertexSet) {
		v->dist = INF;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}
/**
 * Analyzes an edge in single-source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */

bool Graph::relax(Vertex *v, Vertex *w, Trip weight) {

	if (v->dist + weight.getPrice() < w->dist) {
		w->dist = v->dist + weight.getPrice();
		w->path = v;
		return true;
	}
	else
		return false;
}
/**
 * Dijkstra algorithm.
 */

void Graph::dijkstraShortestPath(const City &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex> q;
	q.insert(s);
	while (!q.empty()) {
		auto v = q.extractMin();
		for (auto e : v->adj) {
			auto oldDist = e.dest->dist;
			if (relax(v, e.dest, e.weight)) {
				if (oldDist == INF)
					q.insert(e.dest);
				else
					q.decreaseKey(e.dest);
			}
		}
	}
}


vector Graph::getPath(const City &origin, const City &dest) const {
	vector<City> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
		return res;
	for (; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}



void Graph::unweightedShortestPath(const City &orig) {
	// TODO
}


void Graph::bellmanFordShortestPath(const City &orig) {
	// TODO
}


/**************** All Pairs Shortest Path  ***************/


void Graph::floydWarshallShortestPath() {
	// TODO
}


vector Graph::getfloydWarshallPath(const City &orig, const City &dest) const {
	vector res;
	// TODO
	return res;
}
