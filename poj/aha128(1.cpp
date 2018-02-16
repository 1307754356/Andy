#include<iostream>
#include<cstdio>
using namespace std;
struct note {
	int x;
	int y;
	int s;
} que[2051];
char pic[50][50];
int book[50][50];
int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
int head;
int tail;
int n,m;
int startx,starty;
int area;
int cnt;
void bfs(int startx,int starty)
{	
	cnt++;
	que[tail].x=startx;
	que[tail].y=starty;
	//que[tail].s=0;
	tail++;
	while(head<tail) {
		for(int k=0; k<4; k++) {
			int dx = next[k][0]+que[head].x;
			int dy = next[k][1]+que[head].y;
			if(dx<0||dx>=n||dy<0||dy>=m)
				continue ;
			if(book[dx][dy]==0 && pic[dx][dy]!='0') {
				area++;
				book[dx][dy]=cnt;
				que[tail].x=dx;
				que[tail].y=dy;
				tail++;
			}
		}
		head++;
	}
}
int main() {
	cnt=0;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		scanf("%s",pic[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(book[i][j]==0 && pic[i][j] != '0')
				bfs(i,j);
	cout<<"The number of islands is " <<cnt<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<book[i][j];
		cout<<endl;
	}
	return 0;
}