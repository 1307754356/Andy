
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#define N 20000
bool bPrime[N];     // ������־����
// һ������ɸѡ��: ������ظ�ɸѡͬһ����
void make_prime(int primes[], int& cnt)
{

    cnt = 0;            // ��������
    memset(bPrime, true, sizeof(bPrime));// ����ȫ������
    bPrime[0] = false;                  // 0: ������
    bPrime[1] = false;                  // 1: ������

    for (int i = 2; i < N; i++)
    {
        if (bPrime[i])                  // i������
        {
            primes[cnt++] = i;          // ������i���浽bPrimes[]��

            // ��ɸѡ: i�ı�������������
            for (int k = i * i; k < N; k += i)   // ������i�ı���ȫ��Ϊ��������־
                  bPrime[k] = false;
        }
    }
}


int main()
{
    int primes[N];      // ������������
    int cnt = 0;        // ��������

    make_prime(primes, cnt);    // ����һ������ɸѡ��

    int test_num;
    cin>>test_num;
    if(bPrime[test_num])
        cout<<"\\t";
    else
        cout<<"\\n";

    return 0;
}
