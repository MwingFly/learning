#include"AVL.h"
#include<iostream>
using namespace std;

//height,�������Ϊ�գ�height=0,һ�����=1,�����ȼ����Ĳ���
int AvlTreeHeight(AvlNode* root)
{
	return (nullptr==root)? 0 : (root->height);
}
//�����ֵ
int max(int a,int b)
{
	return a>b?a:b;
}
//LL �����������ɾ����㵼����������ƽ�⣬Ҫ����ת��������ת��������������
pavlNode LL_Right_Rotate(pavlNode& root)
{
	if(nullptr==root)
		return nullptr;
	//����һ��ָ��ָ��root��������
	AvlNode* left = root->lchild;
	root->lchild = left->rchild;
	left->rchild = root;
	//��ʱ������Ϊleft
	//��������ÿ�����ĸ߶�

	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;  //��һ������ڵ�
	left->height = max(AvlTreeHeight(left->lchild),root->height) + 1;

	return left;  //�µĸ����
}
//RR �����������ɾ����㵼����������ƽ�⣬Ҫ����ת�����ص�������������
pavlNode RR_Left_Rotate(pavlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* right = root->rchild;
	root->rchild = right->lchild;
	right->lchild = root;

	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;
	right->height = max(AvlTreeHeight(right->rchild),root->height) + 1;
	
	return right;
}
//LR �������������������ɾ����㵼�²�ƽ�⣬Ҳ��������������������������ƽ������һ��һ��
//��������������������ת��Ȼ������������ת
pavlNode LR_Left_Right_Rotate(pavlNode& root)
{
	root->lchild = RR_Left_Rotate(root->lchild);  //�����ת��ĸ���㣬ǰ��һ��Ҫ���������ת����root->lchild
	return LL_Right_Rotate(root);
}
//RL �������������������ɾ����㵼�²�ƽ�⣬Ҳ��������������������������ƽ������һ��һ��
//��������������������ת��Ȼ������������ת
pavlNode RL_Right_Left_Rotate(pavlNode& root)
{
	root->rchild = LL_Right_Rotate(root->rchild);
	return RR_Left_Rotate(root);
}

//AVL������һ�����
//˼·�������Ϊ�գ�ֱ�Ӳ��룬���������ĸ߶Ȳ����ظ�����ַ
//���գ����õݹ飬�½��ֻ�ܲ��뵽������󣬲����������½��ĸ߶ȣ�
//�ݹ��㷵�أ�ÿ����һ��ͼ��㵱ǰ���������������߶ȲҲ������һ�εݹ鷵�ص�ʱ�����ģ����ֲ�ƽ�⣨�߶�>1��
//˵���ӵ�ǰ��㿪ʼ����������ƽ���ˣ�������ת�������ж����ڵ�ǰ��������߻����ұ߲���ģ���ȡ���ʵ���ת����
pavlNode AvlTreeInsertNode(pavlNode& root,int key)
{
	if(nullptr==root)
	{
		root = new AvlNode();
		if(nullptr==root)
		{
			cout<<"new ����AvlNode�ռ�ʧ��"<<endl;
			return nullptr;
		}
		root->height = 0;   //��ʼΪ0����������������
		root->key = key;
		root->lchild = root->rchild = nullptr;
	}
	else if(key<root->key)  //�ȸ����С��������Ѱ��
	{
		root->lchild = AvlTreeInsertNode(root->lchild,key);  //�ݹ�Ѱ��
		//�ݹ鷵�أ��ж��������ǲ���ƽ�����
		//��Ϊֻ������������ģ�ֻ�������������ĸ߶�,��������û��Ӱ��
		if(2 == AvlTreeHeight(root->lchild) - AvlTreeHeight(root->rchild))  //ģ��ݹ�Ĳ��Ƕ�ף�����Ҷ�ӽ������½���λ�û��ݣ����ﲻ�ü�ȡ����ֵ����ģ�������ָ���
		{
			//LL������������������������ƽ��  BF 2 1 LL
			if(key<root->lchild->key)
				root = LL_Right_Rotate(root);  //��ת�����������µĸ����
			else  //BF 2 -1   û��Bf 2 0�����
				root = LR_Left_Right_Rotate(root);  
		}
	}
	else if(key>=root->key)  //���ڸ���㣬������������
	{
		root->rchild = AvlTreeInsertNode(root->rchild,key);
		if(2==AvlTreeHeight(root->rchild) - AvlTreeHeight(root->lchild))
		{
			//RR BF -2 -1
			if(key>root->rchild->key)
				root = RR_Left_Rotate(root);
			else //RL BF -2 1
				root = RL_Right_Left_Rotate(root);
		}
	}
	//else if(key==root->key)
	//{
	//	cout<<"�ùؼ��ִ��ڣ���ֹ����"<<endl;
	//	return root;
	//}
	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;  //���������ܼ������height,��Ϊ�ݹ鷵�ص�ʱ�����ת��ת����
	return root;
}


