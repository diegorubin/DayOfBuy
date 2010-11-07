#include "dialog-preferences.h"

DialogPreferences::DialogPreferences()
:   tblServer(2,2,false),
    lblHost("Endereço IP: "),
    lblPort("Porta: ")
{
    VBox *vbxPreferences = this->get_vbox();

    set_title("Preferências - Day Of Buy");

    vbxPreferences->pack_start(notPreferences);

    // notebook
    notPreferences.set_border_width(10);
    notPreferences.append_page(tblServer,"Servidor");
    
    // buttons
    btnCancel = add_button(Stock::CANCEL,RESPONSE_CANCEL);
    btnOk = add_button(Stock::OK,RESPONSE_OK);

    // page 1 - server
    tblServer.attach(lblHost,0,1,0,1,FILL,FILL,0,0);
    tblServer.attach(entHost,1,2,0,1,FILL,FILL,0,0);
    tblServer.attach(lblPort,0,1,1,2,FILL,FILL,0,0);
    tblServer.attach(entPort,1,2,1,2,FILL,FILL,0,0);

    show_all();
}

DialogPreferences::~DialogPreferences()
{
}

