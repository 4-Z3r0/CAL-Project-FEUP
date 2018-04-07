#pragma once
#include <set>
#include <vector>
#include <list>
#include <limits>
#include <cmath>
#include "MutablePriorityQueue.h"
#include "City.h"
#include "Trip.h"
#include <ostream>
#include <iostream>
#include "BT.h"


using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()


/************************* Vertex  **************************/



template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // outgoing edges
	bool visited = false;          // auxiliary field
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool processing = false;
	bool tree = false;
	void addEdge(Vertex<T> *dest, Trip w);

public:
	Vertex(T in);
	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
	friend ostream& operator<< <>(ostream& out, Graph<T>& graph);


};


template <class T>
Vertex<T>::Vertex(T in) : info(in) {}

/*
* Auxiliary function to add an outgoing edge to a vertex (this),
* with a given destination vertex (d) and edge weight (w).
*/
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, Trip w) {
	adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	Trip weight;         // edge weight
public:
	Edge(Vertex<T> *d, Trip w);
	friend class Graph<T>;
	friend class Vertex<T>;
	friend ostream& operator<< <>(ostream& out, Graph<T>& graph);


};

template <class T>
Edge<T>::Edge(Vertex<T> *d, Trip w) : dest(d), weight(w) {}





template<class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, Trip w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	// Fp05 - single source
	void showShortestPath(T &origin, T &dest);
	Vertex<T> * initSingleSource(const T &origin);
	bool relax(Vertex<T> *v, Vertex<T> *w, Trip weight);
	void dijkstraShortestPath(const T &s);
	void dijkstraShortestPathOld(const T &s);
	void unweightedShortestPath(const T &s);
	void bellmanFordShortestPath(const T &s);
	vector<T> getPath(const T &origin, const T &dest) const;

	T findClosestNotTree(const T &source, set<T> &cities);
	BTCustom<T> makeMinTree(T &source, set<T> cities);
	vector<T> travellingSalesman(BTCustom<T> tree);


	friend ostream& operator<< <>(ostream& out, Graph<T>& graph);


	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;

};

template<class T>
int Graph<T>::getNumVertex() const
{
	return vertexSet.size();
}


template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
* Auxiliary function to find a vertex with a given content.
*/
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
*  Adds a vertex with a given content or info (in) to a graph (this).
*  Returns true if successful, and false if a vertex with that content already exists.
*/
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if (findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

/*
* Adds an edge to a graph (this), given the contents of the source and
* destination vertices and the edge weight (w).
* Returns true if successful, and false if the source or destination vertex does not exist.
*/
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, Trip w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2, w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/
template<class T>
inline void Graph<T>::showShortestPath(T & origin, T & dest) 
{
	vector<T> path;
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
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
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
template<class T>
bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, Trip weight) {
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
template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
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

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const {
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
		return res;
	for (; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	// TODO
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
	// TODO
}


/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
	// TODO
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const {
	vector<T> res;
	// TODO
	return res;
}


//returns the closest Vertex to source not included in the BT
//WILL ONLY WORK WITH CITY
template <class T>
T Graph<T>::findClosestNotTree(const T &source , set<T> &cities)
{
	Vertex<T> * v = findVertex(source);
	Vertex<T> * minV = new Vertex<T>(source);
	T minDest("NULLCITY");
	bool flag = false;
	int min = -1;

	for (auto it = v->adj.begin(); it != v->adj.end(); it++)
	{
		if (((min == -1) || (it->weight.getPrice() < min)) && (it->dest->tree == false) &&  cities.end() != cities.find(it->dest->info.getName()))
		{
			minDest = it->dest->info;
			min = it->weight.getPrice();
			minV = it->dest;
			flag = true;
		}
	}
	if(flag)
		minV->tree = true;
	cities.erase(minDest);
	return minDest;
}


//Creates a minimum spanning tree
//Based on Prim's algorithm
//Possible alternatives Kruskal's and Boruvka's algorithms
template <class T>
BTCustom<T> Graph<T>::makeMinTree(T &source, set<T> cities)
{
	BTCustom<T> B = BTCustom<T>(source);
	vector<BTNodeCustom<T>* > q;
	BTNodeCustom<T>* node = B.getRoot();
	BTNodeCustom<T>* left;
	BTNodeCustom<T>* right;
	T info("NULL_CITY");
	q.push_back(node);
	while (!cities.empty())
	{
		node = q.at(0);
		q.erase(q.begin());
		
		info = findClosestNotTree((*node).getInfo(), cities);
		left = new BTNodeCustom<T>(info);
		node->setNodeLeft(left);
		q.push_back(left);

		info = findClosestNotTree((*node).getInfo(), cities);
		right = new BTNodeCustom<T>(info);
		node->setNodeRight(right);
		q.push_back(right);
		
	}
	return B;
}

template<class T>
vector<T> Graph<T>::travellingSalesman(BTCustom<T> tree)
{
	vector<T> order = {};
	BTCPre<T> it = BTCPre<T>(tree);
	while (!it.isAtEnd())
	{
		order.push_back(it.retrieve());
		it.advance();
	}
	return order;
}



template<typename T>
ostream& operator<< <>(ostream& out, Graph<T>& graph)
{
	Vertex<T>* v;
	for (int i = 0; i < graph.getNumVertex(); i++)
	{
		v = graph.vertexSet.at(i);
		cout << "VERTEX: " << v->info << endl;
		for (int j = 0; j < v->adj.size(); j++)
		{
			cout << "edge to: " << v->adj.at(j).dest->info.getName() << "     price: " << v->adj.at(j).weight.getPrice() << endl;
		}
		cout << endl << endl;
	}
	return out;
}
