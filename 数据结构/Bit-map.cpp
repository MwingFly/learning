//����Bit-map��Ҫ���ܹ���ʾ�����ֵΪ10,000,000
//˼·��һ�������ܱ�ʾ32λ��10000000/32�õ�Ҫ���ٸ�����
//���ڲ����ܸպ��ܱ�32����������Ҫ���һ����������ʾ10000000
#if 0
#include<iostream>
using namespace std;
#define BITWORD 32
#define SHIFT 5  //һ��������5λ���൱�ڳ���32
#define MASK 0x1F  //���룬ȷ��һ����Ҫ��ʾ��һ��32λ����һλ�ϣ�����0~31
#define N 10000000
int a[1+N/BITWORD];   //����һ����С���ܱ�ʾ10000000������
void set(int count)  //���ñ�ʾ��count�Ķ�ӦλΪ1��count>=0
{
	a[count>>SHIFT] |= ( 1<<( count & MASK ) );  
	//count>>SHIFT�õ�countҪ�������������һ��int�У�count&MASK
	//�õ��ڸ�int�У���һλҪ��1��MASK = 0x1F��
	//���|=����Ҫ��Ϊ1��λ
}
void clr(int count)  //����ʾcount��λ��0
{
	a[count>>SHIFT] &= ~( 1<<( count & MASK ) );
}
bool test(int count)  //���ر�ʾcount�Ķ�Ӧλ��״̬
{
	return !!(a[count>>SHIFT] & ( 1<<( count & MASK ) ));
}

int main()
{
	set(10);
	set(20);
	cout<<test(10)<<" "<<test(20)<<" "<<test(30)<<endl;
	clr(10);
	clr(11);
	cout<<test(10)<<" "<<test(20)<<" "<<test(30)<<endl;
	cout<<test(11)<<endl;
	system("pause");
}
#endif
//1 1 0
//0 1 0
//0
//�밴���������. . .