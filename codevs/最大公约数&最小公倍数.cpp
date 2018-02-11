#include<iostream>
using namespace std;
//有两整数a和b，求最大公约数：


//方法一：辗转相除法
//① a%b得余数c
//② 若c=0，则b即为两数的最大公约数
//③ 若c≠0，则a=b，b=c，再回去执行①
int gcd1(int x,int y)
{
    //使用递归计算的方法使得一直算到y==0为止
    return y?gcd1(y,x%y):x;
}


//方法二：更相减损术
//如果A > B，则 gcd(A,B) = gcd(B,A-B)
//如果A < B，则 gcd(A,B) = gcd(A,B-A)
//重复以上过程直到A==B为止
//此时A的值就是最大公约数
int gcd2(int x,int y)
{
    while(x!=y)
    {
        //以两数之差替换大数
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }

    return x;
}

//在计算方面，辗转相除法有更少的计算次数
int main()
{
     int p,q;
     cin>>p,q;
     cout<<gcd1(p,q)<<endl;
     cout<<gcd2(p,q)<<endl;
     return 0;
}
