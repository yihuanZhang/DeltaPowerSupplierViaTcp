#include "sources.h"
//#include <gtk/gtk.h>

void interface()
{
    myWin=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(myWin),200,100);
    gtk_window_set_title(GTK_WINDOW(myWin),myWinTitle);

    ipCom=gtk_button_new_with_label("confirm");
    aButton=gtk_button_new_with_label("about");
    sButton=gtk_button_new_with_label("send");
    cButton=gtk_button_new_with_label("clear");

    ipText=gtk_entry_new();
    //gtk_entry_set_input_hints(GTK_ENTRY(ipText),"xxx.xxx.xxx.xxx");
    sText=gtk_entry_new();
    rText=gtk_entry_new();

    ipLabel=gtk_label_new("IP Address : ");
    sLabel=gtk_label_new("msg to send : ");
    rLabel=gtk_label_new("received msg : ");


    myGrid=gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(myWin),myGrid);
    gtk_grid_attach(GTK_GRID(myGrid),
                    ipLabel,
                    0 , 0 , 1 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    ipText,
                    1 , 0 , 4 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    ipCom,
                    5, 0 , 1 ,1);


    gtk_grid_attach(GTK_GRID(myGrid),
                    sLabel,
                    0 ,1 , 1 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    sText,
                    1 , 1 , 4 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    sButton,
                    5, 1 , 1 ,1);

    gtk_grid_attach(GTK_GRID(myGrid),
                    rLabel,
                    0 , 2 , 1 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    rText,
                    1 , 2 , 4 ,1);
    gtk_grid_attach(GTK_GRID(myGrid),
                    cButton,
                    5,  2, 1 ,1);

       gtk_grid_attach(GTK_GRID(myGrid),
                   aButton,
                    0,  3 , 1 ,1);

    gtk_widget_show_all(myWin);
    /*
    gtk_widget_show(myGrid);
    gtk_widget_show(ipCom);
    gtk_widget_show(sButton);
    gtk_widget_show(cButton);
    gtk_widget_show(aButton);
    gtk_widget_show(ipLabel);
    gtk_widget_show(sLabel);
    gtk_widget_show(rLabel);
    gtk_widget_show(ipText);
    gtk_widget_show(sText);
    gtk_widget_show(rText);
    */
}
