 ///
 /// @file    destruct.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-17 10:01:36
 ///

//-fno-elide-constructors
//编译器有返回值优化，要看到return 对象发生的赋值构造函数，就要加上面的命令
//代码第一个输出结构是有构造函数的，第二个是无构造函数的
//每次例子前的解释。。。不懂，以输出结构为准
#include<iostream>
using namespace std;
class point
{
	private:
		int _x;
		int _y;
	public:
		point()
		{
			cout<<"默认构造函数"<<this<<" "<<endl;
			_x = 0;
			_y = 0;
		}
		//带一个参数的可用于类型转换的构造函数
		point(int x)
		{
			cout<<"1参数构造函数"<<this<<" "<<endl;
			_x = x;
			_y = 0;
		}
		//带参数的构造函数
		point(int x,int y)
		{
			cout<<"2参数构造函数"<<this<<" "<<endl;
			_x = x;
			_y = y;
		}
		//拷贝构造函数,如果此函数不定义，系统将生成缺省拷贝构造函数功能,
		//缺省拷贝构造函数的行为是：用传入的对象参数的成员初始化正要建立的对象的相应成员
		point(const point &p)
		{
			cout<<"拷贝构造函数"<<this<<" "<<endl;
			_x = p._x;
			_y = p._y;
		}
		point &operator=(const point &p)
		{
			cout << "赋值运算符重载函数 " << this << " " << endl;
			if(this!=&p)  //=两边不是同一个
			{
				_x = p._x;
				_y = p._y;
			}
			return (*this);
		}
		//析构函数，一个类中只能有一个析构函数,如果用户没有定义析构函数，
		//系统会自动未类生成一个缺省的析构函数
#if 1
		~point()
		{
			cout << "析构函数 " << this << " " << endl;
		}
#endif
};
point func1()
{
	point a;
	return a;
}
int main()
{
	//当有析构函数的时候，CPoint()不会生成调用构造函数生成临时的匿名对象。
	//当没有析构函数的时候，CPoint()会生成一个临时的匿名对象，等价于CPoint pt1;这句话只会调用无参构造函数，不会调用拷贝构造函数
	//point pt1 = point();   //只调用一次构造函数
	                         //point();   //会调用默认构造函数的
	//默认构造函数0x7ffd6a109ef0 
	//拷贝构造函数0x7ffd6a109ee0 
	//析构函数 0x7ffd6a109ef0 
	//析构函数 0x7ffd6a109ee0 
	//
	//默认构造函数0x7ffdec3a5a40 
	//拷贝构造函数0x7ffdec3a5a30
	
	//当有析构函数的时候，CPoint(1)不会生成调用构造函数生成临时的匿名对象。
	//当没有析构函数的时候，CPoint()会生成一个临时的匿名对象，等价于CPoint pt(1);这句话只会调用一个参数的构造函数，不会调用拷贝构造函数
	//point pt2 = point(1);
	//1参数构造函数0x7ffc3b5a3360 
	//拷贝构造函数0x7ffc3b5a3350 
	//析构函数 0x7ffc3b5a3360 
	//析构函数 0x7ffc3b5a3350
	//
	//1参数构造函数0x7ffc533a4ba0 
	//拷贝构造函数0x7ffc533a4b90
	

	//普通数据类型转换为类类型，利用相应的构造函数就可以实现。等价于CPoint pt(1);
	//point pt3 = 1;
	//1参数构造函数0x7fff4bcbea20 
	//拷贝构造函数0x7fff4bcbea10 
	//析构函数 0x7fff4bcbea20 
	//析构函数 0x7fff4bcbea10
	//
	//1参数构造函数0x7ffca3575720 
	//拷贝构造函数0x7ffca3575710
	
	/*拷贝构造函数与赋值运算符重载函数的区别:
	*1. 拷贝构造函数是用已经存在的对象的各成员的当前值来创建一个相同的新对象。
	* 在下述3种情况中，系统会自动调用所属类的拷贝构造函数。
	* 1.1  当说明新的类对象的同时，要给它赋值另一个已经存在对象的各成员当前值。
	* 1.2  当对象作为函数的赋值参数而对函数进行调用要进行实参和形参的结合时。
	* 1.3  当函数的返回值是类的对象，在函数调用结束后返回主调函数处的时候。
	*2. 赋值运算符重载函数要把一个已经存在对象的各成员当前值赋值给另一个已经存在的同类对象*/
	
	//point pt4;
	//point pt5 = pt4;
	//有析构函数
	//默认构造函数0x7ffc2ba82f80 
	//拷贝构造函数0x7ffc2ba82f90 
	//析构函数 0x7ffc2ba82f90 
	//析构函数 0x7ffc2ba82f80 
	
	//调用无参构造函数，拷贝构造函数，此处如果没有写析构函数，则还会调用一次拷贝构造函数
	//因为函数返回会生成一个临时对象，然后再将这个临时对象赋值给pt6，所以多调用一次拷贝构造函数；
	//如果有析构函数,则不会生成中间的临时变量，所以少一次拷贝构造函数的调用
	//point pt6 = func1();
	// -fno-elide-constructors    编译带上这个命令才看的到
	//默认构造函数0x7fff3eaa2a50 
	//拷贝构造函数0x7fff3eaa2a90 
	//析构函数 0x7fff3eaa2a50 
	//拷贝构造函数0x7fff3eaa2a80 
	//析构函数 0x7fff3eaa2a90 
	//析构函数 0x7fff3eaa2a80 
	//func1()先执行，point a return的时候发生拷贝构造函数，完了析构a, = 发生拷贝，最后返回的匿名对象析构，pt6 析构
	//
	//默认构造函数0x7ffc26728660 
	//拷贝构造函数0x7ffc26728690 
	//拷贝构造函数0x7ffc26728680 
	point pt7(1,2);
	point pt8;
	pt8 = pt7;
	//2参数构造函数0x7ffeded09530 
	//默认构造函数0x7ffeded09540 
	//赋值运算符重载函数 0x7ffeded09540 
	//析构函数 0x7ffeded09540 
	//析构函数 0x7ffeded09530 
}
