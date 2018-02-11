#include<iostream>
using namespace std;
int gcd(int x, int y) {

    return y ? gcd(y, x % y) : x;
}
int main() {


    int x, y;
    int p, q;
    cin >> x >> y;
    int sum = 0;
    //若例子为 12 4096 不加此条件会超时。
    // (p / x) * (q / x)*x == y
    //是利用的 p * q ==x * y ,这样写的原因是避免p*q溢出
    if(y % x == 0) {
        for (p = x; p <= y; p++)
            for(q = x; q <= y; q++)
                if(gcd(p, q) == x && (p / x) * (q / x)*x == y)
                    sum++;
    }
    cout << sum << endl;

    return 0;
}
