//
// Created by 孔振华 on 2018/6/11.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[30][3];
int b[30];

void front(int x) {
    cout << x << " ";
    if (a[x][0] != 0)
        front(a[x][0]);
    if (a[x][1] != 0)
        front(a[x][1]);
    if (x != 1 && a[x][0] == 0 && a[x][1] == 0)
        return;
}


void middle(int x) {
    if (a[x][0] != 0)
        middle(a[x][0]);
    cout << x << " ";
    if (a[x][1] != 0)
        middle(a[x][1]);
    if (x != 1 && a[x][0] == 0 && a[x][1] == 0)
        return;
}


void back(int x) {
    if (a[x][0] != 0)
        back(a[x][0]);
    if (a[x][1] != 0)
        back(a[x][1]);
    cout << x << " ";
    if (x != 1 && a[x][0] == 0 && a[x][1] == 0)
        return;
}

int main() {
    int n;
    int k;
    while (cin >> n) {
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            a[i][0] = x;
            a[i][1] = y;
            a[x][2] = i;
            a[y][2] = i;
        }
        front(1);
        cout << endl;
        middle(1);
        cout << endl;
        back(1);
        cout << endl;
       // cout << "Done" << endl;
    }
    return 0;
}
