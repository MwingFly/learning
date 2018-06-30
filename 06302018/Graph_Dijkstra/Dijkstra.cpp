#include"Dijkstra.h"
namespace meihao
{
	void ShortestPath_Dijkstra(const meihao::Graph& g,int* pathPre,weight_vaule_type* weight,int vertexCnt)
	{
		if(nullptr==pathPre||nullptr==weight||0==vertexCnt)
			return ;
		//����һ��������ÿ������Ƿ��Ѿ������·����
		int* isInShortestPath = new int[vertexCnt]();  //��ʼΪ0����ʾ����û�������·��֮��
		//Ĭ�ϴ�ͼ�е�0����㿪ʼ����ʼ��weight����ʾ0�������������·��
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			weight[idx] = g.getGraphEdgeWeight(0,idx);   //weight[idx]��ŵľ���0��idx��Ȩֵ
			pathPre[idx] = 0;  //weight�ʼ��0����Ӧ�±�ľ�������ʼ��������pathPreֻ��ȫ����0��
		}
		//����V0�������������·��
		isInShortestPath[0] = 1; 
		for(int idx=1;idx!=vertexCnt;++idx)  //V0�Ѿ���·���У�ֻҪ����һ�����㿪ʼ
		{
			int min = max_weight_value;
			int nextShortestPathVertex = 0;  //��һ�����Լӵ����·���ϵĶ���
			//��ʼ����weight�����ҵ�һ����V0���㵽��Ӧ����С�궥���������СȨֵ�ıߣ�����¼�ߵ���һ�˶���
			for(int iidx=0;iidx!=vertexCnt;++iidx)
			{
				if(0==isInShortestPath[iidx]&&
					weight[iidx]<min)
				{
					nextShortestPathVertex = iidx;
					min = weight[iidx];
				}
			}
			//�ҵ��˸����Լ��뵽���·���Ķ���
			isInShortestPath[nextShortestPathVertex] = 1;  //�޸�nextShortestPathVertexΪ1
			//�õ���һ���㣬ͨ���������Ե�һЩ�������㣬���Ǻ����·���ֻ��б仯
			//����nextShortestPathVertex������weight����
			for(int iiidx=0;iiidx!=vertexCnt;++iiidx)
			{
				/*if(0==isInShortestPath[iiidx]&&
					(weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx))<weight[iiidx])  */   
				//��������ԭ�����е�weigth��weight_vaule_type�ܱ�ʾ�����ֵ���ټӾ������
				if(0==isInShortestPath[iiidx] &&
					 g.getGraphEdgeWeight(nextShortestPathVertex,iiidx) !=max_weight_value &&     //��һ����������ֹ�����Ҳ����(nextShortestPathVertex,iiidx)֮���бߵĶ���
					 (weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx) ) < weight[iiidx] )

				//����¼������·���ĵ㵽����û�б�ǵ����·���еĵ�idx��ȨֵС��֮ǰĳ�㵽idx��Ȩֵ���Ϳ��Ը������Ȩֵ
				{
					weight[iiidx] = weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx);
					pathPre[iiidx] = nextShortestPathVertex;
				}
			}
		}
	}

	void printShortestPath(int vi,int vj,int* pathPre,int vertexCnt)
	{
		if(nullptr==pathPre||0==vertexCnt||vi<0||vj<0||vi>vj||vi>=vertexCnt||vj>=vertexCnt)
			return ;
		if(vi==vj)
		{
			cout<<vi<<" ";
			return ;
		}
		printShortestPath(vi,pathPre[vj],pathPre,vertexCnt);
		cout<<vj<<" ";
	}
};