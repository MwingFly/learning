#include<iostream>
#include<stdlib.h>
using namespace std;
void func(const int & v1, const int & v2)
{
	cout << v1 << ' ';
	cout << v2 << ' ';
}
int main1()  //ע�͵�
{
	int i = 0;
	func(++i, i++);  //�������ã��ֲ�������ջ˳���Ǵ��ҵ��󣻺����ڲ�����ľ�̬�����ǲ���ջ�ģ������ȫ�־�̬����
	//i++ �ȴ�ֵ0����+1 , ++i  = 2
	system("pause");
	return 0;
}
//2 0