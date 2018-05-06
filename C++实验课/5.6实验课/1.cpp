#include<iostream>
using namespace std;
class Animal {
public:
    int age;
};
class dog : public Animal {
public:
    void SetAge(int myage);

};
void dog::SetAge(int myage) {
    age = myage;
}
int main() {
    dog a;
    a.SetAge(15);
    return 0;
}
