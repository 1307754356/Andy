#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int w[100];
int v[100];
int dp[100][100];
int num,W;
int  solve(int i,int j) {
	if(dp[i][j]>=0) {
		return dp[i][j];
	}
	int res;
	if(i==num) {
		res=0;
	} else if(j<w[i]) {
		res=solve(i+1,j);
	} else {
		res = max(solve(i+1,j),solve(i+1,j-w[i])+v[i]);
	}
	return dp[i][j]=res;
}
int main() {
	cin>>num;
	for(int i=0; i<num; i++) {
		cin>>w[i];
		cin>>v[i];
	}
	cin>>W;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,W)<<endl;
	return 0;
}
/*
4
2 3
1 2
3 4
2 2
5



*/