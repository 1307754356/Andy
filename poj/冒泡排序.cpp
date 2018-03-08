#include<iostream>
#include<cstdlib>
#include<ctime>
//冒泡排序时间复杂度高达O(N^2),除了名字之外。。没啥好说的
using namespace std;
int main()
{
    int a[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i)
        {
            a[i]=rand()%21;
            cout<<a[i]<<endl;
        }
    cout<<"After the sort"<<endl;

    //以上部分用随机数构造了一个数组

    //外层从第一个 元素遍历到倒数第二个元素
    //（因为前面的归位了，最后一个也归位了）
    //内层循环是从第一个到未归位元素的最后一个
    for(int i=0;i<9;i++)
        for(int j=0;j<9-i;j++)
    {
        if(a[j]<a[j+1])
        {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    for(int i=0;i<10;++i)
        cout<<a[i]<<endl;
return 0;
}
