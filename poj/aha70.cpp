#include<iostream>
using namespace std;
int a[15];
int book[10];
int ans;
int dfs(int step)
{

    if(step==10)
    {
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9])
        {
            ans++;
            cout<<a[1]*100+a[2]*10+a[3]<<"+"<<a[4]*100+a[5]*10+a[6]<<"="<<a[7]*100+a[8]*10+a[9]<<endl;
        }
        return 0;
    }

    for(int i=1;i<10;i++)
    {
        if(!book[i])
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}

int main()
{
    dfs(1);
    cout<<"The number of answer is "<<ans/2<<endl;
    return 0;
}
