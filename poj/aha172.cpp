#include<iostream>
//强大的邻接表
//邻接表用来存储图的时间空间复杂度是O（M）
//如果一个图是稀疏图的话，M要远小于N^2.
//因此稀疏图选用邻接表来存储要比用邻接矩阵来好得多
using namespace std;
int n,m;
int u[6],v[6],w[6];
int first[5],next[5];
/*
4 5
1 4 9
2 4 6
1 2 5
4 3 8
1 3 7

*/
int main() {
	cin>>n>>m;
	//first数组的作用是
	//first[i]的值是指以i号节点作为起始的线段在u,v,w数组中的编号
	for(int i=1; i<=n; i++)
		first[i]=-1;
	//此处略微费解
	for(int i=1; i<=m; i++) {
		//输入起点，终点，距离
		cin>>u[i]>>v[i]>>w[i];
		//这一步操作是说
		//把first的上一次的值赋给next
		//first默认为-1，
		//即若赋值后next值为-1，当前的first就是唯一的值
		next[i]=first[u[i]];
		//然后更新first数组中的值，表明其在u,v,w中的编号
		first[u[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		int k=first[i];
		while(k!=-1) {
			cout<<u[k]<<" "<<v[k]<<" "<<w[k]<<endl;
			k=next[k];
		}
	}

	/*
	第一次
	u[1]=1	v[1]=4  w[1]=9  next[1]=first[1]=-1  first[1]=1;
	u[2]=2  v[2]=4  w[2]=6  next[2]=first[2]=-1  first[2]=2;
	u[3]=1  v[3]=2  w[3]=5  next[3]=first[1]= 1  first[1]=3;
	*/
	return 0;

}