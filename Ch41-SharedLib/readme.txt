第41章 共享库基础

命令准备：
1.静态库相关
ar r libxx.a xx1.o xx2.o         //创建和更新静态库

ar tv libdemo.a                   //查看静态库中的目标文件

ar d libdemo.a  mod3.o       //从静态库中删除目标文件

静态库的使用：
gcc -o prog prog.o libdemo.a  //直接法
gcc -o prog prog.o -ldemo     //libdemo.a在标准库路径中，如（/usr/lib）
gcc -o prog prog.o -Lmylibdir -ldemo   //libdemo.a在指定的路径，编译时会搜索库路径

2.共享库相关
gcc -c -fPIC mod1.c mod2.c mod3.c    //编译共享库所需要的目标文件
gcc -shared -o libfoo.so mod1.o mod2.o mod3.o
gcc -shared -o libfoo.so mod1.c mod2.c mod3.c
gcc -o prog  prog.c libfoo.so       //使用动态链接库

命令是否有输出，来确定是否用-fPIC编译
nm mod1.o | grep _GLOBAL_OFFSET_TABLE
readelf -s mod1.o | grep _GLOBAL_OFFSET_TABLE


ldd   prog //查看prog程序依赖哪些共享库


3，共享库的运行
拷贝到标准库路径中，/user/lib  /lib等
LD_LIBRARY_PATH 环境变量加库库路径；
编译指定路径（rpath），gcc -rpath,/home/mtk/ ...


4,共享库的注意事项
1)程序只能使用库中非static变量或函数
2）在库中可以定义main函数
3）程序优先使用自身函数，没有才会使用库中
4）include和extern一致，主要解决函数声明问题


