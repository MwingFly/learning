//��Ŀ29(�ڶ�������)����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//eg��һ������Ϊ9������{1,2,3,2,2,2,5,4,2}.����2������5�Σ��������鳤�ȵ�һ�룬������2��
//˼·������һ�����飬������ʱ�򱣴�����ֵ��һ���������е�һ�����֣�һ���Ǵ�����
//�����Ǳ�������һ�����ֵ�ʱ�������һ�����������֮ǰ�����������ͬ���������1��
//�����һ�����ֺ�����֮ǰ��������ֲ�ͬ���������1��
//�������Ϊ0�����Ǿͱ�����һ�����֣����Ѵ�������Ϊ1����������Ҫ�ҵ������ֳ��ֵĴ�������������
//���ֳ��ֵĴ���֮�ͻ�Ҫ�࣬��ôҪ�ҵ������ֿ϶������һ�ΰѴ�������Ϊ1ʱ��Ӧ�����֡�
#include<iostream>
using namespace std;
int findMoreThanHalt(int* arr,int length);
bool isMoreThanHalt(int* arr,int length,int value);
void test(int* arr,int length);
int main()
{
	int arr[] = {1,1,3,3,2,2,5,4,2};
	test(arr,9);
	cout<<endl;

	int arr1[2] = {1};
	test(arr1,1);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,0);
	cout<<endl;

	int arr4[] = {1,2,2,2};
	test(arr4,4);
	cout<<endl;

}
void test(int* arr,int length)
{
	int ret = findMoreThanHalt(arr,length);
	cout<<ret<<endl;
}
int findMoreThanHalt(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int times = 1;
	int value = arr[0];
	for(int idx = 1;idx<length;++idx)
	{
		if(times==0)
		{
			value = arr[idx];
			times = 1;
		}
		else if(arr[idx]==value)
			++times;
		else
			--times;
	}
	//���õ���value�ǲ��ǹ���
	if( isMoreThanHalt(arr,length,value) )
		return value;
	else 
		return -1;
}
bool isMoreThanHalt(int* arr,int length,int value)
{
	 if(NULL==arr)
		 return false;
	 int times=0;
	 for(int idx=0;idx!=length;++idx)
	 {
		 if(arr[idx]==value)
			 ++times;
	 }
	 if(times>length>>1)
		 return true;
	 return false;
}
//-1
//
//1
//
//-1
//
//2
