 ///
 /// @file    Epoll.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-13 14:55:07
 ///
 
#ifndef __EPOLL_H__
#define __EPOLL_H__
#include<iostream>
#include"TcpConnection.h"
#include<vector>
#include<sys/epoll.h>
#include<map>
using namespace std;
namespace meihao
{
	class Epoll
	{
		public:
			Epoll(int sfd);
			void loop();
			void unloop();
			void waitEpollfd();
			//在epoll类中用函数设置TcpConnection类中的私有变量
			void epollSetConnectionCallback(TcpConnectionCallback cb);
			void epollSetMessageCallback(TcpConnectionCallback cb);
			void epollSetCloseCallback(TcpConnectionCallback cb);
		private:
			void handleConnection();  //epoll处理新连接的客户端
			void handleMessage(int connfd);  //处理消息
			bool isConnected(int connfd);  //查看描述符是否断开
		private:
			int _efd;  // epoll_create得到的fd
			int _sfd;  // sockfd,用来监听客户端请求
			bool _isLooping;  // 是否还在监听客户端请求
			vector<struct epoll_event> _events;  //存放epoll_wait返回的监听描述符事件数组
			map<int,TcpConnectionPtr> _mapConnections;  // 存放所有客户端请求的描述符和对应的智能指针
			
			TcpConnectionCallback _onConnectionCb;  // 为监听到的客户端设置连接的回调函数
			TcpConnectionCallback _onMessageCb;
			TcpConnectionCallback _onCloseCb;
	};
};
#endif
