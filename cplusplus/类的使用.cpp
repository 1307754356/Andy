#include<iostream>
#include<string>
using namespace std;

//����һ�� ��
class Teacher
{

    //���ݳ�Ա�ͳ�Ա����
    //��װ������ͨ����Ա�����������ʺ��޸�
public:
    //����Ϊ��װ�������˴�Ϊ���ڶ��壬Ҳ���Դ˴������������ⲿ���壩
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
    //����ĳ�Ա�������أ�����ͨ����Ա���������ʺ��޸�
    string m_strName;
    string m_strGender;
    int    m_intAge;
};
int main()
{
    //ͨ��ջʵ����
    Teacher t;

    //ͨ����Ա�����޸����ݳ�Ա
    t.setName("����");
    t.setGender("��");
    t.setAge(30);

    //ͨ����Ա�����������ݳ�Ա
    cout<<"Let's have a look "<<endl;
    cout<<t.getName()<<" "<<t.getGender()
        <<" "<<t.getAge()<<endl;
    t.teach();
    //ʹ����Ϻ���Զ��黹�ڴ�




    //ͨ����ʵ����
    Teacher *p=new Teacher();
    p->setName("Andy");
    p->setGender("male");
    p->setAge(18);

    cout<<"Let's have a look "<<endl;
    cout<<p->getName()<<" "<<p->getGender()
        <<" "<<p->getAge()<<endl;
    p->teach();
    delete p;
    //delete �� new ������Գ���

    return 0;
}
