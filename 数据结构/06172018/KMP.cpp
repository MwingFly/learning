#include<iostream>
using namespace std;
void test();
void testNext(const char* tStr,int* next,int nextLen);
int makeNextArr(const char* tStr,int* next);
int KMP(const char* sStr,const char* tStr);
int main()
{
	test();

	char* sStr = "abcabcabc";
	char* tStr = "abcab";
	cout<<"主串："<<sStr<<endl;
	cout<<"匹配串："<<tStr<<endl;
	KMP(sStr,tStr);
	cout<<endl;

	char* sStr2 = "abcdefabcdef";
	char* tStr2 = "abcab";
	cout<<"主串："<<sStr2<<endl;
	cout<<"匹配串："<<tStr2<<endl;
	KMP(sStr2,tStr2);

	system("pause");
}
void test()
{
	cout<<"---start test makeNextArr---"<<endl;
	char* tStr = "abcdex";
	int next[6];
	testNext(tStr,next,6);
	cout<<endl;

	char* tStr2 = "abcabx";
	int next2[6];
	testNext(tStr2,next2,6);
	cout<<endl;

	char* tStr3 = "aaaaa";
	int next3[6];
	testNext(tStr3,next3,5);
	cout<<endl;

	char* tStr4 = "abcab";
	int next4[5];
	testNext(tStr4,next4,5);
	cout<<endl;

	char* tStr5 = "abaabb";
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
	next[0] = 0;  //初始next[0] = 0;  表示当第0个字符匹配失败时，下次从第0个字符开始
	//next数组下标表示的是从0开始字符串中的第几个字符,值表示下一个用匹配串的第几个字符去和主串匹配
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
			iidx = next[iidx-1];  //第iidx个匹配失败就找0~iidx-1中的最大前后缀。
		}
		if(sStr[idx]==tStr[iidx])
			++iidx;
		if(iidx==strlen(tStr))
		{
			cout<<"主串中第 "<<idx - (iidx - 1)<<" 的位置出现匹配串"<<endl;
			iidx = next[iidx-1];  //接着寻找下一个匹配的位置，假设当前iidx和主串最后一个不相等，减小iidx
		}
	}
	return 0;
}
//
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
//主串：abcabcabc
//匹配串：abcab
//主串中第 0 的位置出现匹配串
//主串中第 3 的位置出现匹配串
//
//主串：abcdefabcdef
//匹配串：abcab