#include"BFS.h"
#include<queue>
namespace meihao
{
	void BFSTraversal(const meihao::Graph& g)
	{//������ȱ����൱�ڲ������
		queue<int> rootNode;  //���ͼ�Ķ���
		bool* visited = new bool[g.getGraphVertexNumber()];
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			visited[idx] = false;
		}
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(false==visited[idx])  //����ý��û�з��ʵ�
			{
				//����
				cout<<g.getGraphVertexData(idx)<<" ";
				visited[idx] = true;
				rootNode.push(idx);
				while(!rootNode.empty())  //�Ѹոշ��ʵ��Ľ�����һ������ʲ������
				{
					for(int iidx=0;iidx!=g.getGraphVertexNumber();++iidx)
					{
						if(1==g.getGraphEdgeWeight(rootNode.front(),iidx)&&
							false==visited[iidx])
						{
							cout<<g.getGraphVertexData(iidx)<<" ";
							visited[iidx] = true;
							rootNode.push(iidx);
						}
					}
					rootNode.pop();  //���ȷ��ʵ�һ����������
				}
			}
		}
	}
};