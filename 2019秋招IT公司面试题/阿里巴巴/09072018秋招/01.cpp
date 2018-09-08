#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;
void func(multimap<int,vector<string> >& subWords,string input,set<string>& inputWords);
int main()
{
	//¼������
	string input;
	cin>>input;
	int cnt;
	cin>>cnt;
	set<string> word;
	while(cnt)
	{
		string tmp;
		cin>>tmp;
		word.insert(tmp);
		--cnt;
	}
	//�ַ����п��Է�Ϊ��Щ����
	set<string> inputWords;
	for(int idx=0;idx!=input.size();++idx)
	{
		string copyInput = input.substr(idx);
		for(int iidx=0;iidx<=copyInput.size();++iidx)
		{
			string tmp = copyInput.substr(0,iidx);
			if(word.find(tmp)!=word.end())
			{
				inputWords.insert(tmp);
			}
		}
	}
	//������Щ�������ƴ�ճ�Դ�ַ���
	multimap<int,vector<string> > subWords;
	func(subWords,input,inputWords);
	//�õ������ַ��������п�����Ͻ���Լ�ֵ���ҳ�����
	//���Խ��
	int max = 0;
	for(auto it = subWords.begin();it!=subWords.end();++it)
	{
		if(it->first>max)
			max = it->first;
	}
	auto it = subWords.equal_range(max);
	int maxSize = 0;
	multimap<int,vector<string> >::iterator ans;
	auto iit = it.first;
	for(;iit!=it.second;++iit)
	{
		if((iit->second)[0].size()>maxSize)
		{
			maxSize = (iit->second)[0].size();
			ans = iit;
		}
	}
	for(auto elem:iit->second)
		cout<<elem<<" ";
	cout<<endl;
	system("pause");
}
void func(multimap<int,vector<string> >& subWords,string input,set<string>& inputWords)
{
	static vector<string> rightWords;
	if(input.size()==0)
	{
		int cnt ;
		for(auto elem:rightWords)
		{
			cnt = (elem.size())*(elem.size());
		}
		subWords.insert(::make_pair(cnt,rightWords));
		rightWords.clear();
		return;
	}
	for(int idx=1;idx<=input.size();++idx)
	{
		string tmp = input.substr(0,idx);
		if(inputWords.find(tmp)!=inputWords.end())
		{
			rightWords.push_back(tmp);
			func(subWords,input.substr(idx),inputWords);
		}
	}
}