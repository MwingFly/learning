//������
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct BinaryTreeNode  //������������ݽṹ
{
	char data;  
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode,*pBTNode;
//����һ��������
int createBinaryTree(pBTNode& root);
//�����������ֱ���
void preorderTraversal(const pBTNode& root);  //ǰ�����,������
void inorderTraversal(const pBTNode& root);  //��������������
void postorderTraversal(const pBTNode& root);  //������������Ҹ�
int main()
{
	do{
		BTNode* root;  //����һ�������ָ��
		createBinaryTree(root);
		cout<<"preorder traversal:"<<endl;
		preorderTraversal(root);
		cout<<endl<<endl;

		cout<<"inorder traversal:"<<endl;
		inorderTraversal(root);
		cout<<endl<<endl;;

		cout<<"postorder traversal:"<<endl;
		postorderTraversal(root);
		cout<<endl<<endl;;
	}while(cout<<"continue?(Y/N):",fflush(0),getchar(),getchar()=='Y');
}
int createBinaryTree(pBTNode& root)
{
	char data;
	if(cin>>data)  //������while, ��Ȼ�ݹ�һֱ��whileѭ����ֱ��������
	{
		if('#'==data)  //������������ַ�Ϊ��#����ʾ�����Ϊ��
			root = NULL;
		else
		{
			root = new BTNode();
			root->data = data;
			createBinaryTree(root->lchild);  //�ݹ齨��������
			createBinaryTree(root->rchild);  //�ݹ齨��������
		}
	}
	return 0;
}
void preorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ; 
	cout<<root->data<<" ";  //ǰ�����������������
	preorderTraversal(root->lchild);  //ǰ�����������
	preorderTraversal(root->rchild);  //ǰ�����������
}
void inorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	inorderTraversal(root->lchild);  //�������������
	cout<<root->data<<" ";  //�������������������
	inorderTraversal(root->rchild);  //�������������
}
void postorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	postorderTraversal(root->lchild);  //�������������
	postorderTraversal(root->rchild);  //�������������
	cout<<root->data<<" ";  //�������������������
}
//ab##c##
//preorder traversal:
//a b c 
//
//inorder traversal:
//b a c 
//
//postorder traversal:
//b c a 
//
//continue?(Y/N):Y
//ABC###DE##F##
//preorder traversal:
//A B C D E F 
//
//inorder traversal:
//C B A E D F 
//
//postorder traversal:
//C B E F D A 
//
//continue?(Y/N):N
