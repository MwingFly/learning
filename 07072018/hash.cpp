#include<iostream>
#include<stdlib.h>
#define max  ~( 1<<(sizeof(int)*8-1) )
using namespace std;
//ɢ�к������ó���������
//��ͻ������ÿ��Ŷ�ַ��������̽�ⷨ
int hashFunc(int key,int length);
int initHashTable(int* hashTable,int length);  //�ɹ�����0��ʧ�ܷ���-1
int hashInsert(int* hashTable,int key,int length);   //�ɹ�����0��ʧ�ܷ���-1
static enum status{failture=-1,success=0} flag;
int hashSearch(int*hashTable,int key,int length);  
void test();
int main()
{
	test();
}
void test()
{
	int arr[12] = {12,67,56,16,25,37,22,29,15,47,48,34};
	int* hashTable = new int[12]();
	int ret = initHashTable(hashTable,12);
	if(-1==ret)
		cout<<"initHashTable fail!"<<endl;

	cout<<"��ϣ�������Ԫ�أ�";
	for(int idx=0;idx!=12;++idx)
	{
		cout<<arr[idx]<<" ";
		hashInsert(hashTable,arr[idx],12);
	}
	cout<<endl;

	cout<<"��ϣ��";
	for(int idx=0;idx!=12;++idx)
	{
		cout<<hashTable[idx]<<" ";
	}
	cout<<endl;

	cout<<"��Ӧ����Ԫ�������ڹ�ϣ�����Ԫ�أ�";
	for(int idx=0;idx!=12;++idx)
	{
		int ret = hashSearch(hashTable,arr[idx],12);
		if( ret==-1 && flag == failture)
		{
			cout<<"search "<<arr[idx]<<" fail"<<endl;
		}
		cout<<hashTable[ret]<<" ";
	}
	cout<<endl;
	cout<<"����1:"<<endl;
	int rett = hashSearch(hashTable,1,12);
	if( rett==-1 && flag == failture)
	{
		cout<<"search "<<1<<" fail"<<endl;
		return ;
	}
	cout<<hashTable[rett]<<endl;
}
int initHashTable(int* hashTable,int length)
{
	if(nullptr==hashTable || length<=0)
		return -1;
	for(int idx=0;idx!=length;++idx)
	{
		hashTable[idx] = max;
	}
	return 0;
}
int hashFunc(int key,int length)
{
	if(key==max||length<=0)
		return -1;
	return key % length;  //��������
}
int hashInsert(int* hashTable,int key,int length)
{
	if(nullptr==hashTable||length<=0)
		return -1;
	int hashAddr = hashFunc(key,length);
	if(-1==hashAddr)
		return -1;
	for(int idx=0;idx!=length;++idx)  //ѭ��������ϣ����
	{
		if(hashTable[hashAddr]!=max)  //��ͻ
			hashAddr = (hashAddr+1) % 12; //���Ŷ�ַ��������̽�ⷨ,������һ���ɴ�����ݵĿռ�
		else 
			break;
	}
	if(max==hashTable[hashAddr])
	{
		hashTable[hashAddr] = key;
		return 0;
	}
	return -1;
}
int hashSearch(int*hashTable,int key,int length)
{
	flag = success;
	if(nullptr==hashTable||length<=0)
	{
		flag = failture;
		return -1;
	}
	int hashAddr = hashFunc(key,length);
	while(key!=hashTable[hashAddr])
	{
		hashAddr = (hashAddr+1) % length;
		if(max==hashTable[hashAddr] || hashAddr == hashFunc(key,length))  //���̽�⵽��һ����ַΪ�գ���û���ҵ�������ѭ������һ���ֻص��ʼ��hashAddr
		{
			flag = failture;
			return -1;
		}
	}
	return hashAddr;
}
//��ϣ�������Ԫ�أ�12 67 56 16 25 37 22 29 15 47 48 34 
//��ϣ��12 25 37 15 16 29 48 67 56 34 22 47 
//��Ӧ����Ԫ�������ڹ�ϣ�����Ԫ�أ�12 67 56 16 25 37 22 29 15 47 48 34 
//����1:
//search 1 fail
