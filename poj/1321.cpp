#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int n, k;
int g[11][11];
int a[11];
int ans;
//喜闻乐见的dfs
//按照套路是先写终止条件
//然后后面用循环遍历结果
//在遍历的过程中使用递归

//但是此题的做法稍有不同
int dfs(int now, int step) {
    //两个结束条件

    //一个是全部填满，因为有step+1
    if(step == k) {
        ans++;
        return 0;
    }
    //一个是边界
    if(now == n)
        return 0;
    //循环部分，这里不好理解，一步步分析
    /*
        循环是针对一行来说的
        a[i] 实际标记的是这一列有没有被放过
    */
    for(int i = 0; i < n; i++) {
        //放入的条件是地图上这一点可以放并且未放过
        if(g[now][i] && !a[i]) {
            //标记此点已经走过
            a[i] = 1;
            //深度搜索，加一行，加一步
            //此步一直递归执行至
            //1. 全部空格被填满
            //2. 走到了边界
            dfs(now + 1, step + 1);
            //上一步结束之后
            //后退一步
            a[i] = 0;
        }
    }
    dfs(now + 1, step);
}


int main() {
    while(cin >> n >> k && n != -1 && k != -1) {
        ans = 0;
        memset(g, 0, sizeof(g));
        memset(a, 0, sizeof(a));
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            int len = s.size();
            for(int j = 0; j < len; j++) {
                if(s[j] == '#')
                    g[i][j] = 1;
            }
        }
        dfs(0, 0);
        cout << ans << endl;

    }
    return 0;
}
