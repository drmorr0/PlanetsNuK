
#include "data/planet.h"
#include "data/ship.h"
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
	vector<Planet*> planets;
	vector<Ship*> ships;

	for (auto p : root["planets"])
		planets.push_back(new Planet(p));
	for (auto s : root["ships"])
		ships.push_back(new Ship(s));

	Gtk::Main kit(argc, argv);

	VizWindow window(planets, ships);
	Gtk::Main::run(window);

	return 0;
}



