//��Ŀ32������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
//��������12����1��12��Щ�����а���1��������1,10,11,12��1һ��������5�Ρ�
//˼·������n��21345�������Σ�1~1345��1346~21345
//1346~21345��1���ֵĴ���������1���������λ��10000~19999��10000��������һ������10000��
//��������5λ������λ���ֵĴ�������10000����12345��1���ֵĴ�������2346
//����1�����ڳ����λ֮���������λ���е������1346~21345��20000�������к�4λ��1���ֵĴ�����2000�Ρ�
//�������λΪ2���ֿ��Էֳ�1346~11345��11346~21345��ÿһ�������У�ѡ������һλ��1��������λ������0~9��10������
//������ѡ������2*4*10^3=2000�Ρ�
//���1~1345�п��Եݹ���ã�������ʼΪʲôҪ��21345�ֳ�1~1345��1346~21345
//ʱ�临�Ӷ�O(logn)
#include<iostream>
#include<string.h>
using namespace std;
int NumberOf1Between1AndN(int n);
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);
int main()
{
	int ret = NumberOf1Between1AndN(21345); //21345->18821   //1345->821
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(1345); 
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(9); 
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(19); 
	cout<<ret<<endl;
}
int NumberOf1Between1AndN(int n)
{
	if(n<=0)
		return 0;
	char strN[50];
	sprintf(strN,"%d",n);
	return NumberOf1(strN);
}
int NumberOf1(const char* strN)
{
	if(!strN||*strN<'0'||*strN>'9'||*strN=='\0')
		return 0;
	int first = *strN - '0';  //��ȡ���������λ
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if(length==1&&first==0)
		return 0;
	if(length==1&&first>0)
		return 1;  //0~9ֻ��һ��1
	//����strN��21345
	int numFirstDigit = 0;
	//numFirstDigit������10000~19999��1���ֵĴ��������λΪ1,10^4��
	if(first>1)
		numFirstDigit = PowerBase10(length-1); //10^4
	else if(first==1)
		numFirstDigit = atoi(strN+1) + 1;  //eg������Ϊ12345����ô1�ĸ�������2346

	int numOtherDigits = first*(length-1)*PowerBase10(length-2);
	//numOtherDigits��1346~21345���˵�һλ֮�����λ�е���Ŀ
	//2*4*10^3 = 8000
	//first��ʾ���Էּ��Σ�length-1��ʾʣ�µ�λ����ʣ�µ�λ�������ѡһλΪ1��������λ������ѡ0~9��ȫ���о���2*4*10^3
	//1346~11345  11346~21345
	int numRecursive = NumberOf1(strN+1);
	//numRecursive��1-1345�е���Ŀ

	return numFirstDigit + numOtherDigits + numRecursive;
}
int PowerBase10(unsigned int n)
{
	int result = 1;
	for(unsigned int i=0;i<n;++i)
	{
		result *= 10;
	}
	return result;
}
//18821
//821
//1
//12
