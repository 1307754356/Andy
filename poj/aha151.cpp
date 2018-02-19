#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a,b,c;
int e[101][101];
int book[101];
int mmin=999999;
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3


*/
void dfs(int  cur,int dis) {
	if(dis>mmin)
		return ;
	if(cur==5) {
		mmin=(mmin<dis)?mmin:dis;
		return ;
	}
	for(int i=1; i<=5; i++) {
		if(book[i]==0 && e[cur][i]!=0) {
			book[i]=1;
			dfs(i,dis+e[cur][i]);
			book[i]=0;
		}
	}

}
int main() {
	cin>>n>>m;
	for(int i=0; i<8; i++) {
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	book[1]=1;
	dfs(1,0);
	cout<<"The minest length is "<<mmin<<endl;

	return 0;
}