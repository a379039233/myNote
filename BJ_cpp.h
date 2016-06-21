/* 数据,通信,数据抽象. 问题的解决之道
1. 我想特别强调（怎么强调都不过分）的是，应该多使用静态类型安全的字符串和容器，
而不要学那些大量使用宏，强制转换和数组的编程风格。
2. 集中关注概念，不要迷失在语言的技术细节中。
static成员函数，const成员函数。
3.用const，enum代替宏。inline,template,namespace ;
对于realloc,试试vector。避免void *;
4.尽量少用数组和C风格的字符串。使用string和vector 常常可以简化程序设计。
5.将程序考虑为一组由类和对象表示的相互作用的概念。
需求分析-设计类，表达现实概念.
不要使用全局变量和函数.友元.
6.程序设计泛型:面向过程(模块化);OOP;泛型程序设计(STL)
vtbl:虚函数表.P36
7.不要害怕，一切都会随着时间的推移而逐渐明朗起来。
string str = name.c_str();
8.容器
vector,list,map.    map<key,value>
标准库算法：for_each,find,find_if,count,copy,replace.
使用标准库。使用string而不是char*.
9. char *str[] = {"","","1"}; 引用。int& ref = i;
memset,memcpy;
10.new :自由存储区，堆对象，动态存储区。 函数返回后仍可使用。
static_cast<int>(var);const_cast<>();
string str = "q2"; string str;str = "q2";前一个性能好
尽量在要使用的时候定义。异常前定义不必要的开销。
11. for,while,goto,break,continue;
static; 无const的引用参数，说明该参数将被修改。
函数：默认参数，作用域，const引用参数。P140
typedef void (*pf)(int);
pf edit_ops[] = {&cut,&paste,&copy};
12 广泛而一致地使用const。
不要返回局部变量的指针或者引用。
一个函数引用的类型定义。typedef int(&f)(int, int);
13.匿名的名字空间。保持代码的局部性。
分别编译-连接-
#ifdef _cplusplus
extern "C"
#endif
strlen,sizeof()+1;_countof()
14.类---用户定义类型
static:唯一的副本；常量成员函数；
自引用：Data& add_day(){return *this;};add_year().add_day();
mutable int id;
struct 并不是完整的类型，不过是个数据结构。
/////////////////////////////////
文件分割  _fseeki64 ， _ftelli64，ifstream
feof(FILE* fp)查看文件是否到结尾，到结尾返回true

ferror(FILE* fp)查文件是否状态异常，文件正常返回0
clearerr(FILE*fp)清空文件各种错误标志位。包括文件结尾标志和文件读取越界等错误。

size_t fread ( void * ptr, size_t size, size_t count, FILE * stream ); 读取文件内容，这个函数非常高效。
再次强调，mapping适合随机读写，不适合超大文件，如果你没办法一次性将文件全部映射，用mapping其实很麻烦
p213
//*/
1.设为连接器清单文件的uac执行级别：管理员
2.main函数的返回值用于说明程序的退出状态。如果返回0，则代表程序正常退出。返回其它数字的含义则由系统决定。
返回非零代表程序异常退出。
利用程序的返回值，我们可以控制要不要执行下一个程序。
如果你想你的程序拥有很好的可移植性，请一定要用int main 。
main 函数的返回值类型必须是int，这样返回值才能传递给程序的激活者（如操作系统）。 
3.可能你听说过数据结构多么枯燥难懂，实际上你如果你的目标不是考证或考研而是真正做编程这一行，你完全可以略过它不学，因为大部分在实际编程工作中用不到，或者说在实际工作中你会慢慢把80%的知识学会，而且是通过很自然的方式学会。
因为有的是现成的数据或算法库可用
4.机器指令--0101--。。。。输出参数-指针或者引用。
5.⑴定义一个回调函数；
⑵提供函数实现的一方在初始化的时候，将回调函数的函数指针注册给调用者；
⑶当特定的事件或条件发生的时候，调用者使用函数指针调用回调函数对事件进行处理。
其实回调就是一种利用函数指针进行函数调用的过程  starUML...

