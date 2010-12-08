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

    Button *btnOk;
    Button *btnCancel;

    // callback methods
    virtual void on_button_cancel_clicked();
    virtual void on_button_ok_clicked();
};

#endif //_DIALOG_NEW_USER_H_
