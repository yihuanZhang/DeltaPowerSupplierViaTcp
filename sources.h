#ifndef _SOURCES_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <ctype.h>
#include <netdb.h>

#define RemotePort 8462
#define myWinTitle "tcp-client"
#define version "alpha0.10"
#define ipInfo "ip you have inputed is"
#define errInfo " an error occured : "

//extern parametre
extern char sendBuff[1024];
extern char recvBuff[1024];
extern int sBufflen;
extern int rBufflen;

extern int h_errno;
extern char remoteIP[16];
extern int port  ;
extern struct sockaddr_in client;
extern int cSocket;
extern int addr_len ;


extern GtkWidget * myWin;
extern GtkWidget * myGrid;
extern GtkWidget * ipCom;
extern GtkWidget * sButton;
extern GtkWidget * cButton;
extern GtkWidget * aButton;
extern GtkWidget * ipLabel;
extern GtkWidget * sLabel;
extern GtkWidget * rLabel;
extern GtkWidget * ipText;
extern GtkWidget * sText;
extern GtkWidget * rText;


//end of extern parametre


extern void * memset(void* ptr,int value,size_t num);
extern void interface();
extern void signalAdder();
extern void diagWin(char * ,char *);
extern void myConnect();
extern void pre_connection();
//extern void diagLogin();
extern void aboutInfo();

extern void click_send();
extern void click_ip();
extern void click_clear();
#endif // _SOURCES_H
