#include<iostream>
#include<string>
using namespace std;

//定义一个 类
class Teacher
{

    //数据成员和成员函数
    //封装的数据通过成员函数啦来访问和修改
public:
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
        cout<<"Class begin now!"<<endl;
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

    return 0;
}
