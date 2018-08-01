#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include"Graph.h"
namespace meihao
{
	void ShortestPath_Dijkstra(const meihao::Graph& g,int* pathPre,weight_vaule_type* weight,int vertexCnt);  //����pathPre������������ż���õ���ͼ��ĳһ������·��ǰ��
	//pathPre[2] = 1,��ʾV2��V1�����·����,V2ǰ��һ������V1, ...V1->V2...
	//weight�Ǵ��ָ����һ����ʼ�����ĵ���Ӧ����С��ĵ��Ȩֵ��eg:ͼ����ʼ�ĵ�V0��weight[2] = N,��ʾV0��V2�����·��Ȩֵ��ΪN
	
	//����һ���������ָ������֮������·����Ȩֵ��
	void printShortestPath(int vi,int vj,int* pathPre,int vertexCnt);
};
#endif