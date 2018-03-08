#include<iostream>
#include<string>
using namespace std;

//1.定义一个 类，
//2.通过两种方式 实例化
//3.构造函数和默认值的使用
class Teacher
{

    //数据成员和成员函数
    //封装的数据通过成员函数啦来访问和修改
public:

    //下面展示构造函数
    //构造函数不需要返回值（连“void”也不需要）
    //构造函数必须和类同名
    Teacher(void)
    {
        cout<<"Teacher(void)"<<endl;
        m_strName="Wang";
        m_strGender="NULL";
        m_intAge=18;
    }
    Teacher(string _name,int _age=18)
    //即此函数可以接受一或两个参数，若仅一个参数，则_age使用默认值18
    {
         cout<<"Teacher(string _name,int _age=18)"<<endl;
         m_strName=_name;
         m_intAge=_age;
         m_strGender="NULL";
    }
    //以上两个为构造函数，在实例化的同时被调用，且仅调用一次
    //构造函数可以重载，前提是系统可以分辨出该调用哪些函数



    //下列为封装函数（此处为类内定义，也可以此处仅声明，在外部定义）
    void setName(string _name)
    {
         m_strName=_name;
    }
    string getName(void)
    {
        return m_strName;
    }
    void setGender(string _gender)
    {
         m_strGender=_gender;
    }
    string getGender(void)
    {
        return m_strGender;
    }
    void setAge(int _age)
    {
        m_intAge=_age;
    }
    int  getAge(void)
    {
         return m_intAge;
    }
    void teach(void)
    {
        cout<<"Class begin now!"<<endl<<endl;
    }
private:
    //下面的成员对外隐藏，仅能通过成员函数来访问和修改
    string m_strName;
    string m_strGender;
    int    m_intAge;
};
int main()
{
    //通过栈实例化
    Teacher t;

    //通过成员函数修改数据成员
    t.setName("孔子");
    t.setGender("男");
    t.setAge(30);

    //通过成员函数访问数据成员
    cout<<"Let's have a look "<<endl;
    cout<<t.getName()<<" "<<t.getGender()
        <<" "<<t.getAge()<<endl;
    t.teach();
    //使用完毕后会自动归还内存




    //通过堆实例化
    Teacher *p=new Teacher();
    p->setName("Andy");
    p->setGender("male");
    p->setAge(18);

    cout<<"Let's have a look "<<endl;
    cout<<p->getName()<<" "<<p->getGender()
        <<" "<<p->getAge()<<endl;
    p->teach();
    delete p;
    //delete 和 new 必须配对出现




    //构造函数的应用
    //注意：此处并未给函数赋初始值
    Teacher a;
    cout<<"下面的是构造函数赋值的例子a"<<endl;
    cout<<a.getName()<<" "<<a.getGender()
        <<" "<<a.getAge()<<endl<<endl;


    //此处使用了初始值
    Teacher b("Try",22);
    cout<<"下面的是构造函数赋值的例子b"<<endl;
    cout<<b.getName()<<" "<<b.getGender()
        <<" "<<b.getAge()<<endl;
    return 0;
}
