//��Ŀ33������һ�����������飬������������������ƴ�������ų�һ��������ӡ����ƴ�Ӵ���������������С��һ����
//������������{3,32,321}��������������������ųɵ���С����321323��
//˼·��������Ԫ�طŵ��ַ����������棬ʹ�ÿ⺯��qsort�����������������������ַ���ƴ����һ������ƴ�ӷ�
//���յõ����ַ���С���������е�һ����321 32 2
//ʱ�临�Ӷ�O(nlogn)
#if 0
#include<iostream>
using namespace std;
int compare(const void* left,const void* right);
void MinNumber(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {3,32,321};
	test(arr,3);
	cout<<endl;

	int arr2[] = {123,312,31};
	test(arr2,3);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,1);
	cout<<endl;

	int arr4[] = {1,2,3,4};
	test(arr4,4);
	cout<<endl;

	int arr5[] = {1};
	test(arr5,1);
	cout<<endl;
	system("pause");
}
void test(int* arr,int length)
{
	MinNumber(arr,length);
}
void MinNumber(int* arr,int length)
{
	if(NULL==arr||length<=0)
	{
		cout<<"input error!"<<endl;
		return ;
	}
	int strSize = 10;
	char** twoArr = new char*[length];
	for(int idx=0;idx!=length;++idx)
	{
		twoArr[idx] = new char[strSize];
		sprintf(twoArr[idx],"%d",arr[idx]);
	}
	qsort(twoArr,length,sizeof(char*),compare);
	for(int idx=0;idx!=length;++idx)
	{
		cout<<twoArr[idx];
	}
	cout<<endl;
	for(int idx=0;idx!=length;++idx)
		delete []twoArr[idx];
	delete []twoArr;
}
int compare(const void* left,const void* right)
{
	char** pleft = (char**)(left);
	char** pright = (char**)(right);
	char* leftRight = new char[100];
	char* rightLeft = new char[100];
	strcpy(leftRight,*pleft);
	strcat(leftRight,*pright);
	strcpy(rightLeft,*pright);
	strcat(rightLeft,*pleft);
	int ret = strcmp(leftRight,rightLeft);
	delete leftRight;
	delete rightLeft;
	return ret;
}
#endif
//321323
//
//12331231
//
//input error!
//
//1234
//
//1
