//����ĵ�һ��Ϊһ��������T����ʾ�������������� ��������T�����ݡ�ÿ�����ݵĵ�һ�а�����������m��n��
//��ʾ�ַ��������������������������m�У�ÿһ��Ϊһ������Ϊn���ַ�������˳���ʾÿһ��֮�е��ַ���
//�ٽ���������һ�а���һ���ַ�������ʾҪѰ�ҵĵ��ʡ�  ���ݷ�Χ�� �����������ݣ�������1<=T<=9��
//�����������λ���ַ�����͵����е��ַ���Ϊ��д��ĸ��ҪѰ�ҵĵ������Ϊ2���ַ����Ϊ9���ַ���
//�ַ����������������СΪ1�����Ϊ99�� ��������50%�������ļ����ַ������������������Ϊ���Ϊ20��
//

//�������:
//
//����ÿһ�����ݣ����һ�У�����һ��������Ϊ�ڸ������ַ��������ҵ������ĵ��ʵĺϷ���������
//
//��������1:
//
//3
//10 10
//AAAAAADROW
//WORDBBBBBB
//OCCCWCCCCC
//RFFFFOFFFF
//DHHHHHRHHH
//ZWZVVVVDID
//ZOZVXXDKIR
//ZRZVXRXKIO
//ZDZVOXXKIW
//ZZZWXXXKIK
//WORD
//3 3
//AAA
//AAA
//AAA
//AA
//5 8
//WORDSWOR
//ORDSWORD
//RDSWORDS
//DSWORDSW
//SWORDSWO
//SWORD
//
//
//�������1:
//
//4
//16
//5
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
static int cnts = 0;
void statistic(char (*arr)[99],int rows,int colums,string words);
int main()
{
	int demos;
	cin>>demos;
	vector<int>  answer;
	char dataArr[99][99];
	while(demos)
	{
		int rows,colums;
		cin>>rows>>colums;
		string tmp;
		for(int idx=0;idx!=rows;++idx)
		{
			cin>>tmp;
			for(int iidx=0;iidx!=colums;++iidx)
			{
				dataArr[idx][iidx] = tmp[iidx];
			}
		}
		cnts = 0;
		string words;
		cin>>words;
		statistic(dataArr,rows,colums,words);
		answer.push_back(cnts);
		--demos;
	}
	for(auto&elem:answer)
		cout<<elem<<endl;
	//system("pause");
}
void core(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words);
void statistic(char (*arr)[99],int rows,int colums,string words)
{
	if(NULL==arr)
		return ;
	for(int idx=0;idx!=rows;++idx)
	{
		for(int iidx=0;iidx!=colums;++iidx)
		{
			string tmp;
			core(arr,rows-1,colums-1,idx,iidx,tmp,words);
		}
	}
}
void rightCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//�ҷ�
	rightCore(arr,rows,colums,mrows,mcolums+1,tmp,words);
}
void downCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//�·�
	downCore(arr,rows,colums,mrows+1,mcolums,tmp,words);
}
void rightDownCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//����
	rightDownCore(arr,rows,colums,mrows+1,mcolums+1,tmp,words);
}

void core(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//�ҷ�
	rightCore(arr,rows,colums,mrows,mcolums+1,tmp,words);
	//�·�
	downCore(arr,rows,colums,mrows+1,mcolums,tmp,words);
	//����
	rightDownCore(arr,rows,colums,mrows+1,mcolums+1,tmp,words);
}
#endif