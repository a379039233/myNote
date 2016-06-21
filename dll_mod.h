#ifndef XDH_DLL_H
#define XDH_DLL_H

#ifdef  XDH_DLL_EXPORTS
#define HZ_API extern "C" __declspec(dllexport)
#else
#define HZ_API __declspec(dllimport)
#endif 

#include <vector>
#include <string>
using std::string;

HZ_API size_t test(const string& in,string out);

#endif //XDH_DLL_H  添加一个头文件
cpp:
#inlcude "head.h"

size_t test(const string& in,string out){}
//////////////////////////////////////////