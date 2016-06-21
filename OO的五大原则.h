/*高内聚低耦合 solid
OO的五大原则是指SRP、OCP、LSP、DIP、ISP
1. SRP（Single Responsibility Principle 单一职责原则） 
单一职责很容易理解，所谓单一职责，就是一个设计元素只做一件事。
2. OCP （Open Close Principle 开闭原则）
一句话：“Closed for Modification; Open for Extension”——“对变更关闭；对扩展开放”。   可以扩展但是不可以修改
3. LSP（Liskov Substitution Principle 里氏替换原则）
子类应当可以替换父类并出现在父类能够出现的任何地方。这个原则是Liskov于1987年提出的设计原则。
它同样可以从Bertrand Meyer 的DBC (Design by Contract) 的概念推出。我们以学生为例，夜校生为学生的子类，
因此在任何学生可以出现的地方，夜校生均可出现。这个例子有些牵强，一个能够反映这个原则的例子时圆和椭圆，
圆是椭圆的一个特殊子类。因此任何出现椭圆的地方，圆均可以出现。但反过来就可能行不通。运用替换原则时，
我们尽量把类B设计为抽象类或者接口，让C类继承类B(接口B)并实现操作A和操作B，运行时，类C实例替换B，
这样我们即可进行新类的扩展(继承类B或接口B)，同时无须对类A进行修改。
4.DIP（Dependence Inversion Principle 依赖倒置原则）
依赖倒置（Dependence Inversion Principle）原则讲的是：要依赖于抽象，不要依赖于具体。简单的说，
依赖倒置原则要求客户端依赖于抽象耦合。原则表述：抽象不应当依赖于细节；细节应当依赖于抽象；
要针对接口编程，不针对实现编程。
5.ISP（Interface Segregation Principle 接口分隔原则）
采用多个与特定客户类有关的接口比采用一个通用的涵盖多个业务方法的接口要好。
ISP原则是另外一个支持诸如COM等组件化的使能技术。缺少ISP，组件、类的可用性和移植性将大打折扣。
这个原则的本质相当简单。如果你拥有一个针对多个客户的类，为每一个客户创建特定业务接口，
然后使该客户类继承多个特定业务接口将比直接加载客户所需所有方法有效。
*/
2.
Open-Closed Principle:我们在设计一个模块的时候,应当使这个模块可以在不被修改的前提下被扩展,换句话说就是,应当可以在不必修改源代码的情况下改变这个模块的行为.
factory mode.
但至少是要向着这个方向努力：对修改关闭（尽量不要让变化影响到已经设计好的类），对扩展开放（新的逻辑采用添加新代码即可实现）。
3.
//
Liskov替换原则：子类型必须能够替换它们的基类型.
即在一个软件系统中，基类出现的所有地方都必须能够被子类型替代。
所以有一个原则，子类的能力必须大于等于父类，即父类可以使用的方法，子类都可以使用。企鹅 鸟父类。
任何子类的对象都可以当做父类使用
//
 LSP是继承复用的基石，只有当子类可以替换掉父类，软件单位的功能不受到影响时，父类才能真正被复用，而子类也能够在
父类的基础上增加新的行为。里氏代换原则是对“开-闭”原则的补充。实现“开-闭”原则的关键步骤就是抽象化。而基类与子类的继承关系就是抽象化的具体实
现，所以里氏代换原则是对实现抽象化的具体步骤的规范。
正确的写法是我们可以把正方形和长方形抽象出来，再让正方形和长方形继承这个抽象类，从而这两个类互不
影响，各实现各的功能。
//当使用继承时，遵循里氏替换原则。类B继承类A时，除添加新的方法完成新增功能P2外，尽量不要重写父类A的方法，
也尽量不要重载父类A的方法。(方法名相同，参数不同)
父类中凡是已经实现好的方法（相对于抽象方法而言），实际上是在设定一系列的规范和契约，虽然它不强制要求所有的子类必须遵从这些契约，但是如果子类对这些非抽象方法任意修改，就会对整个继承体系造成破坏。而里氏替换原则就是表达了这一层含义。
如果非要重写父类的方法，比较通用的做法是：原来的父类和子类都继承一个更通俗的基类，原有的继承关系去掉，采用依赖、聚合，组合等关系代替。
//契约
！！！子类可以扩展父类的功能，但不能改变父类原有的功能。
11 子类可以实现父类的抽象方法，但不能覆盖父类的非抽象方法。
22 子类中可以增加自己特有的方法。
33 当子类的方法重载父类的方法时，方法的前置条件（即方法的形参）要比父类方法的输入参数更宽松。
44 当子类的方法实现父类的抽象方法时，方法的后置条件（即方法的返回值）要比父类更严格。
非要不遵循里氏替换原则会有什么后果？你写的代码出问题的几率将会大大增加。
4. 依赖倒置原则：要依赖于抽象，不要依赖于具体

