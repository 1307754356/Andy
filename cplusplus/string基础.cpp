#include<iostream>
#include<string>//声明头文件
int main()
{
    using namespace std;//命名空间
    string name;
    cout<<"Please enter your name:";
    getline(cin,name);//读取一行（包含空格）
    if(name.empty())//如果是个空串，name.empty()会返回
                    //true，非空则为false
    {
        cout<<"input is NULL.."<<endl;
        return 0;
    }
    if(name == "imooc") //string 可直接用等号比较
        cout<<"You are a administrator"<<endl;
    cout<<"Hello "+name<<endl; //这种加法仅能在string类之间
                               //或string与常量之间，
                               //不能用于两个常量之间。
    cout<<"Your name length is "<<name.size()<<endl;
                                //name.size()返回字符串长度
                                //相当于strlen（name）

    cout<<"Your name first letter is "<<name[0]<<endl;
                                //可直接以下标形式访问字符串中的
                                //单个字符。
    return 0;
}
