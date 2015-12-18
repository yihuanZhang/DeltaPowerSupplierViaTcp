#ifndef _SOURCES_H
#include "sources.h"
#endif // _SOURCES_H
//#include <gtk/gtk.h>


void signalAdder()
{
    printf("in function Signal Adder \n");
    printf("processing.....");
    g_signal_connect( G_OBJECT( aButton ) , "clicked" , G_CALLBACK( aboutInfo ) , NULL );
    g_signal_connect(G_OBJECT(cButton),"clicked",G_CALLBACK(click_clear),NULL);
    g_signal_connect(G_OBJECT(ipCom),"clicked",G_CALLBACK(click_ip),NULL);
    g_signal_connect(G_OBJECT(sButton),"clicked",G_CALLBACK(click_send),NULL);
    printf("done.....\n\n\n\n\n");
}

void click_send()
{
    char * sBuffer;
    char * rBuffer;
    //char temp[1024];
    memset(sendBuff,0,1024);

    sBuffer=gtk_entry_get_text(sText);
    sprintf(sendBuff,"%s\n",sBuffer);
    printf("sendBuff in function temp before send function: %s    end\n",sendBuff);
    //if( write(cSocket,temp,strlen(temp)) < 0)
    if (send(cSocket,sendBuff,strlen(sendBuff),0)<  0 )
    {
        diagWin(errInfo,"error occured in send process.");
    }
    else
    {
        memset( ( void * ) recvBuff , 0 , 1024);
        printf("before recv .....");
        //read(cSocket,temp,1024);
        recv(cSocket,recvBuff,sizeof(recvBuff),0);
        recvBuff[strlen(recvBuff-2)]=0;
        gtk_entry_set_text(rText,recvBuff);
    }
}

void click_ip()
{
    char * temp = gtk_entry_get_text(GTK_ENTRY( ipText ) );
    diagWin( ipInfo , temp );
    myConnect();
}

void click_clear()
{
    gtk_entry_set_text(GTK_ENTRY(sText),"");
    gtk_entry_set_text(GTK_ENTRY(rText),"");
}

void aboutInfo()
{
    GtkWidget * dialog;
    dialog = gtk_message_dialog_new( GTK_WINDOW(myWin),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "author : iHz(张亦欢|Yihuan Zhang|Anfaenger) \n version : %s \n Plathom: Ubuntu 14.04 \n complie with c & gtk+3.0" , version);
    gtk_window_set_title(GTK_WINDOW(dialog),"About");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

