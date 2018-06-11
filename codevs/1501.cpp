#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iterator>
#include <cstdio>
#include <string>
//han nuo ta
using namespace std;

long long pow(int num) {
    long long x = 1;
    for (int i = 0; i < num; i++) {
        x *= 2;
    }
    return x;
}

void move(int step, string start, string goal) {


    string medim;
    /*
     * 此处(若为字符)可优化为 198 - start - goal
     * 因为198 = 'A'+'B'+'C'
     * */

    if (start != "A" && goal != "A")
        medim = "A";
    if (start != "B" && goal != "B")
        medim = "B";
    if (start != "C" && goal != "C")
        medim = "C";
    if (step == 2) {
        cout << 1 << " from " << start << " to " << medim << endl;
        cout << 2 << " from " << start << " to " << goal << endl;
        cout << 1 << " from " << medim << " to " << goal << endl;

        return;
    }
    if (step == 1) {
        cout << 1 << " from " << start << " to " << goal << endl;
        return;
    }
    move(step - 1, start, medim);
    cout << step << " from " << start << " to " << goal << endl;

    move(step - 1, medim, goal);

}

int main() {

    int n;
    while (cin >> n) {
        cout << pow(n) - 1 << endl;
        move(n, "A", "C");
    }
    return 0;
}