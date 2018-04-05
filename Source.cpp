#include <iostream>
#include <set>
#include "Graph.h"
#include "City.h"
#include "Trip.h"
#include "Utilities.h"
#include "Date.h"
using namespace std;



int main() {

	Graph<City> graph;
	/*
	City porto("Porto");
	City madrid("Madrid");
	City lisboa("Lisboa");
	City barcelona("Barcelona");
	City londres("Londres");
	City frankfurt("Frankfurt");
	City oslo("Oslo");
	City roma("Roma");
	City kiev("Kiev");
	City helsiquia("Helsinquia");
	City monaco("Monaco");

	Trip PortoLisboa(300, 1);
	Trip PortoLondres(600, 3);
	Trip PortoFrankfurt(500, 3);
	Trip LisboaLondres(400, 2);
	Trip LisboaFrankfurt(600, 4);
	Trip BarcelonaFrankfurt(300, 1);
	Trip LondresFrankfurt(400, 1);
	Trip MadridFrankfurt(700, 1);
	Trip MadridRoma(50, 1);
	Trip OsloFrankfurt(100, 0.5);
	Trip OsloHelsinquia(250, 2);
	Trip HelsinquiaFrankfurt(600, 4);
	Trip HelsinquiaKiev(300, 2);
	Trip KievFrankfurt(300, 2);
	Trip RomaFrankfurt(200, 1);

	/*int PortoLisboa = 300;
	int PortoLondres = 600;
	int PortoFrankfurt = 500;
	int LisboaLondres = 400;
	int LisboaFrankfurt = 600;
	int BarcelonaFrankfurt = 300;
	int LondresFrankfurt = 400;
	int MadridFrankfurt = 700;
	int MadridRoma = 50;
	int OsloFrankfurt = 100;
	int OsloHelsinquia = 250;
	int HelsinquiaFrankfurt = 600;
	int HelsinquiaKiev = 300;
	int KievFrankfurt = 300;
	int RomaFrankfurt = 200;

	graph.addVertex(porto);
	graph.addVertex(madrid);
	graph.addVertex(lisboa);
	graph.addVertex(barcelona);
	graph.addVertex(londres);
	graph.addVertex(frankfurt);
	graph.addVertex(oslo);
	graph.addVertex(roma);
	graph.addVertex(kiev);
	graph.addVertex(helsiquia);
	graph.addVertex(monaco);

	graph.addEdge(porto, lisboa, PortoLisboa);
	graph.addEdge(lisboa, porto, PortoLisboa);

	graph.addEdge(porto, londres, PortoLondres);
	graph.addEdge(londres, porto, PortoLondres);

	graph.addEdge(porto, frankfurt, PortoFrankfurt);
	graph.addEdge(frankfurt, porto, PortoFrankfurt);

	graph.addEdge(londres, lisboa, LisboaLondres);
	graph.addEdge(lisboa, londres, LisboaLondres);

	graph.addEdge(frankfurt, lisboa, LisboaFrankfurt);
	graph.addEdge(lisboa, frankfurt, LisboaFrankfurt);

	graph.addEdge(barcelona, frankfurt, BarcelonaFrankfurt);
	graph.addEdge(frankfurt, barcelona, BarcelonaFrankfurt);

	graph.addEdge(londres, frankfurt, LondresFrankfurt);
	graph.addEdge(frankfurt, lisboa, LondresFrankfurt);

	graph.addEdge(madrid, frankfurt, MadridFrankfurt);
	graph.addEdge(frankfurt, madrid, MadridFrankfurt);

	graph.addEdge(madrid, roma, MadridRoma);
	graph.addEdge(roma, madrid, MadridRoma);

	graph.addEdge(oslo, frankfurt, OsloFrankfurt);
	graph.addEdge(frankfurt, oslo, OsloFrankfurt);

	graph.addEdge(oslo, helsiquia, OsloHelsinquia);
	graph.addEdge(helsiquia, oslo, OsloHelsinquia);

	graph.addEdge(helsiquia, frankfurt, HelsinquiaFrankfurt);
	graph.addEdge(frankfurt, helsiquia, HelsinquiaFrankfurt);

	graph.addEdge(helsiquia, kiev, HelsinquiaKiev);
	graph.addEdge(kiev, helsiquia, HelsinquiaKiev);

	graph.addEdge(kiev, frankfurt, KievFrankfurt);
	graph.addEdge(frankfurt, kiev, KievFrankfurt);

	graph.addEdge(roma, frankfurt, RomaFrankfurt);
	graph.addEdge(frankfurt, roma, RomaFrankfurt);


	
	graph.showShortestPath(helsiquia, frankfurt);
	graph.showShortestPath(madrid, frankfurt);
	graph.showShortestPath(porto, frankfurt);
	graph.showShortestPath(porto, madrid);
	graph.showShortestPath(lisboa, helsiquia);

	*/;


	//Test Travelling Salesman with Chars
	/*
	set<char> cities = {'B', 'D', 'G', 'F'};
	vector<char> result;
	graph = makeCompleteGraph<char>(7);
	cout << graph << endl << endl << endl << endl;
	result = graph.travellingSalesman(graph.makeMinTree('A', cities));
	printVec<char>(result);
	*/

	//Testing travelling Salesman with City
	City porto("Porto");
	City madrid("Madrid");
	City lisboa("Lisboa");
	City barcelona("Barcelona");
	City londres("Londres");
	vector<City> cities;
	cities.push_back(porto);
	cities.push_back(madrid);
	cities.push_back(lisboa);
	cities.push_back(barcelona);
	cities.push_back(londres);
	graph = makeCGraphFromVertices(cities);
	cout << graph << endl << endl << endl << endl;
	set<City> setCities = { madrid, lisboa, barcelona, londres };
	cities = graph.travellingSalesman(graph.makeMinTree(porto, setCities));
	printVec<City>(cities);



	/*
	City frankfurt("Frankfurt");
	City oslo("Oslo");
	City roma("Roma");
	City kiev("Kiev");
	City helsiquia("Helsinquia");
	City monaco("Monaco");
	*/


}