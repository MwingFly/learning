//��Ŀ20������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
//˼·��ע��߽������ͽ�������
//ÿ�ζ��Ǿ���ĶԽǿ�ʼ��ӡ��(0,0)-(1,1)-(2,2)
//���ñ�����ʼ����������ֹ����
int printMatrix(int **arr,int rows,int columns);   //��̬����Ķ�ά�������������ֵ
//int printMatrix(int (*arr)[4],int rows,int columns);  //��ͨ����������ֵ
void test(int **arr,int rows,int columns);
int printTwoMatrix(int **arr,int rows,int columns);
#include<iostream>
using namespace std;
int main()
{
	int** arr = new int*[3];
	arr[0] = new int[3];
	arr[1] = new int[3];
	arr[2] = new int[3];
	int total = 0;
	for(int idx=0;idx<3;++idx)
	{
		for(int iidx=0;iidx<3;++iidx)
		{
			++total;
			*(*(arr + idx) + iidx) = total ;  //Ҳ��������д
		}
	}

	int** arr1 = new int*[1];
	arr1[0] = new int[2];
	arr1[0][0] = 1;
	arr1[0][1] = 2;

	int** arr2 = new int*[2];
	arr2[0] = new int[1];
	arr2[1] = new int[1];
	arr2[0][0] = 1;
	arr2[1][0] = 2; 


	int** arr3 = new int*[1];
	arr3[0] = new int[1];
	arr3[0][0] = 1;


	int** arr4 = new int*[2];
	arr4[0] = new int[2];
	arr4[1] = new int[2];
	arr4[0][0] = 1;
	arr4[0][1] = 2;
	arr4[1][0] = 3;
	arr4[1][1] = 4;


	int** arr5 = new int*[4];
	arr5[0] = new int[4];
	arr5[1] = new int[4];
	arr5[2] = new int[4];
	arr5[3] = new int[4];
	arr5[0][0] = 1;
	arr5[0][1] = 2;
	arr5[0][2] = 3;
	arr5[0][3] = 4;
	arr5[1][0] = 5;
	arr5[1][1] = 6;
	arr5[1][2] = 7;
	arr5[1][3] = 8;
	arr5[2][0] = 9;
	arr5[2][1] = 10;
	arr5[2][2] = 11;
	arr5[2][3] = 12;
	arr5[3][0] = 13;
	arr5[3][1] = 14;
	arr5[3][2] = 15;
	arr5[3][3] = 16;

	test(arr,3,3);
	cout<<endl;
	test(arr1,1,2);  // ��һ�ε��������ӡ1,2,1��
	// ���Ƿ���������ˣ�����ֱ�����ͽ�forѭ����Ҫ���ж�һ���ǲ��ǻ��д�ӡ�ı�Ҫ��,�ͱ��������1*2������
	cout<<endl;
	test(arr2,2,1);
	cout<<endl;
	test(arr3,1,1);
	cout<<endl;
	test(arr4,2,2);
	cout<<endl;
	test(arr5,4,4);
}
int printMatrix(int **arr,int rows,int columns)
{
	if(NULL==arr||rows<=0||columns<=0)
		return -1;
	int start = 0;  //�����ӡ����㣬���Ǿ�������Ͻ�
	while(rows>start*2&&columns>start*2)
	{
		int endx = rows - 1 - start;  //��������㣬���Ǿ�������½�
		int endy = columns - 1 - start;
		//��ӡ������  //���ﲻ���ж��ˣ������϶���Ҫ�����ѭ����
		for(int idx = start;idx<=endy;++idx)
		{
			cout<<arr[start][idx]<<"\t";
		}
		//��ӡ���ϵ���  //�жϾ����ǲ��Ƕ��е�
		if(endx>start)
		{
			for(int idx=start+1;idx<=endx;++idx)
			{
				cout<<arr[idx][endy]<<"\t";
			}
		}
		//��ӡ���ҵ���  //����Ҫ���У���Ҫ���У���Ȼû�д�ӡ�ı�Ҫ ����1*2�ľ���
		if(endx>start&&endy>start)
		{
			for(int idx=endy-1;idx>=start;--idx)
			{
				cout<<arr[endx][idx]<<"\t";
			}
		}
		//��ӡ���µ���  //���ж���
		if(endx>start&&endy>start)
		{
			for(int idx=endx-1;idx>start;--idx)
			{
				cout<<arr[idx][start]<<"\t";
			}
		}
		++start;
	}
	cout<<endl;
	return 0;
}
void test(int **arr,int rows,int columns)
{
	printTwoMatrix(arr,rows,columns);
	printMatrix(arr,rows,columns);
}
int printTwoMatrix(int **arr,int rows,int columns)
{
	for(int idx=0;idx<rows;++idx)
	{
		for(int iidx=0;iidx<columns;++iidx)
		{
			//cout<<arr[idx][iidx]<<"\t";
			cout<<*(*(arr + idx) + iidx) <<"\t";
		}
		cout<<endl;
	}
	return 0;
}
