#include<iostream>
//0 1 2 3 4
//0 1 2
using namespace std;
int m[100][100];
int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    int n;
    cin>>n;
    int x=n/2;
    int y=n/2;
    int step=0;
    int nstep=1;

    for(int i=0;i<n*n;i++)
    {
        m[x][y]=i+1;
        if(m[x+next[nstep][0]][y+next[nstep][1]]==0&&x+next[nstep][0]<n && x+next[nstep][0]>=0 && y+next[nstep][1]<n && y+next[nstep][1]>=0)
           {
                step=(step+1)%4;
                nstep=(nstep+1)%4;
           }
        x+=next[step][0];
        y+=next[step][1];
    }
    int v=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                if(i==j||i+j==n-1)
                    v+=m[i][j];
                cout<<m[i][j]<<" ";
            }
        cout<<endl;

    }
    cout<<v<<endl;
     return 0;
}
