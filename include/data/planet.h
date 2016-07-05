#ifndef _DATA_PLANET_H
#define _DATA_PLANET_H

#include "data/object.h"
#include "data/mineral.h"
#include "util/point.h"

#include <json/json.h>

class Planet : public Object
{
public:
	Planet(const Json::Value& planetData);

	int mines() const { return mMines; }
	int factories() const { return mFactories; }
	int defense() const { return mDefense; }

	Mineral neut() const { return mNeut; }
	Mineral dur() const { return mDur; }
	Mineral tri() const { return mTri; }
	Mineral moly() const { return mMoly; }

	int supplies() const { return mSupplies; }
	int MCs() const { return mMCs; }

private:

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
