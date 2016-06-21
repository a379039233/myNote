RapidJSON是只有头文件的C++库。只需把include/rapidjson目录复制至系统或项目的include目录中。

example:
simpleWroter,reader.tutorial,serizlize.....

DOM实际上是以面向对象方式描述的文档模型。DOM定义了表示和修改文档所需的对象、这些对象的行为和属性以及这些对象之间的关系。可以把DOM认为是页面上数据和结构的一个树形表示，不过页面当然可能并不是以这种树的方式具体实现。


JSON 值可以是：
数字（整数或浮点数）
字符串（在双引号中）
逻辑值（true 或 false）
数组（在方括号中）
对象（在花括号中）
null

1. 
{
"employees": [
{ "firstName":"John" , "lastName":"Doe" },
{ "firstName":"Anna" , "lastName":"Smith" },
{ "firstName":"Peter" , "lastName":"Jones" }
]
}  employees[0].lastName;employees[0].lastName = "Jobs";


DOM树。HTML 文档中的所有内容都是节点：
整个文档是一个文档节点
每个 HTML 元素是元素节点
HTML 元素内的文本是文本节点
每个 HTML 属性是属性节点
注释是注释节点


assert(document.IsObject());IsBool，isNUll；GetDouble getint
for (Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
    printf("%d ", itr->GetInt());

HasMember ，IsUint，IsUint64，IsDouble
Value b(true);    // 调用Value(bool)
Value i(-123);    // 调用 Value(int)
Value u(123u);    // 调用Value(unsigned)
Value d(1.5);     // 调用Value(double)

1
C++文件流：
fstream　　// 文件流ifstream　 // 输入文件流ofstream　 // 输出文件流
  ofstream f1("d:\\me.txt");      //打开文件用于写,若文件不存在就创建它,empty
  if(!f1)return;                 //打开文件失败则结束运行
  string str = "";
  f1 << str;
  f1.close(); 
  2
#include <string>  
#include <fstream>  
#include <sstream>  
std::ifstream f2("file.txt");  
std::stringstream buffer;  
buffer << f2.rdbuf();  
std::string contents(buffer.str());
f2 >> str;
f1.close();
3.
 Value & contents = doc["content"];
    if (contents.IsArray()) {
        for (size_t i = 0; i < contents.Size(); ++i) {
            Value & v = contents[i];
            assert(v.IsObject());
            if (v.HasMember("key") && v["key"].IsString()) {
                psln(v["key"].GetString());
            }
            if (v.HasMember("value") && v["value"].IsString()) {
                psln(v["value"].GetString());
            }
        }
    }
	4.
	/ rapidjson/example/simpledom/simpledom.cpp`
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
using namespace rapidjson;
int main() {
    // 1. 把JSON解析至DOM。
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    // 2. 利用DOM作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. 把DOM转换（stringify）成JSON。
    StringBuffer buffer;
    Writer<StrinBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
}
5.
StartObject();writer.Key("hello");StartArray();endarray()l


char szBuf[1024]={0};
string strPath;
getcwd(szBuf,1024);
strPath =szBuf;
GetModuleFileNameA(NULL,szBuf,sizeof(szBuf));
strPath =szBuf;
strPath = strPath.substr(0,strPath.rfind('\\'));

tinyxml;




// rapidjson/example/simpledom/simpledom.cpp`
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
using namespace rapidjson;
int main() {
    // 1. 把JSON解析至DOM。
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    // 2. 利用DOM作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. 把DOM转换（stringify）成JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
}
