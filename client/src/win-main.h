/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * scrum-clock
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 * scrum-clock is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * scrum-clock is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _WIN_MAIN_H_
#define _WIN_MAIN_H_

#include <iostream>
#include <gtkmm.h>

using namespace Gtk;

class WinMain: public Gtk::Window 
{
public:
	WinMain();
	virtual ~WinMain();

	void set_systray(Glib::RefPtr<Gtk::StatusIcon> tray);
protected:

private:

	// attributes
	bool showed;
	Glib::RefPtr<Gtk::StatusIcon> systray;

	// main menu
	Glib::RefPtr<Gtk::ActionGroup> actMenu;
	Glib::RefPtr<Gtk::UIManager> uimMenu;
	Glib::RefPtr<Gtk::ListStore> treModel;

	// menu widgets
	VBox vbxMenu;
	
	Table tblMain;

	// callback methods
	virtual void on_systray_activate();
	// callback methods - menu
	virtual void on_menu_file_quit();
	
};

#endif // _WIN_MAIN_H_
