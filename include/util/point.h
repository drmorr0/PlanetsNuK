#ifndef _UTIL_POINT_H
#define _UTIL_POINT_H

#include <cmath>

struct Point
{
	int x, y;
};

inline double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

#endif // _UTIL_POINT_H
