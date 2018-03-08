#include<iostream>
int main()
{
    using namespace std;

    int n;
    while(cin>>n&&n)
    {
        if(n%2)
            cout<<n-1<<endl;
        else
            cout<<"No Solution!"<<endl;
    }
    return 0;
}
