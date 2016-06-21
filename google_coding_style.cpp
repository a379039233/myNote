Google C++ Coding Style
everyday:thingking
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
关于C/C++的头文件包含顺序，Google style：
C 系统文件
C++系统文件
其他库头文件
本项目内头文件
#ifndef 
#define
#include "other"
#endif
/////////////////////////////////////////////////////////////////////////////////end
git push -u origin master -f 强制
//申明一个类时，编译器会默认为你提供四个函数。
  //无参构造函数，析构函数，copy构造函数，copy assignment操作符。
boost build,smart ptr.
有些人已经解决你的问题了
 namespace sss{
	class AAA{
	public:
		void p();
	};
}
namespace sss{
	void AAA::p(){
		cout<<"namespace"<<endl;
	}
}
this class name copy delete,=
public fun
基类：纯虚函数（抽象类）


设计模式、 经验总结
1.复用，修改的少。 不知情和忽略 也是天赐之福。STL。。。
void swap(T &a,T& b)T =temp(a);a=b;b=temp;
void fun(int (&arr)[10]){}
int *pTable = &table;//head or tail
operator = (const obj&that){
	if(this !=  &that)
	{}
}
虚拟继承在一般的应用中很少用到，所以也往往被忽视，这也主要是因为在C++中，多重继承是不推荐的，也并不常用，而一旦离开了多重继承，虚拟继承就完全失去了存在的必要因为这样只会降低效率和占用更多的空间。
class A

class B1:public virtual A;

class B2:public virtual A;

class D:public B1,public B2;  节省内存
以下是我在网上看到的几个形象比喻,真的非常不错,呵呵:
1.飞机会飞，鸟会飞，他们都继承了同一个接口“飞”；但是F22属于飞机抽象类，鸽子属于鸟抽象类。
2. 就像铁门木门都是门（抽象类），你想要个门我给不了（不能实例化），但我可以给你个具体的铁门或木门（多态）；而且只能是门，你不能说它是窗（单继承）；一个门可以有锁（接口）也可以有门铃（多实现）。 门（抽象类）定义了你是什么，接口（锁）规定了你能做什么（一个接口最好只能做一件事，你不能要求锁也能发出声音吧（接口污染））。

string data;  
      demo::People p;  
      p.set_name("Hideto");  
      p.set_id(123);  
      p.set_email("hideto.bj@gmail.com");  
      p.SerializeToString(&data);  
      char bts[data.length()];  
      strcpy(bts, data.c_str());  
      send(connectfd, bts, sizeof(bts), 0);  http://blog.csdn.net/a379039233/article/details/51141426
	  
	  numbytes = recv(fd, buf, MAXDATASIZE, 0);  
  buf[numbytes] = '\0';  
  string data = buf;  
  demo::People p;  
  p.ParseFromString(data);  
  
  series *se = new series(chart);
  chart->addseries(se);
  key1 OR key2
   +how a plan work
   key1 -key2
  protobuf
  简单类型：bool, int32, float, double, string.
sqlite site:blog.csdn.net/a379039233  精确匹配--“”
  #include "../systeminfo/systeminfo.h"
  #pragma comment(lib,"../debug/systeminfo.lib") wangluotiaoshizhushou网络调试助手
3.无法解析的外部符号。私有静态成员变量在使用前必须初始化，否则link会报错
静态变量 A::a 没有定义
static成员在类内的出现只是声明，需要在类的外部定义。
可以在singleClass.cpp定义SingleClass * SingleClass::
single=NULL;
4.virtual (function)table :记录了所有虚函数的函数指针
虚函数表的结构：它是一个函数指针表，每一个表项都指向一个函数。
任何一个包含至少一个虚函数的类都会有这样一张表。
需要注意的是vtable只包含虚函数的指针，没有函数体。实现上是一个函数指针的数组。
虚函数表既有继承性又有多态性。虚函数的重载性和它声明的权限无关。TemplateMethod设计模式
  网络关口，契约。
C++标准（也称ISO 14882）告诉我们，虚拟函数的重写与它的具体存储权限没有任何关系，即便是声明为private的虚拟函数，在子类中我们也同样可以重写它。
将所有的虚拟函数都声明为private/protected，然后再使用一个public的非虚拟函数调用它
facade:外观; 外观模式; 门面模式;
引入外观角色之后，用户只需要直接与外观角色交互.
  粘包 指TCP协议中，发送方发送的若干包数据到接收方接收时粘成一包，从接收缓冲区看，后一包数据的头紧接着前一包数据的尾。
  若连续几次发送的数据都很少，通常TCP会根据优化算法把这些数据合成一包后一次发送出去，这样接收方就收到了粘包数据。
  socket:phone dail,hangup.
  插件，反射。dll
  #include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

