//����ɾ��һ���ڵ㣬
//����գ�����һ���ڵ㣬ɾ������Ϊβ�ڵ�
//��������ڵ㣬O(1)��ɣ�β�ڵ�O(n),ƽ����O(1)*(n-1)+O(n)��/n = O(1);
#include<iostream>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;
}*List,node;
int deleteListNode(List* head,node* deleteNode);
void printList(List head);
void test(List* head,node* deleteNode);
#if 0
int main()
{
#if 1
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
	List head1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//ֻ��һ���ڵ������
	node* node6 = new node;
	List head2 = node6;
	node6->data = 8;
	node6->next = NULL;
#endif
	printList(head1);
	printList(head2);
	test(&head1,node3);  //ɾ���м�ڵ�
	test(&head1,node5);  //ɾ��β�ڵ�
	test(&head2,node6);  //����ֻ��һ���ڵ�
	List head3 = NULL;
	test(&head3,node2);   //ָ��Ϊ��
	printList(head1);
	printList(head2);
	system("pause");
}
#endif
void printList(List head)
{
	if(NULL==head)
		return ;
	while(head!=NULL)
	{
		cout<<head->data<<"\t";
		head = head->next;
	}
	cout<<endl;
}
int deleteListNode(List* head,node* deleteNode)
{
	if(NULL==(*head)||NULL==deleteNode)  //����Ҫ(*head)��������Դ���ֱ�Ӵ�NULL,NULL����Ҳ����һ����ַ��
		return -1;
	if(deleteNode->next!=NULL)  //�м�ڵ�,�������O(1)ʱ�临�Ӷ���ɾ���ڵ㣬���Բ��ÿ���ɾ������ͷ���,���������ú�һ���ڵ㸲��
	{
		node* tmp = deleteNode->next;
		deleteNode->data = deleteNode->next->data;
		deleteNode->next = deleteNode->next->next;
		delete tmp;
		tmp = NULL;
	}
	else if((*head)==deleteNode)//ֻ��һ���ڵ������
	{
		delete deleteNode;
		deleteNode = NULL;
		(*head) = NULL;  //����ͷ��㸳ֵNULL
	}
	else //���һ�������ɾ���������һ���ڵ�
	{
		List phead = (*head);
		while(phead->next!=deleteNode)
			phead = phead->next;
		phead->next = NULL;
		delete deleteNode;
		deleteNode = NULL;
	}
	return 0;
}
void test(List* head,node* deleteNode)
{
	deleteListNode(head,deleteNode);
	printList(*head);
}