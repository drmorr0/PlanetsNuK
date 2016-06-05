// scene.cpp: David R. Morrison, March 2014
// Class to manage the scene for the visualization software

#include "viz/scene.h"
#include "viz/scene_obj.h"

using namespace std;

// Delete everything in the scene graph
Scene::~Scene()
{
	for (auto i = mpObjects.begin(); i != mpObjects.end(); ++i)
		delete (i->second);
}

// Add an object to the scene graph and return its id
int Scene::addObject(SceneObject* obj)
{
	obj->mfpParentScene = this;
	obj->mId = mObjNextId++;
	mpObjects[obj->mId] = obj;
	return obj->mId;
}

// Find all objects that contain a particular point
vector<SceneObject*> Scene::findObjects(const Vector2D& pt) const
{
	vector<SceneObject*> objs;
	for (auto i : mpObjects)
		if (i.second->contains(pt))
			objs.push_back(i.second);

	return objs;
}

// Get an object by its ID
SceneObject* Scene::get(int id) const
{
	if (mpObjects.count(id) == 0) return nullptr;
	else return mpObjects.find(id)->second;
}

// Render all visible objects (TODO what about objects off-screen?)
void Scene::render(const CairoContext& ctx, const Vector2D& canvOffset, double zoom)
{
	for (auto i : mpObjects)
		i.second->render(ctx, canvOffset, zoom);
}



