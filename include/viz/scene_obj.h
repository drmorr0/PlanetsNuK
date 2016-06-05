#ifndef SCENE_OBJ_H
#define SCENE_OBJ_H
/*
 * scene_obj.h: David R. Morrison, March 2014
 *
 * An abstract base class for an object that belongs to a scene graph
 *
 */

#include "util/vector2d.h"
#include "viz/types.h"

class Scene;

// A generic SceneObject base class
class SceneObject
{
public:
	SceneObject() { };
	virtual ~SceneObject() { };

	int id() const { return mId; }

	virtual bool contains(const Vector2D& pt) const = 0;
	virtual void render(const CairoContext& ctx, const Vector2D& canvOffset, double zoom) const= 0;
	virtual std::string getInfoText() const = 0;

protected:
	friend class Scene;
	Scene* mfpParentScene;

private:		// Only the Scene Manager should be able to control the object's id
	int mId;
};


#endif // SCENE_OBJ_H
