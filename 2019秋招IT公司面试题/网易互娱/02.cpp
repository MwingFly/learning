//С�����ڲ��뿪��һ����ʱ���칤�ߣ����������еĻỰ�б��֡�
//
//�Ự�б�Ϊ��ʾΪһ�����ϵ��µĶ��пؼ�������ÿһ�б�ʾһ���Ự��ÿһ���Ự��������һ��Ψһ������id��ʾ��
//
//���û���һ���Ự�з��ͻ������Ϣʱ������ûỰ�Ѿ��ڻỰ�б��У�����ԭ����λ���Ƶ��б�����Ϸ������û���ڻỰ�б��У����ڻỰ�б����Ϸ�����ûỰ��
//С��������Ҫ���Ĺ����ǲ��ԣ������ȰѻỰ�б���յȴ�������Ϣ����������������Բ�ͬ�Ự����Ϣ�󣬾������ǰ�ĻỰ�б��Լ�������Ƿ���bug��
//��������:
//
//����ĵ�һ��Ϊһ��������T��T<=10������ʾ��������������
//��������T�����ݡ�ÿ�����ݵĵ�һ��Ϊһ��������N��1<=N<=200������ʾ���յ���Ϣ�Ĵ�����
//�ڶ���ΪN������������ʱ����ȵ����˳���ʾ���յ���Ϣ�ĻỰid���Ựid������1000000000��
//
//
//
//�������:
//
//����ÿһ�����ݣ����һ�У����Ự�б���ϵ��µ�˳������Ựid��
//���ڵĻỰid��һ���ո�ָ�����ĩû�пո�
//
//
//��������1:
//
//3
//5
//1 2 3 4 5
//6
//1 100 1000 1000 100 1
//7
//1 6 3 3 1 8 1
//
//
//�������1:
//
//5 4 3 2 1
//1 100 1000
//1 8 3 6
//
#if 0
#include<iostream>
#include<deque>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int demos;
	cin>>demos;
	map<int,vector<int>> data;
	int idx = 0;
	while(idx<demos)
	{
		int messages;
		cin>>messages;
		deque<int> tmpList;
		while(messages)
		{
			int data;
			cin>>data;
			auto it = tmpList.begin();
			for(;it!=tmpList.end();++it)
			{
				if(*it==data)
					break;
			}
			if(it!=tmpList.end())
			{
				tmpList.erase(it);
			}
			tmpList.push_front(data);
			--messages;
		}
		for(auto it = tmpList.begin();it!=tmpList.end();++it)
		{
			data[idx].push_back(*it);
		}
		++idx;
	}
	for(int idx=0;idx!=demos;++idx)
	{
		int iidx = 0;
		for(;iidx!=(data[idx].size()-1);++iidx)
		{
			cout<<data[idx][iidx]<<" ";
		}
		cout<<data[idx][iidx]<<endl;
	}
	//system("pause");
}
#endif