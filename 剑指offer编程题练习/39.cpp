//��Ŀ39������һ�ö������ĸ���㣬���������ȡ��Ӹ���㵽Ҷ�ڵ����ξ����Ľ�㣨������Ҷ�ڵ㣩�γ�����
//һ��·�����·���ĳ���Ϊ�������
//˼·��ǰ���������������Ⱦ͵���������������߸߶�+1��Ҷ�ӽ����������Ϊnull���߶Ⱦ���1
#if 0
#include<iostream>
using namespace std;
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
int binaryTreeDepth(const pBinaryTreeNode& binary);
void test();  //�������������
void test2();  //����
void test3();  //��ֻ��,�����ڵ�
void test4();  //һ�����
int main()
{
	test();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;
	test4();
	system("pause");
}
void test()
{
	int arr[15] = {1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,15);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test2()
{
	int arr[11] = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test3()
{
	int arr[5] = {1,2,-1,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,5);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test4()
{
	int arr[13] = {1,2,3,-1,-1,-1,4,5,-1,-1,6,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,13);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length)
{
	if(arrPtr==nullptr || length<=0)
		return ;
	if(*arrPtr==-1)
	{
		binary = nullptr;
		++arrPtr;
		--length;
		return ;
	}
	binary = new binaryTreeNode();
	binary ->data = *arrPtr;
	++arrPtr;
	--length;
	createBinaryTree(binary->lchild,arrPtr,length);
	createBinaryTree(binary->rchild,arrPtr,length);
}
int binaryTreeDepth(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return 0;  // ��Ϊ�գ������Ȼ����0
	int leftDepth = binaryTreeDepth(binary->lchild);
	int rightDepth = binaryTreeDepth(binary->rchild);
	if(leftDepth==0)
		return rightDepth+1;
	else if(rightDepth==0)
		return leftDepth+1;
	else 
		return ( leftDepth<rightDepth?(leftDepth+1):(rightDepth+1) );
}
#endif 
//4
//
//0
//
//2
//
//1
//�밴���������. . .