std::string text = "152";
int number = std::atoi( text.c_str() ); atof()
std::string text = "152";
int number;
std::stringstream ss;
ss << text;//可以是其他数据类型
ss >> number; //string -> int
ss<<number; string str = ss.str();
/////
用using namespace std;的话就是std这个命名空间（namespace）里面的所有都可以用了，比如cin，cout，endl等等，用using std::cout;的话就只能使用cout而不能用cin和endl。如果要用的话需要再用using std::cin;和using std::endl;
初学者都要用上面的using namespace std;

//计算数组维数
#define CountArray(Array) (sizeof(Array)/sizeof(Array[0]))

//计算字符长度
#define CountString(String) ((UINT)((lstrlen(String)+1)*sizeof(TCHAR)))

//安全删除指针
#define  SafeDelete(pData) { try { if(pData) delete pData; } catch (...) { } pData=NULL; }

//安全删除指针
#define  SafeDeleteArray(pData) { try { delete [] pData; } catch (...) { } pData=NULL; }



cppsqlite,sqlite++;pugixml;
Beanstalk，一个高性能、轻量级的分布式内存队列系统
高性能离不开异步，异步离不开队列，而其内部都是Producer-Comsumer模式的原理。 beanstalkd 
thrift最初由facebook开发用做系统内各语言之间的RPC通信 。
for(auto& e : v){}


数据处理和通讯。 boost asio库
 asio是一个轻量级的高质量c++库，由boost 1.35引入，封装了iocp，epoll,kqueue等网络模型,并提供了一致的proactor模式）
心跳包就是在客户端和服务器间定时通知对方自己状态的一个自己定义的命令字，按照一定的时间间隔发送，类似于心跳，所以叫做心跳包。
实TCP中已经为我们实现了一个叫做心跳的机制。
发包方：可以是客户也可以是服务端，看哪边实现方便合理。一般是客户端。服务器也可以定时轮询发心跳下去。心跳包之所以叫心跳包是因为：它像心跳一样每隔固定时间发一次，以此来告诉服务器，这个客户端还活着。
心跳包在GRPS通信和CDMA通信的应用方面使用非常广泛。数据网关会定时清理没有数据的路由，心跳包通常设定在30-40秒之间。

先把基础的东西打好，boost asio我一直在用，用了asio你就不会再想去自己封装一个什么XXX网络库了

mianzi shiggep. meitianjingbuyidiandian.
const_iterator迭代器。这个迭代器是可以自己增加的，但是其所指向的元素是不可以被改变的。const vector<int> :: iterator ite；
C++中的定时器都要使用到第三方的东西。 要么自己写线程来做定时器，虽然精度差点，不过一般都可以使用，要求不会精确到毫秒级。标准C++没有提供这个功能。
只用标准C++恐怕实现不了吧。但你可以使用boost.timer。
while(true)
{
	int nCurTime = GetTickCount();
	while(GetTickCount()-nCurTime < 5000)
	Sleep(500);
	cout<<"hello!"<<endl;
}容器对算法一无所知，算法对容器一无所知
跨平台数据通信的选择：Google ProtoBuf
try{}catch(...){} length-typename-protobuf data...
你读过的最好的 C++ 开源代码是什么？
BOOST的部分代码和SGI STL的源码；leveldb‘Boost.Asio ；OGRE3D libevent 
掌握C++面向过程
掌握C++面向对象
掌握C++模板
掌握C++模板元编程
掌握C++预处理期图灵完备的宏
// 主模板
template<int N> 57
struct Fib 
{
    enum { Result = Fib<N-1>::Result + Fib<N-2>::Result };
};

// 完全特化版
template <>
struct Fib<1>
{
    enum { Result = 1 };
};


// 完全特化版
template <>
struct Fib<0>
{
    enum { Result = 0 };
};

int main()
{
    int i = Fib<10>::Result;
    // std::cout << i << std::endl;
} 
你应该这么定义，argv是字符串数组：
char *argv[]={ "ls", "-1", NULL };

对于驱动程序开发的方式有以下几种：

1．  DDK开发

2．  DrvierStudio

3．  WinDriver

正道而行
以 vector<int> vec; 为例说明。有多种函数声明方式： 

