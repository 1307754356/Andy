#include<iostream>
#include<queue>
using namespace std;
#define INT 99999999
/*
5 5
1 2
1 3
1 5
2 4
3 5

*/
int e[101][101];
int book[101];
int que[10001];
int n,m;
int a,b;
int head,tail;
int main() {

	cin>>n>>m;
	queue<int >q;
	for(int i=1; i<=m; ++i) {
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	q.push(1);
	book[1]=1;
	while(q.size()) {
		int cur=q.front();
		for(int i=1; i<=n; ++i) {
			if(e[i][cur]==1 && book[i]==0) {
				book[i]=1;
				q.push(i);
			}
		}
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}