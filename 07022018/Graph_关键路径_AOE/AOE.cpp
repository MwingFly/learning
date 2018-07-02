#include"AOE.h"
namespace meihao
{
	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr)
	{
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = new VertexNode[vertexNum]();  //�������鿪�ٿռ�
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
				if(0!=g.getGraphEdgeWeight(idx,iidx))
				{
					edgeNode* tmp = new edgeNode();
					tmp->vertexIdx = iidx;
					tmp->weight = g.getGraphEdgeWeight(idx,iidx);
					tmp->next = vertexArr[idx].firstEdge;
					vertexArr[idx].firstEdge = tmp;
				}
			}
		}
	}

	int TopologicalSort_AOV(const meihao::Graph& g,vertexNode*& vertexArr,int* etv,stack<int>& AOV)
	{
		if(!AOV.empty())
			return -1;   //��������AOV�����ǿյ�
		stack<int> zeroInputDegreeVertex;
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = nullptr;
		initDataStruct(g,vertexArr);

		//���Ϊ0�Ķ�����ջ
		for(int idx=0;idx!=vertexNum;++idx)
		{
			if(0==vertexArr[idx].in)
				zeroInputDegreeVertex.push(idx);
		}
		//��ʼ��elv,ÿ����������翪ʼʱ��,ȫ��Ϊ0
		for(int idx=0;idx!=vertexNum;++idx)
		{
			etv[idx] = 0;
		}
		//���������������
		int cnt = 0;
		cout<<"��������";
		while(!zeroInputDegreeVertex.empty())
		{
			int idx = zeroInputDegreeVertex.top();
			cout<<vertexArr[idx].data<<" "; //���һ����Ϊ0�Ķ���
			zeroInputDegreeVertex.pop();
			AOV.push(idx);  //������
			++cnt;
			for(edgeNode* node = vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				if( (etv[idx]+node->weight) >
					 etv[node->vertexIdx] )
				{ //�ӵ�һ�����Ϊ0�ĵ㣬Ҳ����Դ�㣬�Ϳ��Կ�ʼ�����Դ��������Ե���ĵ��elv��
					etv[node->vertexIdx] = etv[idx]+node->weight;
				}
				--(vertexArr[node->vertexIdx].in);
				if(0==vertexArr[node->vertexIdx].in)
					zeroInputDegreeVertex.push(node->vertexIdx);  
				//����Ƚ����⣬node->vertexIdx == vertexArr[node->vertexIdx].data
			}
		}
		cout<<endl;
		if(cnt==vertexNum)
			return 0;
		else 
			return -1;
	}

	void CriticalPath_AOE(const meihao::Graph& g)
	{
		int vertexNum = g.getGraphVertexNumber();
		stack<int> AOV;
		int* etv = new int[vertexNum];  //�����ʾ���¼������翪ʼʱ������
		vertexNode* vertexArr = nullptr;
		int ret = TopologicalSort_AOV(g,vertexArr,etv,AOV);
		if(-1==ret)
		{
			cout<<"TopologicalSort_AOV error!"<<endl;
			return ;
		}
		//���ݵõ���AOE�������������������ltv,  �����ʾ���¼�������ʼʱ������
		int* ltv = new int[vertexNum];
		for(int idx=0;idx!=vertexNum;++idx)
		{
			ltv[idx] = etv[vertexNum-1];
		}
		while(!AOV.empty())
		{
			int vertexIdx = AOV.top();
			for(edgeNode* node = vertexArr[vertexIdx].firstEdge;nullptr!=node;node=node->next)
			{
				if( ltv[vertexIdx] >
					ltv[node->vertexIdx]-node->weight )
					ltv[vertexIdx] = ltv[node->vertexIdx]-node->weight;
			}
			AOV.pop();
		}
		/* test etv �� ltv */
		cout<<"etv"<<" ";
		for(int idx=0;idx!=vertexNum;++idx)
		{
			cout<<etv[idx]<<" ";
		}
		cout<<endl;
		cout<<"ltv"<<" ";
		for(int idx=0;idx!=vertexNum;++idx)
		{
			cout<<ltv[idx]<<" ";
		}
		cout<<endl;
		//�����Ѿ��õ���etv��ltv�ˣ����Ա���ͼ�����ж��㣬����etv��ltv�����Ӧ����֮��Ļ��ete��lte
		cout<<"�ؼ�·����";
		for(int idx=0;idx!=vertexNum;++idx)
		{//��0�Ŷ��㿪ʼ���ж�0�ſ��Ե�����������֮��Ļ
			for(edgeNode* node=vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				//ete ����翪ʼʱ�䣬<idx,node,vertexIdx>, ete = etv[idx]
				int ete = etv[idx];
				//lte �����ʼʱ�䣬<idx,node,vertexIdx>, lte = ltv[node->vertexIdx] - <idx,node,vertexIdx>
				int lte = ltv[node->vertexIdx] - node->weight;
				if(ete==lte)  //��ȣ��ؼ�·�����ؼ��
				{
					cout<<"<"<<idx<<","<<node->vertexIdx<<">="<<g.getGraphEdgeWeight(idx,node->vertexIdx)<<" ";
				}
			}
		}
		cout<<endl;
		//�ͷ��ڼ俪�ٵĶ�̬�ڴ�
		stack<edgeNode*> edgeNodeAddr;
		for(int idx=0;idx!=vertexNum;++idx)
		{
			for(edgeNode* node=vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				edgeNodeAddr.push(node);
			}
			while(!edgeNodeAddr.empty())
			{
				delete edgeNodeAddr.top();
				edgeNodeAddr.top() = nullptr;
				edgeNodeAddr.pop();
			}
		}
		for(int idx=0;idx!=vertexNum;++idx)
		{
			delete []vertexArr;
			vertexArr = nullptr;
		}
		delete []etv;
		etv = nullptr;
		delete []ltv;
		ltv = nullptr;
	}
};