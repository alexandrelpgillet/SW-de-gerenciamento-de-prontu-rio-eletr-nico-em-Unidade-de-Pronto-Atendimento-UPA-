#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "struct_login.h"





void login_button_clicked(GtkWidget *window , Login *sinal_login)
{

    //CONVERTENDO OS CARACTERES PREENCHIDOS PELA ENTRY'S LOGIN E SENHA EM PONTEIRO DE CARACTERES//
    const gchar *login = gtk_entry_get_text(GTK_ENTRY(sinal_login->entry_login));
    const gchar *senha = gtk_entry_get_text(GTK_ENTRY(sinal_login->entry_senha));


    //VERIFICADO SE O LOGIN E SENHA DAS ENTRYS SAO IGUAIS

    if(strcmp(login,"admin")==0 && strcmp(senha,"admin")==0) {

        //CASO O LOGIN E SENHA DAS ENTRYS ESTEJA CORRTO , CRIAR LABEL DE AVISO DE LOGIN REALIZADO E FAZER TRANSICAO PARA A STACK FILHA MENU

        gtk_label_set_text(GTK_LABEL(sinal_login->label_aviso),"login realizado com sucesso");
        gtk_entry_set_text(GTK_ENTRY(sinal_login->entry_login),"");
        gtk_entry_set_text(GTK_ENTRY(sinal_login->entry_senha),"");

        gtk_stack_set_transition_duration(GTK_STACK(sinal_login->stack) , 10000);
        gtk_stack_set_visible_child_name(GTK_STACK(sinal_login->stack), "Menu");
    }
    else {

        //CASO O LOGIN E SENHA DA ENTRY ESTEJA INCORRETO,CRIAR LABEL DE AVISO : LOGIN OU SENHA INCORRETOS

        gtk_label_set_text(GTK_LABEL(sinal_login->label_aviso), "login ou senha incorretos ,tente novamente");
        gtk_entry_set_text(GTK_ENTRY(sinal_login->entry_login),"");
        gtk_entry_set_text(GTK_ENTRY(sinal_login->entry_senha),"");
    }





}

void cancelar_button_clicked(GtkWidget *window , Login *sinal_cancelar) {

    //LIMPANDO  AS ENTRYS DA STACK LOGIN

    gtk_entry_set_text(GTK_ENTRY(sinal_cancelar->entry_login),"");
    gtk_entry_set_text(GTK_ENTRY(sinal_cancelar->entry_senha),"");
}







int main(int argc , char *argv[]) {

//ALOCACAO DINAMICA PARA O PONTEIRO SINAL_LOGIN DESCRITO NO HEADER STRUCT_LOGIN.H//

    Login *sinal_login;

    sinal_login = malloc(sizeof(Login));



//INICIANDO A BIBLIOTECA GTK//

    gtk_init(&argc , &argv);



//##########################PILHA FILHA DA STACK  COM NOME MENU################################/

    GtkWidget *menu;
    menu = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);



//########################################ICONE-LOGIN########################################//
    GtkWidget *icon_menu;
    icon_menu = gtk_image_new_from_icon_name("dialog-password-symbolic", GTK_ICON_SIZE_MENU);


//#######################################LABEL-LOGIN########################################//

    GtkWidget *label_login;
    label_login = gtk_label_new("LOGIN");




//#################################ENTRY-LOGIN#########################################//

    GtkWidget *entry_login;
    entry_login = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(entry_login), 20);
    gtk_widget_set_halign(entry_login,GTK_ALIGN_CENTER);





//###################################LABEL-SENHA######################################//

    GtkWidget *label_senha;
    label_senha= gtk_label_new("SENHA");





//###################################ENTRY-SENHA######################################//

    GtkWidget *entry_senha;
    entry_senha = gtk_entry_new();
    gtk_widget_set_halign(entry_senha, GTK_ALIGN_CENTER);
    gtk_entry_set_visibility(GTK_ENTRY(entry_senha),FALSE);
    gtk_entry_set_invisible_char(GTK_ENTRY(entry_senha), '*');
    gtk_entry_set_max_length(GTK_ENTRY(entry_senha), 20);


//###################################LABEL-BUTTON-LOGIN################################//

    GtkWidget *label_button_login;
    label_button_login = gtk_label_new("Log in");

//##################################ICON-BUTTON-LOGIN###################################################//

    GtkWidget *icon_button_login;
    icon_button_login = gtk_image_new_from_icon_name("object-select-symbolic" , GTK_ICON_SIZE_BUTTON);

//################################CONTEINER-LOGIN#########################################//

    GtkWidget *conteiner_login;
    conteiner_login = gtk_box_new(GTK_ORIENTATION_VERTICAL,2);

//####################################LOGIN-BUTTON######################################//
    GtkWidget *button_login;
    button_login = gtk_button_new();


//#######################################LABEL-BUTTON-CANCELAR########################//

    GtkWidget *label_button_cancelar;
    label_button_cancelar= gtk_label_new("Cancelar");


