//If you have a 2 GB file with one string per line, which sorting algorithm would you use to sort the file and why?

//当面试官说到2GB文件时，他就是暗示，不希望一次性把所有的数据load内存，因此只能每次将部分数据load内存
//假设我们有X MB内存可用
//我们将文件分为k份，其中x*k = 2GB。每次取其中一份载入到内存中，用O(nlogn)的算法排序，然后再保存到外部文件
//载入下一份并排序
//当我们将k份小文件都排好序后，合并它们
//这就是外排序，最后一步又称为N路归并
//使用外排序是由于数据太大了，无法一次性全部加载到内存中，所以需要借助磁盘进行存储，每次只从磁盘中加载一部分数据进入内存，进行排序。

/*
外排序（External sorting）是指能够处理极大量数据的排序算法。通常来说，外排序处理的数据不能一次装入内存，只能放在读写较慢的外存储器（通常是硬盘）上。外排序通常采用的是一种“排序-归并”的策略。在排序阶段，先读入能放在内存中的数据量，将其排序输出到一个临时文件，依此进行，将待排序数据组织为多个有序的临时文件。尔后在归并段阶将这些临时文件组合为一个大的有序文件，也即排序结果。


外排序的一个例子是外归并排序（External merge sort），它读入一些能放在内存内的数据量，在内存中排序后输出为一个顺串（即是内部数据有序的临时文件），处理完所有的数据后再进行归并。[1][2]比如，要对 900 MB 的数据进行排序，但机器上只有 100 MB 的可用内存时，外归并排序按如下方法操作：
1.读入 100 MB 的数据至内存中，用某种常规方式（如快速排序、堆排序、归并排序等方法）在内存中完成排序。 
2.将排序完成的数据写入磁盘。 
3.重复步骤 1 和 2 直到所有的数据都存入了不同的 100 MB 的块（临时文件）中。在这个例子中，有 900 MB 数据，单个临时文件大小为 100 MB，所以会产生 9 个临时文件。 
4.读入每个临时文件（顺串）的前 10 MB （ = 100 MB / (9 块 + 1)）的数据放入内存中的输入缓冲区，最后的 10 MB 作为输出缓冲区。（实践中，将输入缓冲适当调小，而适当增大输出缓冲区能获得更好的效果。） 
5.执行九路归并算法，将结果输出到输出缓冲区。一旦输出缓冲区满，将缓冲区中的数据写出至目标文件，清空缓冲区。直至所有数据归并完成。 

为了增加每一个有序的临时文件的长度，可以采用置换选择排序（Replacement selection sorting）。它可以产生大于内存大小的顺串。具体方法是在内存中使用一个最小堆进行排序，设该最小堆的大小为 M。算法描述如下：
1.初始时将输入文件读入内存，建立最小堆。 
2.将堆顶元素输出至输出缓冲区。然后读入下一个记录：  1.若该元素的关键码值不小于刚输出的关键码值，将其作为堆顶元素并调整堆，使之满足堆的性质；  
2.否则将新元素放入堆底位置，将堆的大小减 1。 

3.重复第 2 步，直至堆大小变为 0。 
4.此时一个顺串已经产生。将堆中的所有元素建堆，开始生成下一个顺串。[3] 

此方法能生成平均长度为 2M 的顺串，可以进一步减少访问外部存储器的次数，节约时间，提高算法效率。


*/


#include <iostream>

using namespace std;

int main()
{
    return 0;
}
