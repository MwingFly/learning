//��Ŀ47�����üӼ��˳����ӷ���дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��1��*��%��/���������
//˼·������������һ����λ��Ӳ������λ���ڶ��������λ������������ǰ���������ӡ�
//������ѭ����ʵ�֣�ѭ�����ھ��ǽ�λΪ0��
//eg��5+17 == 101 + 10001��Ҫ��Ӳ������λֻ�������^ ( 0,0=0; 0,1=1; 1,0=1; 1,1=0 ) 10100
//�����λ������һ����㣬1,1 = 10��ֻ����&������һλ��
//���ھ��ǽ�λΪ0����ʾ���н�λ��������
#include<iostream>
using namespace std;
int add(int num1,int num2);
void test(int num1,int num2);
int main()
{
	test(5,17);
	cout<<endl;

	test(1,2);
	cout<<endl;

	test(-1,-2);
	cout<<endl;

	test(-1,2);
	cout<<endl;

}
void test(int num1,int num2)
{
	int ret = add(num1,num2);
	cout<<ret<<endl;
}
int add(int num1,int num2)
{
	int carry = 0;
	int sum = 0;
	do
	{
		sum = num1 ^ num2;  //�ȼӣ�����λ
		carry = (num1 & num2) << 1;  //�����λ
		num1 = sum;
		num2 = carry;  //�޸�����ֵ�����е�����
	}while(num2!=0);  //��λ��Ϊ0
	return sum;
}
//22
//
//3
//
//-3
//
//1

/*
������⣺����ʹ���µı�������������������ֵ����������������a��b,Ҫ�������ǵ�ֵ
��һ�ַ��������ڼӼ���
	a = a + b;
	b = a - b;
	a = a - b;
�ڶ��ַ����������������
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
*/
#if 0
int main()
{
	int a = 3;
	int b = 4;
#if 0
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
#endif
	a = a + b;
	b = a - b;
	a = a - b;
	cout<<"a = "<<a
		<<" b = "<<b<<endl;
	system("pause");
}
//a = 4 b = 3
#endif
