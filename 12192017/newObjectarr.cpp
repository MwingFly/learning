 ///
 /// @file    newObjectarr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 17:10:23
 ///
 
#include <iostream>
#include<stdlib.h>
using namespace std;

class point
{
private:								//private���ݳ�Ա�б�
	int x;
	int y;

public:
	point(int xp=0,int yp=0)			//���캯������ȱʡ����ֵ
	{
		x=xp;
		y=yp;
		cout<<"point(int,int)"<<endl;
	}
	~point()							//��������
	{
		cout<<"~point()"<<endl;
	}
	void print()						//��Ա���������ڲ�ʵ��
	{
		cout<<"x:  "<<x<<", y:  "<<y<<endl;
	}
};

int main()
{
	point* p = new point(4,5);	//��̬����һ���ڴ棬�洢point����󣬲�����ַ��ֵ��point��ָ��p
	p->print();					//ʹ��ָ��ӣ�>���ó�Ա����
	delete p;					//�ͷŶ�̬������ڴ棬��ֹ�ڴ�й¶
	p=NULL;						//��������ϰ�ߣ���ֹҰָ��

	point *pp = new point[3];	//��ʱ��ᷢ�ַ�����28���ֽڵ��ڴ�ռ䣬������ʼ��4���ֽڵ��ڴ�ռ䣬���3
	pp[0] = point(1,2);   //ֻ��������ʼ��
	pp[1] = point(3,4);
	pp[2] = point(5,6);
	delete[] pp;
	return 0;
}
//point(int,int)
//x:  4, y:  5
//~point()
//point(int,int)
//point(int,int)
//point(int,int)
//point(int,int)
//~point()
//point(int,int)
//~point()
//point(int,int)
//~point()
//~point()
//~point()
//~point()
