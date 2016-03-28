SQLite 是一个开源的嵌入式关系数据库，实现自包容、零配置、支持事务的SQL数据库引擎。 其特点是高度便携、使用方便、结构紧凑、高效、可靠。 与其他数据库管理系统不同，SQLite 的安装和运行非常简单，在大多数情况下 - 只要确保SQLite的二进制文件存在即可开始创建、连接和使用数据库。如果您正在寻找一个嵌入式数据库项目或解决方案，SQLite是绝对值得考虑。

开源嵌入式数据库
在SQLite的官方文档中是这样解释的，我们不要将SQLite与Oracle或PostgreSQL去比较，而是应该将它看做fopen和fwrite。

在 Windows 上安装 SQLite
请访问 SQLite 下载页面，从 Windows 区下载预编译的二进制文件。
您需要下载 sqlite-shell-win32-*.zip 和 sqlite-dll-win32-*.zip 压缩文件。（sqlite-tools-win32-*.zip）
创建文件夹 C:\sqlite，并在此文件夹下解压上面两个压缩文件，将得到 sqlite3.def、sqlite3.dll 和 sqlite3.exe 文件。
添加 C:\sqlite 到 PATH 环境变量，最后在命令提示符下，使用 sqlite3 命令，将显示如下结果。

111.
2）下载 Windows 下的预编译二进制文件包：

sqlite-shell-win32-x86-<build#>.zip
sqlite-dll-win32-x86-<build#>.zip
注意: <build#> 是 sqlite 的编译版本号

将 zip 文件解压到你的磁盘，并将解压后的目录添加到系统的 PATH 变量中，以方便在命令行中执行 sqlite 命令。

可选: 如果你计划发布基于 sqlite 数据库的应用程序，你还需要下载源码以便编译和利用其 API

sqlite-amalgamation-<build#>.zip

//
extern "C"
{
#include "./sqlite3.h"
};
sqlite提供的是一些C函数接口，你可以用这些函数操作数据库。通过使用这些接口，传递一些标准 sql 语句（以 char * 类型）给 sqlite 函数，sqlite 就会为你操作数据库。
sqlite 跟MS的access一样是文件型数据库，就是说，一个数据库就是一个文件，此数据库里可以建立很多的表，可以建立索引、触发器等等，但是，它实际上得到的就是一个文件。备份这个文件就备份了整个数据库。
sqlite 不需要任何数据库引擎，这意味着如果你需要 sqlite 来保存一些用户数据，甚至都不需要安装数据库(如果你做个小软件还要求人家必须装了sqlserver 才能运行，那也太黑心了)。

假如这个要被打开的数据文件不存在，则一个同名的数据库文件将被创建。
#include "stdafx.h"
#include "sqlite3.h"
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++){
       printf("%s = %s/n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("/n");
    return 0;
}
#define CHECK_RC(rc,szInfo,szErrMsg,db) if(rc!=SQLITE_OK) /
           {printf("%s error!/n",szInfo);/
           printf("%s/n",szErrMsg);    /
           sqlite3_free(szErrMsg);         /
           sqlite3_close(db);              /
           return 0;}
int _tmain(int argc, _TCHAR* argv[])
{
 
    sqlite3 *db;
    char *dbPath="f:/test.db";
    char *szErrMsg = 0;
 
    int rc= sqlite3_open(dbPath, &db);
    CHECK_RC(rc,"open database",db);
    char *szSql="create table UserInfo(ID int primary key , UserName char, PassWord char);";
    rc=sqlite3_exec(db,szSql,0,0,&szErrMsg);
    CHECK_RC(rc,"create table",szErrMsg,db);
    rc=sqlite3_exec(db,"insert into UserInfo(ID,UserName,PassWord) values(1,'kfqcome','123456')",0,0,&szErrMsg);
    CHECK_RC(rc,"insert info",szErrMsg,db);
    rc=sqlite3_exec(db,"insert into UserInfo(ID,UserName,PassWord) values(2,'miss wang','654321')",0,0,&szErrMsg);
    CHECK_RC(rc,"insert info",szErrMsg,db);
    szSql="select * from UserInfo";
    rc = sqlite3_exec(db,szSql, callback, 0, &szErrMsg);
    CHECK_RC(rc,"query values",szErrMsg,db);
    sqlite3_close(db);
    getchar();
    return 0;
}

#ifndef _MSVC_H_
#define 
#endif

///////
SQLite，是一款轻型的关系数据库，是遵守ACID的关联式数据库管理系统，它的设计目标是嵌入式的，而且目前已经在很多嵌入式产品中使用了它，它占用资源非常的低，在嵌入式设备中，可能只需要几百K的内存就够了。
小巧，方便，简单容易学
1. 
零配置。SQlite3不用安装，不用配置，不用启动，关闭或者配置数据库实例。当系统崩溃后不用做任何恢复操作，再下次使用数据库的时候自动恢复。
（使用SQLite 一个好处是不用依赖使用其它DB,而且基本不需要担心DB server 崩溃了你的程
序就跟着挂了。）
支持标准sql；
无中间服务器；sqlite数据库没有中间服务器进程。
在使用sqlite时，访问数据库的程序直接在磁盘上的数据库文件读写。
紧凑（compactness）：
　　SQLite是被设计成轻量级，自包含的。一个头文件，一个lib库，你就可以使用关系数据库了，不用任何启动任何系统进程。一般来说，整个SQLITE库小于225KB。
 
　可移植(Portability)
2.SQLite是一种嵌入式数据库，它跟微软的Access差不多，只是一个.db格式的文件。但是与Access不同的是，它不需要安装任何软件，非常轻巧。很多软件都有用到这个家伙，包括腾讯QQ、迅雷(你在迅雷的安装目录里可以看到有一个sqlite3.dll的文件，就是它了)，以及现在大名鼎鼎的android等。SQlite3是它的第三个主要版本。就是SQLite3.0的意思。对了，金山词霸也有用到SQLite，其实太多软件用那玩意儿了。
最大特点：采用无数据类型，所以可以保存任何类型的数据，SQLite采用的是动态数据类型，会根据存入值自动判断。SQLite具有以下五种数据类型：
绿色软件；
1.NULL：空值。
2.INTEGER：带符号的整型，具体取决有存入数字的范围大小。
3.REAL：浮点数字，存储为8-byte IEEE浮点数。
4.TEXT：字符串文本。
5.BLOB：二进制对象。
但同样的，这样的做法会导致在插入和修改时，要花去更多的时间。
QLITE的缺点：
１：SQLITE不可储存过多的数据库，它的性能发挥最好只能在存放较小的数据量情况下。不要把它当做MYSQL甚至ORACLE来使用。它只是一个200K的数据库。
3.11 dll:804 KB 
单一文件
所谓的“单一文件”，就是数据库中所有的信息（比如表、视图、触发器、等）都包含在一个文件内。这个文件可以copy到其它目录或其它机器上，也照用不误。




