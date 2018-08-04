//��Ŀ���������´�ӡ������,ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��
//˼·������ʵ����һ���������
#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //����������
void preorderTraversal(const pBinaryTreeNode& binary);
void inorderTraversal(const pBinaryTreeNode& binary);
void levelTraversal(const pBinaryTreeNode& binary);
void test();
int main()
{
	test();
	system("pause");
}
void test()
{
	string treeData = "ABD##E##CF###";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"ԭ������ǰ�������";
	preorderTraversal(tree);
	cout<<endl;
	cout<<"ԭ���������������";
	inorderTraversal(tree);
	cout<<endl;
	cout<<"���������";
	levelTraversal(tree);
	cout<<endl;
}
void createBinaryTree(pBinaryTreeNode& binary,string& str)
{
	int idx = 0;
	if(str[idx]!='\0')
	{
		if('#'==str[idx])
		{
			binary = nullptr;
			str = str.substr(idx+1);  //��ȡ��һ�����룬�޸�str
			return ;
		}
		else
		{
			binary = new binaryTreeNode();
			binary->data = str[idx];
			//�����ø�����ݹ齨����������
			str = str.substr(idx+1);  //��ȡ��һ�����룬�޸�str
			createBinaryTree(binary->lchild,str);
			createBinaryTree(binary->rchild,str);
		}
	}
}
void preorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	cout<<binary->data<<" ";
	preorderTraversal(binary->lchild);
	preorderTraversal(binary->rchild);
}
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
void levelTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return;
	queue<pBinaryTreeNode> node;
	node.push(::move(binary));
	while(!node.empty())
	{
		if(node.front()->lchild!=nullptr)
			node.push(::move(node.front()->lchild));
		if(node.front()->rchild!=nullptr)
			node.push(::move(node.front()->rchild));
		cout<<node.front()->data<<" ";
		node.pop();
	}
	return;
}
//ԭ������ǰ�������A B D E C F
//ԭ���������������D B E A F C
//���������A B C D E F
//�밴���������. . .
