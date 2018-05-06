#include <iostream>
using namespace std;

int main() {
    cout<<"ÇëÊäÈëÁ½¸ö×Ö·û´®"<<endl;
    char a[1000];
    char b[1000];
    char ch;
    int i = 0;
    while(cin.get(ch) && ch != '\n') {
        a[i] = ch;
        i++;
    }
    a[i]='\0';
    int len1=i;
    i=0;
    while(cin.get(ch) && ch != '\n') {
        b[i] = ch;
        i++;
    }
    int len2=i;
    for(int i=len1;i<len1+len2;i++)
    {
       a[i]=b[i-len1];
    }
    a[len1+len2]='\0';
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
