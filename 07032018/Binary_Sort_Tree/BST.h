#ifndef __BST_H__
#define __BST_H__
#include<iostream>
using namespace std;
typedef struct Binary_Sort_Tree
{
	int data;
	struct Binary_Sort_Tree* lchild,*rchild;
}bstNode,*pBstNode;

void BST_Insert(pBstNode& root,int data);  //�����������в�����
bstNode* BST_Search(pBstNode root,int key);  //�����������в��ҹؼ���key

int deleteNode(bstNode*& node);  //ɾ���ڵ�node,�β�Ϊ��ɾ���ڵ�ĵ�ַ����
int BST_Delete(pBstNode& root,int key);   //������ɾ���ؼ���key  //�ɹ�����


/*  ���������������ֱ���  */
void preorderTraversal_BST(const pBstNode& root);
void inorderTraversal_BST(const pBstNode& root);
void postorderTraversal_BST(const pBstNode& root);
 



#endif