#ifndef __AOV_H__
#define __AOV_H__
#include<iostream>
#include"Graph.h"
namespace meihao
{
	//�߱���
	typedef struct EdgeNode
	{
		int vertexIdx;  //�ڽӵ��򣬴�Ÿý���ڶ���������е��±�
		struct EdgeNode* next;  //�����һ���߱����λ��
	}edgeNode,*pEdgeNode;

	//�������
	typedef struct VertexNode
	{
		int in;  //�������
		int data;  //�����룬��Ŷ���������Ϣ
		edgeNode* firstEdge;
	}vertexNode,*pVertexNode;

	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr);  //����ͼ����ʼ��������Ҫ�Ķ�������Ͷ�Ӧ�ı߱�
	
	int TopologicalSort_AOV(const meihao::Graph& g);  //�ɹ�����0��ʧ�ܷ���-1
};
#endif