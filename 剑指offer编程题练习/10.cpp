//����һ�����Ķ����Ʊ�ʾ���ж��ٸ�1
// ��չ��������������m��n���ж�m��������λ�任���Ա��n
// ˼·�����������1�ĸ���
#include<iostream>
using namespace std;
int num1Cnt(int n);
void test(int n,int expected);
#if 0
int main()
{
	test(13,3);  //1101 - 1 = 1100 & 1101 = 1100 - 1 = 1011 & 1100 = 1000
	test(0x7fffffff,31);
	test(0xffffffff,32);
	system("pause");
}
#endif
int num1Cnt(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n - 1) & n;  //
	}
	return count;
}
void test(int n,int expected)
{
	if(num1Cnt(n)!=expected)
		cout<<"fail"<<endl;
}