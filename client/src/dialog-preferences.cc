#include "dialog-preferences.h"

DialogPreferences::DialogPreferences(Config configs, string alert)
:   tblServer(2,6,false),
    lblHost("Endereço IP: "),
    lblPort("Porta: "),
    ckbSavePasswd("Salvar senha?")
{
    this->configs = configs;
    this->configs.load();

    VBox *vbxPreferences = this->get_vbox();

    set_title("Preferências - Day Of Buy");

    vbxPreferences->pack_start(lblAlert);
    vbxPreferences->pack_start(notPreferences);

    lblAlert.set_markup("<span color='red'>"+alert+"</span>");

    // notebook
    notPreferences.set_border_width(10);
    notPreferences.append_page(tblServer,"Servidor");
    
    // buttons
    btnCancel = add_button(Stock::CANCEL,RESPONSE_CANCEL);
    btnOk = add_button(Stock::OK,RESPONSE_OK);

    // page 1 - server
    entHost.set_text(this->configs.host);
    entPort.set_text(this->configs.port);
    ckbSavePasswd.set_active(configs.save_passwd == "1");


    tblServer.attach(lblHost,0,1,0,1,FILL,FILL,0,0);
    tblServer.attach(entHost,1,2,0,1,FILL,FILL,0,0);
    tblServer.attach(lblPort,0,1,1,2,FILL,FILL,0,0);
    tblServer.attach(entPort,1,2,1,2,FILL,FILL,0,0);
    tblServer.attach(ckbSavePasswd,0,2,4,5,FILL,FILL,0,0);

    // connect signals
    btnCancel->signal_clicked().connect(sigc::mem_fun(*this,&DialogPreferences::on_button_cancel_clicked));
    btnOk->signal_clicked().connect(sigc::mem_fun(*this,&DialogPreferences::on_button_ok_clicked));

    show_all();
}

DialogPreferences::~DialogPreferences()
{
}

void DialogPreferences::on_button_cancel_clicked()
{
  delete this;
}

void DialogPreferences::on_button_ok_clicked()
{
    configs.host = entHost.get_text();
    configs.port = entPort.get_text();
    if(ckbSavePasswd.get_active())
        configs.save_passwd = "1";
    else
        configs.save_passwd = "0";
    configs.save();
    delete this;
}

