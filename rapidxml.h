void build_simple_doc_by_rapidxml() 
{ 
xml_document<> doc; 
xml_node<>* decl = doc.allocate_node(node_declaration); 
xml_attribute<>* decl_ver = 
doc.allocate_attribute(“version”, “1.0″); 
decl->append_attribute(decl_ver); 
doc.append_node(decl);

xml_node<>* node = 
doc.allocate_node(node_element,    “Hello”, “World”); 
doc.append_node(node);

string text; 
rapidxml::print(std::back_inserter(text), doc, 0);

// write text to file by yourself 
}

void parse_doc_by_rapidxml(char* xml_doc) 
{ 
xml_document<> doc;        // character type defaults to char 
doc.parse<0>(xml_doc);  // 0 means default parse flags

xml_node<> *node = doc.first_node(“Hello”); 
string node_val = node->value(); 
}
1.write
#include <iostream>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

using namespace rapidxml;

int main()
{    
	xml_document<> doc;  
	xml_node<>* rot = doc.allocate_node(rapidxml::node_pi,doc.allocate_string("xml version='1.0' encoding='utf-8'"));
	doc.append_node(rot);
	xml_node<>* node =   doc.allocate_node(node_element,"config","information");  
	xml_node<>* color =   doc.allocate_node(node_element,"color",NULL);  
	doc.append_node(node);
	node->append_node(color);
	color->append_node(doc.allocate_node(node_element,"red","0.1"));
	color->append_node(doc.allocate_node(node_element,"green","0.1"));
	color->append_node(doc.allocate_node(node_element,"blue","0.1"));
	color->append_node(doc.allocate_node(node_element,"alpha","1.0"));

	xml_node<>* size =   doc.allocate_node(node_element,"size",NULL); 
	size->append_node(doc.allocate_node(node_element,"x","640"));
	size->append_node(doc.allocate_node(node_element,"y","480"));
	node->append_node(size);

	xml_node<>* mode = doc.allocate_node(rapidxml::node_element,"mode","screen mode");
	mode->append_attribute(doc.allocate_attribute("fullscreen","false"));
	node->append_node(mode);

	std::string text;  
	rapidxml::print(std::back_inserter(text), doc, 0);  

	std::cout<<text<<std::endl; 

	std::ofstream out("config.xml");
	out << doc;

	system("PAUSE");
	return EXIT_SUCCESS;
}
2. 写文件例子
#include <string>
#include <iostream>
#include <fstream>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"


using namespace rapidxml;
using namespace std;

int main(int argc, char* argv[])
{

    xml_document<> doc; //是解析器
    char a[] = "<top>"//如果单独传, 就不能加上xml的头部信息，
               //否则会报错
               "<name>tangqiang</name>"
               "<age>22</age>"
               "</top>";
    char* p = a;
    doc.parse<0>(p);

    xml_node<>* node = doc.first_node();//去顶级结点
    cout << (node->name())<< endl;
    node = node->first_node();
    while (node) {
        cout << node->name() << node->value() << endl;//name() value()返回的字符串不会去掉首尾的空白字符
        node = node->next_sibling();
    }

    ofstream out("test.xml");//ofstream 默认时，如果文件存在则会覆盖原来的内容，不存在则会新建
    out << doc;//doc 这样输出时在目标文件中不会有xml 头信息---<?xml version='1.0' encoding='utf-8' >
    out.close();
	system("pause");
    return 0;
}
3.read
#include <iostream>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

using namespace rapidxml;

int main()
{
    file<> fdoc("config.xml");
    std::cout<<fdoc.data()<<std::endl;
    xml_document<>   doc;
    doc.parse<0>(fdoc.data());

    std::cout<<doc.name()<<std::endl;

    //! 获取根节点
    xml_node<>* root = doc.first_node();
    std::cout<<root->name()<<std::endl;

    //! 获取根节点第一个节点
    xml_node<>* node1 = root->first_node();
    std::cout<<node1->name()<<std::endl;

    xml_node<>* node11 = node1->first_node();
    std::cout<<node11->name()<<std::endl;
    std::cout<<node11->value()<<std::endl;

    //! 添加之后再次保存
    //需要说明的是rapidxml明显有一个bug
//那就是append_node(doc.allocate_node(node_element,"h","0"));的时候并不考虑该对象是否存在!
    xml_node<>* size = root->first_node("size");
    size->append_node(doc.allocate_node(node_element,"w","0"));
    size->append_node(doc.allocate_node(node_element,"h","0"));

    std::string text;
    rapidxml::print(std::back_inserter(text),doc,0);

    std::cout<<text<<std::endl;

    std::ofstream out("config.xml");
    out << doc;

    system("PAUSE");
    return EXIT_SUCCESS;
}
4.del node-
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

#include<iostream>
using namespace rapidxml;

