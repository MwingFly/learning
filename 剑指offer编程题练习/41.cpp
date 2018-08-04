//��Ŀ41������һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
//����ж�����ֵĺ͵���s���������һ�Լ��ɡ�
//eg��{1,2,4,7,11,15}������15,4+11=15���Ʒ�
//˼·����������ָ�룬һ��ָ�����鿪ͷһ��ָ���β������λ�õ�����Ӻ�����Ҫ�õ��������бȽϣ�����ƫ���ĸ�ָ��
#include<iostream>
using namespace std;
bool findNumberWithSum(int* arr,int length,int sum,int& num1,int& num2);
void test(int* arr,int length,int sum);
int main()
{
	int arr[] = {1,2,4,7,11,15};
	test(arr,6,15);
	cout<<endl;

	int arr2[] = {1,3};
	test(arr,2,3);
	cout<<endl;

	int arr3[] = {1,2,4,7,11,15};
	test(arr3,6,20);
	cout<<endl;
}
void test(int* arr,int length,int sum)
{
	int num1 = 0,num2 = 0;
	if(findNumberWithSum(arr,length,sum,num1,num2))
	{
		cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
	}
}
bool findNumberWithSum(int* arr,int length,int sum,int& num1,int& num2)
{
	if(NULL==arr||length<0)
		return false;
	bool flag = false;
	int head = 0;
	int tail = length - 1;
	num1 = 0,num2 = 0;
	while(tail>head)
	{
		if((arr[head]+arr[tail]) == sum)
		{
			flag = true;
			num1 = arr[head];
			num2 = arr[tail];
			break;
		}
		else if( (arr[head]+arr[tail]) > sum )
			--tail;
		else 
			++head;
	}
	return flag;
}
//4 + 11 = 15
//
//1 + 2 = 3
//
