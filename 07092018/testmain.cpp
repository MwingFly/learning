#include<iostream>
#include"AVL.h"
using namespace std;
#define len 10
int main()
{
	int a[len] = {3,2,1,4,5,6,7,10,9,8};
	cout<<"������Ԫ�����У�";
	for(int idx=0;idx!=len;++idx)
	{
		cout<<a[idx]<<" ";
	}
	cout<<endl;
	pAvlNode root = nullptr;
	for(int idx=0;idx!=len;++idx)
	{
		root = AVL_Insert(root,a[idx]);  //��Ϊ�ڲ�������л��޸ĸ����
		if( nullptr == root )
			cout<<"insert "<<a[idx]<<" fail!"<<endl;
	}
	cout<<"���������";
	preorderTraversal(root);
	cout<<endl;

	for(int idx=0;idx!=len;++idx)
	{
		if( nullptr == AVL_Delete(root,a[idx]) && avl_delete_error ==deleteError )
			cout<<"delete "<<a[idx]<<" fail!"<<endl;
		else
		{
			cout<<"ɾ��"<<a[idx]<<",ǰ�������";
			preorderTraversal(root);
			cout<<endl<<endl;
		}
	}
	system("pause");
}
//������Ԫ�����У�3 2 1 4 5 6 7 10 9 8
//���������4��4�� 2��2�� 1��1�� 3��1�� 7��3�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//ɾ��3,ǰ�������4��4�� 2��2�� 1��1�� 7��3�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��2,ǰ�������7��4�� 4��3�� 1��1�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��1,ǰ�������7��3�� 5��2�� 4��1�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��4,ǰ�������7��3�� 5��2�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��5,ǰ�������7��3�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��6,ǰ�������9��3�� 7��2�� 8��1�� 10��1��
//
//ɾ��7,ǰ�������9��2�� 8��1�� 10��1��
//
//ɾ��10,ǰ�������9��2�� 8��1��
//
//ɾ��9,ǰ�������8��1��
//
//ɾ��8,ǰ�������
//
//�밴���������. . .