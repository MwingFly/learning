//��Ŀ43��n�����ӵĵ�������n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs��
//����n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�
//˼·���ݹ飻�Ȱ�n�����ӷ�Ϊ���ѣ���һ��ֻ��һ��������һ����n-1������������һ���п��ܳ���1-6�ĵ�����
//���Σ������n-1��Ҳ���Էֳ����ѡ��ѵ�������һ������ֵ���ʼ��һ����ӡ��������εݹ飬���ھ�����󻮷ֵ���һ������Ϊ0
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void probability(int* proArr,int cnt,int remainCnt,int sum);   
//��һ�����������飬�������ÿ�������ֵĸ��ʣ��ڶ����������������������ǵڶ��ѵ������������һ����ǰ��һ�����ӵĵ�����
void printProbability(int cnt);
void test(int cnt);
int main()
{
	test(1);
	cout<<endl;

	test(2);
	cout<<endl;

	test(3);
	cout<<endl;
}
void test(int cnt)
{
	printProbability(cnt);
}
void printProbability(int cnt)
{
	if(cnt<=0)
		return ;
	int* proArr = new int[cnt*6];  //����������ÿ�ֿ��ܳ��ֵĵ�����
	memset(proArr,0,sizeof(int)*cnt*6);
	for(int idx=1;idx<=6;++idx)
	{
		probability(proArr,cnt,cnt-1,idx);   //��һ�����ӿ��ܳ���1~6�ĵ���
		//����һ�����ӳ��ֵ�����idx��ʱ�򣬵ݹ������cnt-1�����ӿ��ܳ��ֵĵ�����
	}
	int maxSum = cnt * 6;
	int permutation = pow(6,cnt);  //���е�����ȫ���У�����ÿ�������ֵĸ���Ҫ�õ�
	for(int idx=cnt;idx<=maxSum;++idx)
	{
		cout<<"sum is "<<idx<<" appear "<<(double)proArr[idx - cnt]<<
			" times and probability is "<<((double)proArr[idx - cnt]/permutation)<<endl;
		//��С���ܳ��ֵĺ;��ǵ���,����2�����ӣ���С�;���2��2-cnt=0,��Ӧ����ĵ�һ��λ��
	}
	delete []proArr;
}
void probability(int* proArr,int cnt,int remainCnt,int sum)
{
	if(NULL==proArr||cnt<=0)
		return ;
	else if(0==remainCnt)
	{
		++proArr[sum - cnt];
		return ;
	}
	//�ݹ���ʣ�µ����ӿ��ܳ��ֵĺ�
	for(int idx=1;idx<=6;++idx)
	{
		probability(proArr,cnt,remainCnt-1,sum+idx);
	}
}
//sum is 1 appear 1 times and probability is 0.166667
//sum is 2 appear 1 times and probability is 0.166667
//sum is 3 appear 1 times and probability is 0.166667
//sum is 4 appear 1 times and probability is 0.166667
//sum is 5 appear 1 times and probability is 0.166667
//sum is 6 appear 1 times and probability is 0.166667
//
//sum is 2 appear 1 times and probability is 0.0277778
//sum is 3 appear 2 times and probability is 0.0555556
//sum is 4 appear 3 times and probability is 0.0833333
//sum is 5 appear 4 times and probability is 0.111111
//sum is 6 appear 5 times and probability is 0.138889
//sum is 7 appear 6 times and probability is 0.166667
//sum is 8 appear 5 times and probability is 0.138889
//sum is 9 appear 4 times and probability is 0.111111
//sum is 10 appear 3 times and probability is 0.0833333
//sum is 11 appear 2 times and probability is 0.0555556
//sum is 12 appear 1 times and probability is 0.0277778
//
//sum is 3 appear 1 times and probability is 0.00462963
//sum is 4 appear 3 times and probability is 0.0138889
//sum is 5 appear 6 times and probability is 0.0277778
//sum is 6 appear 10 times and probability is 0.0462963
//sum is 7 appear 15 times and probability is 0.0694444
//sum is 8 appear 21 times and probability is 0.0972222
//sum is 9 appear 25 times and probability is 0.115741
//sum is 10 appear 27 times and probability is 0.125
//sum is 11 appear 27 times and probability is 0.125
//sum is 12 appear 25 times and probability is 0.115741
//sum is 13 appear 21 times and probability is 0.0972222
//sum is 14 appear 15 times and probability is 0.0694444
//sum is 15 appear 10 times and probability is 0.0462963
//sum is 16 appear 6 times and probability is 0.0277778
//sum is 17 appear 3 times and probability is 0.0138889
//sum is 18 appear 1 times and probability is 0.00462963
