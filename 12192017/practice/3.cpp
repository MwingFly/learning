#include<iostream>
using namespace std;
int main()
{
	int (*a)[3];
	int (*b)[3];
	int a1[3] = {1,2,3};
	int b1[2][3] = {{4,5,6},{7,8,9}};
	a = &a1;
	b = b1;
	cout<<(*a)[0]<<endl;
	cout<<*(*a+1)<<endl;
	cout<<(*(b+1))[1]<<endl;
	cout<<a1<<"   "<<*a1<<endl;
	cout<<b1<<"   "<<b1[0]<<"   "<<b1[0][0]<<endl;
	cout<<*b1<<"   "<<**b1<<endl;    //����һά����ָ�뻹Ҫȡ��ַ����ά�Ͳ�����
	system("pause");
}