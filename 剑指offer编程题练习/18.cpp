//��Ŀ18���������ö�����A��B���ж�B�ǲ���A���ӽṹ��
//˼·������ǰ��������ʸ�����������ÿ�η��ʵĽ�㶼�Ͷ�����Bȥƥ�䣬����������ͷ���true���ݹ�ͺܼ���
#include<iostream>
#include<string>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //����������
bool judgeIsSubTree(const pBinaryTreeNode& binaryTree1,const pBinaryTreeNode& binaryTree2);
bool isSubTree(const pBinaryTreeNode& tree1,const pBinaryTreeNode& tree2);
void test();
void test2();
void test3();  //BΪ��
void test4();  //AΪ��
void test5();  //AB��Ϊ��
int main()
{
	test();
	test2();
	test3();
	test4();
	test5();
}
void test()
{
	string tree1data = "889##24##7##7##";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test2()
{
	string tree1data = "889##34##7##7##";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test3()
{
	string tree1data = "889##34##7##7##";
	string tree2data = "";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test4()
{
	string tree1data = "";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test5()
{
	string tree1data = "";
	string tree2data = "";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
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
bool judgeIsSubTree(const pBinaryTreeNode& binaryTree1,const pBinaryTreeNode& binaryTree2)
{  //ǰ�����
	bool flag = false;
	if(nullptr==binaryTree2)
	{  //Ҫƥ��������ǿգ��϶������ӽṹ��
		flag = true;
		return flag;
	}
	if(nullptr!=binaryTree1)
	{
		if(binaryTree1->data == binaryTree2->data)
		{ //�����ֵ��ͬ����һ�������ǲ����ӽṹ
			flag = isSubTree(binaryTree1,binaryTree2);
		}
		if(false==flag)  //���ûƥ�䵽������������������
			flag = judgeIsSubTree(binaryTree1->lchild,binaryTree2);
		if(false==flag)  //������Ҳûƥ�䵽�����������������
			flag = judgeIsSubTree(binaryTree1->rchild,binaryTree2);
	}
	return flag;
}
bool isSubTree(const pBinaryTreeNode& tree1,const pBinaryTreeNode& tree2)
{
	if(nullptr==tree2)
		return true;
	if(nullptr==tree1)
		return false;
	if(tree1->data!=tree2->data)
		return false;
	//�����ȣ���Ҫ�ж��������
	return isSubTree(tree1->lchild,tree2->lchild) && isSubTree(tree1->rchild,tree2->rchild);
}
//tree1=889##24##7##7## tree2=89##2##
//1
//tree1=889##34##7##7## tree2=89##2##
//0
//tree1=889##34##7##7## tree2=
//1
//tree1= tree2=89##2##
//0
//�밴���������. . .
