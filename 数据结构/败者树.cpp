//ģ��һ��С��Χ�İ�������·�鲢
//��������Դ����5�����飬����Щ���鶼Ҫ������ģ�����ģ�
#include<iostream>
#include<vector>
#include<limits>
#include<string.h>
using namespace std;
static const int DataSourceNumber = 5;  //����Դ���������
//��������Դ��һ��5��������ÿ������������Ԫ��
int arr[DataSourceNumber][2] = {
	{10,9},{9,8},{11,7},{8,6},{8,7}
};
//�����Ҷ�ӽ�����飬��Ҷ�ӽ���ֵ��ʾ�ý���¼������һ��������Դ��ֵ
int treeNode[DataSourceNumber];

//����Ҷ�ӽ�����飬��Ӧ������С���ʾ���Ǹ�����Դ��ֵ��ʾ����Դ�е�����
int node[DataSourceNumber];

//��������Դ��ƫ��ָ�����ݣ���Ϊÿ�δ�����Դ�ж�ȡ��һ�����ݣ���Ӧ��������Ҫƫ�Ƶ���һλ
int Iterator[DataSourceNumber] = {0};  //��ʼ��ȫΪ0����Ϊÿ����Դ����Ҫ�ӵ�0�����ݿ�ʼȡ

//�����ȡҶ�ӽ���ֵ�ĺ���
int get(int index)
{
	return node[index];
}

//��������Ҷ�ӽ���ֵ�ĺ���
void set(int index)
{
	if(Iterator[index] == 2)
	{
		node[index] = numeric_limits<int>::min();
		return ;
	}
	node[index] = arr[index][Iterator[index]] ; //���node[index]��ֵ����index������Դ�ĵ�Iterator[index]��ֵ��
	//֮��Ҫ����Iterator[index]ƫ�Ƶ���һ��,�����´β���ȡ����һ��ֵ���ö�Ӧ��node���
	Iterator[index] += 1;
}
void adjust(int index)  //��������node���index��ʼ���ϵ���
{
	//�ҵ�index��Ӧ�ĸ����
	int father = (index + DataSourceNumber)>>1;
	while(father>0)  
	{
		if( get(treeNode[father])>get(index) )  //�͸����Ƚϣ����ߵ��������¸����
		{
			int tmp = treeNode[father];
			treeNode[father] = index;
			index = tmp;  //���ϼ����Ƚϣ�����index
		}
		father /= 2;
	}
	treeNode[0] = index;  //����ʤ��
}
//���ð������ĳ�ʼ������
void init()
{//������Ҫ�ҳ���С��ָ��������������������Դ�������׸�Ԫ����������Դ��������ʼ����Ҷ�ӽ��
	//Ȼ��ʼ����
	memset(Iterator,0,sizeof(Iterator));   //
	//1������node
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		set(idx);
	}
	int MAX = 0;  //��ʼ���Ԫ����������Դ0
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		if(node[idx]>node[MAX])
			MAX = idx;
	}
	//2����ʼ��treeNode
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		treeNode[idx] = MAX;
	}
	//3����ʼ�����һ����Ҷ�ӽ�����
	for(int idx=DataSourceNumber-1;idx>=0;--idx)
	{
		adjust(idx);
	}
}
vector<int> merge(int cnt)  //Ҫ���cnt���ٸ�ֵ
{
	vector<int> ans;
	while(cnt)
	{
		ans.push_back(node[treeNode[0]]);  //��������0�Žڵ��ŵľ��ǵ�ǰ��С��nodeֵ����
		set(treeNode[0]);  //���һ����Ҫ���¶�Ӧ��Ҷ�ӽ���ֵ
		adjust(treeNode[0]);  //����
		--cnt;
	}
	return ans;
}
int main()
{
	init();
	vector<int> ret = merge(5);
	for(auto elem:ret)
		cout<<elem<<" ";
	cout<<endl;


	init();
	vector<int> ret2 = merge(10);
	for(auto elem:ret2)
		cout<<elem<<" ";
	cout<<endl;
	//system("pause");
}
//11 10 9 9 8 
//11 10 9 9 8 8 8 7 7 6 
