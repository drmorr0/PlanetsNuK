// dbscan.cpp: David R. Morrison, 2016

#include "algo/dbscan.h"
#include "data/planet.h"

using namespace std;

static vector<Planet*> findNeighbors(Planet* p, const vector<Planet*>& planets, int owner, int eps)
{
	vector<Planet*> neighbors;
	for (auto n : planets)
	{
		if (n->owner() != owner) continue;
		if (dist(p->pos(), n->pos()) < eps) neighbors.push_back(n);
	}
	return neighbors;
}

vector<vector<Planet*>> dbscan(const vector<Planet*>& planets, int owner, int eps, size_t minPts)
{
	vector<vector<Planet*>> clusters;
	vector<bool> visited(planets.size(), false);
	vector<bool> inCluster(planets.size(), false);
	for (auto p : planets)
	{
		if (p->owner() != owner || visited[p->id()]) continue;

		visited[p->id()] = true;
		vector<Planet*> neighbors = findNeighbors(p, planets, owner, eps);

		if (neighbors.size() >= minPts)
		{
			vector<Planet*> cluster = vector<Planet*>{ p };
			while (!neighbors.empty())
			{
				Planet* n = neighbors.back();
				neighbors.pop_back();;
				if (n->owner() != owner || visited[n->id()] || inCluster[n->id()]) continue;

				visited[n->id()] = true;
				vector<Planet*> nNeighbors = findNeighbors(n, planets, owner, eps);
				if (nNeighbors.size() >= minPts)
					neighbors.insert(neighbors.end(), nNeighbors.begin(), nNeighbors.end());

				cluster.push_back(n);
				inCluster[n->id()] = true;
			}
			clusters.push_back(cluster);
		}
	}

	return clusters;
}
