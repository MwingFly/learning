#include<iostream>
#include<string.h>
using namespace std;
void test();
void testNext(const char* tStr,int* next,int nextLen);
int makeNextArr(const char* tStr,int* next);
int KMP(const char* sStr,const char* tStr);
int main()
{
	test();

	const char* sStr = "abcabcabc";
	const char* tStr = "abcab";
	cout<<"main str:"<<sStr<<endl;
	cout<<"sub str:"<<tStr<<endl;
	KMP(sStr,tStr);
	cout<<endl;

	const char* sStr2 = "abcdefabcdef";
	const char* tStr2 = "abcab";
	cout<<"main str:"<<sStr2<<endl;
	cout<<"sub str:"<<tStr2<<endl;
	KMP(sStr2,tStr2);

}
void test()
{
	cout<<"---start test makeNextArr---"<<endl;
	const char* tStr = "abcdex";
	int next[6];
	testNext(tStr,next,6);
	cout<<endl;

	const char* tStr2 = "abcabx";
	int next2[6];
	testNext(tStr2,next2,6);
	cout<<endl;

	const char* tStr3 = "aaaaa";
	int next3[6];
	testNext(tStr3,next3,5);
	cout<<endl;

	const char* tStr4 = "abcab";
	int next4[5];
	testNext(tStr4,next4,5);
	cout<<endl;

	const char* tStr5 = "abaabb";
	int next5[6];
	testNext(tStr5,next5,6);
	cout<<endl;
	cout<<"---end test makeNextArr---"<<endl;
	cout<<endl;
}
void testNext(const char* tStr,int* next,int nextLen)
{
	cout<<tStr<<endl;
	makeNextArr(tStr,next);
	for(int idx=0;idx<nextLen;++idx)
		cout<<"next["<<idx<<"] = "<<next[idx]<<"   ";
	cout<<endl;
}

int makeNextArr(const char* tStr,int* next)
{
	if(NULL==tStr||NULL==next)
		return -1;
	next[0] = 0;  //��ʼnext[0] = 0;  ��ʾ����0���ַ�ƥ��ʧ��ʱ���´δӵ�0���ַ���ʼ
	//next�����±��ʾ���Ǵ�0��ʼ�ַ����еĵڼ����ַ�,ֵ��ʾ��һ����ƥ�䴮�ĵڼ����ַ�ȥ������ƥ��
	int k = 0;
	for(int idx=1;idx!=strlen(tStr);++idx)
	{
		while(k>0&&tStr[idx]!=tStr[k])
		{
			k = next[k-1];
		}
		if(tStr[idx]==tStr[k])
			++k;
		next[idx] = k;
	}
	return 0;
}
int KMP(const char* sStr,const char* tStr)
{
	if(NULL==sStr||NULL==tStr)
		return -1;
	int* next =new int[strlen(tStr)]();
	makeNextArr(tStr,next);
	for(int idx=0,iidx=0;idx!=strlen(sStr);++idx)
	{
		while(iidx>0&&sStr[idx]!=tStr[iidx])
		{
			iidx = next[iidx-1];  //��iidx��ƥ��ʧ�ܾ���0~iidx-1�е����ǰ��׺��
		}
		if(sStr[idx]==tStr[iidx])
			++iidx;
		if(iidx==strlen(tStr))
		{
			cout<<"sub str is start at "<<idx - (iidx - 1)<<endl;
			iidx = next[iidx-1];  //����Ѱ����һ��ƥ���λ�ã����赱ǰiidx���������һ������ȣ���Сiidx
		}
	}
	return 0;
}
//---start test makeNextArr---
//abcdex
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 0   next[4] = 0   next[5] = 0   
//
//abcabx
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 1   next[4] = 2   next[5] = 0   
//
//aaaaa
//next[0] = 0   next[1] = 1   next[2] = 2   next[3] = 3   next[4] = 4   
//
//abcab
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 1   next[4] = 2   
//
//abaabb
//next[0] = 0   next[1] = 0   next[2] = 1   next[3] = 1   next[4] = 2   next[5] = 0   
//
//---end test makeNextArr---
//
//main str:abcabcabc
//sub str:abcab
//sub str is start at 0
//sub str is start at 3
//
//main str:abcdefabcdef
//sub str:abcab
