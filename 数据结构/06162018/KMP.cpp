#include<iostream>
using namespace std;
#if 0
void makeNextArr(const char* tStr,int* next);
//KMP�㷨�У�next������next[i]��ֵ�ĺ������:ƥ�䴮��0~i�е����ǰ��׺����
//ѧϰ���ͣ�https://blog.csdn.net/ebowtang/article/details/49129363
void KMP(const char* sStr,const char* tStr);
void testNext(const char* tStr,int* next,int nextLen);
void test();
int main()
{
	test();

	char* sStr = "abcabcabc";
	char* tStr = "abcab";
	cout<<"������"<<sStr<<endl;
	cout<<"ƥ�䴮��"<<tStr<<endl;
	KMP(sStr,tStr);
	cout<<endl;

	char* sStr2 = "abcdefabcdef";
	char* tStr2 = "abcab";
	cout<<"������"<<sStr2<<endl;
	cout<<"ƥ�䴮��"<<tStr2<<endl;
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
void makeNextArr(const char* tStr,int* next)
{
	if(NULL==tStr||NULL==next)
		return ;
	int k = 0;  //ģʽƥ�����kֵ����Ϊ0
	//kֵ��ʾ���ƥ�䴮�������ĵ�0���ַ�ƥ��ʧ�ܣ���ô��һ�λ�����ƥ�䴮�ĵ�0���ַ�����������һ���ַ���ʼƥ��
	next[0] = 0;  //eg:S��ʾ������T��ʾƥ�䴮��S[i] != T[0],��ô�´�ƥ�� (S[i+1],T[0])
	for(int idx = 1;idx<strlen(tStr);++idx)  //ѭ����������nextֵ
	{
		while(tStr[idx]!=tStr[k] &&
			k>0)  //������һ��next��ֵ�������ȣ��ۼ�k�����Ⱦ��ж�kֵ�Ƿ����0������0�����ż���S[0]~S[k-1]�е����ǰ��׺
		{
			k = next[k-1];   //��0���ַ���next[0] = 0;��k-1���ַ������ǰ��׺����next[k-1]��
		}
		if(tStr[idx]==tStr[k])
			++k;
		next[idx] = k;
	}
}
void KMP(const char* sStr,const char* tStr)
{
	if(NULL==sStr||NULL==tStr)
		return ;
	int sStrLen = strlen(sStr);
	int tStrLen = strlen(tStr);
	int* next = new int[tStrLen]();
	makeNextArr(tStr,next);
	for(int idx=0,iidx=0;idx<sStrLen;++idx)
	{
		while(iidx>0&&
			sStr[idx]!=tStr[iidx])
		{
			iidx = next[iidx-1];   //ƥ�䴮�е�iidx����������idx�����еȣ���С���ݣ��Ƚ�ƥ�䴮�е�next[iidx-1]����
		}
		if(sStr[idx]==tStr[iidx])
		{
			++iidx;  //iidx�ӵ���ƥ���ַ���������ȵ�ʱ��ͱ�ʾ�ҵ�һ���Ӵ�
		}
		if(iidx==tStrLen)
		{
			cout<<"find sub str,pos is:"<<idx-(iidx-1)<<endl;
			//�п����������ж���Ӵ�������next���飬���ٻ��ݣ�������һ����
			iidx = next[iidx-1];
		}
	}
}
#endif
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
//������abcabcabc
//ƥ�䴮��abcab
//find sub str,pos is:0
//find sub str,pos is:3
//
//������abcdefabcdef
//ƥ�䴮��abcab