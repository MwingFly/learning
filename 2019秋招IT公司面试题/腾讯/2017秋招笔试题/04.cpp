//geohash���룺geohash�����ڽ���ά�ľ�γ��ת��Ϊ�ַ�������Ϊ��������һ���Ǿ�γ�ȵĶ����Ʊ��룬�ڶ�����base32ת�롣
//���⿼��γ�ȵĶ����Ʊ��룺�㷨��γ��[-90, 90]ͨ�����ַ��������ޱƽ���ȡ�������辫�ȣ����⾫��Ϊ6����
//ע�⣬������ж��ַ��ƽ�������ֻ��������ȡ�������ж��֣���Զ����м�ֵ���������䡣�㷨�������£� ���γ��Ϊ80���ж����Ʊ�����̣�
//1) ����[-90, 90]���ж���Ϊ[-90, 0),[0, 90]����Ϊ�������䣬����ȷ��80Ϊ�����䣬���Ϊ1��
//2) �����һ����������[0, 90]���ж���Ϊ[0, 45),[45, 90]������ȷ��80�������䣬���Ϊ1��
//3) ���[45, 90]���ж���Ϊ[45, 67),[67,90],����ȷ��80Ϊ�����䣬���Ϊ1��
//4) ���[67,90]���ж���Ϊ[67, 78),[78,90]������ȷ��80Ϊ�����䣬���Ϊ1��
//5) ���[78, 90]���ж���Ϊ[78, 84),[84, 90]������ȷ��80Ϊ�����䣬���Ϊ0��
//6) ���[78, 84)���ж���Ϊ[78, 81), [81, 84)������ȷ��80Ϊ�����䣬���Ϊ0��
//
//��������:
//
//�������һ������n,(-90 �� n �� 90)
//
//
//
//�������:
//
//��������Ʊ���
//
//
//��������1:
//
//80
#if 0
#include<iostream>
#include<string>
using namespace std;
string geohash(int num);
string binarySearch(int first,int second,int key,string& str);
int main(int argc,char** argv)
{
	int num;
	cin>>num;
	cout<<geohash(num);
	//system("pause");
}
string geohash(int num)
{
	if(-90>num||num>90)
		return "";
	string tmp = "";
	tmp = binarySearch(-90,90,num,tmp);
	return tmp;
}
static int times = 0;
string binarySearch(int first,int second,int key,string& str)
{
	int min = (first + second) / 2;
	if(times==6)
		return str;
	//if(first==key||second==key)
	//	return str;
	if(key>=min)
	{
		str += '1';
		++times;
		return binarySearch(min,second,key,str);  //�ǵ÷��ذ�
	}
	else
	{
		str += '0';
		++times;
		return binarySearch(first,min,key,str);
	}
}
#endif