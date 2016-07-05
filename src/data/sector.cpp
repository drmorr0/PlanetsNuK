// sector.cpp: David R. Morrison, 2016

#include "data/sector.h"

using namespace std;

Sector::Sector(const Json::Value& data)
{
	for (auto p : data["planets"])
	{
		mPlanets.push_back(unique_ptr<Planet>(new Planet(p)));
		if (mPlanets.back()->id()+1 != mPlanets.size())
			{ fprintf(stderr, "JSON not in sorted order!\n"); exit(-1); }
	}


	mPlanetIdsSortedByYPos.resize(mPlanets.size());
	mPlanetIdsSortedByYPos[0] = 0;
	for (size_t i = 1; i < mPlanets.size(); ++i)
	{
		int y = mPlanets[i]->pos().y;
		size_t j = i - 1;
		while (j < mPlanets.size() && planetSortedByYPos(j)->pos().y > y)
		{
			mPlanetIdsSortedByYPos[j+1] = mPlanetIdsSortedByYPos[j];
			--j;
		}
		mPlanetIdsSortedByYPos[j+1] = mPlanets[i]->id();
	}
}

void Sector::print(FILE* out) const
{
	for (auto id : mPlanetIdsSortedByYPos)
		fprintf(out, "%s: (%d, %d)\n", mPlanets[id]->name().c_str(), mPlanets[id]->pos().x, mPlanets[id]->pos().y);
}
