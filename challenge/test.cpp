#include<iostream>
#include<cstdio>
#include<cstring>
/*
5 4 3 2
00w0
0000
00w0
0w00
000w


*/
using namespace std;
char pic[100][100];
int idx[100][100];
int n,m;
int p,q;
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}
int minn = 100000;
void dfs(int x,int y,int step) {
	if(x<0 || x>=n || y<0 || y>=n)
		return ;
	if(pic[x][y] != '0' || idx[x][y] > 0)
		return ;
	if(x==p && y==q) {
		minn=(minn<step)?minn:step;
		return ;
	}
	for(int dx=-1; dx <= 1; dx++)
		for(int dy=-1; dy<=1; dy++)
			if((dx==0||dy==0) && (dx+dy)&&idx[x+dx][y+dy]) {
				idx[x+dx][y+dy]=1;
				dfs(x+dx,y+dy,step+1);
				idx[x+dx][y+dy]=0;
			}
}
int main() {

	cin >> n >> m;
	cin >> p >> q;
	for(int i=0; i<n; i++)
		scanf("%s",pic[i]);
	dfs(0,0,0);
	cout << minn << endl;

	return 0;
}