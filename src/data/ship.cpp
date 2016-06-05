// ship.cpp: David R. Morrison, 2016

#include "data/ship.h"

using namespace std;

Ship::Ship(const Json::Value& shipData)
{
	mName = shipData["name"].asString();

	mPos = Point{shipData["x"].asInt(), shipData["y"].asInt()};
	mDest = Point{shipData["targetx"].asInt(), shipData["targety"].asInt()};
}

void Ship::print(FILE* out) const
{
	fprintf(out, "%s\n------------\n\n", mName.c_str());
	fprintf(out, "Trajectory: (%d, %d) -> (%d, %d)\n", mPos.x, mPos.y, mDest.x, mDest.y);
}
