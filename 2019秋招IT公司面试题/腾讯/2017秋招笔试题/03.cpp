//����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
//�磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10,�ֱ�Ϊ(5,5),(3,7)��
//��������:
//
//�������һ������n,(3 �� n < 1000)
//
//
//
//�������:
//
//�������
//
//
//��������1:
//
//10
//
//
//�������1:
//
//2
#if 0
#include<iostream>
using namespace std;
int cntPair(int num);
bool isPrim(int num);
int main()
{
	int num;
	cin>>num;
	cout<<cntPair(num);
	//system("pause");
}
int cntPair(int num)
{
	if(num<3||num>=1000)
		return 0;
	int cnt = 0;
	for(int idx=0;idx!=num;++idx)
	{
		if(isPrim(idx))
		{
			for(int iidx=idx;iidx!=num;++iidx)
			{
				if(isPrim(iidx))
				{
					if(num==idx+iidx)
						++cnt;
				}
			}
		}
	}
	return cnt;
}
bool isPrim(int num)
{
	if(num<=1||num>=1000)
		return false;
	for(int idx=2;idx!=num;++idx)
	{
		if(0==num%idx)
			return false;
	}
	return true;
}
#endif