A.高层次的模块不应该依赖于低层次的模块，他们都应该依赖于抽象。
B.抽象不应该依赖于具体实现，具体实现应该依赖于抽象。
依赖倒置原则（Dependence Inversion Principle）是程序要依赖于抽象接口，不要依赖于具体实现。简单的说就是要求对抽象进行编程，不要对实现进行编程，这样就降低了客户与实现模块间的耦合。
面向过程的开发，上层调用下层，上层依赖于下层，当下层剧烈变动时上层也要跟着变动，这就会导致模块的复用性降低而且大大提高了开发的成本。
面向对象的开发很好的解决了这个问题，一般情况下抽象的变化概率很小，让用户程序依赖于抽象，实现的细节也依赖于抽象。即使实现细节不断变动，只要抽象不变，客户程序就不需要变化。这大大降低了客户程序与实现细节的耦合度。
public class AutoSystem
{
private ICar icar;
public AutoSystem(ICar icar)
{
this.icar=icar;
}
private void RunCar()
{
icar.Run();
}
private void TurnCar()
{
icar.Turn();
}
private void StopCar()
{
icar.Stop();
}
}解决方案：将类A修改为依赖接口I，类B和类C各自实现接口I，类A通过接口I间接与类B或者类C发生联系，则会大大降低修改类A的几率。
依赖倒置原则的核心思想是面向接口编程
5.接口隔离原则 
使用多个专门的接口比使用单一的总接口要好。
 一个类对另外一个类的依赖性应当是建立在最小的接口上的。
 一个接口代表一个角色，不应当将不同的角色都交给一个接口。没有关系的接口合并在一起，形成一个臃肿的大接口，这是对角色和接口的污染。
 、、、
 
客户端不应该依赖它不需要的接口；一个类对另一个类的依赖应该建立在最小的接口上。
建立单一接口，不要建立庞大臃肿的接口，尽量细化接口，接口中的方法尽量少。
其一，单一职责原则原注重的是职责；而接口隔离原则注重对接口依赖的隔离。其二，单一职责原则主要是约束类，其次才是接口和方法，它针对的是程序中的实现和细节；而接口隔离原则主要约束接口接口，主要针对抽象，针对程序整体框架的构建。
 ※接口隔离原则: 多个和客户相关的接口要好于一个通用接口。

///
※迪米特法则：不相互直接通信的类之间，不要直接发生相互作用。

 ※合成/聚合复用原则：尽量使用合成/聚合，尽量不要使用继承。
少管闲事，不要动我的东西，
、、、、、、、、、、、
宿舍违背了“单一职责原则”。除了不是厕所，宿舍既是卧室，又是餐厅，既是书房，又是厨房，还是游戏机室兼棋牌室，甚至还兼琴房及健身房。我勒个去！你想看书，甲在看球，乙在泡面，丙在泡脚，还有一大波同学随时准备过来串门，发小广告，送外卖。
由于它承担了过多的职责，这些职责在并发执行的时候就会相互干扰。
一次只做一件事。惟精惟一
开放封闭原则 化妆和整容。

