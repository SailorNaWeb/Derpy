// NOTE: This file is only for testing the socket

#include <iostream>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>

    void startWinBs() {
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
	    fprintf(stderr, "WSAStartup failed.\n");
	    exit(1);
	}

	if (LOBYTE(wsaData.wVersion) != 2 ||
	    HIBYTE(wsaData.wVersion) != 2)
	{
	    fprintf(stderr,"Version 2.2 of Winsock not available.\n");
	    WSACleanup();
	    exit(2);
	}
    }

#elif __UNIX__
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
#endif

int main() {
#ifdef _WIN32
    startWinBs();
#endif
    
    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;     
    hints.ai_socktype = SOCK_STREAM; 

    // conecta
    status = getaddrinfo("localhost", "3490", &hints, &servinfo);
}
