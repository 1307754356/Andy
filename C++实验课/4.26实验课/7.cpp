#include<iostream>
#include<string>
#include<cstring>
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
    People(char  *myname, char  *mynum, char  *mysex, char  *myid, data mybirth);
    People(People &p);
    Set(char  *myname, char  *mynum, char  *mysex, char  *myid, data mybirth);
    ~People();
    inline void showData();
private:
    char name[11];
    char number[7];
    char sex[3];
    char id[16];
    data birth;
};
People::People() {
}
People::People( char *myname, char  *mynum, char  *mysex, char  *myid, data mybirth) {
    cout << "People construct" << endl;
    strcpy(name, myname);
    strcpy(number, mynum);
    strcpy(sex, mysex);
    strcpy(id, myid);
    birth = mybirth;
}
People::Set(char  *myname, char  *mynum, char  *mysex, char  *myid, data mybirth) {

    strcpy(name, myname);
    strcpy(number, mynum);
    strcpy(sex, mysex);
    strcpy(id, myid);
    birth = mybirth;

}

People::~People() {
    cout << "People destructor" << endl;
}
void People::showData() {
    cout << "name: " << name << endl
         << "number: " << number << endl
         << "sex: " << sex << endl
         << "id: " << id << endl;
    birth.showData();
    cout << endl;
}
People::People(People &p) {
    cout << "People Copy construct" << endl;
    strcpy(name, p.name);
    strcpy(number, p.number);
    strcpy(sex, p.sex);
    strcpy(id, p.id);
    birth = p.birth;
}
int main() {
    char myname[11];
    char mynum[7];
    char mysex[3];
    char myid[16];
    int myyear;
    int mymon;
    int myday;
    People a[5];
    for(int i = 0; i < 5; i++) {
        cin >> myname >> mynum >> mysex >> myid;
        cin >> myyear >> mymon >> myday;
        data mydata(myyear, mymon, myday);
        a[i].Set(myname, mynum, mysex, myid, mydata);
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
