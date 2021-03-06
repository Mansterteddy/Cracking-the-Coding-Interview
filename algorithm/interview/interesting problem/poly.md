假设有一个黑匣子，黑匣子有一个关于x的多项式p(x)，我们不知道它有多少项，但是已知所有的系数都是正整数。每一次你都可以给黑匣子输入一个正数，黑匣子将返回把这个整数代入多项式后的值。那么最少需要多少次，我们就可以得到这个多项式每项的系数。

答案是两次。

第一次，输入1，得到多项式所有系数之和，记作S。
第二次，输入S+1，于是黑匣子中的值应该是a_n * (S + 1)^n + a_{n - 1} * (S + 1)^{n - 1} + ... + a_0的值。
这时我们要得到每一个a，就可以转换成S+1进制，然后依次读出每一位上的数。

第一次得到S是为了保证对于任意系数a_i，a_i <= S，所有系数都是正数，也是为了保证这一点。最大系数不超过N的多项式，就是N进制的本质。