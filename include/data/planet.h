#ifndef _DATA_PLANET_H
#define _DATA_PLANET_H

#include "data/mineral.h"
#include "util/point.h"

#include <json/json.h>
#include <string>

class Planet
{
public:
	Planet(const Json::Value& planetData);

	std::string name() { return mName; }
	int owner() { return mOwner; }
	Point pos() { return mPos; }

	int mines() { return mMines; }
	int factories() { return mFactories; }
	int defense() { return mDefense; }

	Mineral neut() { return mNeut; }
	Mineral dur() { return mDur; }
	Mineral tri() { return mTri; }
	Mineral moly() { return mMoly; }

	int supplies() { return mSupplies; }
	int MCs() { return mMCs; }

private:
	std::string mName;
	int mOwner;
	Point mPos;

	// Structures
	int mMines, mFactories, mDefense;

	// Resources
	Mineral mNeut, mDur, mTri, mMoly;
	int mSupplies, mMCs;

	// Natives
	
public:
	std::string sprint() const;
	void print(FILE* out = stdout) const;
};

#endif // _DATA_PLANET_H
