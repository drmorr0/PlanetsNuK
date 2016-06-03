// planet.cpp: David R. Morrison, 2016

#include "data/planet.h"

using namespace std;

Planet::Planet(const Json::Value& planetData)
{
	mName = planetData["name"].asString();

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

void Planet::print(FILE* out) const
{
	fprintf(out, "%s\n------------\n\n", mName.c_str());
	fprintf(out, "M: %d, F: %d, D: %d\n\n", mMines, mFactories, mDefense);
	fprintf(out, "neut: %d/%d (%d %%)\n", mNeut.surface, mNeut.ground, mNeut.density);
	fprintf(out, "dur: %d/%d (%d %%)\n", mDur.surface, mDur.ground, mDur.density);
	fprintf(out, "tri: %d/%d (%d %%)\n", mTri.surface, mTri.ground, mTri.density);
	fprintf(out, "moly: %d/%d (%d %%)\n\n", mMoly.surface, mMoly.ground, mMoly.density);
	fprintf(out, "supplies: %d, MCs: %d\n\n", mSupplies, mMCs);
}
