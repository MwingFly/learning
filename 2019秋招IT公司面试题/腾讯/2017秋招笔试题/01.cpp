//�ٶ�һ�ֱ���ı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰѸñ��밴�ֵ��������γ�һ���������£� a, aa, aaa, aaaa, aaab, aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy ����a��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ� ��дһ������������������һ�����룬�����������Ӧ��Index.
//��������:
//����һ����������ַ���,�ַ�������С�ڵ���100.
//�������:
//�����������index
#if 0
#include<iostream>
#include<string>
using namespace std;
int index(const string& str);
int main()
{
	string str;
	cin>>str;
	cout<<index(str);
	//system("pause");
}
int index(const string& str)
{
	if(""==str)
		return -1;
	static const int NUM = 25;
	//����������ÿһλ�Ĳ�ֵ
	// 0 1 2 3��Ӧ�ַ��������ҵ�λ��
	int cnt[4] = {1};
	for(int idx=1;idx!=4;++idx)
	{
		cnt[idx] = NUM*cnt[idx-1] + 1;
	}
	int index = 0;
	//ԭ�ַ����Ӹ�λ����λ
	for(int idx=0;idx!=str.size();++idx)
	{
  		index += (str[idx] - 'a')*cnt[4-idx-1] + 1;  //��1�Ǽ�����
	}
	return index - 1; //���λ����+1������ͳһ�������Լ���1
}
#endif