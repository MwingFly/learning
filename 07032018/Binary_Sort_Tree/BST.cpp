#include"BST.h"
bstNode* BST_Search(pBstNode root,int key)  //�����������в��ҹؼ���key
{
	if(nullptr==root)
		return nullptr;
	if(root->data==key)
	{
		return root;
	}
	else if(key>root->data)  //���ڸ���㣬�������м�������
	{
		BST_Search(root->rchild,key);  
	}
	else if(key<root->data)  //С�ڸ���㣬���������м�������
	{
		BST_Search(root->lchild,key);
	}
}  

void BST_Insert(pBstNode& root,int data)  //�����������в�����
{
	if(nullptr==root)
	{
		root = new bstNode();
		root->lchild = root->rchild = nullptr;
		root->data = data;
		return ;
	}
	//�����������������ҵ�������ڵ����ݵ�λ��
	bstNode* parentNode = nullptr;  //parentNode��Զָ��data������λ�õĸ����
	bstNode* curNode = root;
	while(nullptr!=curNode)
	{
		parentNode = curNode;
		if(data>curNode->data)
			curNode = curNode->rchild;  //Ӧ�ò��뵽������
		else if(data<=curNode->data)   
			curNode = curNode->lchild;  //Ӧ�ò��뵽������
	}
	//�ҵ�����λ��
	if(data>parentNode->data)
	{
		bstNode* newNode = new bstNode();
		newNode->data = data;
		newNode->lchild = nullptr;
		newNode->rchild = nullptr;
		parentNode->rchild = newNode;  //���뵽������
		return ;
	}
	else
	{
		bstNode* newNode = new bstNode();
		newNode->data = data;
		newNode->lchild = nullptr;
		newNode->rchild = nullptr;
		parentNode->lchild = newNode;  //���뵽������
		return ;
	}
}

int deleteNode(bstNode*& node)
{//����������ɾ����node��ǰ���滻
	if(nullptr==node)
		return -1;
	bstNode* delNode = node;  //�ݴ�Ҫɾ���ڵ�
	//1��ֻ��һ�����
	if(nullptr==node->lchild && nullptr==node->rchild)
	{
		node = nullptr;  //ǰ����Щ���Ϊʲô��ֱ�Ӹ�nullptr?
		//����ݹ鴫ֵ��ʱ�򴫵���root->lchild����root->rchild,�����ǶԸ���������ָ���޸ġ�
		//��������������node1(lchild,data,adrnode2)->node2(lchild,data,lchild2),Ȼ��node2����node2=nullptr,������ʱ����������ͻ����һ��Ұָ��adrnode2���ʵ������� 
		delete delNode;
		return 0;
	}
	//2��ֻ�����ӣ��ؽ����Ӿͺ�
	else if (nullptr==node->rchild)
	{
		node = node->lchild;
		delete delNode;
		return 0;
	}
	//3��ֻ���Һ���
	else if(nullptr==node->lchild)
	{
		node = node->rchild;
		delete delNode;
		return 0;
	}
	//4�����Һ��Ӷ���
	else if(nullptr!=node->lchild && nullptr!=node->rchild)
	{//��ǰ��
		bstNode* parent = delNode;  //��¼�����
		delNode = delNode->lchild;
		//��ɾ���ڵ�delNodeû����������ǰ������delNode
		if(nullptr==delNode->rchild)
		{
			node->data = delNode->data;
			parent->lchild = delNode->lchild;
			return 0;
		}
		//����������ǰ���������������ҽ��
		while(nullptr!=delNode->rchild)
		{
			parent = delNode;
			delNode = delNode->rchild;
		}
		//�ҵ�ǰ������ʼ�滻,ֻҪ�滻������ݼ��ɣ����Һ��ӹ�ϵ���ܸ���
		node->data = delNode->data;
		//�ж�ǰ���ǲ���Ҫ����������滻
		parent->rchild = delNode->lchild;
		return 0;
	}
	return 0;
}
int BST_Delete(pBstNode& root,int key)  //������ɾ���ؼ���key
{
	if(nullptr==root)
		return -1;
	if(key==root->data)
	{
		return deleteNode(root);
	}
	else if(key>root->data)
		return BST_Delete(root->rchild,key);  //�������в���ɾ��
	else if(key<root->data)
		return BST_Delete(root->lchild,key);
}

/*  ���������������ֱ���  */
void preorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	cout<<root->data<<" ";
	preorderTraversal_BST(root->lchild);
	preorderTraversal_BST(root->rchild);
}
void inorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	inorderTraversal_BST(root->lchild);
	cout<<root->data<<" ";
	inorderTraversal_BST(root->rchild);
}
void postorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	inorderTraversal_BST(root->lchild);
	inorderTraversal_BST(root->rchild);
	cout<<root->data<<" ";
}