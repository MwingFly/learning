///
/// @file    TcpConnection.h
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-05-07 19:00:04
///

#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__
#include<iostream>
#include"SocketIO.h"
#include"Socket.h"
#include"InetAddress.h"
#include<memory>
using namespace std;
namespace meihao
{
	class TcpConnection;
	typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
	//利用智能共享指针托管TcpConnection类型指针，这样不用考虑最后的资源释放
	typedef function<void(const TcpConnectionPtr& conn)> TcpConnectionCallback;   // 这里要为public，不然后面的Epoll类访问不到,最开始我放到类里面了，放到外面访问更方便
	//function函数对象绑定回调函数
	class TcpConnection:public std::enable_shared_from_this<TcpConnection>
	{
		//继承enable_shared_from_this,使用里面的shared_from_this()方法传递指向函数
		//本身的指针，防止出现shared_ptr误用造成多次释放或者拷贝
		public:
			TcpConnection(int confd);  // 连接到的fd
			~TcpConnection();
			string receive();
			void send(const string& msg);
			void shutdown();
			string toString();  // 输出服务器端信息和连接上的客户端的信息
	
			void setConnectionCallback(TcpConnectionCallback cb);
			void setMessageCallback(TcpConnectionCallback cb);
			void setCloseCallback(TcpConnectionCallback cb);

			void handleConnectionCallback();  // 客户端连接上后做出的操作
			void handleMessageCallback();  // 服务器端-客户端之间发送消息
			void handleCloseCallback();  // 服务器端关闭连接做出的行为
		private:
			Socket _sock;
			SocketIO _sockIO;
			InetAddress _localAddress;
			InetAddress _peerAddress;
			bool _isShutdownWrite;
			TcpConnectionCallback _onConnectionCb;  // 请求连接到服务器做出的行为
			TcpConnectionCallback _onMessageCb;  // 双方发送消息 
			TcpConnectionCallback _onCloseCb;  // 关闭链接行为
	};
};
#endif
