
代码的稳定、易读、规范、易维护、专业。学习钻研精神，积极主动，沟通。
SECURITY_ATTRIBUTES sa;
sa.nLength = sizeof(sa);
sa.lpSecurityDescriptor = NULL;
sa.bInheritHandle = TRUE; // 使返回的句柄成为可继承的句柄
HANDLE hMutex = CreateMutex(&sa, FALSE, NULL);

CreateProcess(
这些检查中的任何一项失败，函数都会设置局部于线程的C运行时变量errno。
强烈建议你使用Unicode字符和字符串
///data,ipo, ---stra,algs
//////////book,code,project...stl,designmode,
Programmers who don’t code in their spare time for fun will never become as good as those that do.

1.winapi
文件系统,内存管理，进程线程和模块，设备io驱动程序控制，调试与错误处理
windows系统信息，进程间通信，定时器和消息机制。其他
2.防火墙， cl.exe
虚拟内存划分为两个部分，进程使用2GB，称为用户进程空间；内核使用2GB，称为系统地址空间或内核地址空间
虚拟地址空间在进程上是封闭的，进程只能访问属于自己的地址空间，如果要访问其他进程的地址空间
需特殊的机制。

应用程序可使用的低地址空间中包括了应用程序的代码、数据（全局变量等）、系统和用户DLL的代码、各线程的栈、堆等。
进程的每个线程都有自己的栈，栈与函数的调用、执行和返回及局部变量的保存相关，一般情况下，
栈中保存着函数的参数、返回地址和局部变量，调用函数将参数入栈，调用指令将函数返回地址入栈，
被调用函数负责保存调用函数的相关栈指针，为局部变量分配空间等，而堆是一种可以动态分配和释放的内存，
由堆管理器进行管理，用户在程序中使用的内存分配函数都是通过堆进行分配的。

堆是一种内存管理的对象，一个进程有若干个堆，在分配内存前需要指定从哪个堆上进行分配。堆的句柄惟一标识了一个堆。
推荐软件开发人员使用Heap函数.HeapAlloc();   GlobalAllo,LocalAlloc...
标准C函数的内存分配函数则直接使用了HeapAlloc。
。一个系统中同一时间只能有少量线程执行（决定于CPU个数和核数），操作系统会决定当前执行哪一个线程，并进行调度。

每个内核对象都只是一个内存块，它由内核分配，并只能由内核访问。这个内存块是一个数据结构，其成员维护着与对象相关的信息
这一切没有想象的那么糟 MP3
内核对象的所有者是内核，而非进程。换言之，如果你的进程调用一个函数来创建了一个内核对象，然后进程终止运行，则内核对象并不一定会销毁。大多数情况下，这个内核对象是会销毁的，但假如另一个进程正在使用你的进程创建的内核对象，那么在其他进程停止使用它之前，它是不会销毁的。总之，内核对象的生命期可能长于创建它的那个进程。
3.“用户帐户控制”（User Account Control，UAC）
一个进程在初始化时，系统将为它分配一个句柄表（handle table）。
一个进程首次初始化的时候，其句柄表为空。当进程内的一个线程调用一个会创建内核对象的函数时（比如CreateFileMapping），内核将为这个对象分配并初始化一个内存块。然后，内核扫描进程的句柄表，查找一个空白的记录项（empty entry）。
4.利用三种不同的机制来允许进程共享内核对象：使用对象句柄继承；为对象命名；以及复制对象句柄。
SECURITY_ATTRIBUTES sa;
sa.nLength = sizeof(sa);
sa.lpSecurityDescriptor = NULL;
sa.bInheritHandle = TRUE; // 使返回的句柄成为可继承的句柄
HANDLE hMutex = CreateMutex(&sa, FALSE, NULL);
DuplicateHandle，一个进程想把一个内核对象的访问权授予另一个进程。
5.进程是有“惰性”的。进程要做任何事情，都必须让一个线程在它的上下文中运行。该线
程要执行进程地址空间包含的代码。，Windows内核将负责线程的所有管理和调度任务。
GUI 创建控制台窗口。。/SUBSYSTEM:WINDOWS开关改为/SUBSYSTEM:CONSOLE
获取和设置其进程的当前驱动器和目录 GetCurrentDirectory(),SetCurrentDirectory()
GetModuleFileName.GetVersionEx   
考虑到Win10的免费升级优惠不日即将截止
6.将进程放入作业中
Windows提供了一个作业（job）内核对象，它允许你将进程组合在一起并创建一个“沙箱”来
限制进程能够做什么。最好将作业对象想象成一个进程容器。
7.进程实际是由两个组件组成的：一个进程内核对象和一个地址空间
，每个线程都被分配了一个CPU。所以，如果我计算机有两个CPU，而且应用程序有两个线程，那么两个CPU
都会很忙。其结果就是，只需花一个任务的时间，两个任务都可以完成。
GetCurrentProcess(); GetCurrentThread();
8.20ms 切换线程，我们无法保证线程总在运行，线程会获得整个处理器，系统将不允许允许其他线程等。
共享文件、ftp、scp等难度低，
9.sleep(); time no need to schedule. 并不准确852428470
int i = 0;
		*(int  *)&i = 100;
		int k = *(int  *)&i;
		cout<<"k="<<k<<endl;

双核四线程和四核。超线程。4核8线 就是说, 使用了 超线程技术 , 把一个物理核心, 模拟成 2个逻辑核心, 
10.系统同时会把该进程可以访问的所有内存映射文件映射到这一分区）。
dll在物理内存中只有一份，不同程序映射到同一个物理地址而已。
Unix 环境高级编程
超线程，逻辑cpu：每个运行一个线程。
任何时刻系统中大多数线程都是不可调度的。。。
11.线程同步
1) volatile bool  g_finished = false;不优化，始终从内存读取而非cache。
2) Interlocked 原子访问;
3) 关键段Critical_section; TryEnterCriticalSection...
InitializeCriticalSectionAndSpinCount(cs,100);4000
4) Slim读写锁；写入进程和读取进程（条件变量）
SleepConditionVaribleCS,SleepConditionVaribleSRW;WakeAllConditonVarible
5) 互斥量 WaitForSingleObject(g_hMutex,INFINITE);
6) 事件对象；
对线程同步来说，这些内核对象中的每一种要么处于触发状态，要么处于未触发状态。
进程内核对象在创建的时候总处于未触发状态，当进程终止的时候，os会自动使进程内核对象变成触发状态。
线程，作业，事件，信号量，互斥量。触发旗帜升起，可调度；
WaitForSingleObject(hProcess,INFINITE);
12.  可等待的计时器；
13.IO完成端口  All  is file。CreateFile("");
/////////////Love it or leave it.


 
 
 
 
 
 
 
 
 


