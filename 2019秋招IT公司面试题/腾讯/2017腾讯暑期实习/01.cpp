//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
//
//��������:
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.
//  
//�������:
//
//����ÿ�����ݣ����һ������������������Ҫɾ�����ַ�������
//
//��������1:
//
//abcda
//google
//
//�������1:
//
//2
//2
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int max(int& a,int& b,int&c )
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main(int argc,char** argv)
{
	string data;
	vector<int> answer;
	while(cin>>data)
	{
		int dataLen = data.size();
		//�����ά����
		int** arr = new int*[dataLen+1];
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[idx] = new int[dataLen+1];
		}
		//��ת
		string dataReverse(data);
		for(int idx=0;idx!=dataLen;++idx)
		{
			dataReverse[idx] = data[dataLen-1-idx];
		}
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[0][idx] = 0;
		}
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[idx][0] = 0;
		}
		for(int idx=1;idx<=dataLen;++idx)
		{
			for(int iidx=1;iidx<=dataLen;++iidx)
			{
				if(data[idx-1]==dataReverse[iidx-1])
					arr[idx][iidx] = arr[idx-1][iidx-1] + 1;
				else 
					arr[idx][iidx] = max(arr[idx][iidx-1],arr[idx-1][iidx],arr[idx-1][iidx-1]);
			}
		}
		answer.push_back(dataLen-arr[dataLen][dataLen]);
		//�ͷ�
		for(int idx=0;idx<=dataLen;++idx)
		{
			delete []arr[idx];
			arr[idx] = NULL;
		}
		delete []arr;
		arr = NULL;
	}
	for(auto&elem:answer)
		cout<<elem<<endl;
	//system("pause");
}
#endif