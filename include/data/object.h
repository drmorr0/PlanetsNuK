#ifndef _DATA_OBJECT_H
#define _DATA_OBJECT_H

#include "util/point.h"
#include <string>

class Object 
{
public:
	Object() : mId(-1), mOwner(-1), mPos{0, 0} { }

	std::string name() const { return mName; }
	int id() const { return mId; }
	int owner() const { return mOwner; }
	Point pos() const { return mPos; }

protected:
	std::string mName;
	int mId, mOwner;
	Point mPos;
};

#endif // _DATA_OBJECT_H
