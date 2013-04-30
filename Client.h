#ifndef _CLIENT_H
#define _CLIENT_H

#include <stdio.h>
#define WIN32_LEAN_AND_MEAN
#include <Winsock.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")
class Client
{
public:
	Client();
	Client(char* ip, int port);
	virtual ~Client();
	bool InitSocket();
	bool Send(char* message);
	bool Send(std::string message);
	int Recive(char* buffer);
private:
	SOCKET mSock;
	SOCKADDR_IN mAddrSrv;
	enum {BUFFER=10000};
};
#endif
