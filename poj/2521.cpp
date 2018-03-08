#include<iostream>
using namespace std;
int main()
{
    int n,m,p,c;
    while(cin>>n>>m>>p>>c&&(n||m||p||c))
    {
        cout<<n+p-m<<endl;
    }


    return 0;
}
