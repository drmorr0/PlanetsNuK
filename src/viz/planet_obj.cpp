// scene_obj.cpp: David R. Morrison, March 2014
// Implementation details for SceneObjects

#include "viz/planet_obj.h"
#include "util/vector2d.h"


using namespace std;

PlanetSceneObject::PlanetSceneObject(double x, double y, double radius, double thickness,
		const Gdk::Color& color, const Gdk::Color& fillColor) :
	PlanetSceneObject(Vector2D(x, y), radius, thickness, color, fillColor)
{
	/* Do nothing */
}

PlanetSceneObject::PlanetSceneObject(const Vector2D& center, double radius, double thickness,
		const Gdk::Color& color, const Gdk::Color& fillColor) :
	mCenter(center),
	mRadius(radius),
	mThickness(thickness),
	mColor(color),
	mFill(fillColor)
{
	/* Do nothing */
}

bool PlanetSceneObject::contains(const Vector2D& pt) const
{
	return length(mCenter - pt) < mRadius;
}

void PlanetSceneObject::render(const CairoContext& ctx, const Vector2D& canvOffset, 
		double zoom) const
{
	// Translate from the position in graph-embedding space to canvas space
	Vector2D canvPos = canvOffset + zoom * mCenter;
	double canvRadius = zoom * mRadius;

	// Draw a circle for the node
	ctx->save();
	ctx->arc(canvPos.x, canvPos.y, canvRadius, 0, 2 * M_PI);
	ctx->set_source_rgb(mFill.get_red_p(), mFill.get_green_p(), mFill.get_blue_p());
	ctx->fill_preserve();
	ctx->set_source_rgb(mColor.get_red_p(), mColor.get_green_p(), mColor.get_blue_p());
	ctx->set_line_width(mThickness);
	ctx->stroke();

	ctx->restore();
}



