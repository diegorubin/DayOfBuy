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

#include "win-main.h"

WinMain::WinMain()
: vbxMenu(),
  tblMain(2,2,false)
{
	showed = false;

	set_position(Gtk::WIN_POS_MOUSE);
	set_title("Day of Buy");
	set_default_size(400,600);

	add(vbxMenu);
	
	//cria o menu principal
	
	actMenu = Gtk::ActionGroup::create();
	
	actMenu->add(Gtk::Action::create("FileMenu","Arquivo"));
	actMenu->add(Gtk::Action::create("FileQuit",Gtk::Stock::QUIT),sigc::mem_fun(*this, &WinMain::on_menu_file_quit));
	
	uimMenu = Gtk::UIManager::create();
	uimMenu->insert_action_group(actMenu);
	
	add_accel_group(uimMenu->get_accel_group());
	
	Glib::ustring ui_info =
		"<ui>"
		"	<menubar name='MenuBar'>"
		" 		<menu action='FileMenu'>"
		" 			<separator/>"
		" 			<menuitem action='FileQuit'/>"
		" 		</menu>"
		"	</menubar>"
		"</ui>";
	
	#ifdef GLIBMM_EXCEPTIONS_ENABLED
	try
	{
		uimMenu->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex)
	{
		std::cerr << "building menus failed: " << ex.what();
	}
	#else
	std::auto_ptr<Glib::Error> ex;
	uimMenu->add_ui_from_string(ui_info, ex);
	if(ex.get())
	{
		std::cerr << "building menus failed: " << ex->what();
	}
	#endif //GLIBMM_EXCEPTIONS_ENABLED

	
	Gtk::Widget* MainMenu = uimMenu->get_widget("/MenuBar");
	if(MainMenu)
		vbxMenu.pack_start(*MainMenu, Gtk::PACK_SHRINK);
	vbxMenu.pack_start(tblMain);

	show_all_children();
	hide();
}

WinMain::~WinMain()
{
}

void WinMain::set_systray(Glib::RefPtr<Gtk::StatusIcon> tray)
{
	systray = tray;
	systray->set_tooltip("Day of Buy");
	systray->signal_activate().connect(sigc::mem_fun(*this,&WinMain::on_systray_activate));
}

// callbacks implementations
void WinMain::on_systray_activate()
{
	if(showed){
		showed = false;
		hide();
	}
	else
	{
		showed = true;
		show();
	}
}

// callbacks implementations - menu
void WinMain::on_menu_file_quit()
{
	Gtk::Main::quit();
}

