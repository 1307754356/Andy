//这个类和“对象成员里面的一样”
#include<iostream>
 using namespace std;
class Coordinate
{
    //公共部分包含成员函数

public:
    Coordinate(int x,int y): m_iX(x),m_iY(y)
    {
        cout << "Coordinate" << endl;
    }
    ~Coordinate()
    {

    }
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

private:
    int m_iX;
    int m_iY;
};
 class Line
 {
 public:
     Line(int x1,int y1,int x2,int y2):m_coorA(x1,y1),m_coorB(x2,y2)
     {
         cout<<" Line(int x1,int y1,int x2,int y2)"<<endl;
     }
     ~Line()
     {
         cout<<"~Line"<<endl;
     }
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
 private:
     Coordinate m_coorA;
     Coordinate m_coorB;
 };

 int main()
 {
     Line *p=new Line(1,2,3,4);
     p->printInfo();
     p->setCoorA(0,0);
     p->setCoorB(5,5);
     p->printInfo();

     delete p;
     p=NULL;


     return 0;
 }






