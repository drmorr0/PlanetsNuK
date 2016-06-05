// viz_canvas.cpp: David R. Morrison
// Implementation details for the VizCanvas class

#include "viz/canvas.h"
#include "viz/window.h"
#include "viz/scene.h"
#include "viz/planet_obj.h"

#include "data/planet.h"
#include "data/ship.h"

using namespace std;

/*
 * The VizCanvas constuctor needs to do the following things:
 *  1) Set up the events that the canvas will accept
 *  2) Initialize the scene graph
 */
VizCanvas::VizCanvas(const vector<Planet*>& planets, const vector<Ship*>& ships) :
	pScene(new Scene),
	mCanvOffset(Vector2D{-1500, 2500}),
	mZoomStep(1.1),
	mZoom(1.0),
	mSelection(-1)
{
	// I don't understand exactly how this works -- I can't get GTK to recognize custom event
	// handlers, nor does it seem to work with the Gdk::ALL_EVENTS_MASK (TODO)
	add_events(Gdk::BUTTON_PRESS_MASK | Gdk::SCROLL_MASK | Gdk::POINTER_MOTION_MASK);

	for (auto p : planets)
		pScene->addObject(new PlanetSceneObject(p->pos().x, -p->pos().y, p));
}

void VizCanvas::render(const CairoContext& ctx, double scale, const Vector2D& offset)
{
	pScene->render(ctx, offset, scale);
}

/**** EVENT HANDLERS *****/

/*
 * on_draw: redraw the canvas; we just use our scene manager to control rendering of SceneObjects
 * TODO: just render the currently-visible area
 */
bool VizCanvas::on_draw(const CairoContext& ctx)
{
	render(ctx, mZoom, mCanvOffset);
	return true;
}

/*
 * on_button_press_event:
 *  If a SceneObj is under the cursor, we select it; otherwise, we just mark the location in case
 *  the user is trying to pan
 */
bool VizCanvas::on_button_press_event(GdkEventButton* evt)
{
	mClickPos = Vector2D{evt->x, evt->y};
	vector<SceneObject*> objs = pScene->findObjects(toScenePos(mClickPos));

	mInSelection = false;
	if (objs.size() > 0)
	{
		setSelection(objs[0]->id());
		VizWindow* parent = static_cast<VizWindow*>(this->get_toplevel());
		parent->setSelectionText(objs[0]->getInfoText());

		// Only need to redraw if the selection actually changed...
		queue_draw();

		// Regardless, we are now inside the current selection, so set mInSelection = true
		mInSelection = true;
	}
	
	return true;
}

/* 
 * on_scroll_event:
 *  1) Zoom in or out from the current canvas
 *  TODO: implement some sort of smooth scrolling/animation?
 */
bool VizCanvas::on_scroll_event(GdkEventScroll* evt)
{
	Vector2D nodePos = toScenePos(Vector2D{evt->x, evt->y});
	double oldZoom = mZoom;

	if (evt->direction == GDK_SCROLL_UP) mZoom *= mZoomStep;
	else if (evt->direction == GDK_SCROLL_DOWN) mZoom /= mZoomStep;

	mCanvOffset += nodePos * (oldZoom - mZoom);
	queue_draw();  // TODO only redraw visible part of scene graph
	return true;
}

/*
 * on_motion_notify_event: If the primary mouse button is pressed,
 *  1) If one or more items are being dragged, update their position
 *  2) Otherwise update the position of the canvas
 */
bool VizCanvas::on_motion_notify_event(GdkEventMotion* evt)
{
	if (!(evt->state & GDK_BUTTON1_MASK)) return false;
	else if (evt->is_hint) return true;
	else 
	{
		mDragPos = Vector2D{evt->x, evt->y};
		Vector2D delta = mDragPos - mClickPos;
		if (!mInSelection) mCanvOffset += delta;
		mClickPos = mDragPos;

		queue_draw();  // TODO only redraw visible part of scene graph
	}
	
	return true;
}

/***** End event handlers *****/

Vector2D VizCanvas::toScenePos(const Vector2D& screenPos) const
{
	return 1 / mZoom * (screenPos - mCanvOffset);
}

double VizCanvas::toSceneX(double screenX) const
{
	return 1 / mZoom * (screenX - mCanvOffset.x);
}

double VizCanvas::toSceneY(double screenY) const
{
	return 1 / mZoom * (screenY - mCanvOffset.y);
}

Vector2D VizCanvas::toScreenPos(const Vector2D& scenePos) const
{
	return mCanvOffset + mZoom * scenePos;
}
