#include <iostream>
#include<string>
using namespace std;

int main() {
   cout<<"ÇëÊäÈëÁ½¸ö×Ö·û´®"<<endl;
   string a;
   string b;
   getline(cin,a);
   getline(cin,b);
   a+=b;
   cout<<a<<endl;
    return 0;
}


/*
1 2 3
4 5 6
7 8 9



*/
/*

1 2 3
2 3 4
1 2 3 2 3 4
*/
