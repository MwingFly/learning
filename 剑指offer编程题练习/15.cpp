//��Ŀ15������һ����������������е�����k���ڵ㡣
//ע������³����
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*pList,Node;
Node* findKthToTail(pList head,int k);
void print(pList head);
void test(pList head,int k);

int main()
{
	node* node1 = new node;
	node1->data = 1;
	node1->next = NULL;
	node *node2 = new node;
	node2->data = 2;
	node2->next = NULL;
	node* node3 = new node;
	node3->data = 3;
	node3->next = NULL;
	node* node4 = new node;
	node4->data = 4;
	node4->next = NULL;
	node* node5 = new node;
	node5->data = 5;
	node5->next = NULL;
	pList head1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//ֻ��һ���ڵ������
	node* node6 = new node;
	pList head2 = node6;
	node6->data = 8;
	node6->next = NULL;

	print(head1);
	print(head2);
	test(head1,3);
	test(head1,1);
	test(head1,5);
	test(head2,1);
	test(NULL,2);
	test(head2,2);
	system("pause");
}

Node* findKthToTail(pList head,int k)
{
	if(NULL==head||k<=0)
		return NULL;
	Node* pFront = head;
	Node* pBehind = NULL;
	for(int idx=0;idx!=k-1;++idx)  //������k����k-1
	{
		if(pFront->next!=NULL)
		{
			pFront = pFront->next;
		}
		else 
		{
			return NULL;
		}
	}
	pBehind = head;
	while(pFront->next!=NULL)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
void print(pList head)
{
	if(NULL==head)
		return ;
	while(head->next!=NULL)
	{
		cout<<head->data<<"\t";
		head = head->next;
	}
	cout<<head->data<<"\t";
	cout<<endl;
	return ;
}
void test(pList head,int k)
{
	Node* res = findKthToTail(head,k);
	if(NULL==res)
		return ;
	cout<<res->data<<endl;
}
//�����Ŀ
//��������м�ڵ㣬��������н������Ϊ�����������м��㣻ż�������м�������������һ����
//˼·����������ָ�룬ͬʱ�������ͷ��������һ��ָ��һ����һ������һ��ָ��һ����������
//�ߵĿ��ָ�뵽����ĩβʱ���ߵ�����ָ��ָ���������м䡣

//�ж�һ�����������Ƿ��γ��˻��νṹ��
//˼·���ߵĿ��ָ���ߵ�������ĩβҲû��׷���ߵ�����ָ��˵��û�л���
