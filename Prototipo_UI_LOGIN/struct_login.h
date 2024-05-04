
#ifndef STRUC_LOGIN_H
#define STRUC_LOGIN_H

//STRUCT USADA NA PASSAGEM DE PARAMETRO PARA A FUNCAO LOGIN_BUTTON_CLICKED() E CANCELAR_BUTTON_CLICKED()

typedef struct {
    GtkWidget *entry_login;
    GtkWidget *entry_senha;
    GtkWidget *label_aviso;
    GtkWidget *stack;

}Login;


#endif //STRUC_LOGIN_H
