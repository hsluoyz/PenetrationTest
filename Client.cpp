#include "Client.h"

//The default constructor
Client::Client()
{
	//do nothing
}

//Another constructor, create a connection to the server 
Client::Client(char* ip, int port)
{
	if (InitSocket())
	{
		mSock = socket(AF_INET, SOCK_STREAM, 0);
		mAddrSrv.sin_addr.S_un.S_addr=inet_addr(ip);
		mAddrSrv.sin_family=AF_INET;
		mAddrSrv.sin_port=htons(port);
		int ret = 0;
		ret = connect(mSock, (SOCKADDR*)&mAddrSrv, sizeof(SOCKADDR));
	}
}

//Initialize the socket
bool Client::InitSocket()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int errMessage;
	wVersionRequested = MAKEWORD( 1, 1 );
	errMessage = WSAStartup(wVersionRequested, &wsaData);
	if (errMessage != 0)
	{
		return false;
	}
	 if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 )
	{
		 WSACleanup();
		 return false;
	}
	return true;
}

//Send message to the server throught the connection that have created
bool Client::Send(char* message)
{
	int ret = 0;
	ret = sendto(mSock, message, strlen(message) + 1, 0, (SOCKADDR*)&mAddrSrv, sizeof(SOCKADDR));
	if (ret < 0)
	{
		return false;
	}
	return true;
}

//Another function to send message
bool Client::Send(std::string message)
{
	int ret = 0;
	ret = send(mSock, message.c_str(), message.size() + 1, 0);
	if (ret < 0)
	{
		return false;
	}
	return true;
}

//Recive message from the server
int Client::Recive(char* buffer)
{
	int reply = 0;
	sockaddr_in recvaddr;
	while (true)
	{
		reply = recv(mSock, buffer, BUFFER, 0);
		if (reply > 0)
		{
			break;
		}
	}
	
	return reply;
}

//Destructor
Client::~Client()
{
	 closesocket(mSock);
	 WSACleanup();
}