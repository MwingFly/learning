//��Ŀ22�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������ǲ��Ǹ�ջ�ĵ���˳��
//�����������־������,eg��1��2,3,4,5->4,5,3,2,1 true; 1,2,3,4,5->4,3,5,1,2 false
//˼·������һ���������飬ģ��ѹջ���к͵�ջ����
//���㷨ʹ�������������������У������һ�����е����ֺ͵ڶ�������������ͬ��ջ
//�㷨����жϸ���ջ�ǲ��ǿգ��Լ���ջ�����ǲ��Ǳ�����
#include<iostream>
#include<stack>
using namespace std;
bool isPopOrder(int* pushOrder,int* popOrder,int length);
void test(int* pushOrder,int* popOrder,int length);
int main()
{
	int arrPush[] = {1,2,3,4,5};
	int arrPop[] = {4,5,3,2,1};
	test(arrPush,arrPop,5);
	cout<<endl;

	int arr2Pop[] = {4,3,5,1,2};
	test(arrPush,arr2Pop,5);
	cout<<endl;

	int arr3Push[] = {1};
	int arr3Pop[] = {1};
	test(arr3Push,arr3Pop,1);
	cout<<endl;

	int* arr4Push = NULL;
	int* arr4Pop = NULL;
	test(arr4Push,arr4Pop,5);
	cout<<endl;
}
void test(int* pushOrder,int* popOrder,int length)
{
	bool flag = isPopOrder(pushOrder,popOrder,length);
	cout<<flag<<endl;
}
bool isPopOrder(int* pushOrder,int* popOrder,int length)
{
	bool flag = false;
	if(NULL==pushOrder||NULL==popOrder||length<=0)
	{
		return flag;
	}
	int* tmpPushOrder = pushOrder;  //��ʱ�����ݴ������׵�ַ
	int* tmpPopOrder = popOrder;
	stack<int> tmpStack;
	while(tmpPopOrder-popOrder<length)  //��ջ����û�б�����
	{
		//ѹջ˳�����ҵ��ͳ�ջ˳��һ��������
		while(tmpStack.empty()||tmpStack.top()!=*tmpPopOrder)
		{
			if(tmpPushOrder-pushOrder==length)
				break;
			tmpStack.push(*tmpPushOrder);  //���ѹջ������tmpPushOrder���ǳ�ջ����tmpPopOrder���Ͱ��������ѹջ��
			++tmpPushOrder;  //ѹջ����������һ��
		}
		if(tmpStack.top()!=*tmpPopOrder)  //�����break����whileѭ��������Ҫ�ж�
			break;
		tmpStack.pop();
		++tmpPopOrder;  //�жϳ�ջ�����е���һ��Ԫ��
	}
	if(tmpStack.empty()&&tmpPopOrder-popOrder==length)
	{
		flag = true;
	}
	return flag;
}
//1
//
//0
//
//1
//
//0
