#include <iostream>
#include <set>
#include "Graph.h"
#include "City.h"
#include "Trip.h"
#include "Utilities.h"
#include "FileIO.h"
#include "Date.h"
#include "Stay.h"
using namespace std;


void UI()
{

}



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
	Stay p1(Date(2018, 04, 6), "Porto", 12);
	Stay p2(Date(2018, 04, 7), "Porto", 9);
	Stay p3(Date(2018, 04, 8), "Porto", 4);
	Stay p4(Date(2018, 04, 9), "Porto", 5);
	Stay p5(Date(2018, 04, 10), "Porto", 23);
	Stay p6(Date(2018, 04, 11), "Porto", 15);
	Stay p7(Date(2018, 04, 12), "Porto", 53);
	Stay p8(Date(2018, 04, 13), "Porto", 34);
	Stay p9(Date(2018, 04, 14), "Porto", 16);
	Stay p10(Date(2018, 04, 15), "Porto", 22);
	Stay p11(Date(2018, 04, 16), "Porto", 32);
	porto.addStay(p1);
	porto.addStay(p2);
	porto.addStay(p3);
	porto.addStay(p4);
	porto.addStay(p5);
	porto.addStay(p6);
	porto.addStay(p7);
	porto.addStay(p8);
	porto.addStay(p9);
	porto.addStay(p10);
	porto.addStay(p11);
	City madrid("Madrid");
	Stay m1(Date(2018, 04, 6), "Madrid", 32);
	Stay m2(Date(2018, 04, 7), "Madrid", 24);
	Stay m3(Date(2018, 04, 8), "Madrid", 14);
	Stay m4(Date(2018, 04, 9), "Madrid", 25);
	Stay m5(Date(2018, 04, 10), "Madrid", 23);
	Stay m6(Date(2018, 04, 11), "Madrid", 15);
	Stay m7(Date(2018, 04, 12), "Madrid", 12);
	Stay m8(Date(2018, 04, 13), "Madrid", 31);
	Stay m9(Date(2018, 04, 14), "Madrid", 16);
	Stay m10(Date(2018, 04, 15), "Madrid", 42);
	Stay m11(Date(2018, 04, 16), "Madrid", 14);
	madrid.addStay(m1);
	madrid.addStay(m2);
	madrid.addStay(m3);
	madrid.addStay(m4);
	madrid.addStay(m5);
	madrid.addStay(m6);
	madrid.addStay(m7);
	madrid.addStay(m8);
	madrid.addStay(m9);
	madrid.addStay(m10);
	madrid.addStay(m11);
	City lisboa("Lisboa");
	Stay l1(Date(2018, 04, 6), "Lisboa", 23);
	Stay l2(Date(2018, 04, 7), "Lisboa", 12);
	Stay l3(Date(2018, 04, 8), "Lisboa", 23);
	Stay l4(Date(2018, 04, 9), "Lisboa", 15);
	Stay l5(Date(2018, 04, 10), "Lisboa", 13);
	Stay l6(Date(2018, 04, 11), "Lisboa", 24);
	Stay l7(Date(2018, 04, 12), "Lisboa", 25);
	Stay l8(Date(2018, 04, 13), "Lisboa", 54);
	Stay l9(Date(2018, 04, 14), "Lisboa", 16);
	Stay l10(Date(2018, 04, 15), "Lisboa", 20);
	Stay l11(Date(2018, 04, 16), "Lisboa", 15);
	lisboa.addStay(l1);
	lisboa.addStay(l2);
	lisboa.addStay(l3);
	lisboa.addStay(l4);
	lisboa.addStay(l5);
	lisboa.addStay(l6);
	lisboa.addStay(l7);
	lisboa.addStay(l8);
	lisboa.addStay(l9);
	lisboa.addStay(l10);
	lisboa.addStay(l11);
	City barcelona("Barcelona");
	Stay b1(Date(2018, 04, 6), "Barcelona", 22);
	Stay b2(Date(2018, 04, 7), "Barcelona", 19);
	Stay b3(Date(2018, 04, 8), "Barcelona", 24);
	Stay b4(Date(2018, 04, 9), "Barcelona", 15);
	Stay b5(Date(2018, 04, 10), "Barcelona", 13);
	Stay b6(Date(2018, 04, 11), "Barcelona", 15);
	Stay b7(Date(2018, 04, 12), "Barcelona", 23);
	Stay b8(Date(2018, 04, 13), "Barcelona", 14);
	Stay b9(Date(2018, 04, 14), "Barcelona", 26);
	Stay b10(Date(2018, 04, 15), "Barcelona", 32);
	Stay b11(Date(2018, 04, 16), "Barcelona", 8);
	barcelona.addStay(b1);
	barcelona.addStay(b2);
	barcelona.addStay(b3);
	barcelona.addStay(b4);
	barcelona.addStay(b5);
	barcelona.addStay(b6);
	barcelona.addStay(b7);
	barcelona.addStay(b8);
	barcelona.addStay(b9);
	barcelona.addStay(b10);
	barcelona.addStay(b11);
	City londres("Londres");
	Stay lo1(Date(2018, 04, 6), "Londres", 12);
	Stay lo2(Date(2018, 04, 7), "Londres", 9);
	Stay lo3(Date(2018, 04, 8), "Londres", 4);
	Stay lo4(Date(2018, 04, 9), "Londres", 5);
	Stay lo5(Date(2018, 04, 10), "Londres", 23);
	Stay lo6(Date(2018, 04, 11), "Londres", 15);
	Stay lo7(Date(2018, 04, 12), "Londres", 53);
	Stay lo8(Date(2018, 04, 13), "Londres", 34);
	Stay lo9(Date(2018, 04, 14), "Londres", 16);
	Stay lo10(Date(2018, 04, 15), "Londres", 22);
	Stay lo11(Date(2018, 04, 16), "Londres", 32);
	londres.addStay(lo1);
	londres.addStay(lo2);
	londres.addStay(lo3);
	londres.addStay(lo4);
	londres.addStay(lo5);
	londres.addStay(lo6);
	londres.addStay(lo7);
	londres.addStay(lo8);
	londres.addStay(lo9);
	londres.addStay(lo10);
	londres.addStay(lo11);
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
	if (cities.at(1).getStays().size() == 0) {
		cout << "SadPepe" << endl;
	}
	//getCheapestStays(cities, Date(2018, 04, 8), Date(2018, 04, 15));
	printVec<City>(cities);
	
	


	/*
	City frankfurt("Frankfurt");
	City oslo("Oslo");
	City roma("Roma");
	City kiev("Kiev");
	City helsiquia("Helsinquia");
	City monaco("Monaco");
	*/

	//Testing Graph constructor from file
	//graph = getGraph1FromFile();
	//cout << graph << endl;

}