#include<iostream>
using namespace std;
long long  num(int n)
{
    long long  i=1;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n=3*n+1;
        ++i;
    }
    return i;
}
int main()
{
   int i,j;
   while(cin>>i>>j)
   {
       long long  maxn=0;
       //���ˣ�������˺ܶ�飬��Ȼ��������
       //��Ŀ��û��˵����i��j˭��˭С
       int x=i<j?i:j;
       int y=i<j?j:i;
       for(int k=x;k<=y;++k)
       {
           maxn=(maxn>num(k))?maxn:num(k);
       }
       cout<<i<<" "<<j<<" "<<maxn<<endl;
   }
   return 0;
}
