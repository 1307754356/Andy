#include<iostream>
#include<cstdio>
#include<cstring>
/*
10 10 5 7
1210000023
3020121012
4010123201
3200012400
0000001530
0121015430
0123136210
0034897500
0003786012
0000000010


*/
using namespace std;
int n,m;
int startx,starty;
int area;
char pic[50][50];
int book[50][50];
int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
int cnt;
void dfs(int x,int y,int id) {
	if(x<0 || x>=n || y<0 || y>=m)
		return ;
	if(pic[x][y]=='0' || book[x][y]>0)
		return ;
	book[x][y]=id;
	area++;
	for(int k=0; k<4; k++) {
		int tx=x+next[k][0];
		int ty=y+next[k][1];
		dfs(tx,ty,id);
	}
}
int main() {
	cin>>n>>m;
	cin>>startx>>starty;
	for(int i=0; i<n; i++)
		scanf("%s",pic[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(pic[i][j]!='0'&&book[i][j]==0)
				dfs(i,j,++cnt);
	
	cout<<"The number of island is "<<cnt <<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout << book[i][j];
		cout<<endl;
	}
	return 0;
}