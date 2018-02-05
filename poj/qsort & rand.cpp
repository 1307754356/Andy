#include<iostream>
#include<cstdlib>
#include<ctime>
//排序和随机数都需要 stdlib  头文件
using namespace std;
int comp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    //随机数需要两部分
    //1. 设置种子（不给参数默认为srand(1)）
    //    故一般选择时间作为参数 ，种子设置一次就好
    //2. 使用随机数，若选择范围在（a,b）之间，采用
    //    'rand()%(b-a+1) +a '  的形式
    srand((unsigned)time(NULL));
    int num[10];
    for(int i=0;i<10;++i)
        num[i]=rand()%21;

    //需要四个参数
    //1. 排序首元素的地址
    //2. 排序个数
    //3. 每个元素的大小
    //4. 排序函数
    //（返回值为正，从小到大排）
    //（返回值为负，则从大到小排）
    //为零则无所谓
    //可以简记为 a,b一前一后进入函数
    //return a - b 则相当于a < b 即小的在前
    //return b - a 则相当于b < a 即大的在前
    qsort(num,10,sizeof(int ),comp);
    for(int i=0;i<10;++i)
        cout<<num[i]<<endl;

    return 0;
}
