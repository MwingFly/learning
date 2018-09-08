#if 0
#include <iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
static unordered_map<int,int>  data;
static list<int>  LRU;
static int capacity;
int get(int key);
void put(int key,int value);   //ȷ��Ҫ��Ҫ����
int main()
{
	vector<int > ans;

	cin>>capacity;
	char pg;
	int key,value;
	while(cin>>pg)
	{
		if('p'==pg)
		{
			cin>>key>>value;
			put(key,value);
		}
		else 
		{
			cin>>key;
			int ret = get(key);
			ans.push_back(ret);
		}
	}
	for(auto elem:ans)
		cout<<elem<<endl;
	system("pause");
}
int get(int key)
{
	auto it = data.find(key);
	if(data.end()!=it)
	{
		return it->second;
	}
	return -1;
}
void put(int key,int value)
{
	auto it = data.find(key);
	//ֻ��Ҫ����
	if(it!=data.end())
	{//����
		data[key] = value;
		for(auto iit=LRU.begin();iit!=LRU.end();++iit)
		{ 
			if(*iit==key)
			{
				LRU.erase(iit);
				LRU.push_front(key);
				return;
			}
		}
	}
	else if(data.size()<capacity)
	{//������ֵ
		data[key] = value;
		LRU.push_front(key);
		return ;
	}
	else if(data.size()==capacity)  
	{//Ҫ�滻
		int tmp = LRU.back();
		LRU.pop_back();
		LRU.push_front(key);
		data.erase(tmp);
		//������ֵ
		data.insert(::make_pair(key,value));
		return;
	}
}
#endif