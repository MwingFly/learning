#include"AOV.h"
#include<stack>
namespace meihao
{
	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr)
	{
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = new vertexNode[vertexNum]();  //������������
		for(int idx=0;idx!=vertexNum;++idx)
		{
			vertexArr[idx].data = idx;
			vertexArr[idx].in = g.getInputDegree(idx);  //��ȡ���
			vertexArr[idx].firstEdge = nullptr;
		}
		for(int idx=0;idx!=vertexNum;++idx)
		{
			for(int iidx=0;iidx!=vertexNum;++iidx)
			{
				if(1==g.getGraphEdgeWeight(idx,iidx))
				{
					edgeNode* tmp = new edgeNode();
					tmp->vertexIdx = iidx;
					tmp->next = vertexArr[idx].firstEdge;
					vertexArr[idx].firstEdge = tmp;
				}
			}
		}
	}
	
	int TopologicalSort_AOV(const meihao::Graph& g)
	{
		stack<int> zeroInputDegreeVertex;
		int vertexNum = g.getGraphVertexNumber();
		vertexNode* vertexArr = nullptr;  //�������������
		initDataStruct(g,vertexArr);  //��������ߺͶ�Ӧ�ı߱�
		for(int idx=0;idx!=vertexNum;++idx)
		{
			if(0==vertexArr[idx].in)
			{
				zeroInputDegreeVertex.push(idx);
			}
		}
		//���������������
		int cnt = 0;  //ͳ��������������ĵ��������cnt��󲻵���ͼ�Ķ�������˵������AOV
		while(!zeroInputDegreeVertex.empty())
		{
			int idx = zeroInputDegreeVertex.top();
			cout<<vertexArr[idx].data<<" ";  //���һ����Ϊ0�Ķ���
			zeroInputDegreeVertex.pop();
			++cnt;
			for(edgeNode* node = vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{//ɾ����һ����Ϊ0�Ķ��㣬��Ӧ����߱��еĶ�������Ҫ��1
				
				vertexArr[node->vertexIdx].in--;
				if( 0==(vertexArr[node->vertexIdx].in) )
					zeroInputDegreeVertex.push( node->vertexIdx );
			}
		}
		if(vertexNum==cnt)
			return 0;
		else 
			return -1;
	}
};