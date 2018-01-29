#include<iostream>
#include<string>
using namespace std;

//1.����һ�� �࣬
//2.ͨ�����ַ�ʽ ʵ����
//3.���캯����Ĭ��ֵ��ʹ��
class Teacher
{

    //���ݳ�Ա�ͳ�Ա����
    //��װ������ͨ����Ա�����������ʺ��޸�
public:

    //����չʾ���캯��
    //���캯������Ҫ����ֵ������void��Ҳ����Ҫ��
    //���캯���������ͬ��
    Teacher(void)
    {
        cout<<"Teacher(void)"<<endl;
        m_strName="Wang";
        m_strGender="NULL";
        m_intAge=18;
    }
    Teacher(string _name,int _age=18)
    //���˺������Խ���һ����������������һ����������_ageʹ��Ĭ��ֵ18
    {
         cout<<"Teacher(string _name,int _age=18)"<<endl;
         m_strName=_name;
         m_intAge=_age;
         m_strGender="NULL";
    }
    //��������Ϊ���캯������ʵ������ͬʱ�����ã��ҽ�����һ��
    //���캯���������أ�ǰ����ϵͳ���Էֱ���õ�����Щ����



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
        cout<<"Class begin now!"<<endl<<endl;
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




    //���캯����Ӧ��
    //ע�⣺�˴���δ����������ʼֵ
    Teacher a;
    cout<<"������ǹ��캯����ֵ������a"<<endl;
    cout<<a.getName()<<" "<<a.getGender()
        <<" "<<a.getAge()<<endl<<endl;


    //�˴�ʹ���˳�ʼֵ
    Teacher b("Try",22);
    cout<<"������ǹ��캯����ֵ������b"<<endl;
    cout<<b.getName()<<" "<<b.getGender()
        <<" "<<b.getAge()<<endl;
    return 0;
}
