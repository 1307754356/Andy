#include<iostream>
#include<cstring>
#include<cstdio>
/*
5 4
0010
0000
0010
0100
0001
0 0 3 2


*/
char pic[50][50];
int book[50][50];
int n,m;
int p,q;
struct note {
	int x;
	int y;
	int f;
	int s;
} que[2501];
int head;
int tail;
int flag;
int startx,starty;
int tx,ty;
int k;
int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
using namespace std;
int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++)
		scanf("%s",pic[i]);
	cin >> startx >> starty;
	cin >> p >> q;

	head = 0;
	tail = 0;

	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;

	flag = 0;

	while(head < tail) {

		for(k = 0; k <= 3; k++) {
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if(tx < 0 || tx >= n || ty < 0 || ty>=m)
				continue ;
			if(pic[tx][ty] == '0' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			if(tx == p && ty == q) {
				flag = 1;
				break;
			}
		}
		if(flag==1)
			break;
		head++;
	}

	cout << que[tail-1].s << endl;


	return 0;
}