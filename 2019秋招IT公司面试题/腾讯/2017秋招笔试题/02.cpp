//��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ���������һ����1024��������ID��Χ[1,1024]������32��unsigned int��������¼��
//1024�������Ƿ��Ѿ���ɡ���ʼ״̬����δ��ɡ� ����������������������ID����Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ�
//���һ������������ڶ���ID�������Ѿ�������1�����δ������0�������һ��ڶ���ID����[1,1024]��Χ�������-1��
//��������:
//
//�������һ��,����������ʾ����ID.
//
//�������:
//
//����Ƿ����
//
//��������1:
//
//1024 1024
//
//�������1:
//
//1
#if 0
#include<iostream>
using namespace std;
unsigned int isCompleted(unsigned int a,unsigned int b);
static int flag = 0;
int main(int argc,char** argv)
{
	int num1,num2;
	cin>>num1>>num2;
	int res = isCompleted(num1,num2);
	if(flag == -1)
		cout<<flag;
	else cout<<res;
	//system("pause");
}
unsigned int isCompleted(unsigned int a,unsigned int b)
{
	if(a<1||a>1024||b<1||b>1024)
	{
		flag = -1;
		return 0;
	}
	unsigned int arr[32] = {};
	// a-1 0~1023
	arr[(a-1)/32] = 1<<((a-1)%32);
	if( arr[(b-1)/32] == 1<<(b-1)%32 )
		return 1;
	else
		return 0;
}
#endif


//#include <iostream>
//#include <algorithm>
//int main() 
//{
//    using namespace std;
//    unsigned int n, m;
//    while (cin >> n >> m) 
//    {
//        if (n < 1 || n > 1024 || m < 1 || m > 1024) 
//            cout << -1 << endl;
//        else 
//        {
//            if (n == m) 
//                cout << 1 << endl;
//            else
//                cout << 0 << endl;
//        }
//    }
//    return 0;
//}