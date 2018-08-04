//��Ŀ40��һ�����������������������֮�⣬���������ֶ����������Ρ��ҳ�������ֻ������һ�ε����֡�
//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1);
//eg��{2,4,3,6,3,2,5,5}->4,3
//˼·�������뵽����һ����������ֻ��һ�����ֳ���һ�Σ��������������֣����ʱ����������^��O(n)ʱ�临�Ӷ�����������
//��������������ͬ��Ҳ����������������յĽ������������������������ҵ����ҳ���һ��1��Ȼ���ڰ�������з��顣
//����������һλΪ1�ĺͲ�Ϊ1�ģ���������ͬ�����ͱ������ֿ����ٲ����������ҳ���
//��һ���Ż�����һλΪ1����ִ����������Ϊ0����ִ�������������ֱܷ�õ���������ʡȥ���������
#include<iostream>
using namespace std;
int findAppearOnceNumber(int* arr,int length,int& num1,int& num2);
int findFirstOneBit(int num);  //���ҵ����ҵ���һ��bitΪ1��λ
bool isBitOne(int num,int bitNumber);  //�ж����Ķ����Ʊ�ʾ��ĳһλ�ǲ���1
void test(int* arr,int length);
int main()
{
	int arr[] = {2,4,3,6,3,2,5,5};  //��������
	test(arr,8);
	cout<<endl;

	int arr2[] = {1,2};
	test(arr2,2);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,0);
	cout<<endl;
}
void test(int* arr,int length)
{
	int num1,num2;
	findAppearOnceNumber(arr,length,num1,num2);
	cout<<num1<<" "<<num2<<endl;
}
int findAppearOnceNumber(int* arr,int length,int& num1,int& num2)
{
	if(NULL==arr||length<=0)
	{
		num1 = -1;
		num2 = -1;
		return -1;
	}
	num1 = 0,num2 = 0;  //���������ã��ȳ�ʼ��
	int result = 0;
	for(int idx=0;idx!=length;++idx)
		result ^= arr[idx];
	int firstBitOne = findFirstOneBit(result);
	for(int idx=0;idx!=length;++idx)
	{  
		if(isBitOne(arr[idx],firstBitOne))   //if else ��ͬ������ֳ��������ˣ�һ������ĳһָ��λΪ1������һ������ĳһָ��λΪ0������
		{//�ҵ��Ķ�ӦλΪ1
			num1 ^= arr[idx];
		}
		else 
		{
			num2 ^= arr[idx];
		}
	}
	return 0;
}
int findFirstOneBit(int num)
{
	int cnt = 0;
	while( (num&1)==0 && cnt!=(8*sizeof(int)) )  //�ҵ����ҵ���ĵ�һ��1
	{
		num = num>>1;
		++cnt;
	}
	return cnt;
}
bool isBitOne(int num,int bitNumber)
{
	if(bitNumber<0)
		return false;
	num = num>>bitNumber;
	return num&1;
}
//6 4
//
//1 2
//
//-1 -1
