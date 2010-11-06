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

#ifndef _WIN_PREFERENCES_H_
#define _WIN_PREFERENCES_H_

#include <gtkmm.h>

using namespace Gtk;

class WinPreferences: public Gtk::Window
{
public:
    WinPreferences();
    virtual ~WinPreferences();
protected:

private:
};

#endif // WIN_PREFERENCES_H_
