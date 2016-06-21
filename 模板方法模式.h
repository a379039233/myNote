定义一个操作中的算法骨架，而将一些步骤延迟到子类中。TemplateMethod使得子类可以不改变一个算法的接口即可重定义改算法的某些特定步骤。
class FileOperation
{
public:
     bool DownloadFile(wchar_t *pSrc, wchar_t *pDest)
     {
          if (!pSrc || !pDest) return false;
          if (!DoBeginDownloadFile(pSrc, pDest)) return false;
          if (!DoDownloadFile(pSrc, pDest)) return false;
          if (!DoEndDownloadFile(pSrc, pDest)) return false;
     }

protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};

class HttpFileOperation : public FileOperation
{
protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};

class SOAPFileOperation : public FileOperation
{
protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};
先调用DoBeginDownloadFile，执行下载文件之前的一些操作，再调用DoDownloadFile实现真正的文件下载，最后调用DoEndDownloadFile完成文件下载的清理工作。对于任何服务器，下载文件的这个流程是不会发生变化的。而在DoBeginDownloadFile、DoDownloadFile和DoEndDownloadFile的内部具体是如何实现的，由程序员根据具体的云端服务器和对外公开的接口来完成的。最终客户端去完成文件下载操作时，只会调用DownloadFile函数就可以完成。可以看到，在上面的代码中，只有DownloadFile是public的，其它的操作函数都是protected。这也意味着，我们完成的框架对外只公开DownloadFile接口。
#include <iostream>
using namespace std;

class AbstractClass
{
public:
     void TemplateMethod()
     {
          PrimitiveOperation1();
          cout<<"TemplateMethod"<<endl;
          PrimitiveOperation2();
     }

protected:
     virtual void PrimitiveOperation1()
     {
          cout<<"Default Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"Default Operation2"<<endl;
     }
};

class ConcreteClassA : public AbstractClass
{
protected:
          virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteA Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteA Operation2"<<endl;
     }
};

class ConcreteClassB : public AbstractClass
{
protected:
          virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteB Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteB Operation2"<<endl;
     }
};

int main()
{
     AbstractClass *pAbstractA = new ConcreteClassA;
     pAbstractA->TemplateMethod();

     AbstractClass *pAbstractB = new ConcreteClassB;
     pAbstractB->TemplateMethod();

     if (pAbstractA) delete pAbstractA;
     if (pAbstractB) delete pAbstractB;
}


