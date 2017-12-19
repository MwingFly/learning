///
/// @file    sizeofObject.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-19 15:00:04
///

#include <iostream>
using namespace std;
//64λ����ϵͳĬ�϶���ϵ����8  //sizeof(cex):  56
#pragma pack(4)
class cex
{
	private:
		int a;	//int�ͣ���һ��ϵͳ��ռ��4���ڴ��ֽ� 4
		char b;	//char�ͣ�ռ1���ڴ��ֽ�	1 
		float c;	//�����ȸ����ͣ�ռ4���ڴ��ֽ�	4+1+3+4=12
		double d;	//double�ͣ�ռ8���ڴ��ֽ�	12+8=20 ;   64λ����ϵͳĬ�϶���ϵ��8   �������12+4+8=24
		short e[5]; //short�����飬ÿ��Ԫ��ռ2���ڴ��ֽ�	2*5=10 ; 20+10=30;          24+10=34
		char & f;	//���ã�����ָ��ά��,8���ڴ��ֽ�	30+2+8=40                       34+6+8=48
		double & g; //���ã�����ָ��ά��,8���ڴ��ֽ� 40+8=48                            48+8=56
		static int h;	//static��Ա�������ڴ棬��Ӱ�쵥������Ĵ�С 0

	public:
		cex():f(b), g(d) //���캯�������ó�Ա�����ڳ�ʼ�����г�ʼ��
	{
	}
		void print()	//��Ա�����Ķ��壬��ͨ��Ա������Ӱ������С
		{
			cout << "Hello" << endl;
		}
};
//min(4,8)  ��4���룬48�պ���4�ı���
//min(8,8)  56�պ���8�ı���
int cex::h = 0;		//static��Ա�ĳ�ʼ��

int main()
{
	cex c;
	cout << "sizeof(cex):  " << sizeof(cex) << endl; //��������Ĵ�Сsizeof(cex) = 48
	return 0;
}
//sizeof(cex):  48
