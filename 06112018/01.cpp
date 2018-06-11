//��Ŀ38�����������������г��ֵĴ�����ͳ��һ�����������������г��ֵĴ�����
//����������������{1,2,3,3,3,3,4,5}������3������3����������г�����4�Σ�������4��
//˼·����������������ģ�����ʹ�ö��ֲ��ң����ҵ�һ��k���ֵ�λ�ã�Ȼ�����ҵڶ���k���ֵ�λ�á�
#include<iostream>
using namespace std;
int getFirstK(int* arr,int start,int end,int elem);
int getLastK(int* arr,int start,int end,int elem);
int appearTimes(int* arr,int length,int elem);
void test(int* arr,int length,int elem);
void test0();  //��������
void test1();  //ָ������û��
void test2();  //һ��Ԫ������
void test3();  //��ָ��
int main()
{
	test0();
	test1();
	test2();
	test3();
	system("pause");
}
void test(int* arr,int length,int elem)
{
	int cnt = appearTimes(arr,length,elem);
	cout<<elem<<" appear "<<cnt<<" times."<<endl;
}
void test0()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	for(int idx=0;idx!=8;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,8,3);
}
void test1()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	for(int idx=0;idx!=8;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,8,6);
}
void test2()
{
	int arr[] = {1};
	for(int idx=0;idx!=1;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,1,1);
}
void test3()
{
	int* arr = NULL;
	test(arr,0,0);
}
int appearTimes(int* arr,int length,int elem)
{
	if(NULL==arr||length<=0)
		return -1;  //�������뷵��-1
	int middle = (length-1)>>1;
	int start = 0;
	int end = length - 1;
	int firstK = getFirstK(arr,start,middle,elem);
	int lastK = getLastK(arr,middle+1,end,elem);
	if(firstK!=-1&&lastK!=-1)  //���ֶ��
		return lastK - firstK + 1;
	else if(firstK!=-1||lastK!=-1)  //����һ��
		return 1;
	else   //����0��
		return 0;
}
int getFirstK(int* arr,int start,int end,int elem)
{
	if(NULL==arr||start>end||start<0||end<0)
		return -1;
	int middleIndex = ((end - start)>>1) + start;
	int tmpStart = start;
	int tmpEnd = end;
	if(arr[middleIndex]==elem)
	{
		if((middleIndex>start&&arr[middleIndex-1]!=elem)||
			middleIndex==start)
			return middleIndex;
		else
			tmpEnd = middleIndex - 1;
	}
	else if(arr[middleIndex]>elem) //��ǰ�벿��
	{
		tmpEnd = middleIndex - 1;
	}
	else
	{
		tmpStart = middleIndex + 1;
	}
	return getFirstK(arr,tmpStart,tmpEnd,elem);
}
int getLastK(int* arr,int start,int end,int elem)
{
	if(NULL==arr||start>end||start<0||end<0)
		return -1;
	int middleIndex = ((end - start)>>1) + start;
	int tmpStart = start;
	int tmpEnd = end;
	if(arr[middleIndex]==elem)
	{
		if((middleIndex<end&&arr[middleIndex+1]!=elem)||
			middleIndex==end)
			return middleIndex;
		else
		{
			tmpEnd = middleIndex + 1;
		}
	}
	else if(arr[middleIndex]>elem)
	{
		tmpEnd = middleIndex - 1;
	}
	else
	{
		tmpStart = middleIndex + 1;
	}
	return getLastK(arr,tmpStart,tmpEnd,elem);
}
//1 2 3 3 3 3 4 5
//3 appear 4 times.
//1 2 3 3 3 3 4 5
//6 appear 0 times.
//1
//1 appear 1 times.
//0 appear -1 times.
