//��Ŀ30������n���������ҳ�������С��k��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4
//˼·��ǰ��ĸ��Ӷ�O(n),�����޸������飬�����ú������ʵ�֣����Ӷ�O(n*logn)
#include<iostream>
#include<set>
#include<functional>
using namespace std;
void findLeastElements(int* arr,int length,int k);
int main()
{
	int arr[] = {4,5,1,6,2,7,3,8};
	findLeastElements(arr,8,4);
	cout<<endl;

	int arr2[] = {4,5,1};
	findLeastElements(arr2,3,2);
	cout<<endl;

	system("pause");
}
void findLeastElements(int* arr,int length,int k)
{
	if(NULL==arr||length<=0||k>length||k<=0)
	{
		cout<<"input error!"<<endl;
		return;
	}
	multiset<int,greater<int> > leastK;
	for(int idx=0;idx!=length;++idx)
	{
		if(leastK.size()<k)
		{
			leastK.insert(arr[idx]);
		}
		else 
		{
			if(*leastK.begin()>arr[idx])
			{
				leastK.erase(*leastK.begin());
				leastK.insert(arr[idx]);
			}
		}
	}
	//multiset<int,greater<int> >::iterator it = leastK.begin();
	for(auto& elem:leastK)
		cout<<elem<<" ";
	cout<<endl;
}
//4 3 2 1
//
//4 1
