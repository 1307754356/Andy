#include<iostream>
#define INF 99999
using namespace std;
int e[101][101];
int book[101];
int dis[101];
int n,m;

int a,b,c;
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=n; j++) {
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=INF;
		}
	for(int j=0; j<m; j++) {
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	book[1]=1;
	for(int i=1; i<=n; i++)
		dis[i]=e[1][i];
	
	
	for(int i=0; i<n; i++) {
		//mmin记录当前最近元素的距离
		int mmin=INF;
		int u;
		//这里问题的核心在于选出“最短的”元素并记录下来
		for(int j=1; j<=n; j++) {
			if(book[j]==0 && dis[j]<mmin) {
				mmin=dis[j];
				
				u=j;
			}
		}
		book[u]=1;
		//然后将这个最近的元素尝试插入1和其他元素中
		for(int k=1; k<=n; k++) {
			if(e[u][k]<INF && dis[k]>dis[u]+e[u][k])
				dis[k]=dis[u]+e[u][k];
		}
	}
	cout<<"After"<<endl;
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<endl;

	return 0;
}