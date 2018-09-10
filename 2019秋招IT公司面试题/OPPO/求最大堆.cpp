#if 0
#include<iostream>
#include<vector>
using namespace std;
int maxheapSort(vector<int>&);  //����
void adjust(vector<int>&,int,int);  //�ѵ����㷨
void swap(int&,int&);
void outputMaxHeap(vector<int>&);
int main(int argc,char** argv)
{
	//��������
	vector<int> heapData;  //ͨ��������������������vector��
	int tmp;
	while(cin>>tmp)
	{
		heapData.push_back(tmp);
	}
	//��������
	maxheapSort(heapData);
	//������
	outputMaxHeap(heapData);
	system("pause");
}
int maxheapSort(vector<int>& arr)
{
	int len = arr.size();  //��ȡҪ���н��ѵ�Ԫ�ظ���
	if(0==len)
		return -1;  //���û��Ԫ�أ�����-1��ʧ�ܡ�
	for(int idx = len/2-1;idx>=0;--idx)  //�����������һ��Ԫ�صĸ���㿪ʼ���ϵ���Ϊ����
	{
		adjust(arr,idx,len-1);
	}
}
void adjust(vector<int>& arr,int idx,int len)
{
	if(0==arr.size()||idx>=len||idx<0||len<=0)
		return ;  
	int tmp = arr[idx];  //�ݴ�Ҫ����������
	for(int index=idx*2+1;index<=len;index=index*2+1)  //��Ҫ�����Ľ�����ӿ�ʼ�Ƚ�
	{
		if(index+1<=len&&arr[index]<arr[index+1])
			++index;  //�ҵ����Һ����е����ֵ�±�
		if(arr[index]>tmp)  //�����㣬����
		{
			arr[idx] = arr[index];
			idx = index;  //������ֵ�������������������������������ʣ��������µ���
		}
		else 
		{
			break;
		}		
	}
	arr[idx] = tmp;
	return;
}
void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void outputMaxHeap(vector<int>& arr)
{
	if(0==arr.size())
		return;
	int len = arr.size();
	for(int idx=len-1;idx>0;--idx)
	{
		swap(arr[0],arr[idx]);  //�Ѷ�Ϊ���ֵ������������ĩβ
		adjust(arr,0,idx-1);  //���µ���1~idx+1��Ԫ��������������
	}
	//���
	for(int idx=len-1;idx>=0;--idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
#endif
/* output */
//12 43 43 20 1 39 17 49 590 18 33 0
//^Z
//590 49 43 43 39 33 20 18 17 12 1 0
//�밴���������. . .