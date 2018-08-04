//��Ŀ21������ջ�����ݽṹ���ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min������
//�ڸ�ջ�У�����min,push��pop��ʱ�临�Ӷȶ���O(1)��
//˼·��ע��һ�㣬�����СԪ�ص���ջ�ˣ����㻹��ô�Ҵ�СԪ��
//�����ͣ���Ҫ��ģ����
//����һ������ջ��Ԫ�ؽ�ջ��ʱ������ǵ�һ����ջԪ�أ����Ԫ��Ҳѹ�븨��ջ
//���ǵ�һ����ջԪ�أ�������Ԫ��С�ڵ��ڸ���ջ�е�ջ��Ԫ�أ���ô���Ԫ��Ҳѹ�븨��ջ��������ʹ������ջ�ˣ�
//�����ջԪ��Ҳ�͸���ջ�е�ջ��Ԫ����ͬ����ô����ջҲͬ����������������ջ��ջ����Զ��ջ�е���СԪ��
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
template<class T>
class StackWithMin
{
public:
	void myPush(T elem);
	void myPop();
	T Min()const;
private:
	stack<T> _stack;  //ԭʼջ
	stack<T> _assist;  //����ջ������ջ����Сֵ
};
template<class T>
void StackWithMin<T>::myPush(T elem)
{
	_stack.push(elem);
	if(_assist.size()==0||_assist.top()>=elem)
		_assist.push(elem);
}
template<class T>
void StackWithMin<T>::myPop()
{
	if(!_stack.empty())
	{
		int tmp = _stack.top();
		_stack.pop();
		if(tmp==_assist.top())
		{
			_assist.pop();
		}
	}
}
template<class T>
T StackWithMin<T>::Min()const
{
	if(!_assist.empty())
		return _assist.top();
}
int main()
{
	StackWithMin<int> test;
	test.myPush(3);
	cout<<test.Min()<<endl;
	test.myPush(4);
	cout<<test.Min()<<endl;
	test.myPush(2);
	test.myPush(1);
	cout<<test.Min()<<endl;
	test.myPop();
	cout<<test.Min()<<endl;
	test.myPop();
	cout<<test.Min()<<endl;
	test.myPush(0);
	cout<<test.Min()<<endl;
	system("pause");
}
