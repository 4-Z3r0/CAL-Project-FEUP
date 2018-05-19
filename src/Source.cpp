
#include "FileIO.h"
#include "Utilities.h"
#include <string>
#include "SSearch.h"
using namespace std;



void UI()
{

}

void map(vector<City> m) {
	GraphViewer *j = new GraphViewer(3000, 3000, false);

	int counter = 0;
	j->setBackground("euriope.png");
	j->defineVertexIcon("airicon.png");
	j->createWindow(1900, 1425);
	j->defineEdgeCurved(false);
	j->defineEdgeColor("RED");

	for (int i = 0; i < m.size(); i++) {
		j->addNode(i, m[i].getCoordinates().first, m[i].getCoordinates().second);
		j->setVertexLabel(i, m[i].getName());
	}

	counter = 0;

	for (int i = 0; i <= m.size() - 2; i++) {
		Sleep(2000);
		j->addEdge(i, i, i + 1, 0);
		j->rearrange();


	}

	j->rearrange();

	Sleep(10000);
	j->closeWindow();


	delete(j);
}

void PrintGraph(Graph<City> &oi, vector<City> m = vector<City>()) {
	vector<Edge<City>> ma;
	vector<Vertex<City> *> k = oi.getVertexSet();
	GraphViewer *j = new GraphViewer(1900, 1425, false);
	j->setBackground("euriope.png");
	j->createWindow(1900, 1425);
	j->defineEdgeCurved(false);
	int counter = 0;
	int counteedges = 0;

	for (int i = 0; i < oi.getNumVertex(); i++) {
		j->addNode(k[i]->getInfo().getIndex(), k[i]->getInfo().getCoordinates().first, k[i]->getInfo().getCoordinates().second);
		j->setVertexLabel(k[i]->getInfo().getIndex(), k[i]->getInfo().getName());
		j->setVertexIcon(k[i]->getInfo().getIndex(), "airicon.png");

	}

	for (int i = 0; i < oi.getNumVertex(); i++) {
		ma = k[i]->getAdj();
		for (int l = 0; l < ma.size(); l++, counteedges++) {
			j->addEdge(counteedges, k[i]->getInfo().getIndex(), ma[l].getVertex()->getInfo().getIndex(), 0);
			j->rearrange();
		}
	}

	j->rearrange();

	if (m.size() != 0) {
		for (int i = oi.getNumVertex(); i <= m.size() + oi.getNumVertex() - 1; i++) {
			j->addNode(i, m[i - oi.getNumVertex()].getCoordinates().first, m[i - oi.getNumVertex()].getCoordinates().second);
			j->setVertexLabel(i, m[i - oi.getNumVertex()].getName());
			j->setVertexIcon(i, "airicon.png");
		}

		counter = 0;

		for (int i = oi.getNumVertex(); counter < m.size() - 1; i++, counteedges++, counter++) {
			Sleep(2000);
			j->addEdge(counteedges, i, i + 1, 0);
			j->setEdgeColor(counteedges, "GREEN");
			j->rearrange();

		}
	}
	j->rearrange();

	Sleep(10000);
	j->closeWindow();

	delete(j);

}

int checkBoundaries(int linf, int lsup) {
	int nr;

	cin >> nr;

	while (cin.fail() || nr > lsup || nr < linf) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}

	return nr;
}

void graph1Menu(Graph<City> graph, vector<City> cities) {
	int choice = 0;

	while (choice != 2) {
		cout << "____________________________________________________" << endl;
		cout << "|             FLIGHTS WITH SCALING                 |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Make a Trip                               |" << endl;
		cout << "|     2) Back to Main Menu                         |" << endl;
		cout << "|    Option: ";
		choice = checkBoundaries(1, 2);
		City alpha;
		City beta;
		vector<City> l;
		switch (choice) {
		case 1:
			cout << endl;
			cin.ignore(1000, '\n');
			alpha = getOrigin(graph, cities);
			beta = getArrival(graph, cities);
			l = graph.showShortestPath(alpha, beta);
			PrintGraph(graph, l);

			break;

		case 2:
			cout << endl << endl;
			break;



		}
	}
}

void graph2Menu(Graph<City> graph, vector<City> cities) {
	int choice = 0;
	Graph <City> orginal = graph;
	vector<City> orginalCity = cities;
	while (choice != 3) {
		cout << "____________________________________________________" << endl;
		cout << "|               COMPLETE GRAPH                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Get the Cheapeast AirRoute                |" << endl;
		cout << "|     2) Cheapest Trip between dates               |" << endl;
		cout << "|     3) Go Back to Main Menu                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 3);

		City start;
		set<City> setCities;
		vector<City> citiesInOrder;
		Date startDate;
		Date endDate;
		switch (choice) {
		case 1:

			graph = orginal;
			cities = orginalCity;
			cout << endl;
			cin.ignore(1000, '\n');
			start = getOrigin(graph, cities);
			setCities = getSet(graph, cities);
			citiesInOrder = graph.travellingSalesman(graph.makeMinTree(start, setCities));
			filterCities(citiesInOrder);
			printVec(citiesInOrder);
			PrintGraph(graph, citiesInOrder);
			//map(citiesInOrder);
			return;

		case 2:
			graph = orginal;
			cities = orginalCity;
			cout << endl << endl;
			cout << endl;
			cin.ignore(1000, '\n');
			start = getOrigin(graph, cities);
			setCities = getSet(graph, cities);
			citiesInOrder = graph.travellingSalesman(graph.makeMinTree(start, setCities));
			filterCities(citiesInOrder);
			printVec(citiesInOrder);
			startDate = getStartDate();
			endDate = getEndDate();
			getCheapestStays(citiesInOrder, startDate, endDate);
			PrintGraph(graph, citiesInOrder);
			return;

		case 3:
			cout << endl << endl;
			break;


		}
	}
}

