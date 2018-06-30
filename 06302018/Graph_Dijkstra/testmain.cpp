#include"Graph.h"
#include<iostream>
#include"Dijkstra.h"
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	int vertexCnt = g.getGraphVertexNumber();
	int* pathPre = new int[vertexCnt]();
	weight_vaule_type* weight = new weight_vaule_type[vertexCnt]();
	meihao::ShortestPath_Dijkstra(g,pathPre,weight,vertexCnt);
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		meihao::printShortestPath(0,idx,pathPre,vertexCnt);
		cout<<"·��Ȩֵ��"<<weight[idx];
		cout<<endl;
	}
	cout<<endl;
	cout<<"ͼ����ʼ����0���յ�8�����·����";
	meihao::printShortestPath(0,8,pathPre,vertexCnt);
	cout<<"  ·��Ȩֵ��"<<weight[8]<<endl;
	delete []pathPre;
	delete []weight;
}
//0 ·��Ȩֵ��0
//0 1 ·��Ȩֵ��1
//0 1 2 ·��Ȩֵ��4
//0 1 2 4 3 ·��Ȩֵ��7
//0 1 2 4 ·��Ȩֵ��5
//0 1 2 4 5 ·��Ȩֵ��8
//0 1 2 4 3 6 ·��Ȩֵ��10
//0 1 2 4 3 6 7 ·��Ȩֵ��12
//0 1 2 4 3 6 7 8 ·��Ȩֵ��16
//
//ͼ����ʼ����0���յ�8�����·����0 1 2 4 3 6 7 8   ·��Ȩֵ��16
