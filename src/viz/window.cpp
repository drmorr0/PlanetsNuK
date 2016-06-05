// viz_window.cpp: David R. Morrison, March 2014
// Implementation details for the VizWindow class

#include "viz/window.h"
#include "viz/canvas.h"
#include "viz/builder.h"

#include "data/planet.h"
#include "data/ship.h"

using namespace std;

VizWindow::VizWindow(const vector<Planet>& planets, const vector<Ship>& ships, 
		const Gtk::WindowType& wt) :
	Gtk::Window(wt),
	fpCanvas(Gtk::manage(new VizCanvas(planets, ships)))
{
	Gtk::Viewport* vp = TheBuilder::get<Gtk::Viewport>("viz_viewport");
	vp->add(*fpCanvas);
	vp->show_all();
	add(*TheBuilder::get("viz_main_grid"));
}