//˼·���Ͳ������һ�����ݹ�Ѱ��Ҫɾ���Ľ�㣬
//����ؼ����������������������������ĸ߶ȣ�ѡ��߶ȸߵ�һ�����Ӧ����滻Ҫɾ���Ĺؼ��֣�
//�����������ߣ���ѡ�����������ҽ�㣬Ҳ���ǹؼ��ֵ�ǰ��
//�������ߣ���ѡ�������������㣬Ҳ���ǹؼ��ֵĺ��
//�滻֮�����ڶ�Ӧ����������ɾ���������滻�Ľ��
//��������������Ǵ��ڣ���ѡ��Ϊ�յ�һ��ֱ���滻
//ɾ�������Ҫ���¸߶�
pavlNode AvlTreeDeleteNode(pavlNode& root,int key)
{
	AvlTreeDeleteNodeErrorFlag = delFalse;
	if(nullptr==root)
	{
		AvlTreeDeleteNodeErrorFlag = delTrue;   //��������һ�����ɾ����Ҳ�᷵��nullptr�����Լ�һ�������־
		return nullptr;
	}
	if(key<root->key)
	{
		root->lchild = AvlTreeDeleteNode(root->lchild,key);
		//���������ɾ������ƽ��,������ɾ�����ܵ��º���������ƽ��
		//�����ƽ�⣬����������������̫�ߵ��µĻ��������������������������µ�
		if(2==AvlTreeHeight(root->rchild) - AvlTreeHeight(root->lchild))
		{//��������ɾ���ģ�ֻ������������������2
		 //��̬����root->rchild
		 //�ж������������������߶ȣ�������RL����RR
			if( AvlTreeHeight(root->rchild->lchild) <= AvlTreeHeight(root->rchild->rchild) )
			{//RR,�ұ߸�->ƽ�����Ӹ� ������ת root=-2,root->rchild->lchild = -1  һ������RR_Left_Rotate  ����BF -2 0
				root = RR_Left_Rotate(root);  
			}
			else
			{//RL  root=-2,root->rchild->lchild = 1  ֻ�������������RL
				root = RL_Right_Left_Rotate(root);
			}
		}
	}
	else if(key>root->key)
	{
		root->rchild = AvlTreeDeleteNode(root->rchild,key);
		if(2==AvlTreeHeight(root->lchild) - AvlTreeHeight(root->rchild))
		{
			if( AvlTreeHeight(root->lchild->lchild) >= AvlTreeHeight(root->lchild->rchild) )
			{//LL  BF 2 1 BF 2 0
				root = LL_Right_Rotate(root);
			}
			else 
			{//LR  BF 2 -1
				root = LR_Left_Right_Rotate(root);
			}
		}
	}
	else if(key==root->key)
	{//�ҵ���ɾ��
		if(root->lchild!=nullptr && root->rchild!=nullptr)
		{//�������������գ�ֻ��ѡ��ǰ����ǰ�����ߺ�����滻��Ȼ��ɾ�����ǰ������
		 //Ϊ�˱���ƽ�⣬һ��ѡ��ǰҪɾ���������������нϸߵ�һ��
			if(AvlTreeHeight(root->lchild) > AvlTreeHeight(root->rchild))
			{//����������ǰ��
				AvlNode* delNode = AvlTreeNodePre(root->lchild,key);
				root->key = delNode->key;  //�޸��滻��ֵ
				//��������ɾ��delNode
				root->lchild = AvlTreeDeleteNode(root->lchild,delNode->key);
			}
			else 
			{
				AvlNode* delNode = AvlTreeNodePost(root->rchild,key);
				root->key = delNode->key;
				root->rchild = AvlTreeDeleteNode(root->rchild,delNode->key);
			}
		}
		else //ɾ�����������һ��û�к���
		{
			AvlNode* tmp = root;
			root = nullptr==root->lchild ? root->rchild : root->lchild;
			delete tmp;
			tmp = nullptr;
		}
	}
	//���½��߶�
	if(nullptr!=root) //ɾ��ֻ��һ�������������
	{
		root->height = ( max( AvlTreeHeight(root->lchild) , AvlTreeHeight(root->rchild) ) ) + 1;
	}
	return root;
}

AvlNode* AvlTreeNodePre(pavlNode root,int key)
{
	if(nullptr==root)
		return nullptr;
	while(nullptr!=root->rchild)
		root = root->rchild;
	return root;
}
AvlNode* AvlTreeNodePost(pavlNode root,int key)
{
	if(nullptr==root)
		return nullptr;
	while(nullptr!=root->lchild)
		root = root->lchild;
	return root;
}
void preorderTraversalAVL(const pavlNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->key<<"��"<<root->height<<"��"<<" ";
	preorderTraversalAVL(root->lchild);
	preorderTraversalAVL(root->rchild);
}
void inorderTraversalAVL(const pavlNode& root)
{
	if(nullptr==root)
		return ;
	inorderTraversalAVL(root->lchild);
	cout<<root->key<<"��"<<root->height<<"��"<<" ";
	inorderTraversalAVL(root->rchild);
}

void AvlTreeDestroy(pavlNode& root)
{
	if(nullptr==root)
		return ;
	if(nullptr!=root->lchild)
		AvlTreeDestroy(root->lchild);
	if(nullptr!=root->rchild)
		AvlTreeDestroy(root->rchild);
	delete root;
	root = nullptr;
}