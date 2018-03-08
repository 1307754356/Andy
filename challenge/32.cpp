#include<iostream>
#include<cstdio>
/*
地图如下
10 12
@........@@.
.@@@.....@@@
....@@...@@.
.........@@.
.........@..
..@......@..
.@.@.....@@.
@.@.@.....@.
.@.@......@.
..@.......@.


填充之后

100000000220
011100000222
000011000220
000000000220
000000000200
003000000200
030300000220
303030000020
030300000020
003000000020
*/
using namespace std;
//地图数组
char pic[100][100];
//标记数组
int  idx[100][100];
//n为行，m为列
int n, m;
void dfs(int x, int y, int id) {
    //出界结束函数
    if(x < 0 || x >= n || y < 0 || y >= m)
        return;
    //已经被走过的路不走
    if(idx[x][y] > 0 || pic[x][y] != '@')
        return;
    //若前两条都通过，则标记此位置
    idx[x][y] = id;
    //下面相当于向八个方向尽可能地搜索
    for(int dx = -1; dx <= 1; dx++)
        for(int dy = -1; dy <= 1; dy++)
            if(dx != 0 || dy != 0) //去掉原地的
                dfs(x + dx, y + dy, id);
}
int main() {
    freopen("32input.txt", "r", stdin);
    cin >> n >> m;
    int cnt = 0;
    //地图一行一行读取比较方便(不存在末尾回车的问题)
    for(int i = 0; i < n; ++i)
        scanf("%s", pic[i]);
    //逐次遍历地图上的元素，唯有其未被标记的情况下才dfs
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(idx[i][j] == 0 && pic[i][j] == '@')
                dfs(i, j, ++cnt);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << idx[i][j];
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}