a = b + c;
line:<80
char* s;
int& ref;
 TCHAR ma[2]={L'a',L'b'};
int n[1000000];这样肯定是不行的，因为这样定义的数组用的是栈内存，系统默认值为最大1Mb，一个int型占4字节这样最大可以申请1024*1024/4=264144个，如果考虑到系统自身的占用最大值约为25000个。int *p=(int *)malloc(1000000*sizeof(int));，这样用的是堆内存，只要你内存有那么多的连续空间就可以；
1. fread没有读完整个文件  
最近写一个程序，发现用fread读“.dat”文件时不能读完整个文件，后来用hex格式观察读文件退出位置的数字，才发现只要是读到0x1A时，fread就认为结束！后来看了MSDN后知道用text模式打开文件时，系统默认CTRL+Z为文件结束符，而0x1A刚好就是CTRL+Z的ASCII码。另外在另一个文章里面说到如果遇到“/r/n”，也将被映射为“/n”。因此如果是读普通数据而非文本，以以下格式打开文件。
datafile = fopen("whatever.dat", "rb"); 这样就可以解决以上问题！

提高C++程序运行效率的10个简单方法
一、尽量减少值传递，多用引用来传递参数。string,class .
二、++i和i++引申出的效率问题  use++i;
三、循环引发的讨论1（循环内定义，还是循环外定义对象）
ClassTest CT；
for(int i = 0; i < 100; ++i)//构造1次，赋值操作函数（operator=）100次
{
  CT = a;
  //do something
}for(int i = 0; i < 100; ++i)//构造和析构各100次
{
  ClassTest CT = a;
  //do something
}如果调用赋值操作函数的开销比调用构造函数和析构函数的总开销小，则第一种效率高，否则第二种的效率高。
四、循环引发的讨论2（避免过大的循环）
for(int i = 0; i < n; ++i)
{
  fun1();
  fun2();
}
//n大效率高，局部性原理 Cache
for(int i = 0; i < n; ++i)
{
  fun1();
}
for(int i = 0; i < n; ++i)
{
  fun2();
}
五、局部变量VS静态变量
使用局部变量的效率比使用静态变量要高。
这是因为局部变量是存在于堆栈中的，对其空间的分配仅仅是修改一次esp寄存器的内容即可（即使定义一组局部变量也是修改一次）。而局部变量存在于堆栈中最大的好处是，函数能重复使用内存，当一个函数调用完毕时，退出程序堆栈，内存空间被回收，当新的函数被调用时，局部变量又可以重新使用相同的地址。当一块数据被反复读写，其数据会留在CPU的一级缓存（Cache）中，访问速度非常快。而静态变量却不存在于堆栈中。
六、避免使用多重继承
七、尽量少使用dynamic_cast
八、减少除法运算的使用
if(a > b/c),如果a、b、c都是正数，则可写成if(a*c > b)
九、将小粒度函数声明为内联函数（inline）
十、多用直接初始化
ClassTest ct1;
ClassTest ct2(ct1);  //直接初始化
ClassTest ct3 = ct1;  //复制初始化
---要避免不必要的优化，避免不成熟的优化，不成熟的优化的是错误的来源，因为编译器会为你做很多你所不知道的优化。
这里有句俗语：让经常执行的路径运行更加高效，而运行稀少的路径正确运行。
4.跳转和分支执行代价高，如果可能，尽量少用。

if…else if…else if…else if…很长的分支链执行到最后的分支需要很多的跳转。如果可能，将其转换为一个switch声明语句，编译器有时候会将其转换为一个表查询单次跳转。
 如果你的函数不需要返回值，不要定义一个。尽量避免数据转换
