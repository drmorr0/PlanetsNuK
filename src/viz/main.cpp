
#include "data/sector.h"
#include "data/planet.h"
#include "data/ship.h"
#include "algo/dbscan.h"
#include "viz/window.h"

#include <json/json.h>

#include <fstream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <turnfile>\n", argv[0]);
		return -1;
	}

	ifstream turnfile(argv[1]);
	
	Json::Value root;
	turnfile >> root;

	Sector sector(root);
	sector.print();

	/*for (auto s : root["ships"])
		ships.push_back(new Ship(s));*/

/*	size_t minPts = 3;
	vector<vector<Planet*>> clusters = dbscan(planets, 1, 81, minPts);
	for (auto cluster : clusters)
	{
		printf("[ ");
		for (auto p : cluster) 
			printf("%d ", p->id() + 1);
		printf("]\n");
	}

	Gtk::Main kit(argc, argv);

	VizWindow window(planets, ships);
	Gtk::Main::run(window);*/

	return 0;
}



