#include "sources.h"
#include <stdlib.h>


int main(int argc,char **argv)
{
    addr_len = sizeof( struct sockaddr_in);
    memset(sendBuff,0,1024);
    memset(recvBuff,0,1024);
    gtk_init(&argc,&argv);
    interface();
    signalAdder();
    gtk_main();

    return 0;
}
