1. 在C/C++代码中获取MIC的核数的方法如下：
    #define mic_setup_command "micinfo | grep Active | head -1 | awk ' { print $7 }'"
    FILE *fp;
   fp = (FILE*)popen(mic_setup_command, "r");
    char tmp_buffer[100];
    fread(tmp_buffer, 80, 1, fp);
    mic_cores=atoi(tmp_buffer) ;
    fclose(fp);
如在7110P的系统上运行，得到的结果是：mic_cores=61

2. 在C/C++代码中获取MIC的内存的方法如下：
#define mic_setup_command "micsmc -m | grep 'Total Memory' | head -1 | awk ' { print $4 }'"
        FILE *fp;
        fp = (FILE*)popen(mic_setup_command, "r");
        char tmp_buffer[100];
        fread(tmp_buffer, 80, 1, fp);
        mem_mic = atof(tmp_buffer);
        fclose(fp);305416196
如在7110P的系统上运行，得到的结果是：Total Memory of mic is 15513.179688 MB


“Code Tells You How, Comments Tell You Why
、、、

Code Reivew
对高性能，高可用性，分布式，高并发，以及大规模数据处理系统有一些经验和心得。
软件编程、软件设计、软件工程。

《自适应软件开发》，封面上写着“尤其适用于紧张、高度竞争和经常变更的软件项目”
“我希望让那种使人们像被催眠的机器人那样在高速传送带上组装产品就能够产生生产软件产品的软件工厂的观念永远到一边歇着去”）
我们要让我们的团队充满生命力，充满创造性。要让我们的团队能够适应当今这个变化飞快、竞争激烈、复杂纷乱的年代。
这就是“自适应”理论的世界观，他的三大件是——“混乱边缘的繁荣”、“领导—协作”、“预测—协作—学习”。

“稳定和混乱具有相同的破坏性”！因此，真正的团队应该离开熟悉和稳定的状态，朝着混乱移动，但却不能迷失其中。成功也只会降临在保持忧患意识的人，那些能够调整自我矛盾、迷惘心情的人，以及那些保持足够创造力的人。
“革新、创造性和突发结果在混乱的边缘地带应运而生”！

对于人的个人发展，难道不也是这样的吗？对于一个在“混乱边缘”的民族（如日本和韩国）不是更有创造力吗？不是“乱世出英雄”吗？真正的稳定，是让自己适应变化，而不是呆在温暖的大棚下面。而是要出去接收新的空气，那怕波涛汹涌。真正的稳定是当变化来临时，自已照样屹立不倒。

当然，最最关键的是做到“边缘”，让稳定和混乱保持一种平衡，这是非常难的，但我们别无选择。就个人而言，我的对个人发展的信条是——“永远从事有挑战的事，但不要太有挑战，最好从事70%是熟练的，而30%却是从来没有接触过的事”，包括把自己放在一个高速成展的公司，而不是形成规模稳健的公司，也是给自己一个“混乱的边缘”。就软件工程而言，就是要让目标有那么一点不确定，而让团队自身调整。

那么，我们是不是要抛弃软件工程原有的东西，抛弃CMM？不！答案是否定的。我们需要他们，只不是过，原有的那些教条不再成为束缚我们思想创造力的枷锁，而变成控制这种平衡的工具。控制稳定和混乱的平衡，这才是其中的关键。

“混乱边缘的繁荣”，这是本书最根本的思想，书中所有的章节都是充斥着这种思想。

“领导—协作”是自适应管理的根本思想，也是一个团队的文化氛围。
这是自适应的模型的。“预测—协作—学习”不断迭代，从而让团队不断进化，不断适应多变的环境。
/////Goal 160307 cpp





 leetcode刷过7次的抢答。
当年leetcode才153道题，现在题目数量好像突破200大关了。
刷第一次的时候花了两三个星期，简直是全身心的按摩爽到爆炸。
刷第二次的时候感觉就不一样了，思路比刷第一次的时候清晰很多。
刷完之后感觉还没有参透其中的奥妙，于是乎刷了第三次、第四次、第五次。
刷第六次第七次的时候，一天能刷70+道题。
刷到后边，感觉这些题目已经倒背如流了。
然后歇菜了半年，现在看起来还能记得起其中一部分题目的思路。

刷完之后最大的感受就是： 
practice makes perfect

 、生活才是最重要的.job...
 
 安装git,安装TortoiseGit
 #include <afxinet.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
DWORD timebegin = timeGetTime();


