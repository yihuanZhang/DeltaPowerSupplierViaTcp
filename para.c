#include <gtk/gtk.h>
#include <netinet/in.h>
#define RemotePort 8462

char sendBuff[1024];
char recvBuff[1024];
int sBufflen;
int rBufflen;

int h_errno;
char remoteIP[16];
int port = RemotePort ;
struct sockaddr_in client;
int cSocket;
int addr_len ;


GtkWidget * myWin;
GtkWidget * myGrid;
GtkWidget * ipCom;
GtkWidget * sButton;
GtkWidget * cButton;
GtkWidget * aButton;
GtkWidget * ipLabel;
GtkWidget * sLabel;
GtkWidget * rLabel;
GtkWidget * ipText;
GtkWidget * sText;
GtkWidget * rText;
