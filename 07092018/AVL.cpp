#include"AVL.h"
int nodeHeight(AvlNode* node)
{
	if(nullptr==node)
		return 0;
	else 
		return node->height;
}

int max(int a,int b)
{
	return a>b ? a : b;
}

AvlNode* LL_Right_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	tmp->height = max( nodeHeight(tmp->lchild),nodeHeight(root) ) + 1;
	return tmp;
}

AvlNode* RR_Left_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	tmp->height = max( nodeHeight(root),nodeHeight(root->rchild) ) + 1;
	return tmp;
}

AvlNode* LR_Left_Right_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	root->lchild = RR_Left_Rotate(root->lchild);  //root->lchild���ܸ��ģ�����Ҫ�÷��ص�����ֵ����
	root = LL_Right_Rotate(root);
	return root;
}

AvlNode* RL_Right_Left_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	root->rchild = LL_Right_Rotate(root->rchild);
	root = RR_Left_Rotate(root);
	return root;
}

AvlNode* AVL_Insert(pAvlNode& root,int key)
{
	if(nullptr==root)
	{
		root = new AvlNode();
		root->data = key;
		root->height = 1;
		root->lchild = root->rchild = nullptr;
	}
	else if(key<root->data)
	{//����������
		root->lchild = AVL_Insert(root->lchild,key);  //����Ĺ����л���ת���ṹ������Ҫ�÷��ص�ֵ������root->lchild
		if(nodeHeight(root->lchild)-nodeHeight(root->rchild)==2)
		{
			if(key<root->lchild->data)  //����������������������ƽ��
				root = LL_Right_Rotate(root);
			else 
				root = LR_Left_Right_Rotate(root);
		}
	}
	else if(key>root->data)
	{//����������
		root->rchild = AVL_Insert(root->rchild,key);
		if(nodeHeight(root->rchild)-nodeHeight(root->lchild)==2)  
		{
			if(key>root->rchild->data) //������������������
				root = RR_Left_Rotate(root);
			else 
				root = RL_Right_Left_Rotate(root);
		}
	}
	else if(key==root->data)
	{
		cout<<"same key,can not insert!"<<endl;
		return nullptr;
	}
	//���½��߶�
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	return root;
}

void preorderTraversal(const pAvlNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->data<<"��"<<root->height<<"��"<<" ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

AvlNode* AVL_Delete(pAvlNode& root,int key)
{
	avl_delete_error = deleteSuccess;
	if(nullptr==root)
	{
		avl_delete_error = deleteError;   //�ս�㣬ɾ��ʧ��
		return nullptr;
	}
	else if(key<root->data)
	{
		root->lchild = AVL_Delete(root->lchild,key);  //����������ɾ��
		if(nodeHeight(root->rchild)-nodeHeight(root->lchild)==2)
		{
			if(nodeHeight(root->rchild->lchild)>nodeHeight(root->rchild->rchild))  // -2 1
				root = RL_Right_Left_Rotate(root);
			else 
				root = RR_Left_Rotate(root);
		}
	}
	else if(key>root->data)
	{
		root->rchild = AVL_Delete(root->rchild,key);
		if(nodeHeight(root->lchild)-nodeHeight(root->rchild)==2)
		{
			if(nodeHeight(root->lchild->lchild)<nodeHeight(root->lchild->rchild))
				root = LR_Left_Right_Rotate(root);	
			else 
				root = LL_Right_Rotate(root);
		}
	}
	else if(key==root->data)
	{
		//����������������ڣ���ǰ�����ߺ�����滻����ɾ�����ǰ������
		if(nullptr!=root->lchild&&nullptr!=root->rchild)
		{
			if(nodeHeight(root->lchild)>nodeHeight(root->rchild))
			{
				AvlNode* pre = AVL_NodePre(root->lchild);
				root->data = pre->data;
				root->lchild = AVL_Delete(root->lchild,pre->data);
			}
			else 
			{
				AvlNode* post = AVL_NodePost(root->rchild);
				root->data = post->data;
				root->rchild = AVL_Delete(root->rchild,post->data);
			}
		}
		else
		{
			AvlNode* tmp = root;
			root = nullptr==root->lchild ? root->rchild : root->lchild;
			delete tmp;
			tmp = nullptr;
		}
	}
	//���¸߶�
	if(nullptr!=root)
		root->height = max(nodeHeight(root->lchild),nodeHeight(root->rchild)) + 1;
	return root;
}
AvlNode* AVL_NodePre(pAvlNode& node)
{
	if(nullptr==node)
		return nullptr;
	while(node->rchild!=nullptr)
		node = node->rchild;
	return node;
}
AvlNode* AVL_NodePost(pAvlNode& node)
{
	if(nullptr==node)
		return nullptr;
	while(node->lchild!=nullptr)
		node = node->lchild;
	return node;
}