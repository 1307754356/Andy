#include<iostream>
#include<cstdlib>
#include<ctime>
//���������ƽ�����Ӷ���O(NlogN)
//��ԭ����ѡȡi��j����ע���ҵ�Ԫ��
//��j���У�ֱ�������Ȼ�׼��С��
//��i���У�ֱ�������Ȼ�׼�����
//Ȼ�󽻻�i��j��עԪ�صĴ�С
//�ظ����Ϲ���ֱ��i��j����
//ע���ص㣡����
//���i���У�������ʱ�����Ȼ�׼������Ĭ�ϵ�һ���ǻ�׼���Ļ�
//�ᵼ����������ܵ���ߣ��Ӷ���������
//������˻�׼����
//���õݹ飬��������������
using namespace std;
int a[101],n;

//�˴�int�Ǹ���Э֮�٣��Ժ���
//�������ұ߽磬ע��a[right]Ӧ��������
int  quicksort(int left,int right)
{
    int i,j,t,temp;

    //�ж����ս���������
    //left��right��ȵ�ʱ��ֻ��һ��Ԫ���ˣ���������
    if(left>=right)
         return 0;

     //temp���ǻ�׼��
     temp=a[left];
     i=left;
     j=right;

     //˫��ѭ��
     while(i<j)
     {
         //j����
         //ÿһ����Ҫ�ж�i��j�Ĵ�С��ϵ
         while(a[j]>=temp&&i<j)
            j--;

         //i����
         //�����ж�i��j��С��ϵ
         while(a[i]<=temp&&i<j)
            i++;

         //�����ж�
         if(i<j)
         {
             t=a[i];
             a[i]=a[j];
             a[j]=a[i];
         }
     }
     //���ǰ��� temp = a[left] ���ɿ���������ߵĻ�׼ֵ���м��ֵ����
      a[left]=a[i];
      a[i]=temp;

      //�ݹ����У���һ��Ϊ����
      //����ݹ�������ȫ���������
      quicksort(left,i-1);
      //���ҵݹ�������ȫ���������
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
