//��Ŀ46����1+2+3+����+n��Ҫ����ʹ�ó˳�����for,while,if,else,switch,case�ȹؼ��ּ������ж����(A?B:C)
//˼·��
//�ⷨһ������C++���ԣ��ڹ��캯����++
#if 0
#include<iostream>
using namespace std;
class sum
{
public:
	sum()
	{
		++_num;
		_sum += _num;
	}
	static int getSum()
	{
		return _sum;
	}
private:
	static int _num;
	static int _sum;
};
int sum::_num = 0;
int sum::_sum = 0;
void fun1(int n)
{
	sum* arr = new sum[n];  //����n�����󣬾ͻ����n�ι��캯��
	cout<<sum::getSum()<<endl;
	delete []arr;
	arr = NULL;
}
int main()
{
	int n = 100;
	fun1(n);
	system("pause");
}
#endif
//5050