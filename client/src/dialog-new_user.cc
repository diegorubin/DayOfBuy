#include "dialog-new_user.h"

DialogNewUser::DialogNewUser()
:   tblDialog(2,3,false),
    lblName("Nome Completo: "),
    lblLogin("Login: "),
    lblPasswd("Senha: ")
{
    set_title("Adicionar Novo Usuário");

    VBox *vbxNewUser = this->get_vbox();
    vbxNewUser->pack_start(lblAlert);
    vbxNewUser->pack_start(tblDialog);
    
    entPasswd.set_invisible_char('*');
    entPasswd.set_visibility(false);
    
    // buttons
    btnCancel = add_button(Stock::CANCEL,RESPONSE_CANCEL);
    btnOk = add_button(Stock::OK,RESPONSE_OK);
    
    tblDialog.attach(lblName,0,1,0,1,FILL,FILL,0,0);
    tblDialog.attach(entName,1,2,0,1,FILL,FILL,0,0);
    tblDialog.attach(lblLogin,0,1,1,2,FILL,FILL,0,0);
    tblDialog.attach(entLogin,1,2,1,2,FILL,FILL,0,0);
    tblDialog.attach(lblPasswd,0,1,2,3,FILL,FILL,0,0);
    tblDialog.attach(entPasswd,1,2,2,3,FILL,FILL,0,0);

    // connect signals
    btnCancel->signal_clicked().connect(sigc::mem_fun(*this,&DialogNewUser::on_button_cancel_clicked));
    btnOk->signal_clicked().connect(sigc::mem_fun(*this,&DialogNewUser::on_button_ok_clicked));

    show_all();
}

DialogNewUser::~DialogNewUser()
{
}

void DialogNewUser::on_button_cancel_clicked()
{
    delete this;
}

void DialogNewUser::on_button_ok_clicked()
{
    string name = entName.get_text();
    string login = entLogin.get_text();
    string passwd  = entPasswd.get_text();

    if(client.create_new_user(name,login,passwd))
        delete this;
    else
        lblAlert.set_markup("<span color='red'>Não foi possível criar o usuário</span>");
}
