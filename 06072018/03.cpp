//��Ŀ28���ַ��������У�����һ���ַ�������ӡ�����ַ������������С�
//eg:�����ַ���abc,���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba
//˼·�����ַ����ĵ�һ���ַ���ʼ��һ�κͺ��������Ԫ�ؽ���
//������֮�����Ժ�����ַ����еĵ�һ��Ԫ�ؿ�ʼ����ǰ��һ�������������ַ����Ķ���Ԫ��
//����һ���ݹ����
#include<iostream>
using namespace std;
void test(char* str);
void permutationStr(char* str,char *beginStr);
int main()
{
	char str[] = "abc";
	test(str);
	cout<<endl;

	char str2[] = "a";
	test(str2);
	cout<<endl;

	char* str3 = NULL;
	test(str3);
	cout<<endl;

	char str4[] = "";
	test(str4);
	cout<<endl;

	system("pause");
}
void test(char* str)
{
	if(NULL==str)
		return ;
	cout<<"origin str="<<str<<endl;
	permutationStr(str,str);
}
void permutationStr(char* str,char *beginStr)
{
	if(NULL==str)
		return ;
	if(*beginStr=='\0')
		cout<<str<<endl;
	for(char* ch = beginStr;*ch!='\0';++ch)
	{
		char tmp = *ch;
		*ch = *beginStr;
		*beginStr = tmp;
		permutationStr(str,beginStr+1);
		//�ص㣬ǰ�潻������ԭʼ���ַ����޸��ˣ�����Ҫ�Ļ���
		//eg:��һ�ν���abc,�ڶ���bac,������cab
		//����Ҫ�Ľ����abc,bac,cba
		*beginStr = *ch;  
		*ch = tmp;
	}
}
//origin str=abc
//abc
//acb
//bac
//bca
//cba
//cab
//
//origin str=a
//a
//
//
//origin str=
