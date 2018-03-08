#include<iostream>
#include<stack>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    string a;
    char s[101];
    int top=0;
    int len;
    int next;
    getline(cin,a);
    len=a.size();
    int mid=len/2-1;
    for(int i=0;i<=mid;i++)
        s[++top]=a[i];
        if(len%2==0)
            next=mid+1;
        else
            next=mid+2;
    for(int i=next;i<=len-1;i++)
    {
        if(a[i]!=s[top])
        {
            break;
        }
        top--;
    }
    if(top==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

   return 0;
}




//int main()
//{
//
//    string a;
//    int next;
//    getline(cin,a);
//    int mid=a.size()/2-1;
//    stack <int >s;
//    for(int i=0;i<=mid;i++)
//        s.push(a[i]);
//
//    if(a.size()%2)
//         next=mid+2;
//    else
//         next=mid+1;
//
//    for(int i=next;i<a.size();++i)
//         {
//             if(a[i]!=s.top())
//                break;
//             s.pop();
//         }
//    if(s.size())
//        cout<<"No"<<endl;
//    else
//        cout<<"Yes"<<endl;
//
//    return 0;
//}
