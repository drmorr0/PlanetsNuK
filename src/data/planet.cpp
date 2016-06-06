// planet.cpp: David R. Morrison, 2016

#include "data/planet.h"

using namespace std;

Planet::Planet(const Json::Value& planetData)
{
	mName = planetData["name"].asString();
	mId = planetData["id"].asInt() - 1; 	// IDs start at 1 in the turn data
	mOwner = planetData["ownerid"].asInt();

	mPos = Point{planetData["x"].asInt(), planetData["y"].asInt()};

	mMines = planetData["mines"].asInt();
	mFactories = planetData["factories"].asInt();
	mDefense = planetData["defense"].asInt();

	mNeut = Mineral{planetData["neutronium"].asInt(),
					planetData["groundneutronium"].asInt(),
					planetData["densityneutronium"].asInt()};
	mDur = Mineral{planetData["duranium"].asInt(),
				   planetData["groundduranium"].asInt(),
				   planetData["densityduranium"].asInt()};
	mTri = Mineral{planetData["tritanium"].asInt(),
				   planetData["groundtritanium"].asInt(),
				   planetData["densitytritanium"].asInt()};
	mMoly = Mineral{planetData["molybdenum"].asInt(),
				    planetData["groundmolybdenum"].asInt(),
				    planetData["densitymolybdenum"].asInt()};
}

string Planet::sprint() const
{
	char out[1024];
	sprintf(out, "#%d %s (Owner: %d)\n------------\n\n"
	             "x: %d, y: %d\n\n"
				 "M: %d, F: %d, D: %d\n\n"
				 "neut: %d/%d (%d%%)\n"
				 "dur: %d/%d (%d%%)\n"
				 "tri: %d/%d (%d%%)\n"
				 "moly: %d/%d (%d%%)\n\n"
				 "supplies: %d, MCs: %d\n\n",
			(mId + 1), mName.c_str(), mOwner, mPos.x, mPos.y, mMines, mFactories, mDefense,
			mNeut.surface, mNeut.ground, mNeut.density,
			mDur.surface, mDur.ground, mDur.density,
			mTri.surface, mTri.ground, mTri.density,
			mMoly.surface, mMoly.ground, mMoly.density,
		mSupplies, mMCs);
	return string(out);
}

void Planet::print(FILE* out) const
{
	fprintf(out, "%s", sprint().c_str());
}