使类构造函数尽可能轻量
14. 如果可以的话，使用位移操作>>和<<来代替整数乘除法
推迟定义本地变量
/////////////////////////////////////////////////////////////////////////
#pragma warning(default:123)
跨平台专注者，，但是我已尽量不使用任何 windows 的东西，只使用标准 C 或标准C++。
Hzxz_Service
1. Constants.h,Hz_header.h,Hz_Service.h,main.h hzxz.ico;
2. namespace hzxz;
#ifndef _h #define _h #include ""
namespace hzxz{
	class A{
		
	};	
}

#endif
recv返回0是因为收到了FIN分节，所以返回0，表示对方主动关闭连接
客户端的程序 recv返回0,说明服务器主动断开了连接,需要重新连一下服务器.
服务器端的程序recv返回0,说明客户端主动断开了连接,当作断线处理一下就可以了.
////////////////////////////
握手-文件名，文件大小；发送-----发送结束。
多线程，线程池，内存池，内存映射文件，文件太大？？？
1.增加数据块编号：将数据分块传输，同时增加一个块号。
2.增加头尾：在每个数据块的头和尾各增加一个字节，以表示该数据的头和尾
3.增加文件长度：为了确保该数据的正确接受，可以在数据据块头后紧接着表示长度的数据，这样在收到数据头之后就可以拿数据的长度，然后按着这个长度收数据。
4.增加校验和：为了确保数据的正确性，可以在数据尾的前一位增加一位作为校验和，这样就可以确保收到的数据是正确的。如果不正确，必须请求重发。
5.组合数据：在收到数据后，按编号顺序组合数据。

send(sockClient,"hello",strlen("hello")+1,0);
TCHAR buf[100];
_itow_s(100,buf,10); int value = _tstoi("12");
  _itow
 /////////
 if(pWnd-> GetDlgCtrlID()==IDC_TEXT_MYBOLE) 
{ 
pDC-> SelectObject(pFont); 
pDC-> SetBkMode(TRANSPARENT); 
pDC-> SetTextColor(RGB(255,0,0)); 
GRAY_BRUSH
}m_editFont.CreatePointFont(180, "宋体");   
  
m_editPlace.SetFont(&m_editFont); // 设置新字体
CFileDialog dlg(TRUE,"avi",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"(*.avi;*.mp4;*.wmv)|*.avi;*.mp4;*.wmv||");
 if(dlg.DoModal() == IDOK)
 {
  m_video= dlg.GetPathName();
 }
 _T("((.dll;*.exe)|*.dll;*.exe|All Files(*.*)|*.*||")
 1. 启动隐藏了 ShowWindow(SW_MINIMIZE);
 2. listbox默认sort为true，应该改为false。
string to CString比较简单
string str="abcde";
CString cstr(str.c_str());

CString to string,要看你的CString用的是UNICODE还是非UNICODE,
非UNICODE就简单了
CString cs="abcde";
string str(cs.GetBuffer(cs.GetLength()));
CString 转 string
 USES_CONVERSION;  
CString temp=_T("kjdsaflkjdlfkj"); 
char* s_char=W2A(temp); 
std::string ss=s_char; 
3.垡头 
c++中使用google protobuf在关闭应用程序之前需要调用google::protobuf::ShutdownProtobufLibrary();
要不然会有内存泄露。
　　The sizeof keyword gives the amount of storage, in bytes, associated with a variable or a type (including aggregate types). This keyword returns a value of type size_t. 

sizeof在编译阶段处理的特性。　　结论：不要把sizeof当成函数，也不要看作一元操作符，把他当成一个特殊的编译预处理。 
有位秀才第三次进京赶考，住在一个经常住的店里。考试前两天他做了三个梦，第一个梦是梦到自己在墙上种白菜，第二个梦是下雨天，他戴了斗笠还打伞，第三个梦是梦到跟心爱的表妹躺在一起，但是背靠着背。这三个梦似乎有些深意，秀才第二天就赶紧去找算命的解梦。算命的一听，连拍大腿说："你还是回家吧。你想想，高墙上种菜不是白费劲吗？戴斗笠打雨伞不是多此一举吗？跟表妹躺在一张床上了，却背靠背，不是没戏吗？" 秀才一听，心灰意冷，回店收拾包袱准备回家。店老板非常奇怪，问："不是明天才考试吗，今天你怎么就回乡了？"秀才如此这般说了一番，店老板乐了："哟，我也会解梦的。我倒觉得，你这次一定要留下来。你想想，墙上种菜不是高种吗？戴斗笠打伞不是说明你这次有备无患吗？跟你表妹背靠背躺在床上，不是说明你翻身的时候就要到了吗？"秀才一听，更有道理，于是精神振奋地参加考试，居然中了个探花。-

