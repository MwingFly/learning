#ifndef __AVL_H__
#define __AVL_H__

typedef struct AVLTreeNode
{
	int key;
	int height;  //���߶ȣ��������㵱ǰ���Ϊ�����������ǲ���ƽ���
	struct AVLTreeNode* lchild;
	struct AVLTreeNode* rchild;
}AvlNode,*pavlNode;

//height,�������Ϊ�գ�height=0,һ�����=1,�����ȼ����Ĳ���
int AvlTreeHeight(AvlNode* root);

//�����ֵ
int max(int a,int b);

pavlNode LL_Right_Rotate(pavlNode& root);

pavlNode LR_Left_Right_Rotate(pavlNode& root);

pavlNode RL_Right_Left_Rotate(pavlNode& root);

pavlNode AvlTreeInsertNode(pavlNode& root,int key);

AvlNode* AvlTreeNodePre(pavlNode root,int key);  //������ǰ����Ҳ�������ҽ�㣬���ֵ���

AvlNode* AvlTreeNodePost(pavlNode root,int key);  //��������̣�Ҳ���������㣬��Сֵ���

static enum errorFlag{delFalse=0,delTrue} AvlTreeDeleteNodeErrorFlag;
pavlNode AvlTreeDeleteNode(pavlNode& root,int key);

AvlNode* AvlTreeNodePre(pavlNode root,int key);

AvlNode* AvlTreeNodePost(pavlNode root,int key);

void preorderTraversalAVL(const pavlNode& root);

void inorderTraversalAVL(const pavlNode& root);

void AvlTreeDestroy(pavlNode& root);
#endif