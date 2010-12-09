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

#include "win-main.h"

WinMain::WinMain()
: vbxMenu(),
  tblMain(2,2,false)
{
    alert = "";
    connected = false;
    configs.load();
    if(client.server_connect(configs.host.c_str(),atoi(configs.port.c_str())))
        connected = true;
    else{
        alert = "Não foi possível conectar ao servidor.";
        on_menu_edit_preferences();
    }

	showed = false;

	set_position(Gtk::WIN_POS_MOUSE);
	set_title("Day of Buy");
	set_default_size(400,600);

	add(vbxMenu);
	
	//cria o menu principal
	
	actMenu = Gtk::ActionGroup::create();
	
	actMenu->add(Gtk::Action::create("FileMenu","Arquivo"));
	actMenu->add(Gtk::Action::create("FileNewUser","Adicionar Usuário"),sigc::mem_fun(*this, &WinMain::on_menu_file_new_user));
	actMenu->add(Gtk::Action::create("FileQuit",Gtk::Stock::QUIT),sigc::mem_fun(*this, &WinMain::on_menu_file_quit));
	actMenu->add(Gtk::Action::create("EditMenu","Editar"));
	actMenu->add(Gtk::Action::create("EditPreferences",Gtk::Stock::PREFERENCES),sigc::mem_fun(*this,&WinMain::on_menu_edit_preferences));
	
	uimMenu = Gtk::UIManager::create();
	uimMenu->insert_action_group(actMenu);
	
	add_accel_group(uimMenu->get_accel_group());
	
	Glib::ustring ui_info =
		"<ui>"
		"	<menubar name='MenuBar'>"
		" 		<menu action='FileMenu'>"
		"                      <menuitem action='FileNewUser'/>"
		" 			<separator/>"
		" 			<menuitem action='FileQuit'/>"
		" 		</menu>"
		"               <menu action='EditMenu'>"
		"                      <menuitem action='EditPreferences'/>"
		"               </menu>"
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
	if(connected)
        set_coke_icon();
}

// methods
void WinMain::set_coke_icon()
{
   systray->set_from_file("../shared/imgs/icon100.png"); 
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

void WinMain::on_menu_edit_preferences()
{
    dlgPreferences = new DialogPreferences(configs,alert);
    dlgPreferences->run();
    configs.load();
    if(client.server_connect(configs.host.c_str(),atoi(configs.port.c_str()))){
        connected = true;
        set_coke_icon();
    }
}

void WinMain::on_menu_file_new_user()
{
  dlgNewUser = new DialogNewUser();
  dlgNewUser->run();
}

