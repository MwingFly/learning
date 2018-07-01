#include"Graph.h"
#include<iostream>
#include"Dijkstra.h"
#include"Floyd.h"
#include<iomanip>
using namespace std;
void test0()   //����Dijkstra
{
	cout<<"test Dijkstra:"<<endl;
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
void test1()  //����Floyd
{
	cout<<"test Floyd:"<<endl;
	meihao::Graph g("data.txt");
	int vertexCnt = g.getGraphVertexNumber();
	int** pathPre = new int*[vertexCnt]();
	for(int idx=0;idx!=vertexCnt;++idx)
		pathPre[idx] = new int[vertexCnt]();
	weight_vaule_type** weight = new weight_vaule_type*[vertexCnt]();
	for(int idx=0;idx!=vertexCnt;++idx)
		weight[idx] = new weight_vaule_type[vertexCnt];
	meihao::ShortestPath_Floyd(g,weight,pathPre);

	cout<<"print weight matrix:"<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		for(int iidx=0;iidx!=vertexCnt;++iidx)
		{
			cout<<setw(3)<<weight[idx][iidx]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"print pathPre matrix:"<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		for(int iidx=0;iidx!=vertexCnt;++iidx)
		{
			cout<<setw(3)<<pathPre[idx][iidx]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		meihao::printPath(0,idx,vertexCnt,pathPre);
		cout<<"·��Ȩֵ: "<<weight[0][idx]<<endl;
	}
	//�ͷŶ�̬�ڴ�
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		delete []pathPre[idx];
		pathPre[idx] = nullptr;
		delete []weight[idx];
		weight[idx] = nullptr;
	}
	delete []pathPre;
	pathPre = nullptr;
	delete []weight;
	weight = nullptr;
}
int main()
{
	test0();
	cout<<endl;
	test1();
}

//test Dijkstra:
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
//
//test Floyd:
//print weight matrix:
//  0   1   4   7   5   8  10  12  16
//  1   0   3   6   4   7   9  11  15
//  4   3   0   3   1   4   6   8  12
//  7   6   3   0   2   5   3   5   9
//  5   4   1   2   0   3   5   7  11
//  8   7   4   5   3   0   7   5   9
// 10   9   6   3   5   7   0   2   6
// 12  11   8   5   7   5   2   0   4
// 16  15  12   9  11   9   6   4   0
//
//print pathPre matrix:
//  0   1   1   1   1   1   1   1   1
//  0   1   2   2   2   2   2   2   2
//  1   1   2   4   4   4   4   4   4
//  4   4   4   3   4   4   6   6   6
//  2   2   2   3   4   5   3   3   3
//  4   4   4   4   4   5   7   7   7
//  3   3   3   3   3   7   6   7   7
//  6   6   6   6   6   5   6   7   8
//  7   7   7   7   7   7   7   7   8
//
//0 ·��Ȩֵ: 0
//0 1 ·��Ȩֵ: 1
//0 1 2 ·��Ȩֵ: 4
//0 1 2 4 3 ·��Ȩֵ: 7
//0 1 2 4 ·��Ȩֵ: 5
//0 1 2 4 5 ·��Ȩֵ: 8
//0 1 2 4 3 6 ·��Ȩֵ: 10
//0 1 2 4 3 6 7 ·��Ȩֵ: 12
//0 1 2 4 3 6 7 8 ·��Ȩֵ: 16
//�밴���������. . .
