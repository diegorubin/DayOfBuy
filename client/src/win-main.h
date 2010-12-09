/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * DayOfBuy
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 * DayOfBuy is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * DayOfBuy is distributed in the hope that it will be useful, but
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
#include "config.h"
#include "client.h"

#include "dialog-preferences.h"
#include "dialog-new_user.h"

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
	bool connected;
	string alert;
	Config configs;
	Client client;
	Glib::RefPtr<Gtk::StatusIcon> systray;

	// main menu
	Glib::RefPtr<Gtk::ActionGroup> actMenu;
	Glib::RefPtr<Gtk::UIManager> uimMenu;
	Glib::RefPtr<Gtk::ListStore> treModel;

	// menu widgets
	VBox vbxMenu;
	
	Table tblMain;

    // methods
    void set_coke_icon();

	// callback methods
	virtual void on_systray_activate();
	// callback methods - menu
        virtual void on_menu_file_new_user();
	virtual void on_menu_file_quit();
	virtual void on_menu_edit_preferences();

    // dialogs
    DialogPreferences *dlgPreferences;
    DialogNewUser *dlgNewUser;
};

#endif // _WIN_MAIN_H_
