#include"Employee.h"
int main() {
    string my_name;
    string my_address;
    string my_city;
    int my_post;
    getline(cin, my_name);
    getline(cin, my_address);
    getline(cin, my_city);
    cin >> my_post;
    Employee  a( my_name, my_address, my_city, my_post);
    a.Display();
    a.change_name("����");
    a.Display();

    //�������Ԫ�صĶ���
    Employee stu[5];
    return 0;
}

/*
Andy
Shandong
qufu
273100


*/
