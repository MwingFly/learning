#ifndef __AVL_H__
#define __AVL_H__
#include<iostream>
using namespace std;
typedef struct AVL_Node
{
	int data;
	struct AVL_Node* lchild;
	struct AVL_Node* rchild;
	int height;
}AvlNode,*pAvlNode;
int nodeHeight(AvlNode* node);
int max(int a,int b);  //��ȡ��������������߶ȣ����½��߶ȵ�ʱ��Ҫ�õ�

AvlNode* AVL_Insert(pAvlNode& root,int key);  //ƽ�����������ؼ���key

static enum avl_delete{deleteError=-1,deleteSuccess} avl_delete_error;
AvlNode* AVL_Delete(pAvlNode& root,int key);  //ƽ�������ɾ���ؼ���key
AvlNode* AVL_NodePre(pAvlNode& node);  //�ҽ��ǰ��
AvlNode* AVL_NodePost(pAvlNode& node);  //�ҽ����

AvlNode* LL_Right_Rotate(pAvlNode& root);  //������������������ؼ��ֵ��²�ƽ�⣬˳ʱ����ת
AvlNode* RR_Left_Rotate(pAvlNode& root);  //������������������ؼ��ֵ��²�ƽ�⣬��ʱ����ת
AvlNode* LR_Left_Right_Rotate(pAvlNode& root);  //������������������ؼ��ֵ��²�ƽ�⣬�ȸ�������������ʱ����ת���ٸ����˳ʱ����ת
AvlNode* RL_Right_Left_Rotate(pAvlNode& root);  //������������������ؼ��ֵ��²�ƽ�⣬�ȸ�����������˳ʱ����ת���ٸ������ʱ����ת

void preorderTraversal(const pAvlNode& root);  
#endif