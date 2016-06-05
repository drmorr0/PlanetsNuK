#ifndef VIZ_CANVAS_H
#define VIZ_CANVAS_H
/*
 * viz_canvas.h: David R. Morrison, March 2014
 *
 * This file describes a subclass of the Gtk::DrawingArea widget that manages things like mouse
 * interactivity, and interactions with the Scene object for the current display.
 *
 */

#include "viz/types.h"
#include "viz/vector2d.h"

#include <gtkmm.h>

#include <vector>
#include <memory>

class Scene;
class Planet;
class Ship;

class VizCanvas : public Gtk::DrawingArea
{
public:
	VizCanvas(const std::vector<Planet>& planets, const std::vector<Ship>& ships);
	void render(const CairoContext& ctx, double scale, const Vector2D& offset);

	void setSelection(int id) { mSelection = id; }
	void clearSelection() { mSelection = -1; }
	int getSelection() const { return mSelection; }

private:
	std::unique_ptr<Scene> pScene;

	// Canvas position information
	Vector2D mCanvOffset;
	const double mZoomStep;
	double mZoom;

	int mSelection;
	bool mInSelection;
	Vector2D mClickPos, mDragPos;

	// Signal handlers
	virtual bool on_draw(const CairoContext& ctx);
	virtual bool on_button_press_event(GdkEventButton* evt);
	virtual bool on_scroll_event(GdkEventScroll* evt);
	virtual bool on_motion_notify_event(GdkEventMotion* evt);

	// Convert to and from screen coordinates to scene coordinates
	Vector2D toScenePos(const Vector2D& screenPos) const;
	double toSceneX(double screenX) const;
	double toSceneY(double screenY) const;
	Vector2D toScreenPos(const Vector2D& scenePos) const;
};

#endif // VIZ_CANVAS_H

