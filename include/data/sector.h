#ifndef SECTOR_H
#define SECTOR_H

#include "data/object.h"
#include "data/planet.h"

#include <vector>
#include <memory>

#include <json/json.h>

class Sector
{
public:
	Sector(const Json::Value& data);

	int numPlanets() const { return mPlanets.size(); }
	Planet* planet(size_t id) const { return mPlanets[id].get(); }
	Planet* planetSortedByYPos(size_t i) const { return mPlanets[mPlanetIdsSortedByYPos[i]].get(); }

private:
	std::vector<std::unique_ptr<Planet>> mPlanets;
	std::vector<int> mPlanetIdsSortedByYPos;

public:
	void print(FILE* out = stdout) const;
};

#endif // SECTOR_H
