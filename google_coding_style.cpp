Google C++ Coding Style
1. slowly
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_
...
#endif // FOO_BAR_BAZ_H_
2.使用前置声明可以显著减少需要包含的头文件数量
1) 将数据成员类型声明为Foo *或Foo &；
2) 参数、返回值类型为Foo 的函数只是声明（但不定义实现）；
3) 静态数据成员的类型可以被声明为Foo，因为静态数据成员的定义在类定义之外。
3.只有当函数只有10 行甚至更少时才会将其定义为内联函数（inline function）。
4.定义函数时，参数顺序为：输入参数在前，输出参数在后。
。输入参数一般传值或常数引用（const references），输出参数或输入/输出参数
为非常数指针（non-const pointers）。
5.包含文件的名称及次序:C 库、C++库、其他库的.h、项目内的.h。
6.使用不具名空间保持局部性//source1.cc
 namespace {     int x;     }
 //source2.cc
 namespace {     int x;     }避免链接出错。
 外链接，内链接。
//source1.cc
     namespace {     int x;     }
    //source1.cc
    static int x;
   有什么区别呢，看上去效果一样，区别在于不具名空间的x仍然具有外链接，但是由于它是不具名的，所以别的单元没办法链接到，如果
   namespace haha{   int x;   }  
   则在别的单元可以用haha::x访问到它，static 则因为是内部链接特性，所以无法链接到。
7.C++ 中 static 和 anonymouse namespace 的差别
里的 member 都是有外部链接的，只不过永远都不能被外部link到！而 static 就明确为根本没有外部链接！
在模板里无类型的参数必须是有外部链接的才可以，否则编译无法通

众所周知，命名空间是用来防止对象的重复定义的。
如下，编译不会出错：
namespace n1
{
	int x;
}
namespace n2
{
	int x;
}
//访问
n1.x;
n2.x;

上面是具名的名字空间，不具名的名字空间也是防止对象重复定义用，只是他没有名字而已。
file1.cpp:
namespace 
{
	int x;
}
file2.cpp
namespace 
{
	int x;
}
不能在.h 文件中使用不具名命名空间。

namespace mynamespace {
  void A::f(){}
}

=delete ; = default;
// 禁止——污染命名空间
using namespace foo;
12.嵌套类（Nested Class）
当嵌套（成员）类只在被嵌套类（enclosing class）中使用时很有用,不要将嵌套类定义为public，除非它们是接口的一部分.
13.使用命名空间中的非成员函数或静态成员函数，尽量不要使用全局函数。  辅助函数非类的成员。
14.初始化时声明 int i=fun();
class 类型的全局变量是被禁止的，内建类型的全局变量是允许的，当然多线程代码中非常
数全局变量也是被禁止的。永远不要使用函数返回值初始化全局变量。
如果你一定要使用class 类型的全局变量，请使用单件模式（singleton
pattern）。
15. 大多数全局变量应该是类的静态
数据成员，或者当其只在.cc 文件中使用时，将其定义到不具名命名空间中，或者使用静态
关联以限制变量的作用域。
构造函数中不易报告错误，不能使用异常。
对单参数构造函数使用C++关键字explicit。
16. 仅当只有数据时使用struct，其它一概使用class。
使用组合（composition，译者注，这一点也是GoF 在《Design Patterns》里反复强调
的）通常比使用继承更适宜，如果使用继承的话，只使用公共继承。
C++实践中，继承主要用于两种场合：实现继承（implementation inheritance），子类继承父类的实现代
码；接口继承（interface inheritance），子类仅继承父类的方法名称。
努力做到只在“是一个”（"is-a"， 译者注，
其他"has-a"情况下请使用组合）的情况下使用继承

17. 必要的话，令析构函数为virtual，必要是指，如果该类具有虚函数，其析构函数应该为虚
函数。
定义次序如下：public:、protected:、private:
每一块中，声明次序一般如下：
1) typedefs 和enums；
2) 常量；
3) 构造函数；
4) 析构函数；
5) 成员函数，含静态成员函数；
6) 数据成员，含静态数据成员。
18. 智能指针（Smart Pointers）
/////////////////////////////////////////////////////////////////////////////////end
//申明一个类时，编译器会默认为你提供四个函数。
  //无参构造函数，析构函数，copy构造函数，copy assignment操作符。
boost build,smart ptr.
有些人已经解决你的问题了

