#include "sources.h"
int on = 1;


void myConnect()
{
    char temp[1024];
    memset(temp,0,1024);
    char mybuffer[1024];
    memset(mybuffer,0,1024);
    char portBuffer[512];
    memset(portBuffer,0,512);
    printf("before socket()\n");
    if ( ( cSocket = socket( AF_INET,SOCK_STREAM,0) ) < 0)
    {
        diagWin(errInfo,hstrerror(h_errno));
    }
    memset( ( struct sockaddr_in *) &client , 0 , addr_len);
    client.sin_family=AF_INET;
    client.sin_port=htons(RemotePort);
    client.sin_addr.s_addr=inet_addr( (char *) gtk_entry_get_text(ipText));

    setsockopt(cSocket,SOL_SOCKET,SO_SNDBUF,
                           (char * ) &sBufflen,sizeof(int));
    setsockopt(cSocket,SOL_SOCKET,SO_RCVBUF,
                          (char * ) &rBufflen,sizeof(int));
    //setsockopt(cSocket,IPPROTO_TCP,TCP_NODELAY,(char *) & on,sizeof(on));

    printf("before connect() \n");
    if ( connect( cSocket, (struct sockaddr * ) &client , addr_len) < 0 )
    {
        printf("connect error occured...\n");
        diagWin(errInfo,hstrerror(h_errno));
    }
    else
    {
        sprintf(portBuffer,"%d",RemotePort);
        sprintf(temp , "remoteIP:%s\nremotePort:%s" , gtk_entry_get_text( ipText ) , portBuffer );
        printf("connect()function else route\n");
        diagWin("connect successfully ", temp);
        gtk_widget_set_sensitive(ipText,FALSE);
        gtk_widget_set_sensitive(ipCom,FALSE) ;
    }
    printf("before first recv()\n");
    //read(cSocket,mybuffer,1024);
    recv(cSocket,recvBuff,strlen(recvBuff)+1,0);
    gtk_entry_set_text(rText,recvBuff);
}
