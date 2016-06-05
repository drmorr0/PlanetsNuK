// builder.cpp: David R. Morrison
// Implementation details for the builder interface

#include "viz/builder.h"

/*
 * Get the top-level window
 */
VizWindow* TheBuilder::getToplevel()
{
	Gtk::Widget* tl = get("viz_main_grid")->get_toplevel();
	if (tl && tl->get_is_toplevel())
		return (VizWindow*)tl;
	else return nullptr;
}

