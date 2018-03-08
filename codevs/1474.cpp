#include<iostream>
// 234
// 0  117
// 1  58
// 0  29
// 1  14
// 0  7
// 1  3
// 1  1
// 1  0
using namespace std;
char num[100000];
int main() {
    int cnt = 0;
    int n, m;
    cin >> n >> m;

    while(n != 0) {
        if(n % m < 10)
            num[cnt] = n % m + '0';
        else
            num[cnt] = n % m - 10 + 'A';
        n = n / m;
        cnt++;
    }
    for(int i = cnt - 1; i >= 0; i--)
        cout << num[i];

    return 0;
}
