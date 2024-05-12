//条件语句 -- condition
//if语句 -- 
//分支语句

#include <iostream>

int x = 5;
bool comparisonresult = x == 5;

void log(const char* massage);

void main()
{


    if (comparisonresult)  // 此处（comparisonresult）与（comparisonresult == ture）/（comparisonresult == 1）是一个意思
                           //布尔值通常用整数代表，0代表False ，1（*也可以是其他整数）代表Ture

                           //IF语句也可以写成   if（0） 代表条件语句为假，直接给定布尔值
{
    log("HelloWorld!");
}                          //此处的IF语句没有result返回值，因为包含在main函数下，由于main函数特性，可以没有返回值。
                           //如果没有返回值的话就返回空（什么都没有）
                           //此处当IF语句判断为真，输出“Hello World！” 
                           //如果为假，则直接跳过if，返回值，什么都不输出
    std::cin.get();

}

void main()
{

    int x = 6;
    if (x == 5)
        log("HelloWorld!");//这里的IF比较简单，如果只有一行代码，可以不适用花括号
                         //此处的IF语句没有result返回值，因为包含在main函数下，由于main函数特性，可以没有返回值。
                           //如果没有返回值的话就返回空（什么都没有）
                           //此处当IF语句判断为真，输出“Hello World！” 
                           //如果为假，则直接跳过if，返回值，什么都不输出
    std::cin.get();

}

