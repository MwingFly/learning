#ifndef __AOE_H__
#define __AOE_H__
#include"Graph.h"
#include<iostream>
#include<stack>
namespace meihao
{
	//�߱���
	typedef struct EdgeNode
	{
		int vertexIdx;  //�ڽӵ��򣬴�Ÿý���ڶ���������е��±�
		int weight;  //��Ŷ�Ӧ���㵽�ñ߱���ı��ϵ�Ȩֵ
		struct EdgeNode* next;  //�����һ���߱����λ��
	}edgeNode,*pEdgeNode;

	//�������
	typedef struct VertexNode
	{
		int in;  //�������
		int data;  //�����룬��Ŷ���������Ϣ
		edgeNode* firstEdge;
	}vertexNode,*pVertexNode;

	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr); 
	//����ͼ����ʼ��������Ҫ�Ķ�������Ͷ�Ӧ�ı߱�

	int TopologicalSort_AOV(const meihao::Graph& g,vertexNode*& vertexArr,int* elv,stack<int>& AOV); //�ɹ�����0��ʧ�ܷ���-1
	//����������м����elv,����������������������
	//���������������������ؼ�·��Ҫ��������ltv

	void CriticalPath_AOE(const meihao::Graph& g);
};
#endif