int main()
{
	file<> fdoc("config.xml");
	xml_document<> doc;
	doc.parse<0>(fdoc.data());

	std::string text;  
	rapidxml::print(std::back_inserter(text), doc, 0);  
	std::cout<<text<<std::endl; 

	xml_node<>* root = doc.first_node();

	xml_node<>* sec = root->first_node();

	root->remove_node(sec); //移除根节点下的sec结点(包括该结点下所有结点)
	text="删除一个节点\r\n";  
	rapidxml::print(std::back_inserter(text), doc, 0);  
	std::cout<<text<<std::endl; 

	root->remove_all_nodes(); //移除根节点下所有结点
	text="删除所有节点\r\n";  
	rapidxml::print(std::back_inserter(text), doc, 0);  
	std::cout<<text<<std::endl; 

	std::ofstream out("test.xml");
	out<<doc;
	system("pause");
	return 0;
}
5.edit node-
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

#include<iostream>
using namespace rapidxml;

int main()
{
	file<> fdoc("config.xml");
	std::cout<<fdoc.data()<<std::endl;
	xml_document<> doc;
	doc.parse<0>(fdoc.data());

	std::cout<<doc.name()<<std::endl;

	//! 获取根节点
	xml_node<>* root = doc.first_node();
	xml_node<>* delnode = root->first_node("color");
	root->remove_node(delnode);//先删除address节点
	//
	xml_node<>* lnode = root->first_node("size");//找到post节点
	xml_node<>* mynode=doc.allocate_node(node_element,"address","河北");
	root->insert_node(lnode,mynode);

	std::string text;
	rapidxml::print(std::back_inserter(text),doc,0);


	std::cout<<text<<std::endl;

	std::ofstream out("version.xml");
	out << doc;
	system("pause");
	return 0;   
}6. 遍历所有节点
for(rapidxml::xml_node<char> * node = parent_node->first_node("node name");
    node != NULL;
    node = node->next_sibling())
{
    ...
}
遍历所有属性
for(rapidxml::xml_attribute<char> * attr = node->first_attribute("node name");
    attr != NULL;
    attr = attr->next_attribute())
{
    char * value = attr->value();
}


11111111111111111
关于raidxml资料相关的介绍网上有很多资料，在这里我就不重复介绍了，下面直接贴代码：

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

//下面三个文件是本段代码需要的库文件
#include "rapidxml/rapidxml.hpp"       
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

int CreateXml();
int ReadAndChangeXml();
int _tmain(int argc, _TCHAR* argv[])
{
    //测试用例
    CreateXml();
    //测试用例
    ReadAndChangeXml();
    system("pause");
    return 0;
}
//创建一个名称为config2.xml文件
int CreateXml()
{
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<>* rot = doc.allocate_node(rapidxml::node_pi,doc.allocate_string("xml version='1.0' encoding='utf-8'"));
    doc.append_node(rot);
    rapidxml::xml_node<>* node = doc.allocate_node(rapidxml::node_element,"config","information");
    doc.append_node(node);
    rapidxml::xml_node<>* color = doc.allocate_node(rapidxml::node_element,"color",NULL);
    node->append_node(color);
    color->append_node(doc.allocate_node(rapidxml::node_element,"red","0.1"));
    color->append_node(doc.allocate_node(rapidxml::node_element,"green","0.1"));
    color->append_node(doc.allocate_node(rapidxml::node_element,"blue","0.1"));
    color->append_node(doc.allocate_node(rapidxml::node_element,"alpha","1.0"));
    rapidxml::xml_node<>* size = doc.allocate_node(rapidxml::node_element,"size",NULL);
    size->append_node(doc.allocate_node(rapidxml::node_element,"x","640"));
    size->append_node(doc.allocate_node(rapidxml::node_element,"y","480"));
    node->append_node(size);
    rapidxml::xml_node<>* mode = doc.allocate_node(rapidxml::node_element,"mode","screen mode");
    mode->append_attribute(doc.allocate_attribute("fullscreen","false"));
    node->append_node(mode);
    std::string text;
    rapidxml::print(std::back_inserter(text), doc, 0);
    std::cout<<text<<std::endl;
    std::ofstream out("../config/config1.xml");
    out << doc;

    return 0;
}


//读取并修改config3.xml
int ReadAndChangeXml()
{
     rapidxml::file<> fdoc("../config/config2.xml");
     std::cout<<fdoc.data()<<std::endl;
     rapidxml::xml_document<> doc;
     doc.parse<0>(fdoc.data());
     std::cout<<doc.name()<<std::endl;
     //! 获取根节点
     rapidxml::xml_node<>* root = doc.first_node();
    std::cout<<root->name()<<std::endl;
    //! 获取根节点第一个节点
    rapidxml::xml_node<>* node1 = root->first_node();
    std::cout<<node1->name()<<std::endl;
    rapidxml::xml_node<>* node11 = node1->first_node();
    std::cout<<node11->name()<<std::endl;
    std::cout<<node11->value()<<std::endl;
    //! 修改之后再次保存
    rapidxml::xml_node<>* size = root->first_node("size");
    size->append_node(doc.allocate_node(rapidxml::node_element,"w","1"));
    size->append_node(doc.allocate_node(rapidxml::node_element,"h","1"));
    std::string text;
    rapidxml::print(std::back_inserter(text),doc,0);
   std::cout<<text<<std::endl;
   std::ofstream out("../config/config2.xml");
   out << doc;
   
   return 0;
}
