 ///
 /// @file    namespace1.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 13:08:53
 ///
 
#include <iostream>   //头文件没有.h，这是使用模板编写的
using std::cout;  //编译指令
using std::endl;  
namespace
{
	int num = 666;
}
namespace mh
{
	int num = 1;
	void func1()
	{
		cout << "func1()" << endl;
	}
}
namespace A
{
	int num = 100;
	void funcA()
	{
		cout << "A::funcA()" << endl;
	}
}
using A::funcA;
namespace B
{
	int num = 1000;
	void funcB()
	{
		//A::funcA();   //必须加上作业域限定，不然报错  //如果不想加，就要在开头扩大A的作用于为全局的
		funcA();
		cout << "B::funcB()" << endl;
	}
}
int main(void)
{
	cout << num << endl;	//默认访问的是全局的num
	cout << ::num << endl;
	cout << mh::num << endl;
	mh::func1();
	A::funcA();
	B::funcB();
	return 0;
}

