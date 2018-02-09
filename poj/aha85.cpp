#include<iostream>
using namespace std;
int num[10];
int book[10];
int all;
int dfs(int step,int n)
{
    if(step==n+1)
    {
         for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
        cout<<endl;
        all++;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        if(book[i]==0)
        {
            num[step]=i;
            book[i]=1;
            dfs(step+1,n);
            book[i]=0;
        }
    }
}
int main()
{
   int n1;
   cin>>n1;
   dfs(1,n1);
   cout<<"The number of sort is "<<all<<endl;
   return 0;
}
