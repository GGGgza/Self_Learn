/*

控制流语句与循环语句一起工作
可以方便更好的控制循环的实际运行
通常是使用 continue 、break 、return
continue只能在循环中使用：表示进入循环的下一个迭代，如果没有就结束循环
break主要用于循环中，也可以出现在switch语句：表示直接跳出循环、循环终止
return：只要在函数中碰见了return，就退出函数  函数需要返回值，如果只有return，就返回return本身 return本身只是用与void函数，如果函数需要返回值需要提供一个

*/

#include <iostream>

void Log(const char*massage)
{
    std::cout << massage << std::endl;
}
int main()
{

	for (int i = 0; i < 5; i++)    
	{
        if (i % 2 == 0)
            continue;                    //这里的意思是，当i在循环时 取2的模等于0时跳过循环（就是在当i为2、4时跳过循环）
		Log("Hello World!");
        //continue;                      //在这里写continue不会影响循环，因为这里是循环结尾了。不管怎么样都会迭代
	}

	std::cin.get();

}
/*
    
    int main()
{

	for (int i = 0; i < 5; i++)    
	{
        if (i % 2 == 0)
            break;                      //这里的意思是，当i在循环时 取2的模等于0时结束循环（这里相当于是不会打印任何东西，因为0/2 = 0余0 满足条件，break成立，退出循环）
		Log("Hello World!");
	}

	std::cin.get();

}

*/


/*

    int main()
{

	for (int i = 0; i < 5; i++)    
	{
        if (i % 2 == 0)
        //  return;                    //这里的return 画面不给赋值的话是会报错的
            return 0；                 //这里给return赋值了才不会报错，
                                       //这里遇到了return直接退出了函数，不会打印HelloWorld！ 也不会打开程序运行，等待回车，因为直接跳出了函数了
		Log("Hello World!");
	}

	std::cin.get();

}

*/