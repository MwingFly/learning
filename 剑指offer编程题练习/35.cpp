//��Ŀ35�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������'b'��
//˼·��ϰ����˼ά���Ǵ�ͷ��ʼ�����ƽ⣬���Ӷ�O(n^2);
//�ַ���ASCII��ռһ���ֽڣ���256�ֿɱ�ʾ���ַ������ﲻ�ٽ�����26��Ӣ���ַ���
//����һ���򵥵�hash��һ������4���ֽڣ�2^2*2^8=1K��С����һ��ȫ����ʼ��Ϊ0��
//�����ַ�����ÿ���ַ������ASCII����Ϊ�����±꣬��Ӧ��ֵ+1.����ٴα����ַ������ҳ���һ�����ִ���Ϊ1���ַ���
#if 1
#include<iostream>
#include<string>
using namespace std;
char findFirstAppearOneceChar(const char* str);
void test(const char* str,char expected);
int main()
{
	test("abaccdeff",'b');
	cout<<endl;

	test("aabbcc",-1);
	cout<<endl;

	test("abcabder",'c');
	cout<<endl;

	test("",-1);
	cout<<endl;

	const char* str = NULL;
	test(str,-1);
	system("pause");
}
void test(const char* str,char expected)
{
	if(findFirstAppearOneceChar(str)==expected)
		return;
	else
		cout<<str<<" "<<findFirstAppearOneceChar(str)<<" false"<<endl;
}
char findFirstAppearOneceChar(const char* str)
{
	if(NULL==str)
		return -1;
	char* hashTable = new char[256];  //һ���ֽڿ��Ա�ʾ256���ַ�
	memset(hashTable,0,256);
	const char* pstr = str;
	while(*pstr!='\0')
	{
		++hashTable[(int)(*pstr)];
		pstr++;
	}
	pstr = str;
	while(*pstr!='\0')
	{
		if(hashTable[(int)(*pstr)]==1)
			return *pstr;
		++pstr;
	}
	return -1;
}
#endif