//������25������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·�����Ӹ���㿪ʼ
//����һֱ��Ҷ�ڵ��������Ľ���γ�һ��·����·���ǴӸ���㵽ҲҶ�ӽ��
//˼·�����ƶ�������ǰ��������Ӹ���㿪ʼ���±�������������б������·���ϵ�ֵ������͸�����ֵ��ͬ���ҵ���Ҷ�ӽ�㣬�����·��
//���ݹ�����Ҫ��ȥ��Ӧ�Ľ���ֵ����·����ɾ��
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define BinaryTreeNode_ValueType int
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
void fingPath(const pBinaryTreeNode& root,vector<BinaryTreeNode_ValueType>& path,int& currentSum,int expectedSum);
void preorderTraversal(const pBinaryTreeNode& root);
void test();
int main()
{
	test();
}
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length)
{
	if(arrPtr==nullptr || length<=0)
		return ;
	if(*arrPtr==-1)
	{
		binary = nullptr;
		++arrPtr;
		return ;
	}
	binary = new binaryTreeNode();
	binary ->data = *arrPtr;
	++arrPtr;
	createBinaryTree(binary->lchild,arrPtr,length);
	createBinaryTree(binary->rchild,arrPtr,length);
}
void test()
{
	//string tree1data = "10";
	int arr[11] = {10,5,4,-1,-1,7,-1,-1,12,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	cout<<"ǰ�������";
	preorderTraversal(root);
	cout<<endl;
	vector<BinaryTreeNode_ValueType> path;
	int currentSum = 0;
	fingPath(root,path,currentSum,22);
	cout<<endl;
}
void preorderTraversal(const pBinaryTreeNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->data<<" ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}
void fingPath(const pBinaryTreeNode& root,vector<BinaryTreeNode_ValueType>& path,int& currentSum,int expectedSum)
{
	if(nullptr==root)
		return ;
	path.push_back(root->data);
	currentSum += root->data;
	bool isLeaf = (root->lchild==nullptr && root->rchild==nullptr);
	if(currentSum==expectedSum && isLeaf)  //�ҵ������С��·���������Ѿ�����Ҷ�ӽ��
	{
		for(auto& elem:path)
			cout<<elem<<" ";
		cout<<"sum = "<<currentSum<<endl;
	}
	fingPath(root->lchild,path,currentSum,expectedSum);
	fingPath(root->rchild,path,currentSum,expectedSum);
	//���������������ˣ�����
	currentSum -= root->data;
	path.pop_back();
}
//ǰ�������10 5 4 7 12
//10 5 7 sum = 22
//10 12 sum = 22
//
//�밴���������. . .
