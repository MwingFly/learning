//��Ŀ24������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����������򷵻�true�����򷵻�false��
//�������������������������ֶ�������ͬ
//˼·��������������������С�ڸ���㣬���������ڸ���㣬������������һ�����������ֳ�������������㣬
//�жϣ�����������������С�ڸ����ģ�����false;������������һ�������ֿ��Բɲ��õݹ���ű���
#include<iostream>
using namespace std;
#if 1
bool isPostTraversal(int* arr,int length);
void test();
int main()
{
	test();
	system("pause");
}
bool isPostTraversal(int* arr,int length)
{
	if(nullptr==arr)
		return false;
	int treeRootNode = arr[length-1];
	int leftIdx = 0;
	//�����������
	for(;leftIdx!=length-1;++leftIdx)
	{
		if(arr[leftIdx]>treeRootNode)
			break;
	}
	//�����������
	int rightIdx = leftIdx;
	for(;rightIdx!=length-1;++rightIdx)
	{
		if(arr[rightIdx]<treeRootNode)
			return false;  //���������н�㶼���ڸ����
	}
	//�ݹ��ж����������ǲ���Ҳ����BST
	bool left = true;
	if(leftIdx>0)  //��������
		left = isPostTraversal(arr,leftIdx);  //�ݹ��Ӻ�����ֻҪ��һ������������BST������return false,�Ӷ����պ�������false��
	bool right = true;
	if(rightIdx<length-1)  //��������
		right = isPostTraversal(arr+leftIdx,length-leftIdx);
	return left && right;
}
void test()
{
	int arr[] = {5,7,6,9,11,10,8};
	cout<<isPostTraversal(arr,7)<<endl;
	int arr2[] = {7,4,6,5};
	cout<<isPostTraversal(arr2,4)<<endl;
	int* arr3 = nullptr;
	cout<<isPostTraversal(arr3,4)<<endl;
	int arr4[] = {5,4,6,8,7};
	cout<<isPostTraversal(arr4,5)<<endl;
}
#endif
//1
//0
//0
//1
//�밴���������. . .