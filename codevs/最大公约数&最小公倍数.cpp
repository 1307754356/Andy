#include<iostream>
using namespace std;
//��������a��b�������Լ����


//����һ��շת�����
//�� a%b������c
//�� ��c=0����b��Ϊ���������Լ��
//�� ��c��0����a=b��b=c���ٻ�ȥִ�Т�
int gcd1(int x,int y)
{
    //ʹ�õݹ����ķ���ʹ��һֱ�㵽y==0Ϊֹ
    return y?gcd1(y,x%y):x;
}


//�����������������
//���A > B���� gcd(A,B) = gcd(B,A-B)
//���A < B���� gcd(A,B) = gcd(A,B-A)
//�ظ����Ϲ���ֱ��A==BΪֹ
//��ʱA��ֵ�������Լ��
int gcd2(int x,int y)
{
    while(x!=y)
    {
        //������֮���滻����
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }

    return x;
}

//�ڼ��㷽�棬շת������и��ٵļ������
int main()
{
     int p,q;
     cin>>p,q;
     cout<<gcd1(p,q)<<endl;
     cout<<gcd2(p,q)<<endl;
     return 0;
}
