//��Ŀ46����1+2+3+����+n��Ҫ����ʹ�ó˳�����for,while,if,else,switch,case�ȹؼ��ּ������ж����(A?B:C)
//˼·��
//�ⷨ��������C���Եĺ���ָ��ģ���麯����ʵ�ֵݹ�
#if 0
#include<iostream>
using namespace std;
typedef int (*func)(int n);
static func arr[2];
int sum1(int n)
{
	return 0;
}
int sum2(int n)
{
	return n + arr[!!n](n-1);
}
int main()
{
	arr[0] = sum1;
	arr[1] = sum2;
	int n = 100;
	cout<<sum2(n)<<endl;
	system("pause");
}
#endif
//5050