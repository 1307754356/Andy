#include<iostream>
#include<stack>
#include<queue>
//2 4 1 2 5 6 3 1 3 5 6 4
//这个题错了，原题是说拿走重复的第一张牌
//但是给的答案却是不拿走的
//此为不拿走版的

using namespace std;
int book[10];
int main()
{
    queue <int > q1,q2;
    stack <int > d;
    int num;
    for(int i=0;i<6;i++)
    {
        cin>>num;
        q1.push(num);
    }
    for(int i=0;i<6;i++)
    {
        cin>>num;
        q2.push(num);
    }
    while(q1.size()&&q2.size())
    {
       int t;
       t=q1.front();
       if(!book[t])
       {
          d.push(t);
          q1.pop();
          book[t]=1;
       }
       else
       {
          q1.push(t);
          q1.pop();
          while(d.top()!=t)
          {
              q1.push(d.top());
              book[d.top()]=0;
              d.pop();
          }
//              q1.push(t);
//              book[t]=0;
//              d.pop();
       }


       t=q2.front();
       if(!book[t])
       {
          d.push(q2.front());
          q2.pop();
          book[t]=1;
       }
       else
       {
          q2.push(t);
          q2.pop();
          while(d.top()!=t)
          {
              q2.push(d.top());
              book[d.top()]=0;
              d.pop();
          }
//              q2.push(t);
//              book[t]=0;
//              d.pop();
       }
    }
    if(q1.empty())
        cout<<"q1 has lost"<<endl;
    else
        cout<<"q2 has lost"<<endl;
    cout<<"q1: "<<endl;
    while(!q1.empty())
        {
            cout<<q1.front()<<endl;
            q1.pop();
        }
    cout<<"q2: "<<endl;
    while(!q2.empty())
        {
            cout<<q2.front()<<endl;
            q2.pop();
        }
    cout<<"Desktop:"<<endl;
    while(!d.empty())
        {
            cout<<d.top()<<endl;
            d.pop();
        }


    return 0;
}
