//16.3.28 mode,algo,linux,boost
/*
1. #inclde <iostream>
内存缓冲区刷新 buffer.
C++最初的一个设计焦点是能定义使用上像内置类型一样自然的类类型。
2. 面向过程，基于对象，面向对象，泛型。
对象是指一块能存储书库并具有某种类型的内存空间。
int init = 0;
extern int ii = 1;//define not declare
3. int &ref = i;
int *pi = &i; int **pi = &pi;
4. typedef int INT_P;//别名
auto  i = 1；
dectyppe(i) j = 0;
#ifndef #define #endif
#if defined (_TEST_)
#elif define ()
#endif
5.#include <string>
isalpha(c),isdigit(c);
for(auto &s : arr) s++; 
6.#inclde <vector>
vector<int> v{1,2,3,4,5};v(10,1);
v.push_back(1);
empty(),size();
7.iterator
for(auto it=v.begin();it!=v.end();++it) *it;
所有标准库的迭代器都定义了==和！=,可能没有定义<!!
auto mid = v.begin() + v.size()/2;
8. int arr[] = {1,2,3};
int *(&array)[10] = ar;//The ref of array,The array have 10 pointers.
size_t ttt;
c style string:
strlen,strcmp,strcat,strcpy. end with \0.
const char *str = s.c_str();
尽量使用标准库类型而非数组。
9. 编译器扩展。
~,<<,>>,!,
static_case<int>(var);const_cast<int>(var);
switch,break,continue.goto
10.function... jmp ret
作用域和生命周期。
只存在于块执行期间的对象称为自动对象。实参的拷贝值和返回值。
static int cnt = 0;
值传递，指针传递，引用传递。
使用引用返回额外的信息。尽量使用常量引用。
void print(int *pa,int len);
void print(int (&arr)[10]);//数组引用形参
不要返回局部对象的引用或指针。引用所引用的是在函数之前已经存在的那个对象？
const sring& fun(){string ret;return ret;}
10.复杂声明，由内向外。
int (*func(int i))[10];//三种声明方式
auto func(int i) -> int(*)[10];
int odd[] = {1,3,5};int even[] = {2,4,6};
decltype(odd) * arrPtr(int i=0){
	return (i%2)?&odd:&even;
} 
11.函数指针声明，用指针替换函数名即可。
void f(int i); void (*pf)(int);
pf = f; pf(10);
返回函数指针。
auto f1(int) -> int(*)(int, int);
12. class 
数据抽象和封装。接口和实现。
this指针，const成员函数(mutable). server,mode,boost,
return *this;
如果自定义了构造函数，那么默认构造函数就不可以用了，强制=default声明可以让默认构造函数恢复。
13.简单的来说就是，在有指针的情况下，浅拷贝只是增加了一个指针指向已经存在的内存，而深拷贝就是增加一个指针并且申请一个新的内存，使这个增加的指针指向这个新的内存，采用深拷贝的情况下，释放内存的时候就不会出现在浅拷贝时重复释放同一内存的错误！
程序员只需在函数声明后加上“=default;”，就可将该函数声明为 defaulted 函数，编译器将为显式声明的 defaulted 函数自动生成函数体。
 virtual ~X()= defaulted; // 编译器自动生成 defaulted 函数定义体
14. mutable size_t ss; explicit constructor();
类的静态成员，与类相关。
ifstream in;ofstream out;
15.vector,list,deque,
智能指针，
//////////////////////////////////
io模型
1.同步--等待完成SendMessage  阻塞
异步--通过三种途径返回结果：状态、通知和回调
阻塞：阻塞调用是指调用结果返回之前，当前线程会被挂起。函数只有在 得到结果之后才会将阻塞的线程激活。
//
小结：同步就是当一个进程发起一个函数（任务）调用的时候，一直等待直到函数（任务）完成，而进程继续处于激活状态。而异步情况下是当一个进程发起一个函数（任务）调用的时候，不会等函数返回，而是继续往下执行当，函数返回的时候通过状态、通知、事件等方式通知进程任务完成。

阻塞是当请求不能满足的时候就将进程挂起，而非阻塞则不会阻塞当前进程，
!!!即阻塞与非阻塞针对的是进程或线程而同步与异步所针对的是功能函数。
//非阻塞IO
而对于应用程序，虽然这个IO操作很快就返回了，但是它并不知道这个IO操作是否真的成功了，为了知道IO操作是否成功，
一般有两种策略：一是需要应用程序主动地循环地去问kernel(这种方法就是同步非阻塞IO)；
二是采用I/O通知机制，比如：IO多路复用(这种方法属于异步阻塞IO)或信号驱动IO(这种方法属于异步非阻塞IO)。
IO多路复用：“在这种模型中，IO函数是非阻塞的，使用阻塞 select、poll、epoll系统调用来确定一个 或多个I/O 描述符何时能操作。”
现在用select、poll、epoll这样的函数来专门负责阻塞同时监听这一万个请求的状态，一旦有数据到达了就负责通知，这样就将之前一万个的各自为战的等待与阻塞转为一个专门的函数来负责与管理。
 信号驱动IO(异步非阻塞IO)：
当kernel执行完毕，返回read的响应，(kernel)就会产生一个信号或执行一个基于线程的回调函数来完成这次 I/O 处理过程。
//
为此我们首先来看看服务器编程的模型，客户端发来的请求服务端会产生一个进程来对其进行服务，每当来一个客户请求就产生一个进程
来服务，然而进程不可能无限制的产生，因此为了解决大量客户端访问的问题，引入了IO复用技术，即：一个进程可以同时对多个客户
请求进行服务。也就是说IO复用的“介质”是进程(准确的说复用的是select和poll，因为进程也是靠调用select和poll来实现的)，
复用一个进程(select和poll)来对多个IO进行服务，虽然客户端发来的IO是并发的但是IO所需的读写数据多数情况下是没有准备好的，
因此就可以利用一个函数(select和poll)来监听IO所需的这些数据的状态，一旦IO有数据可以进行读写了，进程就来对这样的IO进行服务。
因此，select/poll一般只能处理几千的并发连接。
/////////////////就六和豆浆旁边 九如村 yiguanmiao.
  堆：char *s1 = "Hellow Word"；是在编译时就确定的；
    栈：char s1[] = "Hellow Word"； 是在运行时赋值的；用数组比用指针速度要快一些，因为指针在底层汇编中需要用edx寄存器中转一下，而数组在栈上直接读取。
dd
51单片机IO口线复用
第一种方法就是最传统的多进程并发模型 (每进来一个新的I/O流会分配一个新的进程管理。)
第二种方法就是I/O多路复用 (单个线程，通过记录跟踪每个I/O流(sock)的状态，来同时管理多个I/O流 。)
 I/O multiplexing
重要的事情再说一遍： I/O multiplexing 这里面的 multiplexing 指的其实是在单个线程通过记录跟踪每一个Sock(I/O流)的状态(对应空管塔里面的Fight progress strip槽)来同时管理多个I/O流.
 发明它的原因，是尽量多的提高服务器的吞吐能力。
提醒下，ngnix会有很多链接进来， epoll会把他们都监视起来，然后像拨开关一样，谁有数据就拨向谁，然后调用相应的代码处理。
select, poll, epoll 都是I/O多路复用的具体的实现，之所以有这三个鬼存在，其实是他们出现是有先后顺序的。 
1. （所谓阻塞方式block，顾名思义，就是进程或是线程执行到这些函数时必须等待某个事件的发生，如果事件没有发生，进程或线程就被阻塞，函数不能立即返回）。
2. 可是使用Select就可以完成非阻塞（所谓非阻塞方式non-block，就是进程或线程执行此函数时不必非要等待事件的发生，一旦执行肯定返回，以返回值的不同来反映函数的执行情况，
如果事件发生则与阻塞方式相同，若事件没有发生则返回一个代码来告知事件未发生，而进程或线程继续执行，所以效率较高）方式工作的程序，
它能够监视我们需要监视的文件描述符的变化情况——读写或是异常。
3. io阻塞-select-poll-epoll 。。epoll 修复了poll 和select绝大部分问题。可是epoll 有个致命的缺点。。只有linux支持。


Cygwin是一个在windows平台上运行的类UNIX模拟环境
如何开发一个高并发、大吞吐量、高稳定性的服务器就是我们要考虑的了。


tcp/ip详解
1.有三类I P地址：单播地址（目的为单个主机）、广播地址（目的端为给定网络上的所有主
机）以及多播地址（目的端为同一组内的所有主机）。比特流送入网络
其中每一层对收到的数据都要增加一些首部信息（有时还要增加尾部
信息）
T C P传给I P的数据单元称作T C P报文段或简称为T C P段（T C P
s e g m e n t）。I P传给网络接口层的数据单元称作I P数据报(IP datagram)。通过以太网传输的比特
流称作帧(Fr a m e )。
2.以太网数据帧的物理特性是其长度必须在4 6～1 5 0 0字节之间。

tcp首部，ip首部，以太网首部
udp首部8字节。
4
I P在首部中存入一个长度为
8 b i t的数值，称作协议域。1表示为I C M P协议， 2表示为I G M P协议， 6表示为T C P协议， 1 7表
示为U D P协议。
5任何T C P / I P实现所提供的服务都用知名的1～1 0 2 3之间的端
口号
以太网是局限在一定的距离之内的，我们可以有成千上百个以太网；但是因特网呢，是最大的广域网了，我们只有一个因特网，所以因特网又可以说是网络中的网络。
在T C P / I P中，网络层和运输层之间的区别是最为关键的：网络层（ I P）提供点到点的服务，
而运输层（ T C P和U D P）提供端到端的服务。
以太网和8 0 2 . 3对数据帧的长度都有一个限制，其最大值分别是
1 5 0 0和1 4 9 2字节。链路层的这个特性称作
M T U，最大传输单元
6.如果I P层有一个数据报要传，而且数
据的长度比链路层的M T U还大，那么I P层
就需要进行分片（ f r a g m e n t a t i o n），把数据
报分成若干片，这样每一片都小于M T U。
003
7. 
T T L（t i m e - t o - l i v e）生存时间字段设置了数据报可以经过的最多路由器数。它指定了数据
报的生存时间。T T L的初始值由源主机设置（通常为3 2或6 4），一旦经过一个处理它的路由器，
它的值就减去1。当该字段的值为0时，数据报就被丢弃，并发送I C M P报文通知源主机.

Ip路由选择：路由表。
链路层(物理接口细节)-网络层（IP,icmp）-运输层(tcp/udp)-应用层(ftp,telnet,SMTP)。
8. 由于各种原因（例如，更换网卡、网络中加入了新的主机等等），不能根据IP地址得出物理地址。这时，想到了在主机中存放一个从IP地址到硬件地址的映射表，并且这个表还得时常更新。
这个映射表就是地址解析协议（ARP)。
。一些I C M P报文把差错报文返回给用户进程。I C M P报文是在I P数据报内部被传输的，
ICMP是（Internet Control Message Protocol）Internet控制报文协议。它是TCP/IP协议族的一个子协议，用于在IP主机、路由器之间传递控制消息。控制消息是指网络通不通、主机是否可达、路由是否可用等网络本身的消息。

ICMP是（Internet Control Message Protocol）Internet控制报文协议。它是TCP/IP协议族的一个子协议，用于在IP主机、路由器之间传递控制消息。控制消息是指网络通不通、主机是否可达、路由是否可用等网络本身的消息。
我们在网络中经常会使用到ICMP协议，比如我们经常使用的用于检查网络通不通的Ping命令（Linux和Windows中均有），这个“Ping”的过程实际上就是ICMP协议工作的过程。还有其他的网络命令如跟踪路由的Tracert命令也是基于ICMP协议的。
错误侦测与回报机制
9.。重新组装由
目的端的I P层来完成，其目的是使分片和重新组装过程对运输层（ T C P和U D P）是透明的，

I P数据报是指I P层端到端的传输单元（在分片之前和重新组装
之后），分组是指在I P层和链路层之间传送的数据单元。一个分组可以是一个完整的I P数据报，
也可以是I P数据报的一个分片。
10.TCP
面向连接意味着两个使用T C P的应用（通常是一个客户和一个服务器）在彼此交换数据
之前必须先建立一个T C P连接。这一过程与打电话很相似，先拨号振铃，等待对方摘机说
“喂”，然后才说明是谁。
当T C P发出一个段后，它启动一个定时器，等待目的端确认收到这个报文段。如果不能
及时收到一个确认，将重发这个报文段。
如果收到段的检验和有差错， T C P将丢弃这个报文段和不确认收到
此报文段（希望发端超时并重发）。ack,nack...
017. lhs,rhsLeft Hand Side 
Right Hand Side 
*/
#include "otlv4.h"
#ifndef HZ_DBMANAGER_H
#define HZ_DBMANAGER_H
namespace HZ_COMPANY{
	class DBManager{
	private:
		DBManager() = default;
		explicit DBManager(const string strConn);
		DBManager(const DBManager& rhs) = delete;
		DBManager& operator=(const DBManager& rhs) = delete;
	public:
		bool open();
		bool exec(const string& sql)   const;
	//	bool select(const string& sql) const;
		bool close();
		static DBManager* getDBManger()
		{	
			if(_instance == NULL){
				_instance = new DBManager();		
			}
			return _instance;
		}	
	private:	
		Db db;
		string conn_str;
		static const DBManager* _instance;
	}
}
#endif //HZ_DBMANAGER_H
#include "DBManager.h"
bool DBManager::open()
{
	//初始化ODBC环境
	otl_connect::otl_initialize();
	return true;
}
DBManager getDBManger()
{
	if(dbSingle == NULL){
		dbSingle = new DBManager();		
	}
	return dbSingle;
}
bool DBManager::exec(const string& sql)
{
	try
	{
		otl_cursor::direct_exec(db,sql.c_str());		
	}
	catch(otl_exception& p)
	{
		throw p;
	}
	return false;
}

bool DBManager::close()
{
	db.logoff();
	return true;
}

class DBManager{
public:
	DBManager();
	DBManager(const string strConn);
	~DBManager();
public:
	bool open();
	bool exec(const string& sql)   const;
//	bool select(const string& sql) const;
	bool close();
private:
	Db db;
	string conn_str;
}