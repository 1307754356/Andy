#include<iostream>
#include<cstdlib>
#include<ctime>
int book[21];
//'book'�б�ǵ���˼�����ڴ˴�����ʾͰ����Ϊ��ȫ�ֱ���������Ԫ��Ĭ������
using namespace std;
int main()
{
    int a[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i)
        {
            a[i]=rand()%21;
            cout<<a[i]<<endl;
            //ͨ��Ͱ��Ԫ�صĴ�С����¼���ִ���
            book[a[i]]++;
        }
    cout<<"After the sort"<<endl;

      //Ͱ�Ĵ�С
      int i=20;
      //���������Ԫ�أ�Ϊ���������
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
//���Ӷ�ΪO(M+N)���ȽϿ��ˣ�ֻ��ռ�ÿռ�ࡣ
