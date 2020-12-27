#include <iostream>
#include <string>
#include <iomanip>
//manipulators defined in <iomanip>
//setprecision(int n)     Set floating-point precision to 'n'
//setw(int w)             Read or write value to 'w' characters
//setbase(int b)          Output integers in base 'b'(only 'b' is 8/10/16 could the function work)

using namespace std;

/*void eatwhitespace()
{

    if(getline(cin>>ws, s2))
    {
        //eat white space
        getline(cin, s2);
    }

}*/

int main()
{
    int i;
    double j;
    char temp[20];
    cout<<"Enter a string: ";
    cin>>i;
    cin>>j;
    //To consume the whitespace or newline between the end of a token and the beginning of the next line:
    cin.get();
    cin.getline(temp, 20, '\n');
    cout<<"Answer is: "<<i<<" "<<j<<" "<<temp<<endl;

    //We want to scale the float to 2 decimal places
    double pi = 3.14159;
    cout<<fixed<<setprecision(2)<<pi<<endl;
    printf("%.2f\n", pi);

    //ostream::fmtflags old = cout.flag();//将cout的flag保存到变量，以便修改后的恢复
    //cout.flag(old);//恢复到原来的保存值

    cout<<"literals: "<<boolalpha<<true<<" or "<<false<<endl;
    cout<<"numeric: "<<noboolalpha<<true<<" or "<<false<<endl;
    cout<<"literals: "<<boolalpha<<0<<endl;//cout中，0不等价于false

    //cout一旦设置，就persistent，除非再次设置解除
    //只适用于Integral Value的base
    const int ival = 17;
    cout<<showbase;
    cout<<oct<<ival<<endl;//八进制
    cout<<dec<<ival<<endl;//十进制
    cout<<hex<<ival<<endl;//十六进制
    cout<<noshowbase;

    cout<<showbase<<uppercase;
    cout<<hex<<15<<endl;
    cout<<nouppercase;
    cout<<hex<<15<<endl;

    //对于float/double，有三种格式化控制
    //precision, default 6
    //输出的数字多于指定的值时，四舍五入
    //输出的数字小于指定的值时，实际输出也将少于指定的值
    cout<<setprecision(4)<<12.34567890<<endl;
    cout<<cout.precision()<<endl;

    //notation: very large and very small are printed using scientific notation, other values use fixed decimal. 
    float f = 101 / 6.0;
    cout<<fixed<<f<<endl;
    cout<<scientific<<f<<endl;
    cout.unsetf(ostream::floatfield);//Retrive to default handling for notation
    cout<<f<<endl;

    //输出十进制浮点
    cout<<10.0<<endl;
    cout<<showpoint<<10.0<<endl;
    cout<<noshowpoint<<endl;

    //输出填充
    //setw to specify the minimum space for the next numeric or string value
    cout<<setw(10)<<12.3<<endl;
    cout<<setw(10)<<12<<3<<endl;
    cout<<setw(3)<<12.3456<<endl;//If the total output is more than 3, it can be extended. 

    //left to left-justify the output
    cout<<left;
    cout<<setw(5)<<12<<setw(5)<<34<<endl;

    //right to right-justify the output. Output is right-justified by default
    cout<<right;
    cout<<setw(5)<<12<<setw(5)<<34<<endl;

    //internal controls placement of the sign on negative value. 
    //internal left-justifies the sign and right-justifies the value 
    //padding any intervening space with blanks. (if setfill not set)
    cout<<internal;
    cout<<setw(5)<<-12<<endl;

    //setfill specify an alternative character to use when padding the output. 
    //Bu default, the value is a space. 
    cout<<setfill('*');
    cout<<setw(5)<<12<<endl;

    return 0;
}