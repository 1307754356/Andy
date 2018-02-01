//深浅拷贝的展示
//浅拷贝指的是将值直接地拷贝给另一个变量
//深拷贝指的是指向两块不同的内存，然后只对应相等

//深拷贝：新建一个堆，
//然后就通过循环的方法把堆中的一个一个的数据拷过去。
//这样就可以避免在修改拷贝对象的数据时，
//同时改变了被拷贝对象的数据
#include<iostream>
using namespace std;

//定义类 Array
class Array
{
public:
    Array(int _count)
    {
        m_iCount =_count;
        m_pArr = new int [m_iCount];
        //在实例化的同时申请内存
        for(int i=0;i<m_iCount;i++)
            m_pArr[i]=i;
        //然后逐个填入数据
        cout<<"Array()"<<endl;
    }
//    Array(const Array& arr)
//    {
//        cout<<"Array(const Array& arr)"<<endl;
//        m_pArr =arr.m_pArr;
//        m_iCount=arr.m_iCount;
//    }
     Array(const Array& arr)
     {
         m_iCount=arr.m_iCount;
         m_pArr =new int [m_iCount];
         for(int i=0;i<m_iCount;i++)
            m_pArr[i]= arr.m_pArr[i];
     }
    ~Array()
    {
        //销毁对象，避免内存泄漏
        delete []m_pArr;
        m_pArr=NULL;
        cout<<"~Array()"<<endl;
    }
    void setCount(int _count)
    {
         m_iCount=_count;
    }
    int getCount(void)
    {
        return m_iCount;
    }
    void printAddr()
    {
        cout<<"地址是： "<<m_pArr<<endl;
    }
    void printArr()
    {
        for(int i=0;i<m_iCount;i++)
        cout<<m_pArr[i]<<" ";
        cout<<endl;
    }
private:
    int m_iCount;
    int *m_pArr;
};
int main()
{
    Array arr1(5);
    arr1.printAddr();
    arr1.printArr();
    Array arr2(arr1);
    arr2.printAddr();
    arr2.printArr();
    return 0;
}

/*浅拷贝输出结果
Array()
地址是： 0xc0c98
Array(const Array& arr)
地址是： 0xc0c98
~Array()
~Array()

可见，浅拷贝会使得两个指针指向同一块内存
这在执行析构函数的时候，会报错（同一块内存释放了两次）
*/

/*深拷贝输出结果
Array()
地址是： 0x2b00c98
地址是： 0x2b00cb8
~Array()
~Array()
可见，深拷贝是不同的地址
*/
