//��Ϊһ���ִ����ˣ��н������㶩����һ������n����ɫ������ִ�����ÿ������Ҫô��ɫ��
//ҪôͿ����������ɫ��Ϊ��ʹ�ִ���ɫ�ʿ���������ô����������Ҫ���ִ��ϵ�����һ����ɫ����������ɫ����
//������������m���������������һ�Σ�ע�������ִ���һ�����Σ����ִ��ϵ���ɫһ����c�֡����ڰ�˳ʱ���������n��������ִ��ϣ�ÿ������������������ɫ�ֱ�����Щ�������жϸ��ִ����ж�������ɫ������Ҫ�󡣼�ѯ���ж�������ɫ����������m�������г������������Ρ�
//
//��������:
//
//��һ������n��m��c���������ÿո������(1 <= n <= 10000, 1 <= m <= 1000, 1 <= c <= 50) ������n��ÿ�еĵ�һ����num_i(0 <= num_i <= c)��ʾ��i�������ж�������ɫ�����������ζ���num_i�����֣�ÿ������x��ʾ��i�������ϰ�����x����ɫ(1 <= x <= c)
//
//�������:
//
//һ���Ǹ���������ʾ���������ж�������ɫ��������
//
//��������1:
//
//5 2 3
//3 1 2 3
//0
//2 2 3
//1 2
//1 3
//
//
//�������1:
//
//2
//
//
//����˵��1:
//
//��һ����ɫ�����ڵ�1�Ŵ��飬������޳�ͻ��
//�ڶ�����ɫ�ֱ�����ڵ� 1��3��4�Ŵ��飬��3�����4�Ŵ������ڣ����Բ���Ҫ��
//��������ɫ�ֱ�����ڵ�1��3��5�Ŵ��飬��5�Ŵ������һ���ǵ�1�ţ����Բ���Ҫ��
//�ܼ���2����ɫ�ķֲ���������ġ� 
//�����2�Ŵ�����͸���ġ�
//
#if 0
#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	map<int,set<int> > inputData;  //��ɫ����Ӧ���ֹ�������
	//for(int idx=1;idx<=c;++idx)
	//{
	//	set<int> tmp;
	//	inputData[idx] = tmp;
	//}
	for(int idx=1;idx<=n;++idx)
	{
		int cntC;
		cin>>cntC;
		for(int iidx=0;iidx!=cntC;++iidx)
		{
			int color;
			cin>>color;
			if(0!=color)
				inputData[color].insert(idx);
		}	
	}
	//����
	int answer = 0;
	for(int idx=1;idx<=c;++idx)
	{
		set<int> value = inputData[idx];  //�õ���idx����ɫ���ֹ������ӱ��
		auto it=value.begin();
		bool flag = false;
		for(;it!=value.end();)
		{
			auto nextIt = it;
			++it;
			if(it!=value.end())
				if((*it-*nextIt)+1<=m)
				{
					++answer;
					flag = true;
					break;
				}

		}
		if(false==flag)
		{
			auto endIt = --value.end();
			if(endIt!=value.begin())
				if(((*endIt+m)%n-1)>=*(value.begin()))
					++answer;
		}	
	}
	cout<<answer<<endl;
	//system("pause");
}
#endif