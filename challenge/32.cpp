#include<iostream>
#include<cstdio>
/*
��ͼ����
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


���֮��

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
//��ͼ����
char pic[100][100];
//�������
int  idx[100][100];
//nΪ�У�mΪ��
int n, m;
void dfs(int x, int y, int id) {
    //�����������
    if(x < 0 || x >= n || y < 0 || y >= m)
        return;
    //�Ѿ����߹���·����
    if(idx[x][y] > 0 || pic[x][y] != '@')
        return;
    //��ǰ������ͨ�������Ǵ�λ��
    idx[x][y] = id;
    //�����൱����˸����򾡿��ܵ�����
    for(int dx = -1; dx <= 1; dx++)
        for(int dy = -1; dy <= 1; dy++)
            if(dx != 0 || dy != 0) //ȥ��ԭ�ص�
                dfs(x + dx, y + dy, id);
}
int main() {
    freopen("32input.txt", "r", stdin);
    cin >> n >> m;
    int cnt = 0;
    //��ͼһ��һ�ж�ȡ�ȽϷ���(������ĩβ�س�������)
    for(int i = 0; i < n; ++i)
        scanf("%s", pic[i]);
    //��α�����ͼ�ϵ�Ԫ�أ�Ψ����δ����ǵ�����²�dfs
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
