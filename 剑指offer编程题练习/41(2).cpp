//��Ŀ41��չ������һ������s����ӡ�����к�Ϊs��������������(���ٺ���������)��
//��������15,1+2+3+4+5=4+5+6=7+8=15,��ӡ�����Ϊ�������������С�
//˼·���ο�40���˼·���������������У����������������1��2��������������¼�����1+2<������������¼�����ı���+1��
//�ӵ���ͬ�������Ȼ���¼������������+1�����������ڸ��������������Ӽ�¼С���ı�����
//��ֹ��������ָʾС���ı���>��������+1����2����Ϊ����������������������
#include<iostream>
using namespace std;
void findContinueSequence(int num);
void printSequence(int first,int second);
void test(int num);
int main()
{
	test(15);
	cout<<endl;

	test(7);
	cout<<endl;
}
void test(int num)
{
	findContinueSequence(num);
}
void printSequence(int first,int second)
{
	if(first>second||first<0||second<0)
		return ;
	for(int idx=first;idx<=second;++idx)
		cout<<idx<<" ";
	cout<<endl;
}
void findContinueSequence(int num)
{
	if(num<3)
		return ;
	int first = 1,second = 2;
	int sum = first + second;
	int index = (num+1)/2;
	while(first<index)  //�ȿ�ʼһֱ����second,ֱ�����ڸ�������num,Ȼ����ȥ��ȥһ����Сֵ��ֱ����Ȼ�����������
	{
		if(sum==num)
			printSequence(first,second);
		while(sum>num&&first<index) //�ӵ�sum>num
		{
			sum -= first;  //�ȼ�ȥһ����Сֵ
			++first;
			if(sum==num)
				printSequence(first,second);
		}
		++second;
		sum += second;
	}
	return ;
}
//1 2 3 4 5
//4 5 6
//7 8
//
//3 4
