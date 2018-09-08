#if 0
#include<iostream>
using namespace std;
typedef struct nextVertex
{
	int vertexNum;
	struct nextVertex* nvnext;
}Nv,*pNv;  //�߱����ݽṹ
typedef struct systemNode
{
	int inputDegree;
	int weight;
	pNv next;
}Sn,*pSn;  //��������
void traversal(pSn& arr,int idx,int& maxsum,int& currentsum,int& links);
int main(int argc,char** argv)
{
	int systems,relations;
	cin>>systems>>relations;
	Sn* arr = new Sn[systems];
	//����¼��

	int timeConsume;
	for(int idx=0;idx!=systems;++idx)
	{
		cin>>timeConsume;
		arr[idx].weight = timeConsume;
		arr[idx].inputDegree = 0;
		arr[idx].next = NULL;
	}
	int systemNum,relationNum;
	while(relations)
	{
		cin>>systemNum>>relationNum;

		Nv* nextVertex = new Nv();
		nextVertex->vertexNum = relationNum;
		nextVertex->nvnext = NULL;

		nextVertex->nvnext = arr[systemNum-1].next;
		arr[systemNum-1].next = nextVertex;
		arr[relationNum-1].inputDegree += 1;

		--relations;
	}
	//��ʼ����
	int maxSum = 0,currentsum = 0,links = 0;
	for(int idx=0;idx!=systems;++idx)
	{
		if(arr[idx].inputDegree == 0)
		{
			currentsum = arr[idx].weight;
			traversal(arr,idx,maxSum,currentsum,links);
		}		
	}
	cout<<links<<" "<<maxSum<<endl;
	for(int idx=0;idx!=systems;++idx)
	{
		for(pNv p=arr[idx].next;p!=NULL;)
		{
			pNv pCur = p;
			p=p->nvnext;
			delete pCur;
			pCur = NULL;
		}
	}
	delete []arr;
	arr = NULL;
	system("pause");
}
void traversal(pSn& arr,int idx,int& maxsum,int& currentsum,int& links)
{
	if(arr==NULL)
		return ;
	if(arr[idx].next == NULL)
	{
		links += 1;
		if(maxsum<currentsum)
			maxsum = currentsum;
		currentsum -= arr[idx].weight;
		return ;
	}
	for(pNv p = arr[idx].next;p!=NULL;p=p->nvnext)
	{
		currentsum += arr[p->vertexNum-1].weight;
		idx = p->vertexNum-1;
		traversal(arr,idx,maxsum,currentsum,links);
	}
}
#endif
//5 4
//3
//2
//10
//5
//7
//1 2
//1 3
//2 5
//4 5
//3 13