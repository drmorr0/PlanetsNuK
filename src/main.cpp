
#include "data/planet.h"

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
	vector<Planet> planets;

	for (auto p : root["planets"])
		planets.push_back(Planet(p));

	return 0;
}



