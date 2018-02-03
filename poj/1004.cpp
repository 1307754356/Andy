#include <iostream>
#include <iomanip>      //  需要添加此头文件（输入输出控制）
using namespace std;
int main()
{
    double money,sum=0;
    for(int i=0;i<12;++i)
    {
        cin>>money;
        sum+=money;
    }
    cout<<setiosflags(ios::fixed);
    /*iso::fixed 是操作符setiosflags 的参数之一，该参数指定的动作是以带小数点的形式表示浮点数，并且在允许的精度范围内尽可能的把数字移向小数点右侧； */
    cout.precision(2);      //设置小数位为2
    cout<<"$"<<sum/12<<endl;
    return 0;
}
