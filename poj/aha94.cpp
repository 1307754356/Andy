#include<iostream>
#include<cstdio>
using namespace std;
int  mp[51][51];
int book[51][51];
int p,q;
int minn=9999999;
int n,m;




int dfs(int x,int y,int step)
{
    int next[4][2]=
    {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };


    if(x==p&&y==q)
    {
        if(step<minn)
            minn=step;
        return 0;
    }

    int tx,ty;
    for(int k=0;k<4;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];


    if(tx<1||tx>n||ty<1||ty>m)
            continue;
    if(mp[tx][ty]==0&&book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
}
int main()
{
    freopen("aha94.input.txt","r",stdin);
    int startx,starty;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin>>mp[i][j];
   cin>>startx>>starty>>p>>q;
   book[startx][starty]=1;
   dfs(startx,starty,0);
   cout<<p<<q<<endl;
   cout<<minn<<endl;



   return 0;
}