1. void deal( vector<int> vec ); 
2. void deal( vector<int>* pvec ); 
3. void deal( const vector<int>* pvec ); // 在函数内不能改变 pvec 指向的对象 
4. void deal( vector<int>& vec ); 
5. void deal( const vector<int>& vec ); // 在函数内不能改变 vec 对象 
125 
其对应的调用分别是： 

1. deal( vec ); 
2. deal( &vec ); 
3. deal( &vec ); 
4. deal( vec ); 
5. deal( vec );

void CExtendDlg::OnButton1() //Hide the separator
{
	CString str;
	if(GetDlgItemText(IDC_BUTTON1,str),str=="收缩<<")
		SetDlgItemText(IDC_BUTTON1,"扩展>>");
	else
		SetDlgItemText(IDC_BUTTON1,"收缩<<");
	static CRect rectLarge;
	static CRect rectSmall;
	if(rectLarge.IsRectNull()){
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);		
	//	rectSmall.left=rectLarge.left;
	//	rectSmall.top=rectLarge.top;
	//	rectSmall.right=rectLarge.right;
	//	rectSmall.right=rectSeparator.right;
		rectSmall.left=rectLarge.left;
		rectSmall.top=rectLarge.top;
		rectSmall.right=rectSeparator.right;
		rectSmall.bottom=rectLarge.bottom;
	}
	if(str=="收缩<<"){
		SetWindowPos(NULL,0,0,rectSmall.Width(),rectSmall.Height(),
			SWP_NOMOVE|SWP_NOZORDER);	
	}else{
		SetWindowPos(NULL,0,0,rectLarge.Width(),rectLarge.Height(),
			SWP_NOMOVE|SWP_NOZORDER);	
	}
}
copy 1.dll c:\windows\system32\1.dll  //重定位

yong.liu@moniloc.com
　 第一种顾名思义。第二种指的是打包时一些MFC的DLL的内容没有被包含在EXE文件中，所以EXE文件较小，但是运行时要求系统中要有相关的DLL文件。第三种是将DLL中的相关代码写进EXE文件中，文件较大，但是可以在没有相关DLL的机器上运行。

/MT是 "multithread, static version ” 意思是多线程静态的版本，定义了它后，编译器把LIBCMT.lib 安置到OBJ文件中，让链接器使用LIBCMT.lib 处理外部符号。

	/MD是 "multithread- and DLL-specific version” ，意思是多线程DLL版本，定义了它后，编译器把 	MSVCRT.lib 安置到OBJ文件中，它连接到DLL的方式是静态链接，实际上工作的库是MSVCR80.DLL。

即：

	静态运行时库：LIBCMT.lib
	动态运行时库：MSVCRT.lib + MSVCR80.DLL
这种情况主要是C运行期函数库和MFC的库冲突造成的。具体的办法就是将那个提示出错的库放到另外一个库的前面。

常见的编译参数VC建立项目时总会定义"Win32"。控制台程序会定义"_CONSOLE"，否则会定义"_WINDOWS"。Debug版定义"_DEBUG"，Release版定义"NDEBUG" 

与MFC DLL有关的编译常数包括：
　　_WINDLL 表示要做一个用到MFC的DLL
　　_USRDLL 表示做一个用户DLL（相对MFC扩展DLL而言） 
　　_AFXDLL 表示使用MFC动态链接库的 regular DLL
　　_AFXEXT 表示要做一个MFC扩展DLL


_WIN64;  
永远不要把外部函数的原型放到.c中。extern int add(); typdef char * pc;

#pragma   warning(push)是保存当前的编译器警告状态；
#pragma   warning(pop)是恢复原先的警告状态。 
#pragma   warning(   push   )
#pragma   warning(   disable   :   4705   )
#pragma   warning(   disable   :   4706   )
#pragma   warning(   disable   :   4707   )
//   Some   code
#pragma   warning(   pop   ) 
#pragma warning(push, 3)  // 3 级警告设置入栈


ms 扩展。TinyXML 
#ifdef _MSC_VER
	#pragma warning(push)
	#pragma warning(disable:4128)
#endif

#ifdef _MSC_VER
	#pragma warning(pop) 
#endif
1.
#ifndef _H
#define _H
//copyright
#inlcude <istream>
namespace rapid{
	const int ii= 0x1;
	namespace internal{
		
		
	}
	
}

