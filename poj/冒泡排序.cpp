#include<iostream>
#include<cstdlib>
#include<ctime>
//ð������ʱ�临�Ӷȸߴ�O(N^2),��������֮�⡣��ûɶ��˵��
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

    //���ϲ����������������һ������

    //���ӵ�һ�� Ԫ�ر����������ڶ���Ԫ��
    //����Ϊǰ��Ĺ�λ�ˣ����һ��Ҳ��λ�ˣ�
    //�ڲ�ѭ���Ǵӵ�һ����δ��λԪ�ص����һ��
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
