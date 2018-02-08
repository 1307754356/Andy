#include<iostream>
#include<cstdlib>
#include<ctime>
//快速排序的平均复杂度是O(NlogN)
//其原理是选取i和j来标注左右的元素
//右j先行，直至遇到比基准数小的
//左i后行，直至遇到比基准数大的
//然后交换i和j标注元素的大小
//重复以上过程直到i与j相遇
//注：重点！！！
//如果i先行，则相遇时的数比基准数大，若默认第一个是基准数的话
//会导致这个大数跑到左边，从而引发错误
//排序完此基准数后
//运用递归，排序其余所有数
using namespace std;
int a[101],n;

//此处int是个妥协之举，稍后解决
//输入左右边界，注：a[right]应该有意义
int  quicksort(int left,int right)
{
    int i,j,t,temp;

    //判断最终结束的条件
    //left和right相等的时候即只有一个元素了，无需排序
    if(left>=right)
         return 0;

     //temp就是基准数
     temp=a[left];
     i=left;
     j=right;

     //双层循环
     while(i<j)
     {
         //j先行
         //每一步都要判断i与j的大小关系
         while(a[j]>=temp&&i<j)
            j--;

         //i后行
         //别忘判断i和j大小关系
         while(a[i]<=temp&&i<j)
            i++;

         //别忘判断
         if(i<j)
         {
             t=a[i];
             a[i]=a[j];
             a[j]=a[i];
         }
     }
     //结合前面的 temp = a[left] ，可看出这是左边的基准值和中间的值交换
      a[left]=a[i];
      a[i]=temp;

      //递归运行，即一分为二，
      //向左递归排序至全部排序完成
      quicksort(left,i-1);
      //向右递归排序至全部排序完成
      quicksort(i+1,right);
}
  int main()
  {
      int i,j,t;
      srand((unsigned)time(NULL));
      for(i=0;i<10;i++)
      {
          a[i]= rand()%21;
          cout<<a[i]<<endl;
      }
      quicksort(0,8);
      cout<<"After the sort"<<endl;
      for(i=0;i<9;i++)
        cout<<a[i]<<endl;

      return 0;
  }
