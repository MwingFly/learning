#ifndef __FLOYD_H__
#define __FLOYD_H__
#include"Graph.h"
#include<iostream>
namespace meihao
{
	void ShortestPath_Floyd(const meihao::Graph& g,weight_vaule_type** weight,int** pathPre);
	//weight�൱��D���飬pathPre�൱��P����
	void printPath(int vi,int vj,int vertexCnt,int** pathPre);
	//��ӡvi��vj�����·��
};
#endif