#ifndef _ALGO_DBSCAN_H
#define _ALGO_DBSCAN_H

#include <vector>
#include <cstdlib>

class Planet;

std::vector<std::vector<Planet*>> 
	dbscan(const std::vector<Planet*>& planets, int owner, int eps, size_t minPts);

#endif // _ALGO_DBSCAN_H