启示：积极的人，象太阳，照到哪里哪里亮，消极的人，象月亮，初一十五不一样。想法决定我们的生活，有什么样的想法，就有什么样的未来。
启示：变换一种方式往往能起到意想不到的效果! 通常很多事情换一种做法结果就不同了。人生道路上，改善心智模式和思维方式是很重要的。. ..~.
乙去买烟，烟29元，他也没火柴，跟店员说：“便宜一毛吧。”最后，他用这一毛买一盒火柴。  


推荐的字符和字符串处理方式
1、开始将文本字符串想象为字符的数组，而不是char或字节的数组。
2、为文本字符和字符串使用泛型（比如TCHAR/PTSTR）。
3、修改字符串算术问题，既是字符数和字节数的区分。
4、避免使用printf系的函数，尤其是不要用%s和%S字段类型来进行ANSI与字符串的相互转换。正确的做法是使用MultiByteToWideChar和WideCharToMultiByte函数。
5、字符串操作，不想明确控制截断，则用StringCch系列安全字符串处理函数，否则选用后缀为_s的函数。

字符>=字节  成都市成华区双庆路 8 号万象城
成都市锦江区中纱帽街 8 号
class DLL_SAMPLE_API DLLClass  ；必须放在class 后面，前面没有输出lib。
 1、 visual studio没有专门的64位版。但32位版可以在64位系统上面正常使用。
hp-socket,libevent,asio.ace,ice,
隐式链接指将DLL的函数符号输出库LIB链接，在执行文件中IMPORT段加入一系列函数的入口点！程序在加载启动时自动加载这些DLL，并查找函数入口点！像普通的SDK程序要加入KERNEL32。LIB链接就是！这样的方法是当使用DLL多时，程序启动很慢、！     动态链接指显式加载DLL，利用LoadLibrary，GetProcAddress取得函数入口点，执行再释放，这种方法是程序简洁，快速！但是不利于输出太多函数的DLL使用！代码量太大！迭代器传的地址…引用传的本身…

64 app:32 dll:
用一个32bit的进程外COM作为代理。
   1、应用程序EXE所在的路径。2、系统目录。          4、Windows目录           5、当前目录       6、PATH环境变量指定的目录
OOM:outof memory.

 ini字段顺序要求。
_CrtSetBreakAlloc(223);  入口  查看内存泄漏
如果用MFC编程，不要用CreateThread，如果只是使用Runtime Library，用_BegingThread，

MFC _beginthreadex {string while(1);} 内存泄漏. AfxBeginThread.
线程异常退出，string未析构。
当你创建工作线程CWinThread *pSndTread = AfxBeginThread(fun,param);

如果你设置 pSndTread->m_bAutoDelete = FALSE;则需要你在线程结束后，要手动delete 掉 pSndTread对象；
如果你不设置m_bAutoDelete的话，则需要保证线程中始终在任何情况下都能执行 return 0;语句返回，因为这样不但可以将在线程中使用return返回所有资源都可以得到释放，包括c++对象。

protobuf leak?  
Zz
typedef unsigned char uint8_t;
不能清空的，除非你把缓冲区的内容全部读出，然后丢弃就可以了
还有个办法,用setsockopt把缓冲区大小改一下. Zz0405 apple  北京北京 南岳衡山 周华健
///////////////
消息  开源中间件库。扇出，发布-订阅，任务分配和请求-应答。
传输协议（进程内，进程间，TCP和多播。）零代理成本延迟，

