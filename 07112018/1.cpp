//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int deleteCharacterCnt(const string& str1);
void test();
int main()
{
	test();
	system("pause");
}
void test()
{
	string str1;
	while(cin>>str1)
	{
		int ret = deleteCharacterCnt(str1);
		if(-1!=ret)
			cout<<ret<<endl;
	}
}
int max(const int& a,const int& b,const int c)
{
	return (a>b)?(a>c?a:c):(b>c?b:c);
}
int deleteCharacterCnt(const string& str1)
{
	if(str1.size()<1||str1.size()>1000)
		return -1;
	if(1==str1.size())
		return 1;
	int strLen = str1.size();
	string str2(str1);
	reverse(str2.begin(),str2.end());
	int** arr = new int*[strLen+1];
	for(int idx=0;idx<=strLen;++idx)
		arr[idx] = new int[strLen+1]();

	//��ʼ����ά�����һ��
	for(int idx=0;idx<=strLen;++idx)
	{
			arr[0][idx] = 0;
			arr[idx][0] = 0;
	}
		
	//������
	for(int idx=1;idx<=strLen;++idx)
	{
		for(int iidx=1;iidx<=strLen;++iidx)
		{
			if(str1[idx]==str2[iidx])
				arr[idx][iidx] = arr[idx-1][iidx-1] + 1;
			else
				arr[idx][iidx] =  max( arr[idx-1][iidx] , arr[idx][iidx-1] );
		}
	}
	int result = strLen - arr[strLen][strLen];
	for(int idx=0;idx<=strLen;++idx)
	{
		delete []arr[idx];
		arr[idx] = NULL;
	}
	delete []arr;
	arr = NULL;
	return result;
}
