//此程序是展示 “对象成员”
//以线段为例，
//一个线段包含两个点
//一个点包含两个坐标
//可将点和线段看成两个类
//线段这个类中包含点这个类

#include<iostream>
 using namespace std;
 //先定义“点”类
class Coordinate
{
    //公共部分包含成员函数

public:
    //构造函数初始化点 （此处使用了列表初始化）
    //注：若采用类外定义的方式，在声明的时候不能列表初始化
    //最后打印出的结果中最先打印的两行（Coordinte）
    //证明了是先创建点，后创建线段的
    Coordinate(int x,int y): m_iX(x),m_iY(y)
    {
        cout << "Coordinate" << endl;
    }
    //析构函数
    ~Coordinate()
    {

    };
    void setX(int x)
    {
        m_iX=x;
    }
    int getX()
    {
        return m_iX;
    }
    void setY(int y)
    {
        m_iY=y;
    }
    int getY()
    {
        return m_iY;
    }

    //私有部分包含横纵坐标
private:
    int m_iX;
    int m_iY;
};
 class Line
 {
 public:
     //此处的实例化体现了以括号形式赋值的优越性
     //即赋值的本身就调用了“点”中的构造函数，完成了初始化
     Line(int x1,int y1,int x2,int y2):m_coorA(x1,y1),m_coorB(x2,y2)
     {
         cout<<" Line(int x1,int y1,int x2,int y2)"<<endl;
     }
     ~Line()
     {
         cout<<"~Line"<<endl;
     }
     //下面设置点坐标的两个函数和显示坐标的函数都是通过“点”中的成员函数实现的
     void setCoorA(int x,int y)
     {
         m_coorA.setX(x);
         m_coorA.setY(y);
     }
     void setCoorB(int x,int y)
     {
         m_coorB.setX(x);
         m_coorB.setY(y);
     }
     void printInfo()
     {
         cout<<"("<<m_coorA.getX()<<","<<m_coorA.getY()<<")" <<endl;
         cout<<"("<<m_coorB.getX()<<","<<m_coorB.getY()<<")" <<endl;
     }

     //私有部分声明了两个“点”
     //之后对这两个点的操作通过“点“的成员函数来进行
 private:
     Coordinate m_coorA;
     Coordinate m_coorB;
 };

 int main()
 {
     //实例化
     Line *p=new Line(1,2,3,4);
     p->printInfo();
     p->setCoorA(0,0);
     p->setCoorB(5,5);
     p->printInfo();

     delete p;
     p=NULL;


     return 0;
 }






