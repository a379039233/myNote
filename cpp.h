//16.3.28 mode,algo,linux,boost
/*
1. #inclde <iostream>
�ڴ滺����ˢ�� buffer.
C++�����һ����ƽ������ܶ���ʹ��������������һ����Ȼ�������͡�
2. ������̣����ڶ���������󣬷��͡�
������ָһ���ܴ洢��Ⲣ����ĳ�����͵��ڴ�ռ䡣
int init = 0;
extern int ii = 1;//define not declare
3. int &ref = i;
int *pi = &i; int **pi = &pi;
4. typedef int INT_P;//����
auto  i = 1��
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
���б�׼��ĵ�������������==�ͣ�=,����û�ж���<!!
auto mid = v.begin() + v.size()/2;
8. int arr[] = {1,2,3};
int *(&array)[10] = ar;//The ref of array,The array have 10 pointers.
size_t ttt;
c style string:
strlen,strcmp,strcat,strcpy. end with \0.
const char *str = s.c_str();
����ʹ�ñ�׼�����Ͷ������顣
9. ��������չ��
~,<<,>>,!,
static_case<int>(var);const_cast<int>(var);
switch,break,continue.goto
10.function... jmp ret
��������������ڡ�
ֻ�����ڿ�ִ���ڼ�Ķ����Ϊ�Զ�����ʵ�εĿ���ֵ�ͷ���ֵ��
static int cnt = 0;
ֵ���ݣ�ָ�봫�ݣ����ô��ݡ�
ʹ�����÷��ض������Ϣ������ʹ�ó������á�
void print(int *pa,int len);
void print(int (&arr)[10]);//���������β�
��Ҫ���ؾֲ���������û�ָ�롣���������õ����ں���֮ǰ�Ѿ����ڵ��Ǹ�����
const sring& fun(){string ret;return ret;}
10.�����������������⡣
int (*func(int i))[10];//����������ʽ
auto func(int i) -> int(*)[10];
int odd[] = {1,3,5};int even[] = {2,4,6};
decltype(odd) * arrPtr(int i=0){
	return (i%2)?&odd:&even;
} 
11.����ָ����������ָ���滻���������ɡ�
void f(int i); void (*pf)(int);
pf = f; pf(10);
���غ���ָ�롣
auto f1(int) -> int(*)(int, int);
12. class 
���ݳ���ͷ�װ���ӿں�ʵ�֡�
thisָ�룬const��Ա����(mutable).






























*/
