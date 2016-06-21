#include "stdafx.h"
class Product : public Product{
	public:
		virtual void show() = 0;
	    virtual] ~Product();//如果你申明了一个（会被使用）类成员函数的话，你就必须去实现它，当然编译的时候不会错误，但是链接的时候就会找不到这个函数。
};
class ProductA{
	public:
		void show(){
			cout<<"ProductA..."<<endl;			
		}
};
class ProductB : public Product{
	public:
		void show(){
			cout<<"Product B..."<<endl;			
		}
};
class Factory{
	public:
		static Product* CreatProduct(int type){
			switch(type){
				case 1:
				return new ProductA();
				case 2:
				return new ProductB();
				default:
				return NULL;
			}	
		}
};
int main()
{
	Product *productA = Product::CreatProduct(1);
	productA.show();
	delete productA;
	Product *productB = Product::CreatProduct(2);
	productB.show();
	delete productB;
	getchar();
	return 0;
}