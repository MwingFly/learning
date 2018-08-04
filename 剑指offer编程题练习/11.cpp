//��һ��double���͵�����double�η�
//1��0���κδη�û�����壬���Ϊ0��1������
//2������η��Ǹ���������0�ĸ����η����Ҫ�󵼻����0
//3��������ô�жϣ� ����ֵ��ȫ�ֱ������쳣
#include<iostream>
using namespace std;
bool powerFlag = false;  //ȫ�ִ����־λ
double power(double base,double exponent);
bool equal(double num1,double num2); //�ж�����double���͵����ǲ������
double unsignedPower(double base,unsigned int absExponent);  //��power����������봦�������дη�����
void test(double base,double exponent,double expected); 
#if 0
int main()
{
	test(4.0,2.0,16.0);
	test(0.0,-1,-1);
	test(2.0,-2,0.25);
	system("pause");
}
#endif 
double power(double base,double exponent)
{
	if(equal(base,0.0)&&exponent<0)  // 2������Ϊ0���η����� ʧ��
	{
		powerFlag = true;  //�޸ı�־λ������-1
		return -1;
	}
	unsigned int absExponent;
	absExponent = exponent;
	if(exponent<0)  //���������С��0ȡ����
		absExponent = (unsigned int)(-exponent);
	double result = unsignedPower(base,absExponent);
	if(exponent<0)
		return 1.0/result;
	return result;
}
bool equal(double num1,double num2)
{
	if((num1-num2)<0.0000001&&(num1-num2)>-0.0000001)
		return true;
	else
	{
		return false;
	}
}
double unsignedPower(double base,unsigned int absExponent)  //ż���η�eg��(2,4)=(2,2)=(2,1)==2,�ݹ���ڷ�������ִ��
	//�����η����һ��base
{
	if(0==absExponent)  //������0��0�η�����1
		return 1;
	else if(1==absExponent)
		return base;
	int res = unsignedPower(base,absExponent>>1);  //���ƺ������ ϸ��Ҫ���߱��ˣ�������ע�⵽
	res *= res;
	if(absExponent&0x1==1)  //�η�Ϊ����   
		res *= base;  
	return res;
}
void test(double base,double exponent,double expected)
{
	if(power(base,exponent)!=expected)
		cout<<"fail"<<endl;
}