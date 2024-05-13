#include <iostream>

void Log(const char*massage)
{
    std::cout << massage << std::endl;
}

int main()
{

	for (int i = 0; i < 5; i++)    //这里使用For做循环
                                   //For循环分为三部分  第一部分（int i =0；） 这一部分是需要先申明一个变量，通常用i表示（i为iterate，也可以用其他的名字） 
                                   //第二部分（i < 5；） 这里是条件判断，只要条件为真将继续执行For循环内的代码
                                   //第三部分（i++）迭代 i++同等与 i = i + 1
	{
		Log("Hello World!");
	}

    /*

    这里循环也可以写成

    int = 0；
    bool condition = ture;
    for （ ; condition ; )
    {
        Log("HelloWorld!");
        i++;
        if (!(i < 5))
            condition = false;
    }

    和上述循环体一致， if（！（i < 5）） 表示当i不小于5时[即i >=5 ]时 就设置为假


    */


	int i = 0;
	while (i < 5)                                        //这里是while循环
                                                         //while循环括号内只需要写一个条件部分，但是需要提前定义变量，即变量在循环体外，迭代在循环体内部
	{
		Log("Hello World~");
		i++;
	}

	std::cin.get();

}