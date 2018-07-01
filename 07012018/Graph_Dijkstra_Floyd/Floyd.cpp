#include"Floyd.h"
#include<iostream>
namespace meihao
{
	void ShortestPath_Floyd(const meihao::Graph& g,weight_vaule_type** weight,int** pathPre)
	{
		if(nullptr==weight||nullptr==pathPre)
			return ;
		//��ȡͼ�������ʼ��weight��pathPre
		int vertexCnt = g.getGraphVertexNumber();
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			for(int iidx=0;iidx!=vertexCnt;++iidx)
			{
				weight[idx][iidx] = g.getGraphEdgeWeight(idx,iidx);
				pathPre[idx][iidx] = iidx;
			}
		}
		//��ʼ����ѡ���м��㣬����weight��pathPre����
		//�м���Ϊ0ʱ�ͳ�ʼ���ľ���һ��
		for(int idx=1;idx!=vertexCnt;++idx)
		{
			for(int v=0;v!=vertexCnt;++v)
			{
				for(int w=0;w!=vertexCnt;++w)
				{
					if( (max_weight_value!=weight[v][idx] && max_weight_value!=weight[idx][w]) &&  //�����м���idx��(v,idx)��(idx,w)�����������ֵ����Ȼ�±ߵ�����жϻ����
						//max_weight_value��Ȩֵweight_vaule_type���ܱ�ʾ�����ֵ�ˣ��ټӾ����
						 weight[v][w]>(weight[v][idx] + weight[idx][w]) )
					{//����
						weight[v][w] = weight[v][idx] + weight[idx][w];
						pathPre[v][w] = pathPre[v][idx];  //pathPre[v][w] = idx,Ҳ����(v,w)Ҫ�ȵ���idx������(v,idx)����һ���͵���ģ�ҲҪ�Ⱦ���pathPre[v][idx]
						//pathPre[v][w] = idx;  //����д�����Ҫ��ǰ��õ����м����Ļ���֮��
					}
				}
			}
		}
	}

	void printPath(int vi,int vj,int vertexCnt,int** pathPre)
	{
		if(vi<0||vj<0||vertexCnt<=0||nullptr==pathPre)
			return ;
		if(vi==vj)
		{
			cout<<vi<<" ";
			return ;
		}	
		int max = vi>=vj?vi:vj;
		int min = vi<vj?vi:vj;
		cout<<min<<" ";  //����С����ʼ�㿪ʼ
		while(min!=max)
		{
			cout<<pathPre[min][max]<<" ";  //��һ��Ҫ�����ĵ�
			min = pathPre[min][max];  //������ʼ����
		}
	}
};