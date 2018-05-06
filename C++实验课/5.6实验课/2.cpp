#include<iostream>
using namespace std;

class BaseClass {
public:
    BaseClass();
    ~BaseClass();
private:
    int Number;
};
BaseClass::BaseClass() {
    cout << "BaseClass constructor" << endl;
}
BaseClass::~BaseClass() {
    cout << "BaseClass destructor" << endl;
}
class DerivedClass : public BaseClass {
public:
    DerivedClass();
    ~DerivedClass();
};
DerivedClass::DerivedClass() {
    cout << "DeriedClass constructor" << endl;
}
DerivedClass::~DerivedClass() {
    cout << "DeriedClass destructor" << endl;
}
int main() {
   DerivedClass a;
   return 0;
}