分布式计算 -沟通问题！！！
软件的本质并不是算法，数据结构，语言和抽象，这些都只是我们制作使用并扔掉的工具。
软件的真正本质正是人的本质。

修复这个世界。代码交流，互联。发送消息给对方。人脑。
1.如何将任何地方的任何代码链接起来；
2.包装为人们容易理解的简单的构件中。



没有生成lib，因为没有包括头文件。
任何分布式，并行的需求，都可以用后三种模型组合起来解决问题。它只专注和解决了消息通讯这一基本问题。
以上模型中，关注的是通讯双方的职责，而不是实现的方式：监听端口还是连接对方端口。对于复杂的多进程协同工作的系统, 不必纠结于进程启动的次序。提供进程内、进程间、机器间、广播等四种通信协议。通信协议配置简单，用类似于URL形式的字符串指定即可，格式分别为inproc://、ipc://、tcp://、pgm://。ZMQ会自动根据指定的字符串解析出协议、地址、端口号等信息。

四种基本常用消息通信模型：分别是一对一结对模型（Exclusive-Pair）、请求回应模型（Request-Reply）、发布订阅模型（Publish-Subscribe）、推拉模型（Push-Pull）。

void (*(*papf)[2])(int);
typedef 
Warning: failed to load indicator string 0xF00C.
stringtable:添加字符串。

	System.EntryPointNotFoundException原因就是：c++源代码中的函数在编译成DLL后，函数的名称就发生了改变：会在函数的前后产生一些字符。
ErrorString(WORD err);

#pragma region 名称1                       // 名称1通常写“隐藏的代码”  
#pragma endregion 名称1                       // 名称1通常写“隐藏的代码”  
#ifdef _WIN64 C#dll直接用，不用类实例化。
有一定经验的程序员应该都知道Copy On Write(写时复制)使用了“引用计数”，会有一个变量用于保存引用的数量。当第一个类构造时，string的构造函数会根据传入的参数从堆上分配内存，当有其它类需要这块内存时，这个计数为自动累加，当有类析构时，这个计数会减一，直到最后一个类析构时，此时的引用计数为1或是0，此时，程序才会真正的Free这块从堆上分配的内存。
引用计数就是string类中写时才拷贝的原理！
什么情况下触发Copy On Write(写时复制)
很显然，当然是在共享同一块内存的类发生内容改变时，才会发生Copy On Write(写时复制)。比如string类的[]、=、+=、+等，还有一些string类中诸如insert、replace、append等成员函数等，包括类的析构时。
1.not extern "C" : ?Open@@YAHH@Z  C# err,C++ ok.
TCP 链接 断开过程。
网络地址  主机地址；
reverse commit 虚拟内存。Critical section Mutex
UINT __cdecl threadFun( LPVOID pParam )

Run-Time check Failure #0
原因：C++和其他语言混合编程，调用其他语言DLL时候，函数调用申明不同（标准和C）；造成错误，改为相同即可。
typedef int (__stdcall *ImpAPI)(int,int);


64 
#define HZ_API extern "C" __declspec(dllexport) 
win32:
HZ_API int c1(int x); == HZ_API int _cdecl c2(int x);   原样。c1 c2
HZ_API int __stdcall c3(int x); // _c3@4 

 __declspec(dllexport) int cpp1(int x);  // ?cpp1@@YAHH@Z
 __declspec(dllexport) int _cdecl cpp2(int x); // ?cpp2@@YAHH@Z
 __declspec(dllexport) int __stdcall cpp3(int x);// ?cpp3@@YGHH@Z
x64:其他一样。
HZ_API int __stdcall c3(int x); // 原样。


stdcall win32: add more _test@8  ; x64 : test.


工作目录是指当前目录， GetCurrentDirectory() 得到的路径； SetCurrentDirectory 来改变。


运行目录是指 exe 所在路径，可通过 GetModuleFileName() 得到。

问题二：某些函数的参数是可变的，如printf函数，这样的函数只能由函数调用者清除栈内数据。
_cdecl...


类方法的extern "C"