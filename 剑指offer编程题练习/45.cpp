//��Ŀ45��ԲȦ�����ʣ�µ����֡�0,1��...��n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
//ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
//eg��{0,1,2,3,4}->ÿ��ɾ������������->{2,0,4,1}->3
//˼·�������һ��Լɪ��(Josephuse)�����⣬����ģ���һ������Ȼ�����ɾ������������ñ�׼ģ��⣬ֱ��ʹ��list
//ֻ����Ҫ�ǵ���󵽴������ĩβҪ�����޸�ָ��ͷ��
//n������ÿ��ɾ����m�����֡�ʱ�临�Ӷ�O(mn)���ռ临�Ӷ�O(m)
#if 0
#include<iostream>
#include<list>
using namespace std;
//��һ������
#if 0
int lastReamining(unsigned int n,unsigned int m)
{
	if(n<1||m<1)
		return -1;
	list<int> numbers;
	for(int idx=0;idx<n;++idx)
		numbers.push_back(idx);
	list<int>::iterator current = numbers.begin();
	while(numbers.size()>1)
	{
		for(int i=1;i<m;++i)
		{
			++current;
			if(current==numbers.end())
				current==numbers.begin();
		}
		list<int>::iterator next = ++current;
		if(next==numbers.end())
			next = numbers.begin();
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}
#endif
// P248���Ƶ���ʽ
//f(n,m)��ʾ1~n��Ԫ������һ��ɾ����m��Ԫ�أ����ʣ����һ��Ԫ��
//��n=1ʱ��f(n,m) = 0;  n>1ʱ��f(n,m) = [f(n-1,m) + m]%n��
int LastRemaining(int n,int m)
{  //ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
	if(n<1||m<1)
		return -1;
	int last = 0;  //��0��ʼ����ɾ����n - 1 = 1,���ʼf(n-1,m) = 0;
	for(int i=2;i<=n;++i)  //ѭ�������ǵݹ飬���Ե����������ս�
		//���ʣ������Ԫ�أ�Ȼ��ɾ����m����ʣ��һ����
	{
		last = (last + m) % i;
	}
	return last;
}
int main()
{
	cout<<LastRemaining(5,3)<<endl;
	cout<<LastRemaining(5,2)<<endl;
	cout<<LastRemaining(6,7)<<endl;
	cout<<LastRemaining(6,6)<<endl;
	cout<<LastRemaining(0,0)<<endl;
	system("pause");
}
#endif
//3
//2
//4
//3
//-1