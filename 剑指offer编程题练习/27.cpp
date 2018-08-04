//��Ŀ27������һ�ö��������������ö�����ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
//˼·��BST��������õ��Ľ�����Ǵ�С��������У�����������Ĺ������޸����ӹ�ϵ�Ϳ��Եõ�һ��˫������
//��ָ��ָ��������ǰһ����㣬��ָ��ָ���һ���ڵ㣬�����ڱ����Ĺ�������Ҫһ��ָ������¼��һ�����ʵĽ��
//��ʼֵ��Ϊnull,���������ָ�벻Ϊ�վͲ����޸��ˡ���һ�����ʵĽ�����ָ��Ϊ�վ�ִ�е�ǰ���ʽ�㣬
//�����Ǻ�һ���ڵ�
#include<iostream>
using namespace std;
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
void inorderTraversal(const pBinaryTreeNode& binary);
pBinaryTreeNode BstToDoubleList(pBinaryTreeNode& binary);
void bstToDoubleList(pBinaryTreeNode& binary,binaryTreeNode*& pre);
void test();
void test2();
void test3();
void test4();
void test5();
int main()
{
	test();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;
	test4();
	cout<<endl;
	test5();
}

void test()
{
	int arr[15] = {10,6,4,-1,-1,8,-1,-1,14,12,-1,-1,16,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	cout<<"���������";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"˫���������������";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"˫�������������";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test2()
{
	int arr[12] = {3,2,1,-1,-1,-1,4,-1,5,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,12);
	cout<<"���������";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"˫���������������";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"˫�������������";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test3()
{
	int arr[7] = {3,2,1,-1,-1,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,7);
	cout<<"���������";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"˫���������������";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"˫�������������";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test4()
{
	int arr[3] = {10,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,3);
	cout<<"���������";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"˫���������������";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"˫�������������";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test5()
{
	int* arr = nullptr;
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,3);
	cout<<"���������";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"˫���������������";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"˫�������������";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
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
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
pBinaryTreeNode BstToDoubleList(pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return nullptr;
	binaryTreeNode* pre = nullptr;
	bstToDoubleList(binary,pre);
	binaryTreeNode* head = pre;
	while(head->lchild!=nullptr)  //�͸�BST��˫�������preָ�����һ����㣬���������ҵ�ͷ���
		head = head->lchild;
	return head;
}
void bstToDoubleList(pBinaryTreeNode& binary,binaryTreeNode*& pre)
{
	if(binary==nullptr)
		return;
	pBinaryTreeNode pcur = binary;   //�����������м�Ļ����ݹ�����������������㣬�����޸ĸ�������ָ��ָ����������������
	//�������ݵ����ʸ����������������ʱ�����ӹ�ϵ�Ѿ��ı䣬����Ҫ�ȶ����������������������������㣬ȷ��������������������
	//�޸�����ָ�������ȷ����
	bstToDoubleList(pcur->lchild,pre);
	//���ʽ���޸�Ϊ����ָ��
	pcur->lchild = pre;
	if(nullptr!=pre) 
		pre->rchild = pcur;
	pre = pcur;  //���¼�¼��һ�η��ʵ�ָ�룬��Ϊ����Ҫ���ʵݹ��������binary->rchild��
	bstToDoubleList(pcur->rchild,pre);   //����������ˣ�ǰ���޸���ָ��
}
//���������4 6 8 10 12 14 16
//˫���������������4 6 8 10 12 14 16
//˫�������������16 14 12 10 8 6 4
//
//���������1 2 3 4 5
//˫���������������1 2 3 4 5
//˫�������������5 4 3 2 1
//
//���������1 2 3
//˫���������������1 2 3
//˫�������������3 2 1
//
//���������10
//˫���������������10
//˫�������������10
//
//���������
//�밴���������. . .
