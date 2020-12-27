#include <iostream>
#include <string>

using namespace std;

//string是以字符为元素的一种容器，string不一定以'\0'结束，string的长度可以根据length()得到
//string可以根据下标访问，不能将string直接赋值给char*
void string_test()
{
    //将string直接转换为const char*
    //如果去掉const，无法编译通过
    //const表示不许修改 引入const的目的，就是取代预编译指令，消除缺点，继承优点
    //const常量，具有不可变性，比如 const int Max = 100; int array[Max];
    //便于类型检查，使得编译器对处理内容有更多的了解，消除了一些隐患 例如void f(const int i) 编译器知道i是一个常量 不允许修改
    //可以避免意义模糊的数字出现 同时很方便地进行参数的调整和修改 和宏定义一样 
    //可以保护被修饰的东西，防止意外修改，增强程序健壮性 比如void f(const int i) {i = 10;};会报错
    //节省空间，避免不必要的内存分配
    //#define PI 3.14; const double Pi = 3.14;//const给出了对应的内存地址，宏每次分配变量，都要重新生成一次
    //double i = Pi;//此时为Pi分配内存，以后不再分配
    //double j = PI;//每次PI出现，都要进行宏替换，分配内存
    //提高了效率，编译器为const常量不分配存储空间，而是保存在符号表中，因此没有了读和写的操作，效率很高
    string s1 = "abcdeg";
    const char *k = s1.c_str();
    const char *t = s1.data();
    cout<<k<<" "<<t<<endl;

    //如果想使用char*
    char *data;
    int len = s1.length();
    data = (char*) malloc((len + 1) * sizeof(char));
    s1.copy(data, len, 0);
    data[len] = '\0';
    cout<<data<<endl;

    //char*转string
    string s;
    char *p = "adghrtyh";
    s = p;
    cout<<s<<endl;

    char q[] = "qazxswedc_=";
    s = q;
    cout<<s<<endl;

    //string转char[] 只能使用循环访问下标的方式访问，不能直接赋值。
    char r[20];
    int i = 0;
    for(; i < s.length(); i++)
    {
        r[i] = s[i];
    }
    r[i] = '\0';
    cout<<r<<endl;


    //printf('%s', string);会出问题，因为string不是一个首地址，应用printf("%s", s1.c_str());

}


int main()
{
    string_test();
    return 0;
}