void mainMenu2(Graph<City> graph, vector<City> cities) {
	int choice = 0;

	while (choice != 3) {
		cout << "____________________________________________________" << endl;
		cout << "|                  MAIN MENU 2                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Graph with Scaling Flights                |" << endl;
		cout << "|     2) Complete Graph                            |" << endl;
		cout << "|     3) Back                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 3);


		switch (choice) {
		case 1:
			graph = getGraph1FromFile(cities);
			loadGraph1PointsOfInterest(cities);
			graph1Menu(graph, cities);
			break;

		case 2:
			graph = getGraph2FromFile(cities);
			loadGraph2PointsOfInterest(cities);
			graph2Menu(graph, cities);
			break;
		case 3:
			cout << endl;
			break;
		}
	}
}

void searchMenu(Graph<City> graph, vector<City> cities) {
	int choice = 0;

	while (choice != 3) {
		cout << "____________________________________________________" << endl;
		cout << "|                  SEARCH MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Exact Search                              |" << endl;
		cout << "|     2) Approximate Search                        |" << endl;
		cout << "|     3) Back                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 3);
		City start;
		set<City> setCities;
		vector<City> citiesInOrder;
		vector<string> poi;
		vector<pair<string, string>> aproxVec;

		switch (choice) {
		case 1:

			break;

		case 2:
			start = readFirstCity(cities);
			do
			{
				poi = readInputPoi();
				setCities = POIfromFile(poi, cities, aproxVec);
				if (!aproxVec.empty())
				{
					cout << "Some of the points of interest you gave us were not recognized here are some sugestions: \n";
					printPair(aproxVec);
					setCities.clear();
					poi.clear();
				}
			} while (!aproxVec.empty());
			citiesInOrder = graph.travellingSalesman(graph.makeMinTree(start, setCities));
			filterCities(citiesInOrder);
			printVec(citiesInOrder);
			for (auto it = citiesInOrder.begin(); it != citiesInOrder.end(); it++)
			{
				cout << it->getName() << endl;
			}
			//PrintGraph(graph, citiesInOrder);
			break;
		case 3:
			cout << endl;
			break;
		}
	}
}

void mainMenu(Graph<City> graph, vector<City> cities) {
	int choice = 0;

	while (choice != 3) {
		cout << "____________________________________________________" << endl;
		cout << "|                  MAIN MENU                       |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Search Flights by City                    |" << endl;
		cout << "|     2) Search Flights by Points of Interest      |" << endl;
		cout << "|     3) Exit                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 3);


		switch (choice) {
		case 1:
			mainMenu2(graph, cities);
			break;

		case 2:
			graph = getGraph2FromFile(cities);
			loadGraph2PointsOfInterest(cities);
			searchMenu(graph, cities);
			break;
		case 3:
			cout << endl;
			cout << "See you next time!\n";
			break;
		}
	}
}




int main() {

	Graph<City> graph;
	vector<int> pref;
	vector<City> cities;
	getGraph2FromFile(cities);
	/*
	vector<pair<string, string>> aproxVec;
	string a;
	vector<string> poi = { "Palacio da Bola", "Torre dos Clerigo", "Ponte D.Luis", "Torre de Bele", "Panteao Nacional","Big Ben", "Palacio Espanhol" , "Parlame", "Catedral" };
	set<City> res;
	/*string t = "aabababaabaabababababababaaaaaaaaaabbbabab";
	string p = "aaba";
	cout << kmpMatcher(t, p) << endl;

	res = POIfromFile(poi, cities, aproxVec);
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << it->getName() << endl;
	}
	printPair(aproxVec);
	system("pause");
	*/
	mainMenu(graph, cities);


	/*set<City> setCities = { findCity(cities,"Madrid"),findCity(cities,"Lisboa"),findCity(cities,"Londres"),findCity(cities,"Barcelona") };
	//vector<City> c2 = graph.travellingSalesman(graph.makeMinTree(findCity(cities, "Porto"), setCities));
	cout << graph << endl;
	printVec<City>(cities);
	vector<City> c2 = { findCity(cities,"Madrid"),findCity(cities,"Lisboa"),findCity(cities,"Londres"),findCity(cities,"Barcelona") };
	getCheapestStays(c2, Date(2018, 4, 8), Date(2018, 4, 15));*/



}