template<class OutIt,class Ch>
inline OutIt Copy_chars(const Ch *begin,const Ch *end,OutIt out)
{
	while(begin != end)
		*out++ = *begin++;
	return out;	
}
rapidxml,rapidjson.
const enum_typ type = SSS;枚举参数不可用int.
#if !defined(PPP)
#endif
reinterpret_cast<type-id> (expression)
type-id 必须是一个指针、引用、算术类型、函数指针或者成员指针。它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，再把该整数转换成原类型的指针，还可以得到原先的指针值）。
int *n= new int ;
double *d=reinterpret_cast<double*> (n);type-id必须是类的指针、类的引用或者是void *；
 unresolved   external   symbol   “symbol”（不确定的外部“符号”）。如果连接程序不能在所有的库和目标文件内找到所引用的函数、变量或标签，将产生此错误消息。一般来说，发生错误的原因有两个：一是所引用 的函数、变量不存在、拼写不正确或者使用错误；其次可能使用了不同版本 的连接库。   
1. lib 文件未引入。可使用“#pragma comment(lib, “winsock.lib”) ”语句添加 lib 引用，也可在项目依赖里添加。
2. 类方法的实现未加类标识。如， “CTest::Connect(void) { … }” 写成了 “Connect(void) { … }”。
3. 缺少 obj 文件。在项目里添加“包含路径”：C:/curl/lib/release-dll.obj。
4. 没有将项目需要的头文件、源文件都加入项目中，这个错误我犯了好几次。

lookuptables[];
459 c
1. short,int,long.   unsigned char.   //int,double first
2. int:机器的自然字长？？ 64bit:win64,int=long=4byte
#include<stdint.h> uint16_t;
数据类型特别是int相关的类型在不同位数机器的平台下长度不同。C99标准并不规定具体数据类型的长度大小
64bi为了保证平台的通用性，程序中尽量不要使用long数据库型。可以使用固定大小的数据类型宏定义：
typedef signed char       int8_t
typedef short int             int16_t;
typedef int                      int32_t;
# if __WORDSIZE == 64
typedef long int              int64_t;
# else
__extension__
typedef long long int      int64_t;
#endift指针 8byte。
3. size_t :32bit app 4,64:8byte.
在32位系统中size_t是4字节的，而在64位系统中，size_t是8字节的....sizeof(size_t);
一个int占多少个字节既由编译器决定，也由CPU或虚拟机或操作系统决定，但归根结底是由编译器决定。？
4.全局声明放入头文件中，extern int i;extern int fun();
extern int i=0;//定义（必须为全局，局部函数内出错）声明一个可被其他文件外链接的变量
下划线开头，私有。64bitcpu+64bit os+64bit app.
typedef int * Int_Ptr;
5. typedef int (*pf)(int);
char *(*pfpc)(); *(*pfpc)():char;(*pfpc)():pointer to char;(*pfpc):function return pointer to char;
指向返回char类型指针的函数的指针。
6. c:void f();任意类型参数。 void f(void);
char s[] = "hello";//数组初始化值
 char *s="hello"; 
char a[12]; strcpy(a,"hello");
char* p是一个指针，根本没分配内存，他指向的"abc123ABC" 是只读的，不能改变，你在下面给他赋值肯定是错的.而char p[]是一个数组，已经分配内存，是将"abc123ABC" 复制到该内存里面，这个内存是可读写的
指针是不分配内存的，它指向的是系统的只读的内存，而数组是分配内存的，就是将系统的只读的内存里面的值复制到它的内存里面，因此可读写。
char * p = (char * )malloc(10);
strcpy(p, "a
7.bc123ABC");内存分配有三种：静态存储区、堆区和栈区。
C++ typedef struct st{};自动加上了类型定义。
8.如果一个变量的内存地址正好位于它长度的整数倍，他就被称做自然对齐。int 0x000004; 起始地址被4整除。
x00000002，则CPU如果取它的值的话需要访问两次内存，第一次取从0x00000002-0x00000003的一个short，第二次取从0x00000004-0x00000005的一个short然后组合得到所要的数据，如果变量在0x00000003地址上的话则要访问三次内存，第一次为char，第二次为short，第三次为char.
9.  struct s2{char c;int len;char name[10];}'a',55aa;name[9] = 'b'; memset(this,0,sizeof(s2));
61 00 00 00   aa 55 00 00 00 00 00 00 00 00 00 00 00 62 00 00;
61 cc cc cc   aa 55 00 00 cc cc cc cc cc cc cc cc cc 62 cc cc;
10. vc中默认是4字节对齐的，GNU gcc 也是默认4字节对齐。

使用伪指令#pragma pack (n)，C编译器将按照n个字节对齐。
· 使用伪指令#pragma pack ()，取消自定义字节对齐方式。
#pragma pack(1) struct 
#pragma pack()
把结构中的变量按照类型大小从小到大声明,尽量减少中间的填补空间.