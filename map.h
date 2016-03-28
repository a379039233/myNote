  HANDLE wp = CreateFile( TEXT("D:\\121.iso"),//这里输入 需要粘贴的文件 dst
  GENERIC_READ | GENERIC_WRITE,
  FILE_SHARE_WRITE,
  NULL,
  CREATE_ALWAYS,
  FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_WRITE_THROUGH, 
  NULL);

 HANDLE hFileMapping2 = CreateFileMapping( wp,
  NULL,
  PAGE_READWRITE, 
  0,//(DWORD)(dwBytesInBlock >> 16), 
  dwBytesInBlock,//(DWORD)(dwBytesInBlock &  0x0000FFFF),
  NULL);

CloseHandle(wp);

 LPVOID pbFile2 = (LPVOID)MapViewOfFile( hFileMapping2,
  FILE_MAP_ALL_ACCESS,
  (DWORD)(qwFileOffset >> 32), 
  (DWORD)(qwFileOffset &  0xFFFFFFFF),
  dwBytesInBlock);

 memcpy(pbFile2,pbFile,dwBytesInBlock);

 UnmapViewOfFile(pbFile2);
 UnmapViewOfFile(pbFile);

 CloseHandle(hFileMapping2);
 CloseHandle(hFileMapping);
 febird c++序列化库。多花些精力在并行计算上吧，一定会有丰富的回报。
 这里所指的网络编程是指socket编程。现在C++的应用很多都是在做服务器开发，如何开发一个高并发、大吞吐量、高稳定性的服务器就是我们要考虑的了。

设计模式不是具体的技术，更多的是如何让代码更容易阅读、更好扩展、更容易使用。


 
 简单来说，序列化就是将对象实例的状态转换为可保持或传输的格式的过程。与序列化相对的是反序列化，它根据流重构对象。这两个过程结合起来，可以轻松地存储和传输数据。
 
    Boost中，与序列化有关的两个库是Archive库和Serialization库。

4.1.2 实现步骤
首先，为被序列化的类实现一个对应的serialize(Archive & ar, const unsigned int version)方法；

其次，构造boost::archive::text_oarchive类或其他archive输出类的对象，并将其关联到一个输出流，利用<<运算符将被序列化的对象输出到某个文档中；

最后，构造boost::archive::text_iarchive类或其他archive输入类的对象，并将其关联到一个输入流，读入数据，利用>>运算符会付出被序列化的对象。

4.1.3 注意事项
使用这种方法需要注意的是：

l  Boost从1.32版本之后才提供对序列化的支持，所以一定要用版本在1.32之后的；

l  Boost中的Serialization库需要编译之后得到库文件才能使用，并加入项目的附加依赖项中才可使用；

l  根据需要包含boost/serialization和boost/archive下的一些头文件。
 
 class Singleton{ 
public: 
    static Singleton* Instance(); 
protected: 
    Singleton(){} 
    Singleton(const Singleton &instance){} 
    Singleton& operator=(const Singleton &instance){} 
private: 
    static Singleton* instance; 
}; 
Singleton* Singleton::Instance(){ 
    if(instance == 0) 
        instance = new Singleton; 
    return instance; 
} 
Singleton* Singleton::instance = 0; 
 1. 客户在接触到产品之后，才会真正明白自己的需求。

Protocol Buffers (ProtocolBuffer/ protobuf )是Google公司开发的一种数据描述语言，
类似于XML能够将结构化数据序列化，可用于数据存储、通信协议等方面。
现阶段支持C++、JAVA、Python等三种编程语言。
为什么不只用XML？同XML相比，Protocol buffers在序列化结构化数据方面有许多优点（google官方提出）：

更简单
数据描述文件只需原来的1/10至1/3
解析速度是原来的20倍至100倍
减少了二义性
生成了更容易在编程中使用的数据访问类
Google大概是2008年7月8日将其作为开源项目对外公布，说是后续还要开源的项目有不少都会用到Protocol Buffers。

windows下，需要下载两个包protobuf-2.5.0.tar.bz2和protoc-2.5.0-win32.zip
xinyoulixiang,chunnuanhuakai.





