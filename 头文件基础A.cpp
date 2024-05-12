/*

AAAAA

#ifndef HEADER_NAME_H
#define HEADER_NAME_H
 
// 这里可以包含标准库、其他头文件或函数/类的声明
 
#endif // HEADER_NAME_H

*/




/*
这里的HEADER_NAME_H是一个宏定义，用于防止该头文件被重复包含。如果你的编译器支持C++17或更新版本，你可以使用#pragma once来防止头文件被多次包含，这样可以简化代码：

#pragma once

// 这里可以包含标准库、其他头文件或函数/类的声明

*/






/*

#ifndef MYHEADER_H
#define MYHEADER_H
 
#include <iostream>
 
class MyClass {
public:
    void printHello();
};
 
#endif // MYHEADER_H

在这个例子中，MyClass声明了一个方法printHello，在一个名为MyHeader.h的头文件中。通过使用#ifndef、#define和#endif，我们确保了即使文件被多次包含，MyClass也只会被定义一次。

*/
