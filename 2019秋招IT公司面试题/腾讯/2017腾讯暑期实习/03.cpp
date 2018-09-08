//СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬�����С���ж��ٶ��أ��������أ�
//
//��������:
//
// �����������������ݡ�
//
// ����ÿ��������ݣ�
//
// N - �������������n����
//
// a1,a2...an - ��Ҫ���������
//
// ��֤:
//
// 1<=N<=100000,0<=ai<=INT_MAX.
//  
//�������:
//
//����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����
//
//��������1:
//
//6
//45 12 45 32 5 6
//
//�������1:
//
//1 2
#if 0
#include<iostream>
#include<limits>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
void calculate(vector<int>& data,queue<int>& result);
int myabs(int a,int b)
{
	int tmp = a - b;
	if(tmp<0)
		return -tmp;
	return tmp;
}
int main()
{
	int cnts;
	vector<int> data;
	data.reserve(100000);
	queue<int> result;
	while(cin>>cnts)
	{
		int number;
		while(cnts)
		{
			cin>>number;
			data.push_back(number);
			--cnts;
		}
		calculate(data,result);
		data.clear();
	}
	while(!result.empty())  //emplace
	{
		cout<<result.front()<<" ";
		result.pop();
		cout<<result.front()<<endl;
		result.pop();
	}
	//system("pause");
}
void calculate(vector<int>& data,queue<int>& result)
{
	int cntMax = 0;
	int cntMin = 0;
	//for(int idx=0;idx!=data.size();++idx)  //���Ӷ�̫�ߣ����г�ʱ
	//{
	//	for(int iidx=idx+1;iidx!=data.size();++iidx)
	//	{
	//		if(myabs(data[idx],data[iidx]) > max)
	//		{
	//			cntMax = 1;
	//			max = myabs(data[idx],data[iidx]);
	//		}
	//		else if(max == myabs(data[idx],data[iidx]))
	//		{
	//			++cntMax;
	//		}
	//		if(myabs(data[idx],data[iidx]) < min)
	//		{
	//			cntMin = 1;
	//			min = myabs(data[idx],data[iidx]);
	//		}
	//		else if(min == myabs(data[idx],data[iidx]))
	//		{
	//			++cntMin;
	//		}
	//	}
	//}
	//result.push(cntMin);
	//result.push(cntMax);  
	sort(data.begin(),data.end(),[](const int& a,const int&b){return a<b;});
	if(data[0]==data[data.size()-1])  //��������ͬ�������С���0��
	{
		cntMax = cntMin = (data.size()*(data.size()-1))/2;
		result.push(cntMin);
		result.push(cntMax); 
		return ;
	}
	//��map���Ż�ͳ��
	map<int,int> dataStatistic;
	for(int idx=0;idx!=data.size();++idx)
	{
		auto it = dataStatistic.find(data[idx]);
		if(it == dataStatistic.end())  //map��û��
		{
			dataStatistic.insert(::make_pair(data[idx],1));
		}
		else 
		{
			it->second += 1;
		}
	}
	int max = numeric_limits<int>::min();
	int min = numeric_limits<int>::max();
	if(dataStatistic.size()<data.size())  //���ظ�����
	{
		auto it = dataStatistic.begin();
		//������С��ֵ��
		for(it;it!=dataStatistic.end();++it)
		{
			if(it->second>1)
			{
				cntMin += ((it->second)*(it->second-1))/2;
			}
		}
	}
	else
	{  //�Ѿ��ź�����
		for(int idx=1;idx!=data.size();++idx)  
		{
				if(myabs(data[idx],data[idx-1]) < min)
				{
					cntMin = 1;
					min = myabs(data[idx],data[idx-1]);
				}
				else if(min == myabs(data[idx],data[idx-1]))
				{
					++cntMin;
				}
		}
	}
	//��������ֵ��
	int val1 = ( dataStatistic.find(data[data.size()-1]) )->second;
	int val2 = ( dataStatistic.find(data[0]) )->second;
	cntMax = (val1*val2);
	result.push(cntMin);
	result.push(cntMax);  
	return ;
}
#endif