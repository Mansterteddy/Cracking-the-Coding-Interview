//Given an integer, print the next smallest and next largest number 
//that have the same number of 1 bits in their binary representation.
#include <iostream>

using namespace std;

int count_one0(int x)
{
    int cnt = 0;
    for(int i = 0; i < 32; i++)
    {
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}

//高效而优美的求解x二进制表示中1的个数
int count_one(int x)
{
    //将奇数位为1 和 右移一位的偶数位为1 的位置  相加 即两位数中1的个数 如果同为1 则最后变为10 如果其中一个为1 则最后是01 如果都不是1 则最后是0
    x = (x & (0x55555555)) + ((x>>1) & (0x55555555));
    //同上所述 随后将相邻两位的包含1的个数相加 就相当于得到四位数中1的个数
    x = (x & (0x33333333)) + ((x>>2) & (0x33333333));
    //随后将相邻四位的包含1的个数相加 就相当于八位数中1的个数
    x = (x & (0x0f0f0f0f)) + ((x>>4) & (0x0f0f0f0f));
    //随后将相邻八位的包含1的个数相加 就相当于十六位数中1的个数
    x = (x & (0x00ff00ff)) + ((x>>8) & (0x00ff00ff));
    //相当于三十二位数中1的个数
    x = (x & (0x0000ffff)) + ((x>>16) & (0x0000ffff));
    return x;
}

//naive method
int next(int x)
{
    int max_int = ~(1<<31);
    int num = count_one(x);
    //数的二进制表示里面没有1 或者全是1
    if(num == 0 || x == -1) return -1;
    for(x++; count_one(x) != num && x < max_int; ++x);
    if(count_one(x) == num) return x;
    return -1;
    
}

int previous(int x)
{
    int min_int = (1<<31);
    int num = count_one(x);
    if(num == 0 || x== -1) return -1;
    for(--x; count_one(x) != num && x > min_int; --x);
    if(count_one(x) == num) return x;
    return -1;
}

//另一种更简单的方法来源于对问题的观察
//以1101110为例子 next的值 如果高位的0后面没有1 就不会有更大的值 比如1000 1100 1110 1111
//如果高位的0后面有1，那么后面的1和0互换 可以得到一个更大的值 那要在更大的值中找到一个最小的 就把这个高位0变为1，但是0后面的1 要放在最低位
//如果1后面全部都是0 那么对这部分0不需要管 因为假如将这部分的0中其中一个置为1 并不会加大整个数
//所以从低位向高位走，在遇到1后，往后遇到的第一个0，将它变为1，然后后面的数先置为0，然后紧跟着这个1在新的数的低位补充1，直到1的个数满足为止
//110 1110 111 0000 111 0011

//负数和正数的逻辑是一样的 只不过多了一个符号位 但是负数在C语言中二进制表示是补码形式
int next_positive(int x, int bits)
{
    int xx = x;
    int bit = 0;
    //最低位的0是没有意义的，因为如果将这些0变为1，那么一定会把高位的1换成0，这样就不是找next，而是找previous了
    for(; (x & 1) != 1 && bit < bits; x >>= 1, bit++);
    //遇到1后的第一个0
    for(; (x & 1) != 0 && bit < bits; x >>= 1, bit++);
    if(bit == bits - 1) return -1; //形如01...0...系列 
    //因为bit == bits - 1 只可能是最后一位为0 其他位满足1...0...的情况 这种情况，没有更大的值了
    //遇到1后，找到第一个0的位置，就是此时bit的位置，将此位置变为1，然后后面的位置先置0
    x |= 1;
    //x在前面右移的部分 现在都移动回来了
    x <<= bit;
    if(bit == 32) x = 0;//for11...0... 比它大的 最小的数 当然是 0...1...
    int num1 = count_one(xx) - count_one(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}

int previous_positive(int x, int bits)
{
    int xx = x;
    int bit = 0;
    //最低位的1是没有意义的，因为如果将这些1变为0，那么一定会把高位的0换成，这样就不是找previous，而是找next了
    for(; (x & 1) != 0 && bit < bits; x >>= 1, bit++);
    //遇到0后第一个1
    for(; (x & 1) != 1 && bit < bits; x >>= 1, bit++);
    if(bit == bits - 1) return -1;
    //形如10...1...系列 没有更小的值了
    //遇到的第一个1，将此1置为0
    x -= 1;
    //将前面右移的部分 左移回来 除了后面位置为0 其他位置不变
    x <<= bit;
    if(bit == 32) x = 0;//0...111..这种数 比它小的最大的数 只有负数了
    int num1 = count_one(xx) - count_one(x);
    x >>= bit;
    for(; num1 > 0; x <<= 1, x |= 1, --num1, bit--);
    for(; bit > 0; x <<= 1, bit--);
    return x;
}

//存在符号位，会导致整个问题比较复杂

//previous的值 如果1只处在最后几位，比如0001 0011 0111 1111 则不会有更小的值
//从低位到高位，遇到的第一个1，将此1置为0，则可以得到更小的值 那要在更小的值中找到一个最大的 将剩余的1 跟在该0后面
//110 1110 110 1100 110 1101

//左移移入0，但是移位太多的话 会产生溢出
//当左移的位数超过该数值类型的最大位数时，编译器会用左移的位数 去模类型的最大位数 然后按照余数进行移位 总之就是丢弃最高位，0补充最低位
//右移 会保持符号位不变 正数补充0 负数补充1

//反码是原来所有的二进制数取反 补码是除符号位 原来所有的二进制数取反后加1 -1的补码为1111 1110 + 1 = 1111 1111
int main()
{
    int x = -5;
    for(int i = 0; i < 32; i++)
    {
        int d = x & 1;
        cout<<"d: "<<d<<" ";
        x = x >> 1;
    }
    cout<<endl;
    cout<<"Count: "<<count_one(10)<<endl;
    int ne = next(-5);
    int pr = previous(-5);
    cout<<"Next: "<<ne<<endl;
    cout<<"Previous: "<<pr<<endl;
    cout<<"Next 1:"<<next_positive(-5, 32)<<endl;
    cout<<"Previous 1: "<<previous_positive(-5, 32)<<endl;
    return 0;
}