#include "FileIO.h"
#include "Utilities.h"
#include <string>
using namespace std;


void UI()
{

}

int checkBoundaries(int linf, int lsup) {
	int nr;

	cin >> nr;

	while (cin.fail() || nr > lsup || nr < linf) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}

	return nr;
}

void graph1Menu(Graph<City> &graph, vector<City> &cities) {
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
		switch (choice) {
		case 1:
			cout << endl;
			cin.ignore(1000, '\n');
			alpha = getOrigin(graph, cities);
			beta = getArrival(graph, cities);
			graph.showShortestPath(alpha,beta);
			break;

		case 2:
			cout << endl << endl;
			break;



		}
	}
}

void graph2Menu(Graph<City> &graph, vector<City> &cities) {
	int choice = 0;
	
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
			cout << endl;
			cin.ignore(1000, '\n');
			start = getOrigin(graph, cities);
			setCities = getSet(graph, cities);
			printVec(graph.travellingSalesman(graph.makeMinTree(start, setCities)));
			break;

		case 2:
			cout << endl << endl;
			cout << endl;
			cin.ignore(1000, '\n');
			start = getOrigin(graph, cities);
			setCities = getSet(graph, cities);
			citiesInOrder = graph.travellingSalesman(graph.makeMinTree(start, setCities));
			printVec(citiesInOrder);
			startDate = getStartDate();
			endDate = getEndDate();
			getCheapestStays(citiesInOrder, startDate, endDate);
			break;

		case 3:
			cout << endl << endl;
			break;


		}
	}
}

void mainMenu(Graph<City> &graph, vector<City> &cities) {
	int choice = 0;

	while (choice != 3) {
		cout << "____________________________________________________" << endl;
		cout << "|                  MAIN MENU                       |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Graph with Scaling Flights                |" << endl;
		cout << "|     2) Complete Graph                            |" << endl;
		cout << "|     3) Exit                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 3);


		switch (choice) {
		case 1:
			graph = getGraph1FromFile(cities);
			graph1Menu(graph, cities);
			break;

		case 2:
			graph = getGraph2FromFile(cities);
			graph2Menu(graph, cities);
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
    vector<City> cities;
	mainMenu(graph,cities);

	
	/*set<City> setCities = { findCity(cities,"Madrid"),findCity(cities,"Lisboa"),findCity(cities,"Londres"),findCity(cities,"Barcelona") };
	//vector<City> c2 = graph.travellingSalesman(graph.makeMinTree(findCity(cities, "Porto"), setCities));
	cout << graph << endl;
	printVec<City>(cities);
	vector<City> c2 = { findCity(cities,"Madrid"),findCity(cities,"Lisboa"),findCity(cities,"Londres"),findCity(cities,"Barcelona") };
	getCheapestStays(c2, Date(2018, 4, 8), Date(2018, 4, 15));*/
	
	

}
