#include<iostream>
using namespace std;
long long  num[25];
bool book[25];
int k;
int T;
int flag;
int dfs(int step,int sum) {
    if(sum == k) {
        flag = 1;
        for(int j = 0; j < T; j++) {
            if(book[num[j]])
              cout << num[j] << " ";
        }
        cout<<endl;
        return 0;
    }
    if(sum > k)
        return 0;
    if(step==T-1&&sum<k)
        return 0;
    for(int i = 0; i < T; i++) {
        if(!book[num[i]]) {
            book[num[i]] = 1;
            dfs(step+1,sum + num[i]);
            book[num[i]] = 0;
        }
    }

}
int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> num[i];
    }
    cin >> k;
    dfs(0,0);
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
