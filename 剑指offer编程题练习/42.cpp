//��Ŀ42������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵�������ֻ����˳�򲻱䡣�����ź���ͨ��ĸһ������
//eg��"I am a student."��"student. a am I"
//˼·���ȶ�����ַ�����ת��Ȼ���ٶ�ÿһ�����ʷ�ת.
#include<iostream>
using namespace std;
void reverse(char* pBegin,char* pEnd);
void reverseSentence(char* pstr);
void test(char* str);
int main()
{
	char str[] = "  I  am a student.  ";  //�����ǳ����ַ���const char*����������ֳ��������ǲ��ܽ����ġ�
	test(str);
}
void test(char* str)
{
	cout<<str<<endl;
	reverseSentence(str);
	cout<<str<<endl;
	reverseSentence(str);
	cout<<str<<endl;
}
void reverseSentence(char* pstr)
{
	if(NULL==pstr)
		return ;
	//���������ӽ��з�ת
	char* pBegin = pstr;
	char* pEnd = pstr;
	while(*pEnd!='\0')
		++pEnd;
	reverse(pBegin,--pEnd);
	//�Ծ�����ÿ�����ʷ�ת
	pBegin = pEnd = pstr;
	while(*pBegin!='\0')
	{
		while(*pBegin==' ')
		{ //�ҵ���һ����Ϊ�ո���ַ�
			++pBegin;
			++pEnd;
		}
		while(*pEnd!=' '&&*pEnd!='\0')  //�ҵ��ַ�����ֵĵ�һ���ո�
		{
			++pEnd;
		}
		reverse(pBegin,--pEnd);  //�������ȼ�һ�����������ٴ���
		++pEnd;
		pBegin = pEnd;
	}
}
void reverse(char* pBegin,char* pEnd)
{
	if(NULL==pBegin||NULL==pEnd)
		return ;
	while(pBegin<pEnd)
	{
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		++pBegin;
		--pEnd;
	}
}
 //I  am a student.
 //student. a am  I
 //I  am a student.
