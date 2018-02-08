#include<iostream>
#include<queue>
#include<cstdio>
//6 3 1 7 5 8 9 2 4
struct dui
{
    int data[100];
    int head;
    int tail;
}q;
using namespace std;

int main()
{
    q.head=1;
    q.tail=1;

    for(int i=1;i<10;++i)
    {
        cin>>q.data[q.tail];
        q.tail++;
    }
    while(q.head!=q.tail)
    {
        cout<<q.data[q.head]<<" ";
        q.head++;

        q.data[q.tail]=q.data[q.head];
        q.tail++;
        q.head++;
    }
    return 0;


}
//int main()
//{
//   queue<int >q;
//
//   int n;
//   for(int i=0;i<9;i++)
//   {
//       cin>>n;
//       q.push(n);
//   }
//   while(q.size())
//   {
//      cout<<q.front()<<" ";
//      q.pop();
//      q.push(q.front());
//      q.pop();
//   }
//   return 0;
//
//}
