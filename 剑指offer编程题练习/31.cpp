//��Ŀ31������һ���������飬������������Ҳ�и�����������һ������������������һ�������顣
//������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
//eg������{1,-2,3,10,-4,7,2,-5}��������������Ϊ{3,10,-4,7,2}��������Ϊ��������ĺ�18��
//˼·����������������ֵ���ȼ������ֵΪ��С�ĸ���������һ��Ϊ0����sum��������ͷ��ʼ�������
//�����Ӵ���0����һ����ȥ�͵�ǰ���ֵ�Ƚϣ�����������ֵ��������ֵ��С�����������һ������Ԫ�ء�
//�����Ӻ�С��0��֤��ǰ������������鲻���������ֵ�������޸�sumΪ��һ��Ԫ�ص�ֵ������������ӡ�
//�������ֵ��¼�ľ���������ĺ͵����ֵ��
#include<iostream>
using namespace std;
int findMaxSubarray(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {1,-2,3,10,-4,7,2,-5};
	test(arr,8);
	cout<<endl;

}
void test(int* arr,int length)
{
	int result = findMaxSubarray(arr,length);
	cout<<result<<endl;
}
int findMaxSubarray(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int sum = 0;  //��¼��ǰ���ֵ
	int totalSum = 0x80000000;   //int����4���ֽڣ���С��������-128����������һ���������������Ų��룬��Ӧ�Ĳ������1000 0000 0000 0000��
	//�����Ĳ���ȡ����һΪ��Ӧ�ľ���ֵ��128�������������ʾ����-128��
	for(int idx=0;idx!=length;++idx)
	{
		if(sum<=0)
			sum = arr[idx];
		else
			sum += arr[idx];
		if(sum>totalSum)
			totalSum = sum;
	}
	return totalSum;
}
