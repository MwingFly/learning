//��Ŀ46����1+2+3+����+n��Ҫ����ʹ�ó˳�����for,while,if,else,switch,case�ȹؼ��ּ������ж����(A?B:C)
//˼·��
//�ⷨ���������麯��������ģ��ݹ�
#if 0
#include<iostream>
using namespace std;
class A;
static A* arr[2];
class A
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};
class B:public A
{
	virtual int sum(int n)
	{
		return n + arr[!!n]->sum(n-1);  //���n>0��!!n = 1�����n==0��!!n = 0;   //ģ���˵ݹ�
		//�麯��ʵ���˶�̬��̬��
	}
};
int main()
{
	arr[0] = new A;
	arr[1] = new B;
	int n = 100;
	cout<<arr[1]->sum(n)<<endl;
	system("pause");
}
#endif
//5050