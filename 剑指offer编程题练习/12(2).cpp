//��������n,��˳���ӡ����1������nλʮ��������
//��������3����ӡ1��2��3^999
//����:������ܴ󣬴�long int���޷�����
// �ڶ��ֽⷨ���ݹ�
#include<iostream>
#include<string.h>
using namespace std;
int printMaxNum(int n);
int printMaxNumRecursion(char* num,int len,int idx);  //len�ǽ�����������0(��һλ��ʼ��ӡ)��idx������
//ԭ��len = 1��ѭ��10�Σ� 1~9
//len = 2; ��num[0] = 0;��ʼ���ݹ飬idx=0��num[idx+1]=0,1,2,~9,����������idx = len-1,������ӡ�ľ���00,01,02~09,��ӡ��ʱ��ȥ����ͷ��0
void print(char* num);  //��ӡ����
void test(int n);
#if 1
int main()
{
	test(1);
	cout<<endl;
	test(0);
	cout<<endl;
	test(3);
	cout<<endl;
	system("pause");
}
#endif
int printMaxNum(int n)
{
	if(n<=0)
		return -1;
	char* num = new char[n+1];
	memset(num,'0',n);
	num[n] = '\0';
	for(int idx = 0;idx<10;++idx)
	{
		num[0] = idx + '0';  //���ȴӵ�һ���ַ�����ʾ������Ϊ0��ʼ��ӡ
		printMaxNumRecursion(num,n,0);  //��һ������Ϊ0���ݹ�ȫ���д�ӡ�������
	}
	delete num;
	return 0;
}
int printMaxNumRecursion(char* num,int len,int idx)
{
	if(idx==len-1)//�ݹ����
	{//�ַ�����ʾ�������Ѿ����������һ��
		print(num);
		return 0;
	}
	for(int iidx=0;iidx<10;++iidx)
	{
		num[idx+1] = iidx + '0';  //idx����һ�����Գ��ֵ������0~9; ��0��ʼ���ٵݹ�鿴��һ�����Գ��ֵ����
		printMaxNumRecursion(num,len,idx+1);
		//eg: n = 3->000,001,002~009,010,011,����
	}
}
void print(char* num)
{
	if(NULL==num)
		return ;
	int i=0;
	while(num[i]=='0')
		++i;
	if(num[i]=='\0')
		return ;  //�ʼ��һ��0����ӡ
	printf("%s\t",num+i);
}
void test(int n)
{
	printMaxNum(n);
}