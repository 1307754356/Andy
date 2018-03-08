#include<iostream>
#include<cstdio>
#define N 21
#define M 99999
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12




*/
using namespace std;
int e[N][N];
int n,m;
int a,b,c;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=M;
		}
	for(int i=0; i<m; i++) {
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	//Floyd-Warshall算法
	//仅有五行
	//无法模拟有负权边的情况
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
			}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			printf("%3d",e[i][j]);
		printf("\n");
	}

	return 0;
}