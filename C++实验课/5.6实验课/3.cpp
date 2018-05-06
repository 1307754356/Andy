#include<iostream>
using namespace std;
class vehicle {
private:

public:
    void Run();
    void Stop();
    int Maxspeed;
    int Weight;

};
class bicycle: virtual public vehicle {
private:
    double Height;
};

class motorcar: virtual public vehicle {
private:
    int SeatNum;
};
class motorbicycle: public motorcar, public bicycle {

};
int main(void) {

    motorbicycle a;
    cout << a.Weight<endl;
    return 0;
}
void vehicle::Run() {
    cout << "vehicle Run!" << endl;
}
void vehicle::Stop() {
    cout << "vehicle Stop!" << endl;
}
