//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
//���ܰ��СQ��
//
//��������:
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.
//  
//
//�������:
//
//����ÿ�����ݣ������λ����ַ�����
//
//��������1:
//
//AkleBiCeilD
//
//�������1:
//
//kleieilABCD
#if 0
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{
	string data;
	queue<string> answer;
	while(cin>>data)
	{
		string tmp(data);
		int iidx = 0;
		for(int idx=0;idx!=data.size();++idx)
		{
			if(data[idx]>='a'&&data[idx]<='z')
				tmp[iidx++] = data[idx];
		}
		for(int idx=0;idx!=data.size();++idx)
		{
			if(data[idx]>='A'&&data[idx]<='Z')
				tmp[iidx++] = data[idx];
		}
		data = tmp;
		answer.push(data);
	}
	while(!answer.empty())
	{
		cout<<answer.front()<<endl;
		answer.pop();
	}
	//system("pause");
}
#endif