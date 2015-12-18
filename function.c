#include "sources.h"

void diagWin(char * info ,char * cStr)
{
    GtkWidget * dialog;
    dialog = gtk_message_dialog_new(myWin,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "%s :%s",info,cStr);
    gtk_window_set_title(GTK_WINDOW(dialog),"Information");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

/*
void diagLogin()
{
    GtkWidget * dialog;
    dialog = gtk_message_dialog_new(myWin,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_,
                                    "ip you have inputed is :%s",ip);
    gtk_window_set_title(GTK_WINDOW(dialog),"Information");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
*/