//##########################################ICON-BUTTON-CANCELAR##########################//

    GtkWidget *icon_button_cancelar;
    icon_button_cancelar = gtk_image_new_from_icon_name("process-stop-symbolic", GTK_ICON_SIZE_BUTTON);

//############################################CONTEINER-CANCELAR########################//
    GtkWidget * conteiner_cancelar;
    conteiner_cancelar = gtk_box_new(GTK_ORIENTATION_VERTICAL,2);


//#########################################CANCELAR-BUTTON###############################//
    GtkWidget *button_cancelar;
    button_cancelar = gtk_button_new();

//################################BUTTON-BOX#########################################//

    GtkWidget *button_box_acesso;
    button_box_acesso=gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_halign(button_box_acesso, GTK_ALIGN_CENTER);

//###############################AVISO-LABEL#############################################//

    GtkWidget *aviso_label;
    aviso_label=gtk_label_new("");

//################################BOX-LOGIN#########################################//

    GtkWidget *box_login;
    box_login = gtk_box_new(GTK_ORIENTATION_VERTICAL , 8);
    gtk_box_set_spacing(GTK_BOX(box_login), 20);




//###############################DECLARANDO-A-STACK##################################//

    GtkWidget *stack;
    stack = gtk_stack_new();



//################JANELA GTK###############################################//

    GtkWidget *janela;
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);







//################CONFIGURACAO JANELA DO PROGRAMA###############################################//


    gtk_window_set_title( GTK_WINDOW(janela),"SW-GERENCIADOR-PRONTURARIOS");

    gtk_window_set_default_icon_name("help-contents-symbolic");

    gtk_window_set_default_size(GTK_WINDOW(janela), 300 , 300);

    gtk_container_add(GTK_CONTAINER(janela), stack);

    g_signal_connect(janela , "destroy" , G_CALLBACK(gtk_main_quit), NULL);


//#################################CONFIGURACAO DA BOX-LOGIN#########################################///

    gtk_container_add(GTK_CONTAINER(box_login), icon_menu);
    gtk_container_add(GTK_CONTAINER(box_login),label_login);
    gtk_container_add(GTK_CONTAINER(box_login),entry_login);
    gtk_container_add(GTK_CONTAINER(box_login),label_senha);
    gtk_container_add(GTK_CONTAINER(box_login), entry_senha);




    gtk_container_add(GTK_CONTAINER(conteiner_cancelar), icon_button_cancelar);
    gtk_container_add(GTK_CONTAINER(conteiner_cancelar), label_button_cancelar);
    gtk_container_add(GTK_CONTAINER(button_cancelar), conteiner_cancelar);



    gtk_container_add(GTK_CONTAINER(conteiner_login), icon_button_login);
    gtk_container_add(GTK_CONTAINER(conteiner_login), label_button_login);
    gtk_container_add(GTK_CONTAINER(button_login), conteiner_login);



    gtk_container_add(GTK_CONTAINER(button_box_acesso), button_cancelar);
    gtk_container_add(GTK_CONTAINER(button_box_acesso), button_login);



    gtk_container_add(GTK_CONTAINER(box_login), button_box_acesso);
    gtk_container_add(GTK_CONTAINER(box_login), aviso_label);


//################################ADICIONANDO A BOX_LOGIN COMO PILHA PAI DA STACK############################//

    gtk_container_add(GTK_CONTAINER(stack), box_login);


//#################################ADICIONANDO O BOX MENU COMO UMA PILHA FILHA DA STACK COM NOME "Menu"#################//


    gtk_stack_add_named(GTK_STACK(stack), menu, "Menu");

//################################SINAL DOS BOTOES LOGIN E CANCELAR - O PARAMETRO PASSADO PELO G_CALLBACK É UM PONTEIRO DE ESTRUTURA DO TIPO LOGIN E QUE ESTA DECLARADO NO HEADER STRUCT_LOGIN.H#########################################################################################


    sinal_login->entry_login=entry_login;
    sinal_login->entry_senha=entry_senha;
    sinal_login->label_aviso=aviso_label;
    sinal_login->stack=stack;

    g_signal_connect(button_login , "clicked", G_CALLBACK(login_button_clicked), sinal_login);
    g_signal_connect (button_cancelar , "clicked", G_CALLBACK(cancelar_button_clicked), sinal_login);


//########################################################################################################################################################################################################################################################################



//QAL WIDGET DEVE SER MOSTRADO AO SER CHAMADO A FUNCAO GTK_MAIN ()//

    gtk_widget_show_all(janela);

//INICIALIZANDO A INTERFACE GRAFICA GTK//

    gtk_main();


//LIBERANDO ESPACO DA MEMORIA ALOCADO PARA A VARIAVEL SINAL_LOGIN DO TIPO STRUCT DE PONTEIROS//

    free(sinal_login);



    return 0;
}
