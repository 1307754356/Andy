#include<iostream>
#include<string>
using namespace std;
class data {
public:
    data();
    data(int myyear, int mymon, int myday);
    data(data &a);
    ~data();
    inline void showData();
private:
    int year;
    int mon;
    int day;
};
data::data() {
}
data::data(int myyear, int mymon, int myday) {
    cout << "data construct" << endl;
    year = myyear;
    mon = mymon;
    day = myday;
}
data::data(data &a) {
    cout << "data copy construct" << endl;
    year = a.year;
    mon = a.mon;
    day = a.day;
}
data::~data() {
    cout << "data destructor" << endl;
}
void data::showData() {
    cout << year << " " << mon << " " << day << " ";
}
class People {
public:
    People();
    People(string mynum, string mysex, string myid, data birth);
    People(People &p);
    Set(string mynum, string mysex, string myid, data birth);
    ~People();
    inline void showData();
private:
    string number;
    string sex;
    string id;
    data birth;
};
People::People() {
}
People::People(string mynum, string mysex, string myid, data mybirth): number(mynum), sex(mysex), id(myid), birth(mybirth) {
    cout << "People construct" << endl;
}
People::Set(string mynum, string mysex, string myid, data mybirth) {
    number = mynum;
    sex = mysex;
    id = myid;
    birth = mybirth;

}

People::~People() {
    cout << "People destructor" << endl;
}
void People::showData() {
    cout << "number: " << number << endl
         << "sex: " << sex << endl
         << "id: " << id << endl;
    birth.showData();
    cout << endl;
}
People::People(People &p): number(p.number), sex(p.sex), id(p.id), birth(p.birth) {
    cout << "People Copy construct" << endl;
}
int main() {
    string mynum;
    string mysex;
    string myid;
    int myyear;
    int mymon;
    int myday;
    People a[5];
    for(int i = 0; i < 5; i++) {

        getline(cin, mynum);
        getline(cin, mysex);
        getline(cin, myid);
        cin >> myyear >> mymon >> myday;
        data mydata(myyear, mymon, myday);
        a[i].Set(mynum, mysex, myid, mydata);
        a[i].showData();

    }
    return 0;
}
/*
20174631
m
257
2018
4
26



*/
