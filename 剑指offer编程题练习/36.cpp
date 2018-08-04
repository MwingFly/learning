//��Ŀ36���������е������������ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ�����飬���������������Ե�����
//eg��{7,5,6,4}�У�һ������5������ԣ��ֱ���(7,6),(7,5),(7,4),(6,4),(5,4)��
//˼·�����ʵ�����Ӷ�O(nlogn)���鲢����
//��������{7,5,6,4}->��ʼ����->{7,5},{6,4}->{7}{5}{6}{4}->��ʼ�ϲ�(7,5һ������)(6,4��һ������)
//->{5,7}{4,6}(����ϲ��Ĺ����У�7>6,˵������������5>4һ������)->{4,5,6,7};���ͳ��5������
//�ռ临�Ӷ�O(n),��Ϊ���Ҫ��һ��һ�����������������õ�����
#include<iostream>
#include<string.h>
using namespace std;
int inversePairs(int* arr,int length);
int inversePairsMerge(int* arr,int* sortArr,int start,int end);
void test(int* arr,int length);
int main()
{
	int arr[] = {7,5,1,6,4};
	test(arr,5);
	cout<<endl;

}
void test(int* arr,int length)
{
	int ret = inversePairs(arr,length);
	cout<<ret<<endl;
}
int inversePairs(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int* sortArr = new int[length];  //����������ϲ������������
	memset(sortArr,0,length*sizeof(int));
	/*for(int idx=0;idx!=length;++idx)
	sortArr[idx] = arr[idx];*/
	//��ʼ����(�鲢����)
	int count =	inversePairsMerge(arr,sortArr,0,length-1);
	for(int idx=0;idx!=length;++idx)
		cout<<sortArr[idx]<<" ";
	cout<<endl;
	delete []sortArr;
	return count;
}
int inversePairsMerge(int* arr,int* sortArr,int start,int end)
{
	if(NULL==arr||NULL==sortArr||start<0||end<0||start==end)
		return 0;  //0�������
	int middle = (end-start)/2;
	int leftCount = inversePairsMerge(arr,sortArr,start,start + middle);  //���ֺ����������������
	int rightCount = inversePairsMerge(arr,sortArr,start + middle + 1,end);  ////���ֺ���Ұ������������
	//���ֵ���󵥸�Ԫ�غ�ʼ���ºϲ�
	int leftIndex = start + middle;  //�������һ��Ԫ���±�
	int rightIndex = end;  //�Ұ�����һ��Ԫ���±�
	int inversePairsCount = 0;  //ͳ������
	int sortArrIndex = end;  //��ʼ��sortArr��ʼ���Ԫ��λ�õ��±�
	while(leftIndex>=start&&rightIndex>=start + middle + 1)
	{
		if(arr[leftIndex]>arr[rightIndex])
		{
			inversePairsCount += rightIndex - (start + middle + 1) + 1;
			sortArr[sortArrIndex--] = arr[leftIndex--];
		}
		else
		{
			sortArr[sortArrIndex--] = arr[rightIndex--];
		}
	}
	//��������ʣ�²��ֵ�Ԫ��ȫ��������sortArr����
	//�������ʣ��
	for(;leftIndex>=start;)
		sortArr[sortArrIndex--] = arr[leftIndex--];
	//�Ұ��ʣ��
	for(;rightIndex>=start + middle + 1;)
		sortArr[sortArrIndex--] = arr[rightIndex--];
	//�ϲ������л��������������飬Ҫͬ���޸�ԭ���飬��Ȼ������ºϲ����������������������������Ϊ�ϲ������еĽ�������
	for(int idx=0;idx<=end;++idx)
		arr[idx] = sortArr[idx];
	return leftCount + rightCount + inversePairsCount;
}
//1 4 5 6 7
//7
/*
int leftCount = inversePairsMerge(arr,sortArr,start,start + middle);  //���ֺ����������������
int rightCount = inversePairsMerge(arr,sortArr,start + middle + 1,end);  ////���ֺ���Ұ������������
�������������Խ���arr��sortArr��ǰ����sortArr�ʼҪ��ԭ�����ʼ�����������Ͳ���
for(int idx=0;idx<=end;++idx)
arr[idx] = sortArr[idx];
�޸�ԭ������
�����Ĺ鲢�����в���������ֱ��ԭ����ȽϽ����ͺ���
������������Ҳ�ǿ����������ġ�
�����ĿҪ�����޸�ԭ���飬�Ǿ�ֻ���������ˡ���һ�������������������õ����顣
*/
