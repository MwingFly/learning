//��Ŀ19�����һ������������һ�����������ú���������ľ���
//˼·�����񣬾��ǴӸ���㿪ʼ������������������ڣ��ͽ����������ڵ㣬ÿһ������ͬ˫�׽�㶼����
#include<iostream>
#include<string>
using namespace std;
#if 0
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //����������
void inorderTraversal(const pBinaryTreeNode& binary);
void swap(binaryTreeNode*& node1,binaryTreeNode*& node2);
void mirrorBinaryTree(pBinaryTreeNode& binary);
void test();
void test2();
void test3();
int main()
{
	test();
	test2();  //����
	test3();  //һ�����
	system("pause");
}
void test()
{
	string treeData = "ABD##E##CF###";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"ԭ��������";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"�����������";
	inorderTraversal(tree);
	cout<<endl;
};
void test2()
{
	string treeData = "";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"ԭ��������";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"�����������";
	inorderTraversal(tree);
	cout<<endl;
}
void test3()
{
	string treeData = "A##";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"ԭ��������";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"�����������";
	inorderTraversal(tree);
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
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
void swap(binaryTreeNode*& node1,binaryTreeNode*& node2)
{
	binaryTreeNode* tmp;
	tmp = node1;
	node1 = node2;
	node2 = tmp;
}
void mirrorBinaryTree(pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	if(binary->lchild!=nullptr || binary->rchild!=nullptr)
	{//����
		swap(binary->lchild,binary->rchild);  
		//swap1(binary->lchild->data,binary->rchild->data);  //����ֱ�ӻ����ݣ�������һ��Ϊ�յ�������GG
	}
	mirrorBinaryTree(binary->lchild);
	mirrorBinaryTree(binary->rchild);
}
#endif
//ԭ��������D B E A F C
//�����������C F A E B D
//ԭ��������
//�����������
//ԭ��������A
//�����������A
//�밴���������. . .