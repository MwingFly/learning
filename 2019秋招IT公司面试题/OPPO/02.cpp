#if 0
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc,char** argv)
{
	vector<int> N;
	//�����׼���뵽����N��
	int cnts;
	cin>>cnts;
	while(cnts)
	{
		int tmp;
		cin>>tmp;
		N.push_back(tmp);
		--cnts;
	}
	//��N������ȡ����������͵õ�����A
	vector<int> A;
	for(int idx=0;idx<N.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<N.size();++iidx)
		{
			A.push_back(N[idx]+N[iidx]);
		}
	}
	//��N������ȡ���������鲢���ľ���ֵ����������B
	vector<int> B;
	for(int idx=0;idx<N.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<N.size();++iidx)
		{
			B.push_back( abs(N[idx]-N[iidx]) );
		}
	}
	//��A��B������ȡ�������������ľ���ֵ��������D
	// ��AB��ϳ�Ԫ��D1
	vector<int> D1(A);
	for(auto elem:B)
		D1.push_back(elem);
	vector<int> D;
	for(int idx=0;idx<D1.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<D1.size();++iidx)
		{
			D.push_back( abs(D1[idx]-D1[iidx]) );
		}
	}
	//D�е�Ԫ�ش�С��������
	sort(D.begin(),D.end());
	int d1 = D[0],d2 = D[D.size()-1],s = D.size();
	cout<<d1+d2+s<<endl;
	system("pause");
}
#endif
//5
//101
//102
//103
//104
//105
//398
//�밴���������. . .