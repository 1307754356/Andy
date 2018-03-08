# C++ learn_note 2.3

标签（空格分隔）： C++

---
#C++中的小数位数(poj 1004)



```C
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
```
---

>  以下是一些常见的控制函数的
>  下面假设a是一个浮点数
 
1. 强制性使用小数（默认六位）   `cout << setiosflags(ios::fixed) << a ;`
2. 强制性使用指数（科学记数法） `cout << setiosflags(ios::scientific) << a ;`
3. `cout << setprecision(int)`(设置精度)  
此命令在小数模式下是保留几位小数，在科学记数法模式下是保留几位有效数字（若有效数字位数超过原本位数，则以原位数表示）
4. setw( n ) 设域宽为n个字符 这个控制符的意思是保证输出宽度为n。
5. `cout << setiosflags(ios::left)`左对齐(直接输入`left`也可？)
6. `cout << setiosflags(ios::right)`右对齐
7.  `setfill( 'c' ) `设填充字符为c
8. 上述三个命令都是建立在域宽的基础上的，且一次设置只能对一次输出（一个数或字符串）有效
9. 进制转换代码
```C
    int i=30;
    cout<<hex<<i<<endl; //输出十六进制数
    cout<<oct<<i<<endl; //输出八进制数
    cout<<dec<<i<<endl; //输出十进制数
    //setbase（int）可以设置8,10,16
    cout << setbase() << i << endl;//注：此代码中仅setbase()需要头文件<iomanip>
```
---
> 百度解释

>  - dec 置基数为10 相当于"%d"
>  - hex 置基数为16 相当于"%X" 
>  
>  - oct 置基数为8 相当于"%o"
>  
>  - setfill( 'c' ) 设填充字符为c
>  
>  - setprecision( n ) 设显示有效数字为n位
>  setiosflags(ios::fixed) 固定的浮点显示
   setiosflags(ios::scientific) 指数表示
>  - setw( n ) 设域宽为n个字符 这个控制符的意思是保证输出宽度为n。如： cout << setw( 3 ) << 1 << setw( 3 ) << 10 << setw( 3 ) << 100 << endl; 输出结果为
> _ _1_10100 （默认是右对齐）当输出长度大于3时(<<1000)，setw(3)不起作用。 ▲setw(n)用法： 通俗地讲就是预设宽度 如 cout<<setw(5)<<255<<endl; 结果是: (空格)(空格)255
> 
>    setfill(char c) 用法 : 就是在预设宽度中如果已存在没用完的宽度大小，则用设置的字符c填充
>  setbase(int n) : 将数字转换为 n 进制.
setiosflags(ios::left) 左对齐
setiosflags(ios::right) 右对齐

setprecision(long f)方法的用法
使用setprecision(n)可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。
如果setprecision(n)与setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数。setiosflags(ios::fixed)是用定点方式表示实数。
如果与setiosflags(ios::scientific)合用， 可以控制指数表示法的小数位数。setiosflags(ios::scientific)是用指数方式表示实数。
setiosflags(ios::skipws)    忽略前导空白
setiosflags(ios::uppercase) 16进制数大写输出
setiosflags(ios::lowercase) 16进制小写输出 //VS2010中该方法已不使用，意外使用显示没有该成员错误。
setiosflags(ios::showpoint) 强制显示小数点
setiosflags(ios::showpos)   强制显示符号
▲ resetflags(long f)方法的用法
该方法是setiosflags方法的反向方法，即清除之前语句中所使用的setiosflags设定的格式，恢复为默认格式。

