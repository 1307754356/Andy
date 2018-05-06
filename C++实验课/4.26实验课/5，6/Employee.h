#include <iostream>
#include<string>
using namespace std;
class Employee {
public:
    Employee(string my_name="", string my_address="", string my_city="", int my_post=0);
    void Display();
    void change_name(string my_name);
private:
    string name;
    string address;
    string city;
    int post;
};
Employee::Employee(string my_name, string my_address, string my_city, int my_post) {
    cout<<"Employee constructor"<<endl;
    name = my_name;
    address = my_address;
    city = my_city;
    post = my_post;
}
void Employee::Display() {
    cout << "name: " << name << endl
         << "address: " << address << endl
         << "city: " << city << endl
         << "post: " << post << endl;
}
void Employee::change_name(string my_name){
    name=my_name;
}
