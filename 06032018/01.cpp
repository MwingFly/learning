//���ֲ���
//��ת�������С����
#include<iostream>
#include<exception>
using namespace std;
int min(int* arr,int length);
int minInorder(int* arr,int idx1,int idx2);
#if 0
int main()
{
	int arr[] = {3,4,1,1,3};
	int arr2[] = {1,1,1,0,1};  //��������
	try
	{ //��������
		int res = ::min(NULL,5);
		cout<<res<<endl;
	}catch(exception& e)
	{
		cout<<"�쳣"<<endl;
	}
	system("pause");
}
#endif
int min(int* arr,int length)
{
	if(NULL==arr||length<=0)
		throw *(new exception);
		//return -1;
	int idxLeft = 0,idxRight = length-1;
	int midIdx ;
	while(idxLeft<idxRight)
	{
		midIdx = (idxRight+idxLeft)/2;
		//���������idxLeft��idxRight��midIdx����ֵ��һ��
		if(arr[idxLeft]==arr[idxRight]==arr[midIdx])
			return minInorder(arr,idxLeft,idxRight);
		else if(idxRight-idxLeft==1)
			break; //�ҵ���СԪ��
		else if(arr[idxLeft]<=arr[midIdx])
			idxLeft = midIdx;
		else if(arr[idxRight]>=arr[midIdx])
			idxRight = midIdx;
	}
	return arr[idxRight];
}
int minInorder(int* arr,int idx1,int idx2)
{
	if(NULL==arr||idx1<0||idx2<0||idx1>idx2)
		return -1;
	int min = arr[idx1];
	for(;idx1<idx2;idx1++)
	{
		if(min>arr[idx1])
			min = arr[idx1];
	}
	return min;
}