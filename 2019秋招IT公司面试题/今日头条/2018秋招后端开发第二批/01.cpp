//Ϊ�˲����Ż��Ƽ�Ч��������ͷ��ÿ��Ҫ�洢�ʹ��������ݡ�����������һ�ֳ��������Ƕ��û��������ǵ�ע��ʱ���Ⱥ�����ţ�����һ�����£�ÿ���û����в�ͬ��ϲ��ֵ�����ǻ���֪��ĳһ��ʱ����ע����û������������һ���û����У��ж����û�����������ϲ��ֵΪk����ΪһЩ�����ԭ�򣬲������һ����ѯ���û�������ȫ������һ����ѯ���û�����(������L1<=L2<=R2<=R1)��
//
//��������:
//
//���룺 ��1��Ϊn�����û��ĸ��� ��2��Ϊn����������i�������û����Ϊi���û���ĳ�����µ�ϲ�ö� ��3��Ϊһ��������q�����ѯ������  ��4�е��ڣ�3+q���У�ÿ�а���3������l,r,k����һ���ѯ�������Ϊl<=i<=r���û��ж���������ϲ��ֵΪk���û��ĸ����� ���ݷ�Χn <= 300000,q<=300000 k������
//
//�������:
//
//�����һ��q�У�ÿ��һ����������ϲ��ֵΪk���û��ĸ���
//
//��������1:
//
//5
//1 2 3 3 5
//3
//1 2 1
//2 4 5
//3 5 3
//
//
//�������1:
//
//1
//0
//2
//
//
//����˵��1:
//
//��������:
//��5���û���ϲ��ֵΪ�ֱ�Ϊ1��2��3��3��5��
//��һ��ѯ�ʶ��ڱ��[1,2]���û�ϲ��ֵΪ1���û��ĸ�����1
//�ڶ���ѯ�ʶ��ڱ��[2,4]���û�ϲ��ֵΪ5���û��ĸ�����0
//������ѯ�ʶ��ڱ��[3,5]���û�ϲ��ֵΪ3���û��ĸ�����2
#if 0
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	unordered_multimap<int,int> inputData;  //��һ��int��ϲ�ö�k���ڶ����Ƕ�Ӧ�ĵ�i���û�
	for(int idx=1;idx<=n;++idx)
	{
		int tmp;
		cin>>tmp;
		inputData.insert(::make_pair(tmp,idx));
	}
	int queryCnt;
	cin>>queryCnt;
	vector<int> answer;
	for(int idx=0;idx!=queryCnt;++idx)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int result = 0;
		auto pair = inputData.equal_range(k);
		for(auto it=pair.first;it!=pair.second;++it)
		{
			if((*it).second>=l&&(*it).second<=r)
				++result;
		}
		answer.push_back(result);
	}
	for(auto elem:answer)
		cout<<elem<<endl;
	//system("pause");
}
#endif
