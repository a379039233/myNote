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
this指针，const成员函数(mutable).






























*/
