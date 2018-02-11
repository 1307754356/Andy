
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#define N 20000
bool bPrime[N];     // 质数标志数组
// 一般线性筛选法: 会出现重复筛选同一个数
void make_prime(int primes[], int& cnt)
{

    cnt = 0;            // 素数个数
    memset(bPrime, true, sizeof(bPrime));// 假设全是素数
    bPrime[0] = false;                  // 0: 非素数
    bPrime[1] = false;                  // 1: 非素数

    for (int i = 2; i < N; i++)
    {
        if (bPrime[i])                  // i是素数
        {
            primes[cnt++] = i;          // 将素数i保存到bPrimes[]中

            // 作筛选: i的倍数都不是素数
            for (int k = i * i; k < N; k += i)   // 将素数i的倍数全置为非素数标志
                  bPrime[k] = false;
        }
    }
}


int main()
{
    int primes[N];      // 保存所有素数
    int cnt = 0;        // 素数个数

    make_prime(primes, cnt);    // 调用一般线性筛选法

    int test_num;
    cin>>test_num;
    if(bPrime[test_num])
        cout<<"\\t";
    else
        cout<<"\\n";

    return 0;
}
