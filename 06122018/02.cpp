//������44�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
//2~10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
//˼·����С�������������������ֵ������Ϊ0.�ȶ�5��������Ȼ��ͳ��0�ĸ�����
//�ڶ�������б�����������������֮��Ĳ�ֵ�Ƿ����1���������1��ͳ�������ֵ������ж������ֵ�Ƿ�
//����0���������������˵��������0�������Ӧ����ֵʹ��5���Ƶ���������������5���Ʋ��������ġ�
//�ڱ����Ĺ����������������ȣ�ֱ�ӷ���ʧ�ܡ�
//ʱ�临�Ӷ�O(n*logn)
#if 0
#include<iostream>
#include<algorithm>
using namespace std;
bool isSequence(int* arr,int length);
int compare(const void* left,const void* right);
void printArr(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {0,3,1,4,5};
	test(arr,5);
	cout<<endl;

	int arr1[] = {0,1,2,3,4};
	test(arr1,5);
	cout<<endl;

	int arr2[] = {0,1,1,3,4};
	test(arr2,5);
	cout<<endl;

	int arr3[] = {0,2,0,4,6};  //{0,0,2,4,6}
	test(arr3,5);
	cout<<endl;
	system("pause");
}
void test(int* arr,int length)
{
	printArr(arr,length);
	cout<<isSequence(arr,length)<<endl;
	printArr(arr,length);
}
void printArr(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return ;
	for(int idx=0;idx!=length;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
}
bool isSequence(int* arr,int length)
{
	if(NULL==arr||length!=5)
		return false;
	//sort(arr,arr+length);  //C++�Դ��Ĵ�С�Ƚ�
	qsort(arr,length,sizeof(int),compare);
	int zeroNum = 0;
	for(int idx=0;idx!=length;++idx)
	{
		if(arr[idx]==0)
		{
			++zeroNum;
			continue;
		}
		break;
	}
	//��ʼ�����ֵ
	int diff = 0;
	for(int idx=zeroNum;idx!=length;++idx)
	{
		if(arr[idx]==arr[idx+1])  //����������һ�����϶��Ͳ�����������
			return false;  
		diff += arr[idx+1] - arr[idx] - 1;  //������������1��
	}
	if(diff = zeroNum||
		0==diff)
		return true;
	return false;
}
int compare(const void* left,const void* right)
{
	return *(int*)left - *(int*)right;
}
#endif
//0 3 1 4 5
//1
//0 1 3 4 5
//
//0 1 2 3 4
//1
//0 1 2 3 4
//
//0 1 1 3 4
//0
//0 1 1 3 4
//
//0 2 0 4 6
//1
//0 0 2 4 6
