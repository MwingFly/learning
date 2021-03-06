 ///
 /// @file    TcpConnection.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-07 19:11:01
 ///
 
#include"TcpConnection.h"
#include<iostream>
#include<strings.h>
#include<stdlib.h>
#include<errno.h>
#define handle_error(msg) \
	do{\
		perror(msg);\
		exit(-1);\
	}while(0);
using namespace std;
namespace meihao
{
	TcpConnection::TcpConnection(int confd):_sock(confd)
											,_sockIO(confd)
											,_localAddress(meihao::Socket::getLocalAddress(confd))
											,_peerAddress(meihao::Socket::getPeerAddress(confd))
										    ,_isShutdownWrite(false)
	{
		//剩下的回调函数使用成员函数来设置，方便使用过程中修改
	}
	TcpConnection::~TcpConnection()
	{
	}
	string TcpConnection::receive()
	{
		char buf[1024];
		bzero(buf,sizeof(buf));
		int ret = _sockIO.readline(buf,sizeof(buf));
		if(-1==ret)
		{
			handle_error("recvive");
		}
		return string(buf);
	}
};
