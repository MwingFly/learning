//��Ŀ29����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//eg��һ������Ϊ9������{1,2,3,2,2,2,5,4,2}.����2������5�Σ��������鳤�ȵ�һ�룬������2��
//˼·����������˼�룬�Ȼ������飬ÿһ�����ֶ���ȷ��һ��ֵ������λ�ã�������λ�������м�ľ�ֹͣ����
//����ٱ������飬�ж�����м�ֵ�ǲ��ǳ��ֵĴ����������鳤�ȵ�һ��
#include<iostream>
using namespace std;
int divide(int* arr,int left,int right);  //�������䣬���ƿ��ĵĻ���
int moreThanHalf(int* arr,int length);
bool judgeMoreThenHalf(int* arr,int length,int number);  //�жϵõ���Ԫ���ǲ�����Ĺ���
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
	int ret= moreThanHalf(arr,length);
	cout<<ret<<endl;
}
int moreThanHalf(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int middle = length>>1;
	int left = 0,right = length - 1;
	int index = divide(arr,left,right);
	while(index!=middle&&index!=-1)
	{
		if(index>middle)
		{
			right = index - 1;
			index = divide(arr,left,right);
		}
		else
		{
			left = index + 1;
			index = divide(arr,left,right);
		}
	} //��whileѭ�����ҵ����������е��м�ֵ
	int result = arr[middle];
	//�ж����ֵ�����ǲ��ǳ����˹������
	if(!judgeMoreThenHalf(arr,length,result))
		result = 0;
	return result;
}
bool judgeMoreThenHalf(int* arr,int length,int number)
{
	if(NULL==arr)
		return false;
	int times = 0;
	for(int idx=0;idx<length;++idx)
	{
		if(arr[idx]==number)
			times++;
	}
	if(times>=length>>1)
		return true;
	return false;
}
int divide(int* arr,int left,int right)
{
	if(NULL==arr||left>right)
		return -1;
	if(left==right)
		return left;
	int dLeft = left;
	int dRight = right - 1;
	int pivot = arr[left];
	while(dLeft<dRight)
	{
		while( dLeft<dRight&&arr[dLeft]<=pivot )
			++dLeft;
		while( dLeft<dRight&&arr[dRight]>=pivot )
			--dRight;
	}
	return dLeft;
}
//0
//
//1
//
//-1
//
//2