1.可扩展性Extensibility :允许一个具有同样接口的新类替代旧类，是对抽象接口的复用。
客户端依赖于抽象接口，而不是一个具体实现类，使得这个具体类可以被别的具体类替换，
而不影响客户端。以下原则实现可扩展性。
※开/闭原则
※里氏替换原则
※依赖倒转原则
※合成/聚合复用原则
2.可修改性Flexibility:模块相对独立，通信尽可能少。这样当一个模块修改时，对别的模块的影响很小。
以下原则实现可修改性。
※开/闭原则
※迪米特法则
※接口隔离原则
3、可替换性Pluggability：当一部分不再满足需要时，可以将旧的部分拔出，新的部分插入。
以下原则实现可替换性。
※开/闭原则
※里氏代换原则
※依赖倒转原则
※合成/聚合复用原则

 五．OO(面向对象)的设计过程
1. 分析式样，进行机能分类。
2. 根据机能进行类的抽象。
※ 类的抽象 - 在这里步里，我们可以根据 “单一职责原则”，进行类的具体抽象。
     尽量做到，类的功能单一和清晰化。
※ 封装变化点– 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，
     而不会对另一侧产生不良的影响，从而实现层次间的松耦合。
 3. 设计抽象基类和接口类。
※ 在进行基本的基类的抽象和接口定义时，要遵照“接口分离原则”进行接口的抽象。
※ 在设计接口和基类时，不要总是关注细节，要记住针对接口编程，而不是针对实现编程。
※ 对于抽象的基类和派生类之间要做到“里氏替换原则”的要求。
4.确定类间的耦合关系。
4.1 决定耦合的程度的依据何在呢？
※ 简单的说，就是根据需求的稳定性，来决定耦合的程度。
※ 对于稳定性高的需求，不容易发生变化的需求，我们完全可以把各类设计成紧耦合的，
     因为这样可以提高效率，而且我们还可以使用一些更好的技术来提高效率或简化代码。
※ 如 果需求极有可能变化，我们就需要充分的考虑类之间的耦合问题，我们可以想出各种
     各样的办法来降低耦合程度，但是归纳起来，不外乎增加抽象的层次来隔离不同的类，
     这个抽象层次可以是抽象的类、具体的类，也可以是接口，或是一组的类。
     我们可以用一句话来概括降低耦合度的思想："针对接 口编程，而不是针对实现编程。
※ 在决定类的耦合关系时，尽量考虑“迪米特法则”和“合成/聚合复用原则”。
4.2 怎样做到依赖倒转？
※ 以抽象方式耦合是依赖倒转原则的关键。抽象耦合关系总要涉及具体类从抽象类继承，
     并且需要保证在任何引用到基类的地方都可以改换成其子类，因此，里氏代换原则是依赖倒转原则的基础。
※ 依赖于抽象：建议不依赖于具体类，即程序中所有的依赖关系都应该终止于抽象类或者接口。尽量做到：
    （1）任何变量都不应该持有一个指向具体类的指针或者引用。
    （2）任何类都不应该从具体类派生。
    （3）任何方法都不应该覆写它的任何基类中的已经实现的方法。
5．运用OO设计的5大原则来对设计进行进一步的优化
※ 对于类的抽象和职能，是否满足“单一职责原则”
※ 对于继承关系和引用基类的地方，是否满足“里氏代换原则”和“依赖倒置原则”
※ 对于接口和基类，是否“接口隔离原则”
※ 总体上是否满足“开-闭原则”
 
总体上说，在面向对象设计时，要充分考虑设计的5大原则，但不是强求的，一味的追求满足原则也可能会
导致设计出的系统在性能和资源上的消耗，可以根据具体的情况来具体的分析和设计。

////////////
迪米特法则迪米特法则（Law of Demeter）又叫作最少知识原则（Least Knowledge Principle 简写LKP），
就是说一个对象应当对其他对象有尽可能少的了解,不和陌生人说话。
定义：一个对象应该对其他对象保持最少的了解。

