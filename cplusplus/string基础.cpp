#include<iostream>
#include<string>//����ͷ�ļ�
int main()
{
    using namespace std;//�����ռ�
    string name;
    cout<<"Please enter your name:";
    getline(cin,name);//��ȡһ�У������ո�
    if(name.empty())//����Ǹ��մ���name.empty()�᷵��
                    //true���ǿ���Ϊfalse
    {
        cout<<"input is NULL.."<<endl;
        return 0;
    }
    if(name == "imooc") //string ��ֱ���õȺűȽ�
        cout<<"You are a administrator"<<endl;
    cout<<"Hello "+name<<endl; //���ּӷ�������string��֮��
                               //��string�볣��֮�䣬
                               //����������������֮�䡣
    cout<<"Your name length is "<<name.size()<<endl;
                                //name.size()�����ַ�������
                                //�൱��strlen��name��

    cout<<"Your name first letter is "<<name[0]<<endl;
                                //��ֱ�����±���ʽ�����ַ����е�
                                //�����ַ���
    return 0;
}
