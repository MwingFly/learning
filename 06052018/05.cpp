//���Գ���ָ���ָ�볣��
#include<iostream>
using namespace std;
int main()
{
	int a = 1,b = 2;
	const int* p = &a;   //�ȼ��� int const *p = &a;  
	//*p = 2;  //error
	cout<<*p<<endl;
	p = &b;
	cout<<*p<<endl;
	int* const p1 = &b;
	//p1 = &a;
	cout<<*p1<<endl;
	*p1 = 3;
	cout<<*p1<<endl;
	system("pause");
}
//1
//2
//2
//3