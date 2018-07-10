#include<iostream>
using namespace std;
int headSort(int* arr,int length);
void adjust(int* arr,int idx1,int idx2);
void swap(int& a,int& b);
int main()
{
	int arr[9] = {50,10,90,30,70,40,80,60,20};
	for(int idx=0;idx!=9;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;

	headSort(arr,9);

	for(int idx=0;idx!=9;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
}
void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//�����������±��Ӧ���ڶ����ݽṹ�еĽ��λ�ã���0��ʼ��ţ�������ȫ������
int headSort(int* arr,int length)
{
	if(nullptr==arr||length<=0)
		return -1;
	//������˳���ŵ����ݾͶ�Ӧ��ȫ���������еĶ�Ӧ����ֵ�����ڵ���Ϊ�����
	for(int idx=length/2-1;idx>=0;--idx)  //�����һ����Ҷ�ӽ�㿪ʼ����Ϊ����
	{
		adjust(arr,idx,length-1);  //���һ����Ҷ�ӽ������ĺ��ӱȽϵ���
	}
	//���򣬸��������һ����㽻��������
	for(int idx=length-1;idx>0;--idx)
	{
		swap(arr[0],arr[idx]);  //ÿ��ѡ��һ���������ŵ�ĩβ��Ҳ��������ĩβ
		adjust(arr,0,idx-1);  //��������㵽idx-1�����Ϊ�����
	}
	return 0;
}
void adjust(int* arr,int idx1,int idx2)
{
	if(nullptr==arr||idx1>=idx2||idx1<0||idx2<0)
		return ;
	int tmp = arr[idx1];  //��ʱ���Ҫ����������
	for(int idx=idx1*2+1;idx<=idx2;idx=idx*2+1)  //��Ҫ���������ݵ����ӿ�ʼ�Ƚ�
	{
		//ѡ�����Һ����е������
		if(idx+1<=idx2 && arr[idx]<arr[idx+1])
			++idx;
		if(arr[idx]>tmp)  //���������ѣ�����
		{
			arr[idx1] = arr[idx];  //�����������ƻ������������ѵ�����
			idx1 = idx;  //��������Ҫ�����ģ���ʱtmp��ʱ����˳�ʼarr[idx1]��ֵ������ÿ�αȽ϶��Ǻ�tmp�Ƚ�,�ñȽ����ˣ����Կ��Բ����Ƚ���
			//�������µ�����ֱ����������������
		}
		else
			break;
	}
	arr[idx1] = tmp;
}
//50 10 90 30 70 40 80 60 20 
//10 20 30 40 50 60 70 80 90 
