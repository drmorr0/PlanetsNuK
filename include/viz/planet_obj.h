#ifndef PLANET_OBJ_H
#define PLANET_OBJ_H
/* 
 * vertex_obj.h: David R. Morrison, March 2014
 *
 * A scene object representing a vertex in a graph
 *
 */

#include "scene_obj.h"
#include <gdkmm-3.0/gdkmm.h>
#include <string>

// A scene object for vertices of a graph
class PlanetSceneObject : public SceneObject
{
public:
	PlanetSceneObject(double x, double y, double radius = 10, double thickness = 1, 
			const Gdk::Color& color = Gdk::Color("#000000"), 
			const Gdk::Color& fillColor = Gdk::Color("#ffffff"));
	PlanetSceneObject(const Vector2D& center, double radius = 10, double thickness = 1, 
			const Gdk::Color& color = Gdk::Color("#000000"), 
			const Gdk::Color& fillColor = Gdk::Color("#ffffff"));

	virtual bool contains(const Vector2D& pt) const;
	virtual void render(const CairoContext& ctx, const Vector2D& canvOffset, double zoom) const;

	Vector2D getPos() const { return mCenter; }
	void setFill(const Gdk::Color& c) { mFill = c; }
	Gdk::Color getFill() const { return mFill; }
	void setColor(const Gdk::Color& c) { mColor = c; }
	Gdk::Color getColor() const { return mColor; }
	void setRadius(double r) { mRadius = r; }
	double getRadius() const { return mRadius; }
	void setThickness(double t) { mThickness = t; }
	double getThickness() const { return mThickness; }
	double getAbsRadius() const { return mRadius + mThickness; }

private:
	Vector2D mCenter;
	double mRadius;
	double mThickness;
	Gdk::Color mColor;
	Gdk::Color mFill;
};

#endif // PLANET_OBJ_H
