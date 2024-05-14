/*
//指针是一个整数，是一种保存内存地址的数字，告诉电脑需要操作的XXX在XXX（指针指向的地址）位置
#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
    void* prt = 0;                 //void 的意思是无类型，在这里的意义是void 的指针。这个意思是我们不关心指针的类型，只需要一个指针的地址。 ptr = pointer
                                   //这里的指针是指向的内存地址是0，但是0并不是一个有效的内存地址，内存地址不会一直到0，0是无效的，这就意味着指针是无效的，无效的指针可以接受
                                   //如果我们从0的内存地址进行读写，程序就会崩溃。
    void* prt = NULL;              //这里给 NULL 相当于是#define Null 0，和我们使用0是一样的。 
    void* prt = nullptr;           //Null的关键字是nullptr。
    std::cin.get();
}


//这里创建了指针，但是它指向的内存地址是0 ，相当于是没有意义的指针。
//这里使用NULL(#define Null 0) 是c++ 创建一个空的指针。 #define是一个定义宏
*/

#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
    int var = 8;            //这里创建了一个变量var 变量有一个内存地址
//  void* prt = &var;       // 使用&变量可以取得变量的内存地址       
                            //在这里，如果使用VS debug的话，查找指针的内存地址，不管是使用void、int、double，都指向的是内存的地址，与类型无关。这里已经将prt作为指针指向了var了
//  *prt = 10；             //这里是再逆向指针（解指针）意味着我正在访问可以读写的数据。但是这里会报错。因为我们指针是无类型的指针，但是变量是整数int。
                            //但是当我们使用无类型指针拿到整数变量后，编译器不知道这个是什么类型了。

    int* ptr = &var;        //这里就是将指针类型变成整数，是我们告诉编译器这个指针是整数，。
    *ptr = 10;              //这里是指针获取变量地址后，进行读写，将 变量 var = 8 重新改写成为10 

    char* buffer = new char[8];  //char是一个字节，这里做一个 buffer = new char分配一个8字节的内存，并返回一个指向那块内存的指针。
    memset(buffer, 0, 8);        //这里使用memset函数，它的作用是制定一个数据填充一个内存块。它接收一个指针，这个指针是内存块开始的指针
                                 //这里是取一个值，这里给0 ，然后我们给向每一个字节赋值为00（这里我们创建了8个字节）
                                 //这里其实相当于是直接给8个字节写入数据，如果是（xxx, 8 ,6）; 相当于是给八个字节的前六个写为08，最后两个空。
    char** ptr = &buffer;        //这里创建的是指针的指针（指针buffer 的指针ptr），这里指针ptr指向的是指针buffer 的内存地址。 
                                 //开启debuff，找到指针ptr的内存地址，里面的内容填写的是一个内存地址，里面填写的是指针buffer的地址，使用这个地址可以找到buffer的位置，根据上面我们赋值的0，会找到00 ..... 
    
    delete[] buffer;             //由于给内存赋值了，我们最后需要清空内存
    std::cin.get();
}
