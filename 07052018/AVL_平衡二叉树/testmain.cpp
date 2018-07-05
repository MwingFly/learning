#include"AVL.h"
#include<iostream>
using namespace std;
#define len 10
int main()
{
	int a[len] = {3,2,1,4,5,6,7,10,9,8};
	//int a[len] = {62,88,58,47,35,73,51,99,37,93};
	cout<<"������Ԫ�����У�";
	for(int idx=0;idx!=len;++idx)
	{
		cout<<a[idx]<<" ";
	}
	cout<<endl;

	
	pavlNode root = nullptr;
	for(int idx=0;idx!=len;++idx)
	{
		root = AvlTreeInsertNode(root,a[idx]);  //��Ϊ�ڲ�������л��޸ĸ����
		if( nullptr == root )
			cout<<"insert "<<a[idx]<<" fail!"<<endl;
	}
	cout<<"���������";
	inorderTraversalAVL(root);
	cout<<endl;
	cout<<"���������";
	preorderTraversalAVL(root);
	cout<<endl<<endl;
	//AvlTreeDestroy(root);
	for(int idx=0;idx!=len;++idx)
	{
		if( nullptr == AvlTreeDeleteNode(root,a[idx]) && delTrue ==AvlTreeDeleteNodeErrorFlag )
			cout<<"delete "<<a[idx]<<" fail!"<<endl;
		else 
		{
			cout<<"ɾ��"<<a[idx]<<",���������";
			inorderTraversalAVL(root);
			cout<<endl;
			cout<<"ɾ��"<<a[idx]<<",���������";
			preorderTraversalAVL(root);
			cout<<endl<<endl;
		}
	}
}
//������Ԫ�����У�3 2 1 4 5 6 7 10 9 8
//���������1��1�� 2��2�� 3��1�� 4��4�� 5��1�� 6��2�� 7��3�� 8��1�� 9��2�� 10��1��
//���������4��4�� 2��2�� 1��1�� 3��1�� 7��3�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��3,���������1��1�� 2��2�� 4��4�� 5��1�� 6��2�� 7��3�� 8��1�� 9��2�� 10��1��
//ɾ��3,���������4��4�� 2��2�� 1��1�� 7��3�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��2,���������1��1�� 4��3�� 5��1�� 6��2�� 7��4�� 8��1�� 9��2�� 10��1��
//ɾ��2,���������7��4�� 4��3�� 1��1�� 6��2�� 5��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��1,���������4��1�� 5��2�� 6��1�� 7��3�� 8��1�� 9��2�� 10��1��
//ɾ��1,���������7��3�� 5��2�� 4��1�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��4,���������5��2�� 6��1�� 7��3�� 8��1�� 9��2�� 10��1��
//ɾ��4,���������7��3�� 5��2�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��5,���������6��1�� 7��3�� 8��1�� 9��2�� 10��1��
//ɾ��5,���������7��3�� 6��1�� 9��2�� 8��1�� 10��1��
//
//ɾ��6,���������7��2�� 8��1�� 9��3�� 10��1��
//ɾ��6,���������9��3�� 7��2�� 8��1�� 10��1��
//
//ɾ��7,���������8��1�� 9��2�� 10��1��
//ɾ��7,���������9��2�� 8��1�� 10��1��
//
//ɾ��10,���������8��1�� 9��2��
//ɾ��10,���������9��2�� 8��1��
//
//ɾ��9,���������8��1��
//ɾ��9,���������8��1��
//
//ɾ��8,���������
//ɾ��8,���������
//
//�밴���������. . .
//
//������Ԫ�����У�62 88 58 47 35 73 51 99 37 93
//���������35��2�� 37��1�� 47��3�� 51��1�� 58��2�� 62��4�� 73��1�� 88��3�� 93��1�� 99��2��
//���������62��4�� 47��3�� 35��2�� 37��1�� 58��2�� 51��1�� 88��3�� 73��1�� 99��2�� 93��1��
//
//ɾ��62,���������35��2�� 37��1�� 47��3�� 51��1�� 58��2�� 73��4�� 88��1�� 93��2�� 99��1��
//ɾ��62,���������73��4�� 47��3�� 35��2�� 37��1�� 58��2�� 51��1�� 93��2�� 88��1�� 99��1��
//
//ɾ��88,���������35��2�� 37��1�� 47��3�� 51��1�� 58��2�� 73��4�� 93��2�� 99��1��
//ɾ��88,���������73��4�� 47��3�� 35��2�� 37��1�� 58��2�� 51��1�� 93��2�� 99��1��
//
//ɾ��58,���������35��2�� 37��1�� 47��3�� 51��1�� 73��4�� 93��2�� 99��1��
//ɾ��58,���������73��4�� 47��3�� 35��2�� 37��1�� 51��1�� 93��2�� 99��1��
//
//ɾ��47,���������35��1�� 37��2�� 51��1�� 73��3�� 93��2�� 99��1��
//ɾ��47,���������73��3�� 37��2�� 35��1�� 51��1�� 93��2�� 99��1��
//
//ɾ��35,���������37��2�� 51��1�� 73��3�� 93��2�� 99��1��
//ɾ��35,���������73��3�� 37��2�� 51��1�� 93��2�� 99��1��
//
//ɾ��73,���������37��2�� 51��1�� 93��3�� 99��1��
//ɾ��73,���������93��3�� 37��2�� 51��1�� 99��1��
//
//ɾ��51,���������37��1�� 93��2�� 99��1��
//ɾ��51,���������93��2�� 37��1�� 99��1��
//
//ɾ��99,���������37��1�� 93��2��
//ɾ��99,���������93��2�� 37��1��
//
//ɾ��37,���������93��1��
//ɾ��37,���������93��1��
//
//ɾ��93,���������
//ɾ��93,���������
//
//�밴���������. . .
