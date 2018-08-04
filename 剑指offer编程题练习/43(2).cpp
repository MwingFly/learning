//��Ŀ43(�ǵݹ�ⷨ��ʱ�临�Ӷȵ�)��
//˼·���������������洢���ӵ�����ÿһ���������ֵĴ�������һ�����ӵ�ʱ��
//��һ�������ֵ����{0,1,1,1,1,1,1}����Ķ���0����Ӧ��0,1,2,3,4,5,6���ܳ��ֵĴ�������Ϊֻ��һ�����ӣ�ֻ��1�Σ����������±��Ӧ
//��ʱ���һ�����飬�ڶ��������Ӧ�ĺ;�Ϊǰһ�������Ӧ�ĺ�Ϊn-1,n-2,n-3,n-4,n-5,n-6���ܳ��ֵĴ����ĺͣ�
//��Ϊ���⼸������¶���ͨ������һ�����ӳ��ֶ�Ӧ�����ִﵽ��Ϊn��
//�ڶ���������ܳ��ֵĺ�2,3,4,5,6,7,8,9,10,11,12���������(ǰ������0,0){1,2,3,4,5,6,5,4,3,2,1};
//��Ϊ7�͵�����һ�������±�Ϊ6+5+4+3+2+1 = 1+1+1+1+1+1 = 6
#if 1
#include<iostream>
using namespace std;
#define maxDiceNum 6  //��ߴ������չ�ԣ��Ժ����ӵĵ�����Ϊ7��������λ������ֻҪ�����޸�
void printProbabilityOfDice(int cnt);
void test(int cnt);
int main()
{
	test(1);
	cout<<endl;

	test(2);
	cout<<endl;

	test(3);
	cout<<endl;
	system("pause");
}
void test(int cnt)
{
	printProbabilityOfDice(cnt);
}
void printProbabilityOfDice(int cnt)
{
	if(cnt<=0)
		return;
	int* arr[2];
	arr[0] = new int[cnt*maxDiceNum+1];
	arr[1] = new int[cnt*maxDiceNum+1];
	//�������ʼ��
	memset(arr[0],0,(cnt*maxDiceNum+1)*sizeof(int));
	memset(arr[1],0,(cnt*maxDiceNum+1)*sizeof(int));

	int arrNum = 0;  //�������飬�ʼ�ӵ�һ����ʼ�����渳ֵ
	//���һ������������Ե�һ�����鸳ֵ
	for(int idx=1;idx<=maxDiceNum;++idx)
		arr[arrNum][idx] = 1;
	//��ʼ�������ͳ��ֵĴ���
	for(int idx=2;idx<=cnt;++idx)
	{
		arrNum = (idx&1)^1;
		for(int iidx=0;iidx<idx;++iidx)
		{
			arr[arrNum][iidx] = 0;
		}
		for(int iiidx=idx;iiidx<=idx*maxDiceNum;++iiidx)
		{//��ǰ���Ӹ������ܳ��ֵĺ�
			arr[arrNum][iiidx] = 0;  //��һ�α�����ŵ�ֵ���¸�0����ΪҪ�ٴθ��£�ǰ�汣���ֵ����
			for(int iiiidx=1; iiiidx<=maxDiceNum && iiiidx<iiidx ; ++iiiidx)  //iiiidx<iiidxȷ��n-(i~6)��ֵ����0
			{//iiiidxΪ��ǰ���ӳ��ֵ����֣������ܳ���0,��ǰ���ӳ��ֵ����ֺͣ�Ҫ����ֵ��ܵĴ�������Ҫ�����ϴγ���iiidx-iiiidx�Ĵ�����
				arr[arrNum][iiidx] += arr[(arrNum+1)%2][iiidx-iiiidx];
			}
		}
	}
		//��ʼ�������
		int totoalSumCnt = pow(maxDiceNum,cnt);
		for(int idx=cnt;idx<=cnt*maxDiceNum;++idx)
		{
			cout<<"sum is "<<idx<<" appear "<<arr[arrNum][idx]<<
				" times and probability is "<<(double)arr[arrNum][idx]/totoalSumCnt<<endl;
		}
		delete []arr[0];
		delete []arr[1];
}
#endif
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