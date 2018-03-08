/*在同一范围中声明几个功能类似的同名函数，
但是这些同名函数的形式参数
（指参数的个数、类型或者顺序）
必须不同，
也就是说用同一个运算符完成不同的运算功能。
这就是重载函数。
*/
#include <iostream>
using namespace std;
/**
  *函数功能：返回a和b的最大值
  *a和b是两个整数
  */
int getMax(int a, int b)
{
    return a > b ? a : b;
}

/**
  * 函数功能：返回数组中的最大值
  * arr：整型数组
  * count：数组长度
  * 该函数是对上面函数的重载
  */
int getMax(int arr[],int count)
{
    //定义一个变量并获取数组的第一个元素
    int maxNum=arr[0];
	for(int i = 1; i < count; i++)
	{
        //比较变量与下一个元素的大小
		if(arr[i]>maxNum)
		{
            //如果数组中的元素比maxNum大，则获取数组中的值
			maxNum=arr[i];
		}
	}
	return maxNum;
}

int main(void)
{
    //定义int数组并初始化
	int numArr[3] = {3, 8, 6};

    //自动调用int getMax(int a, int b)
	cout << getMax(3, 6) << endl;

    //自动调用返回数组中最大值的函数返回数组中的最大值
	cout << getMax(numArr,3) << endl;
	return 0;
}
