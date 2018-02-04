#include<iostream>
using namespace std;
void mod(int n,int m)
{
    cout<<n%m<<endl;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        mod(a,b);
    }

    return 0;
}
