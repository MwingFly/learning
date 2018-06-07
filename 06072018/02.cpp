//��Ŀ26��ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead);����һ����������
//		���������У�ÿ���ڵ������һ��m_pNextָ��ָ����һ������⣬����һ��m_pSiblingָ�������е�����
//		������NULL��
//˼·����֤ʱ�临�Ӷ�O(n),���ҿռ临�Ӷ�O(1);
//		����������һ�����ƽ���m_pNext,ͬʱ�Ѹ��ƵĽ�����ӵ�����ֵ�ڵ�֮��
//		�ڶ���������m_pSibling
//      ǰ�����õ��������ֳ�������������õ�����ԭʼ����ż����õ����Ǹ��ƺ������
#if 0
#include<iostream>
#include<stack>
typedef struct node
{
	int m_nValue;
	node* m_pNext;
	node* m_pSibling;
}*ComplexList,ComplexListNode;
using namespace std;
ComplexListNode* createNode(int m_value);
void buildNode(ComplexListNode* node,ComplexListNode* next,ComplexListNode* sibling);  //����ÿ���ڵ��ָ�� 
void printList(ComplexList head);

ComplexListNode* Clone(ComplexListNode* pHead);
void CloneNodes(ComplexListNode* pHead);  //��һ��
void ConnectSiblingNodes(ComplexListNode* pHead);  //�ڶ���
ComplexListNode* ReturnNewList(ComplexListNode* pHead);  //������
//���ǿ������Ͳ��ô�����ͷָ��ĵ�ַ
void printList(ComplexList head);
void test1();
void test2();  //siblingָ���Լ�
void test3();  //sibling�ɻ�
void test4();  //��ָ��
int main()
{
	test1();
	cout<<endl<<endl;
	test2();
	cout<<endl<<endl;
	test3();
	cout<<endl<<endl;
	test4();
	system("pause");
}
void test1()
{
/*
	   _______
      ��     |
	1->2->3->4->5
	|__|__��
	   |________��	 
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node5);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,NULL);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void test2()
{
/*
	   _______
       ��     |
	1->2->3->4->5
	|  ��
	|_____��  
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node2);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,NULL);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void test3()
{
/*
         ________
	   ��______ |
       ��     | |
	1->2->3->4->5   
	|  |_____��
	|_____��  
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node4);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,node4);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);

}
void test4()
{
	ComplexList head= NULL;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void printList(ComplexList head)
{
	if(NULL==head)
		return ;
	while(head!=NULL)
	{
		cout<<head->m_nValue;
		if(head->m_pSibling!=NULL)
			cout<<"("<<head->m_pSibling->m_nValue<<")"<<" -> ";
		else
			cout<<"(NULL)"<<" -> ";
		head = head->m_pNext;
	}
	cout<<"NULL"<<endl;
}
ComplexListNode* createNode(int m_value)
{
	ComplexListNode* node = new ComplexListNode;
	node->m_nValue = m_value;
	node->m_pNext = NULL;
	node->m_pSibling = NULL;
	return node;
}
void buildNode(ComplexListNode* node,ComplexListNode* next,ComplexListNode* sibling)
{
	node->m_pNext = next;
	node->m_pSibling = sibling;
}
void CloneNodes(ComplexListNode* pHead)
{
	if(NULL==pHead)
		return ;
	ComplexListNode* pCurNode = pHead;
	while(pCurNode!=NULL)
	{
		ComplexListNode* pCloneNode = new ComplexListNode;
		pCloneNode->m_nValue = pCurNode->m_nValue;
		pCloneNode->m_pNext = pCurNode->m_pNext;
		pCloneNode->m_pSibling = NULL;  //����ڶ���������
		pCurNode->m_pNext = pCloneNode;
		pCurNode = pCloneNode->m_pNext;
	}
}
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if(NULL==pHead)
		return ;
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pCloneNode = NULL;
	while(pCurNode!=NULL)
	{
		pCloneNode = pCurNode->m_pNext;
		if(pCurNode->m_pSibling!=NULL)
			pCloneNode->m_pSibling = pCurNode->m_pSibling->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
}
ComplexListNode* ReturnNewList(ComplexListNode* pHead)
{ //���������������ż�����
	if(NULL==pHead)
		return NULL;
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;
	if(pCurNode!=NULL)
	{//���ȳ�ʼ����������ͷ���
		pCloneHead = pCloneNode = pCurNode->m_pNext;  
	 //pCurNode��ǰƫ��
		pCurNode->m_pNext = pCloneNode->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
	while(pCurNode!=NULL)
	{
		pCloneNode->m_pNext = pCurNode->m_pNext;
		pCloneNode = pCurNode->m_pNext;
		pCurNode->m_pNext = pCloneNode->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
	return pCloneHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	ComplexListNode* newList = ReturnNewList(pHead);
	return newList;
}
#endif
//1(3) -> 2(5) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//1(3) -> 2(5) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//
//
//1(3) -> 2(2) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//1(3) -> 2(2) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//
//
//1(3) -> 2(4) -> 3(NULL) -> 4(2) -> 5(4) -> NULL
//1(3) -> 2(4) -> 3(NULL) -> 4(2) -> 5(4) -> NULL