//��������n,��˳���ӡ����1������nλʮ��������
//��������3����ӡ1��2��3^999
//����:������ܴ󣬴�long int���޷�����
#if 0
#include<iostream>
#include<string.h>
using namespace std;
int printMaxNum(int n);
bool increaseCarry(char* num);  //�ַ�����ʾ������1�Ƿ��λ��O(1)ʱ�临�Ӷ��ڵõ��Ƿ��ӡ���������
void print(char* num);  //��ӡ����
void test(int n);
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
int printMaxNum(int n)
{
	if(n<=0)
		return -1;
	char* num = new char[n+1];
	memset(num,'0',n+1);   //����ע�Ⱑ ����̬���� ������sizeof��
	num[n] = '\0';  //***�ַ�����β��
	while(!increaseCarry(num))  //�������ĩβ��ʼ+1û�н�λ����ӡ�������ʾ��ӡ��������ˣ�����ѭ��
	{
		print(num);
	}
	delete num;
	return 0;
}
bool increaseCarry(char* num)
{
	int carryFlag = 0;  //+1���ܲ����Ľ�λ��־
	bool owerFlow = false;  //�����־λ
	int total = 0;
	int len = strlen(num);
	for(int idx = len-1;idx>=0;--idx)
	{
		total = num[idx] - '0' + carryFlag;  //ĩβת����ʮ��������
		if(len-1==idx)
			total++;  //ĩβ��һ����
		if(total>=10)  //��λ
		{
			if(0==idx)//��λ���������λ
			{
				owerFlow = true;
				return owerFlow;
			}
			total -= 10;
			num[idx] = total + '0';
			carryFlag = 1;
		}
		else 
		{
			num[idx] = total + '0';
			break;
		}
	}
	return owerFlow;
}
void print(char* num)
{
	int len = strlen(num);
	for(int idx = 0 ;idx!=len;++idx)
	{
		if(num[idx]=='0')
			continue;
		printf("%s\t",num+idx);  
		break;
	}
}
void test(int n)
{
	printMaxNum(n);
}
#endif