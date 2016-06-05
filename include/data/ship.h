#ifndef _DATA_SHIP_H
#define _DATA_SHIP_H

#include "util/point.h"
#include <json/json.h>
#include <string>

class Ship
{
public:
	Ship(const Json::Value& shipData);

	std::string name() { return mName; }
	Point pos() { return mPos; }
	Point dest() { return mDest; }

private:
	std::string mName;
	Point mPos;
	Point mDest;

public:
	void print(FILE* out = stdout) const;
};

#endif // _DATA_SHIP_H
