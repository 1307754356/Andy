#include<iostream>
#include<cstdlib>
#include<ctime>
int book[21];
//'book'有标记的意思，用于此处，表示桶。因为是全局变量，所有元素默认是零
using namespace std;
int main()
{
    int a[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i)
        {
            a[i]=rand()%21;
            cout<<a[i]<<endl;
            //通过桶中元素的大小来记录出现次数
            book[a[i]]++;
        }
    cout<<"After the sort"<<endl;

      //桶的大小
      int i=20;
      //依次序输出元素（为零则不输出）
      while(i)
      {
          while(book[i])
          {
              cout<<i<<endl;
              book[i]--;
          }
          i--;
      }

   return 0;
}
//复杂度为O(M+N)，比较快了，只是占用空间多。
