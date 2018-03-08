#include<iostream>
using namespace std;
long long W[310];
int main()
{
    W[1]=3;
    for(int i=2;i<=300;i++)
    {
        W[i]=W[i-1]+i*(i+2)*(i+1)/2;
    }
    //cout<<W[3]<<endl;
    int T;
    int n,i=0;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<++i<<" "<<n<<" "<<W[n]<<endl;
    }
    return 0;
}
