#ifndef _DIALOG_NEW_USER_H_
#define _DIALOG_NEW_USER_H_

#include <gtkmm.h>

using namespace Gtk;

class DialogNewUser: public Gtk::Dialog
{
public:
    DialogNewUser();
    virtual ~DialogNewUser();
private:
    Table tblDialog;
    Label lblName;
    Entry entName;
    Label lblLogin;
    Entry entLogin;
    Label lblPasswd;
    Entry entPasswd;
};

#endif //_DIALOG_NEW_USER_H_