linux c++,design mode,shujujiegiu yu als
l
wangluopashen
王老师
1.系统层软件开发 ；
服务器程序开发；流戏，网络，分布式，云计算
面向对像，具有较强的抽像和建模能力。使其在电信，金融，电商，通信，媒体，交
换路由等方面中不可或缺。
2.++ 1：C extend,2:oop(extend,,),3:stl
http://pan.baidu.com/s/1ntYhz8P  QT
int i = 123;
cout<<i<<endl;
cout<<dec<<i<<endl;
cout<<hex<<i<<endl;
cout<<oct<<i<<endl;
cout<<setbase(16)<<i<<endl;
3.extern "C"
default parameter...
int &b = a;//for parameter
use const whatever possible...
4.int *a = new int(5); delete a;
int *a = new int[100]; delete []a;
，重点用在类对像的申请与释放。申请的时候会调用构造器完成初始化，释
放的时候，会调用析构器完成内存的清理。
5.inline 
int i = static_cast<int>i1;
const_cast<>();
namespace ST{class a{}}
C++之父给C 程序员的建议
1、在C++中几乎不需要用宏，用const 或enum 定义显式的常量，用inline 避免函数调
用的额外开销，用模板去刻画一族函数或类型，用namespace 去避免命名冲突。
2、不要在你需要变量之前去声明，以保证你能立即对它进行初始化。
3、不要用malloc,new 运算会做的更好。
4、避免使用void*、指针算术、联合和强制，大多数情况下，强制都是设计错误的指示器。
5、尽量少用数组和C 风格的字符串，标准库中的string 和vector 可以简化程序。
6、更加重要的是，试着将程序考虑为一组由类和对象表示的相互作用的概念，而不是一
堆数据结构和一些可以拨弄的二进制。
7.
1 系统提供默认的拷贝构造器。一经实现，不复存在。
2 系统提供的时等位拷贝，也就是所谓的浅浅的拷贝。
3 要实现深拷贝，必须要自定义。
MyString::MyString(const MyString & other)
{
	int len = strlen(other._str);
	this->_str = new char[len+1];
	strcpy(this->_str,other._str);
}
MyString & MyString::operator=(const MyString & another)
{
	if(this == &another)
		return *this;
	else
	{
		delete []this->_str;
		int len = strlen(another._str);
		this->_str = new char[len+1];
		strcpy(this->_str,another._str);
		return *this;
	}
} 
8.ObjA is a ObjB, has a

 C++14...
开发者实现最高生产力的基础结构是什么。

第一级：减少不必要的干扰
准备好做小任务
戴上噪音消除耳机
不要失去状态 为什么打断 15 分钟的代价是 1 个小时 


、停止作重复的事情，并使它自动化!!!
于是 15 分钟法则就诞生了
1. 选出一件自己要做的正事(这会让你很明确地清楚目标)
2. 把所有干扰项都关掉 15 分钟，不要让它们在这个时间段打扰你
3. 没有干扰没有中断地做正事 15 分钟
4. 15 分钟后，如果我坚持不住，那我就放弃或是做其他事情
   Advanced C++
1.#include <array> array<int,3> = {1,2,3}; 替代C的数组；
for(int i : arr){}
auto fun(return 0;)
模板(auto,decltyoe);
int *p = nullptr;
2. delete []p;p=NULL;
 三种智能指针:
 std::unique_ptr,std::shared_ptr,std::weak_ptr;
 auto p = std::make_unique<obj>();
 std::unique_ptr<obj> p(new obj());
3. auto 去掉了引用和const限定符，
decltype(auto) f = foo();//keep the const and ref...
 兼容c面向过程；oop；STL   ；；；标准库；
 对象的思维而非0101位。
4. vector<int>,vector<string>
使用引用代替指针；
ch4！！！设计专业的C++软件
高效C++程序设计的两个基本主题：抽象和重用。人类思维 OOP。。。。 思想！
O(1) ,logn,n,n*logn,n^2,2^n,,,,,,
常数，对数，线性对数，二次方，指数。
5.OOP  类 组件，属性和行为。
 has a ,is a  关系，有一个，是一个。。。not a关系；
 ！设计。。。抽象和重用 OOP
 多重继承。
 （抽象：接口和实现分离）
实现是用来完成任务的代码，接口是其他用户使用代码的方式。
设计时重点考虑的两个因素---用户和目的。
6.堆栈中的对象，堆中的对象new。
///////////////////////////////////////////////////////////////
现代操作系统

1. CPU，内存，磁盘，IO设备（网络）
内核态和用户态
硬件-os-用户接口程序-应用程序
 为程序员提供一个资源集的清晰抽象，并管理这些硬件资源。文件，虚拟内存
 
 
 json
[{"age":100,"name":"hello world"}]
对象{} {"名称":值,"名称":值,};   名称/值 对集合
数组[值1，值2]  值的有序集合
 值：“”，23，true,null,array
 
 
 
 我有个字符串：
{"total":1,"toReturn":[{"createTime":"20080806114526000+0800","sex":"先生"}],"success":false}
但是想获取toReturn的内容就获取不了，请教楼主。。谢谢！

 
数据在键值对中
数据由逗号分隔
花括号保存对象 {}
方括号保存数组  [{0},{1},{2}]
 people.programmers[2].firstName
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 











说话的七宗罪
1.流言蜚语 评判 消极（抱怨） 借口 浮夸吹牛 固执己见。
传播太阳和光明。
四种：  言语有力
hail：honisty,
诚实，真实，正直，爱。
说的话和表达方式。
音域和音色，韵律。


