#if 0
#include<iostream>
#include<set>
using namespace std;
typedef struct Node
{
	int a;
	int b;
	int c;
}node;
bool isUnqualified(const node& a ,const node& b)
{
	if(a.a<b.a&&a.b<b.b&&a.c<b.c)
		return true;  //���ϸ�
	return false;  //�ϸ�
}
int main()
{
	int cnts;
	cin>>cnts;
	node* arr = new node[cnts];
	for(int idx=0;idx<cnts;++idx)
	{
		node tmp;
		cin>>tmp.a>>tmp.b>>tmp.c;
		arr[idx] = tmp;
	}
	//���㲻�ϸ���
	int badCnts = 0;
	set<int> badGoods;
	for(int idx=0;idx<cnts;++idx)
	{
		for(int jdx=0;jdx<cnts;++jdx)
		{
			if(idx==jdx||badGoods.find(idx)!=badGoods.end())
				continue;
			if(isUnqualified(arr[idx],arr[jdx]))  //idx���ϸ�
			{
				++badCnts;
				badGoods.insert(idx);
				break;
			}
		}
	}
	cout<<badCnts<<endl;
	//system("pause");
}
#endif