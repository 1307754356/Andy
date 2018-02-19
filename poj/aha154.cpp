//广度优先搜索适用于“所有边权值相同的情况”
#include<iostream>
#include<queue>
using namespace std;
int n,m;
int s,f;// the start and the final
int a,b;
int e[101][101];
int book[101];
int cnt=0;
int head;
int tail;
/*

5 7 1 5  
1 2
1 3
2 3
2 4
3 4
3 5
4 5

*/
//暂时妥协之策，采用结构体数组
struct note
{
	int x;
	int s;
}q[101];

int main() {
	
	cin>>n>>m;
	cin>>s>>f;
	//无向图
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	//输入队列第一个元素
	book[s]=1;
	q[tail].x=1;
	q[tail].s=0;
	tail++;
	
	//开始bfs
	while(head < tail) {
		int cur=q[head].x;
		for(int i=1; i<=n; i++) {
			if(e[cur][i]==1 && book[i]==0) {
				book[i]=1;
				q[tail].x=i;
				q[tail].s=q[head].s+1;
				tail++;
			}
		}
		//当然也可以在循环内部遍历到终点时直接停止
		if(book[f]==1)
			break;
		head++;
	}
	//tail始终指向最后一个元素的后面的位置
	cout<<q[tail-1].s<<endl;
	
	return 0;
}