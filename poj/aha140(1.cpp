#include<iostream>
using namespace std;
int e[101][101];
int book[101];
int n,m;
int a,b;
void dfs(int cur,int step)
{
	if(step==6)
		return ;
	book[cur]=1;
	cout<<cur<<" ";
	for(int i=1;i<=n;i++)
	{	
		if(e[cur][i]==1 && book[i]==0)
			dfs(i,step+1);
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	dfs(1,1);
	return 0;
}