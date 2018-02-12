#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int n, k;
int g[11][11];
int a[11];
int ans;
//ϲ���ּ���dfs
//������·����д��ֹ����
//Ȼ�������ѭ���������
//�ڱ����Ĺ�����ʹ�õݹ�

//���Ǵ�����������в�ͬ
int dfs(int now, int step) {
    //������������

    //һ����ȫ����������Ϊ��step+1
    if(step == k) {
        ans++;
        return 0;
    }
    //һ���Ǳ߽�
    if(now == n)
        return 0;
    //ѭ�����֣����ﲻ����⣬һ��������
    /*
        ѭ�������һ����˵��
        a[i] ʵ�ʱ�ǵ�����һ����û�б��Ź�
    */
    for(int i = 0; i < n; i++) {
        //����������ǵ�ͼ����һ����ԷŲ���δ�Ź�
        if(g[now][i] && !a[i]) {
            //��Ǵ˵��Ѿ��߹�
            a[i] = 1;
            //�����������һ�У���һ��
            //�˲�һֱ�ݹ�ִ����
            //1. ȫ���ո�����
            //2. �ߵ��˱߽�
            dfs(now + 1, step + 1);
            //��һ������֮��
            //����һ��
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
