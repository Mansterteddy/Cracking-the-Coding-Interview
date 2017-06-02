# Logo解释器

1、首先做一个parser，将输入的程序，变成token，这个过程中，要注意nested，对于“[]”这样的关键字，要注意处理成子语句。另外负数也是要特殊处理的操作。

2、eval_line这个函数用来处理每一行logo程序的，同时参数中还有env，用来和当前环境进行交互，从当前环境中查询变量和程序。

3、logo_eval的原理就是，读取line中第一个元素，判断是哪个类别，执行相应的操作，执行某一行程序中第一个表达式。

如果是数字，则返回数字；

如果是变量，即":"开头的字符串，则从env中寻找对应的变量；

如果是定义函数名，即to开头，则执行定义函数的程序eval_definition；

如果是quoted，即"开头的字符串，或者list，则返回列表或者字符串；

如果是(的话，是执行这个子语句；

如果是logo程序的话，则执行该程序，该程序的执行方式是调用apply_procedure；

这里还有一个问题，调用函数是pre_order，但是+-*/这类操作是in_order的，所以要对这类操作特殊处理，该部分内容执行了嵌套的logo程序。logo_apply这个函数是对参数和对应操作进行执行的函数。

4、apply_procedure

执行某个程序，需要该程序的代码，和对应的参数。

所以需要collect_args收集参数，然后调用logo_apply执行程序。

5、

collect_args，递归调用logo_eval，取得参数。

logo_apply 获取函数体和参数，执行函数，也就是eval_line，返回结果。

6、随后构造了一大堆primitive procedure，专门用来处理Logo语言中的关键词。

7、procedure类，用于定义Logo中的procedure，其中包括预定义的和自定义的程序。

8、Environment类，用于保存变量名和函数名。

9、eval_definition函数，用于生成一个procedure类，然后存到env中。



最后回顾一下整个解释器的构造过程：

整个程序可以当成一个有规则的文本，进而我们将文本看作数据，python程序的输入数据，只不过是有规则的数据。

首先要有parser，将输入的logo程序当作文本，变成nested list，随后处理整个list。

随后开始对list进行eval，针对list的第一个元素，利用判断条件处理，使用正确的程序去处理它。

因为变量和程序需要反复使用，所以我们需要environment对象，来hold它们。我们需要维护一个Environment类，来维护我们定义的变量和函数。

函数包括两个部分：函数体和参数，首先使用collect_args程序收集函数所需要的参数，随后函数体部分的执行，就是不断执行eval_line，直到遇到end。

函数分为两种，预定义和自定义：

预定义程序，类似if， ifelse这样的关键字，我们遇到关键字，然后执行关键字对应的程序，预定义程序没有end关键字，它只需要知道自己的参数，然后执行对应的python程序即可。

自定义程序，从定义开始，到end关键字结束，这个过程中不断执行eval_line。

这种程序，先按照正确的case写好，然后考虑意外，如果出现了意外的情况，就raise error，然后catch error，打印error。

总之，logo语言还是很简单，所以整个程序处理也比较简单。