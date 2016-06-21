/*
工厂模式有一种非常形象的描述，建立对象的类就如一个工厂，而需要被建立的对象就是一个个产品；在工厂中加工产品，使用产品的人，
不用在乎产品是如何生产出来的。从软件开发的角度来说，这样就有效的降低了模块之间的耦合。

简单工厂模式是属于创建型模式，又叫做静态工厂方法（Static Factory Method）模式.
简单工厂模式的实质是由一个工厂类根据传入的参数，动态决定应该创建哪一个产品类（这些产品类继承自一个父类或接口）的实例。
1.工厂（Creator）角色 2. 抽象产品（Product）角色 (描述公共接口) 3.具体产品（Concrete Product）角色

适用场合:
1.在程序中，需要创建的对象很多，导致对象的new操作多且杂时，需要使用简单工厂模式；
2.由于对象的创建过程是我们不需要去关心的，而我们注重的是对象的实际操作，所以，我们需要分离对象的创建和操作两部分，如此，方便后期的程序扩展和维护。
使用场景
工厂类负责创建的对象比较少；
客户只知道传入工厂类的参数，对于如何创建对象（逻辑）不关心；
由于简单工厂很容易违反高内聚责任分配原则，因此一般只在很简单的情况下应用。
/*
** FileName     : SimpleFactoryPatternDemo
** Author       : Jelly Young
** Date         : 2013/11/17
** Description  : More information, please go to http://www.jellythink.com
*/
//算法的父类，抽象出返回结果的接口
class Operation
{
public:
    virtual int GetResult() =0;
public:
    double m_Num1;
    double m_Num2;
};
//工厂类，用于生产相应的算法子类
class OperationFactry
{
public:
    OperationFactry(void);
    ~OperationFactry(void);
public:
    static Operation* CreateOperate(int n )
    {
        switch(n)
        {
        case 1:
            return new OperationAdd;
            break;
        }
    }
};
//算法子类，由工厂类创建，重写父类中的虚函数
class OperationAdd：Public Operation
{
public:
    int GetResult();
};
///////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

typedef enum ProductTypeTag
{
	TypeA,
	TypeB,
	TypeC
}PRODUCTTYPE;

// Here is the product class
class Product
{
public:
	virtual void Show() = 0;
	virtual Product() = 0;
};

class ProductA : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductA"<<endl;
	}
};

class ProductB : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductB"<<endl;
	}
};

class ProductC : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductC"<<endl;
	}
};

// Here is the Factory class
class Factory
{
public:
	Product* CreateProduct(PRODUCTTYPE type)
	{
		switch (type)
		{
		case TypeA:
			return new ProductA();

		case TypeB:
			return new ProductB();

		case TypeC:
			return new ProductC();

		default:
			return NULL;
		}
	}
};

int main(int argc, char *argv[])
{
	// First, create a factory object
	Factory *ProductFactory = new Factory();
	Product *productObjA = ProductFactory->CreateProduct(TypeA);
	if (productObjA != NULL)
		productObjA->Show();

	Product *productObjB = ProductFactory->CreateProduct(TypeB);
	if (productObjB != NULL)
		productObjB->Show();

	Product *productObjC = ProductFactory->CreateProduct(TypeC);
	if (productObjC != NULL)
		productObjC->Show();

	delete ProductFactory;
	ProductFactory = NULL;

	delete productObjA;
	productObjA = NULL;

	delete productObjB;
	productObjB = NULL;        

	delete productObjC;
	productObjC = NULL;

	return 0;
}



































*/