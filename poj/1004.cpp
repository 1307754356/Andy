#include <iostream>
#include <iomanip>      //  ��Ҫ��Ӵ�ͷ�ļ�������������ƣ�
using namespace std;
int main()
{
    double money,sum=0;
    for(int i=0;i<12;++i)
    {
        cin>>money;
        sum+=money;
    }
    cout<<setiosflags(ios::fixed);
    /*iso::fixed �ǲ�����setiosflags �Ĳ���֮һ���ò���ָ���Ķ������Դ�С�������ʽ��ʾ������������������ľ��ȷ�Χ�ھ����ܵİ���������С�����Ҳࣻ */
    cout.precision(2);      //����С��λΪ2
    cout<<"$"<<sum/12<<endl;
    return 0;
}