问题由来：类与类之间的关系越密切，耦合度越大，当一个类发生改变时，对另一个类的影响也越大。
设计模式的门面模式（Facade）和中介模式（Mediator），都是迪米特法则应用的例子。
解决方案：尽量降低类与类之间的耦合。
、、、、、
filemapping
ftp...
任何时候，只要你提供了析构函数、拷贝构造函数或赋值运算符中的一个，你通常需要三个都提供。([
josuttis 绝不要提领一个空指针。if(p!=NULL) *p;
使用引用代替指针的主要的理由之一就是把你从不得不测试它是否引用一个无效的目标的负担中解放出来。空引用的唯一来源就是提领一个空指针
——这在神圣的标准里明确被禁止，在未定义的行为(Undefined Behavior)里也写的很清楚。” 
1.团队合作的第二准则：你不能破坏整体结构。 
for_each(ivec.begin(), ivec.end(), printElem);
for(vector<int>::const_iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
for_each(ivec.begin(), ivec.end(), bind2nd(ptr_fun(printElem), "Element:"));
 for_each(ivec.begin(), ivec.end(), printElem());operator()
 python脚本 技术不牢，地动山摇
 redis
 EPOLLLT——水平触发
 EPOLLET——边缘触发 one
 epoll有EPOLLLT和EPOLLET两种触发模式，LT是默认的模式，ET是“高速”模式。LT模式下，只要这个fd还有数据可读，每次 epoll_wait都会返回它的事件，提醒用户程序去操作，而在ET（边缘触发）模式中，它只会提示一次，直到下次再有数据流入之前都不会再提示了，无 论fd中是否还有数据可读。所以在ET模式下，read一个fd的时候一定要把它的buffer读光，也就是说一直读到read的返回值小于请求值，或者 遇到EAGAIN错误。
 理论和实践的区别实际上要比在理论上更大一些..
 所有的问题都可以通过多加一个间接层来解决。” 
 设计了类体系!!! 架构设计。
 ///////////////////////////////////
 Decorator:动态地给一个对象添加一些额外的职责。Facade 装饰器模式的本质就是动态组合。动态是手段，组合才是目的.
 在VC++中，生成DLL可以不使用.def文件。只需要在VC++的函数定义前要加__declspec(dllexport)修饰就可以了。
 C++ interface
 有三种导出定义的方法，按照建议的使用顺序依次为：
源代码中的 __declspec(dllexport) 关键字
.def 文件中的 EXPORTS 语句
LINK 命令中的 /EXPORT 规范
 #   define HZ_API   __declspec(dllexport)
 Insert @1
Delete @2
// 整个CXyz类被导出，包括它的函数和成员ok
class XYZAPI CXyz
{
public:
    int Foo(int n);
};
// 只有 CXyz::Foo函数被导出
//
class CXyz
{
public:
    XYZAPI int Foo(int n);
};
 #ifdef __cplusplus
extern "C" {
#endif
 在.c文件中包含了extern "C"时会出现编译时错误。extern "C"的真实目的是实现类C和C++的混合编程。在C++源文件中的语句前面加上extern "C"，表明它按照类C的编译和连接规约来编译和连接，而不是C++的编译的连接规约。
 DLL的主要目的，就是要被别人调用，所以正常情况下，被调DLL中的函数都应该是导出型的，也就是export，而对于主调程序EXE来说DLL中的函数是要导入，所以在EXE头文件中用import来声明；
但例外的情况是，某个DLL文件中不具备全部的被调函数，它也要靠调用其他的DLL函数来实现自己函数中的某些功能，那么最下端被调用的DLL中，只有导出函数export，而上层调用别人的DLL成了主调的身份，要导入，所以也就有了import。
////facade
外观模式，很多人也把它叫做门面模式。在GOF的《设计模式:可复用面向对象软件的基础》一书中对外观模式是这样说的：将子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。细细的理解这句话；子系统中的一组接口，就好比上面举得例子中的语法分析，生成中间代码，生成汇编代码，链接成可执行程序或库；外观模式定义的一个高层接口，就好比上面说的Build按钮，通过这样的一个Build按钮，让编译器更加容易使用，对于这一点，从Linux C++/C转Windows C++/C的程序员是最有体会的。visual studio提供的强大功能，只需要一个Build按钮，就可以进行Build动作，而不需要去写makefile文件，然后再去执行一些命令进行编译。
/*
** FileName     : FacadePatternDemo
** Author       : Jelly Young
** Date         : 2014/1/2
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

// 语法分析子系统
class CSyntaxParser
{
public:
     void SyntaxParser()
     {
          cout<<"Syntax Parser"<<endl;
     }
};

// 生成中间代码子系统
class CGenMidCode
{
public:
     void GenMidCode()
     {
          cout<<"Generate middle code"<<endl;
     }
};

// 生成汇编代码子系统
class CGenAssemblyCode
{
public:
     void GenAssemblyCode()
     {
          cout<<"Generate assembly code"<<endl;
     }
};

// 链接生成可执行应用程序或库子系统
class CLinkSystem
{
public:
     void LinkSystem()
     {
          cout<<"Link System"<<endl;
     }
};

class Facade
{
public:
     void Compile()
     {
          CSyntaxParser syntaxParser;
          CGenMidCode genMidCode;
          CGenAssemblyCode genAssemblyCode;
          CLinkSystem linkSystem;
          syntaxParser.SyntaxParser();
          genMidCode.GenMidCode();
          genAssemblyCode.GenAssemblyCode();
          linkSystem.LinkSystem();
     }
};

// 客户端
int main()
{
     Facade facade;
     facade.Compile();
}
通常来讲，对于子系统的访问，我们提供一个Facade层，而这个Facade入口，只需要一个；也就是说在使用Facade时，我们可以使用单例模式来实现Facade模式。
2.组合：表示两个对象之间是整体和部分的强关系，部分的生命周期不能超越整体，或者说不能脱离整体而存在。人和眼睛。
聚合：表示两个对象之间是整体和部分的弱关系，部分的生命周期可以超越整体。如电脑和鼠标

依赖关系（Dependence）：假设A类的变化引起了B类的变化，则说名B类依赖于A类。
大多数情况下，依       赖关系体现在某个类的方法使用另一个类的对象作为参数。void Drive(Car car);
泛化关系（Generalization）：A是B和C的父类，B,C具有公共类（父类）A，说明A是B,C的一般化（概括，也称泛化）
•  泛化关系(Generalization)也就是继承关系，也称为“is-a-kind-of”关系世界药房
实现关系；
预防为主，治疗为辅

Iterator模式的优点---单一职责原则
1，实现功能分离，简化容器接口。让容器只实现本身的基本功能，把迭代功能委让给外部类实现，符合类的设计原则。


socket客户端。
2. 状态模式的主要优点在于封装了转换规则，并枚举可能的状态，它将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为，还可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数；其缺点在于使用状态模式会增加系统类和对象的个数，且状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱，对于可以切换状态的状态模式不满足“开闭原则”的要求。

 char b[sizeof(struct _dataGram)];
    memcpy(b, &opendoor, sizeof(struct _dataGram));
#pragma pack (1) #pragma pack ()
systeminfo dll,32 64 对应。 x64 debugok,release err.
TCP报文段会有失序，重复，对于截包还会有丢包。分片
send(clientSocket, sendBuf, strlen(sendBuf) + 1, 0); 这样，把0字节也发送了过去，也解决了乱码问题。在多数情况下，程序代码应是简单易懂，甚至清洁工也能看懂。

///
老师打印出来的那一份，就是“原型”，而复制出来的那50份，就是使用的“拷贝”。而原型模式就是这么简单的一个道理，通过现有的东西，再复制出一个来。
我们使用原型模式，就是为了创建对象。

COM也是如此，COM是面对接口的，当完成某一个功能模块时，就可能是系列接口的叠加调用，而接口的实现都是由程序员来控制的。说白了，一个功能模块的实现流程是固定了，但是对于每一步的具体实现都是不固定的。
这个设计模式叫模板方法模式.定义一个操作中的算法骨架，而将一些步骤延迟到子类中。TemplateMethod使得子类可以不改变一个算法的接口即可重定义改算法的某些特定步骤。
、、
项目投入运营以后涉及到版本升级时的新增消息字段全部使用optional或者repeated
共享目录，ftp ZeroMQ 号称史上最好的通讯库(nanomsg),activemq;MSMQ
网络上各种各样的通讯中间件/MQ多不胜数。具作者所知，比较有名的有ACE、ICE、Boost::ASIO、MSMQ、ActiveMQ、RabbitMQ、ZeroMQ等等。

零复制API，允许内存从一台机器复制到另一台机器，而且完全不需要CPU的参与，