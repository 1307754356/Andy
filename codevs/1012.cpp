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
    //������Ϊ 12 4096 ���Ӵ������ᳬʱ��
    // (p / x) * (q / x)*x == y
    //�����õ� p * q ==x * y ,����д��ԭ���Ǳ���p*q���
    if(y % x == 0) {
        for (p = x; p <= y; p++)
            for(q = x; q <= y; q++)
                if(gcd(p, q) == x && (p / x) * (q / x)*x == y)
                    sum++;
    }
    cout << sum << endl;

    return 0;
}
