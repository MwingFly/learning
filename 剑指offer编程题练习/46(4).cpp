//��Ŀ46����1+2+3+����+n��Ҫ����ʹ�ó˳�����for,while,if,else,switch,case�ȹؼ��ּ������ж����(A?B:C)
//˼·��
//�ⷨ�ģ�����ģ���ģ���ػ���ʵ�ֵݹ�
#include<iostream>
using namespace std;
template<int num>  //ȱ�㣬ģ������Ͳ������ʽ������int���ͣ�����һ������
struct sum
{
	static const int Sum = num + sum<num-1>::Sum; //�����Ǿ�̬�ģ���Ҫ�ǳ���������sum<num-1>::Sum���ܵ���
};
template<>  //ģ���ػ����ݹ����
struct sum<1>
{
	static const int Sum = 1;  //�Ҽǵ�c++11�������������ǿ��Ը���ֵ��
	//ֻ�о�̬�������Ͳ����������渳ֵ
};
int main()
{
	int n = 100;
	sum<100> b;
	cout<<b.Sum<<endl; 
}
//5050

template<int num>
struct sum
{
	//enum Sum {N = num + sum<num-1>::Sum::N};
	enum Sum {N = num + sum<num-1>::N};  //���д��
};
template<>
struct sum<1>
{
	enum Sum{ N=1 };   //ö����һ�����ͣ�enum
};
int main()
{
	int n = 100;
	cout<<sum<100>::N<<endl;
	system("pause");
}
#endif
//5050

