#ifndef VIZ_WINDOW_H
#define VIZ_WINDOW_H
/*
 * viz_window.h: David R. Morrison, March 2014
 *
 * Top-level window class for Viz.  This class manages all of the other custom widgets, event
 * handlers, and the like, that are needed in order for the program to run
 */

#include <memory>

#include <gtkmm.h>

class VizCanvas;
class Planet;
class Ship;

class VizWindow : public Gtk::Window
{
public:
	VizWindow(const std::vector<Planet>& planets, const std::vector<Ship>& ships,
			const Gtk::WindowType& wt = Gtk::WINDOW_TOPLEVEL);

private:
	VizCanvas* fpCanvas;
	
	// Disable copy/assignment for now
	VizWindow(const VizWindow&) = delete;
	VizWindow& operator=(const VizWindow&) = delete;
};

#endif // VIZ_WINDOW_H
