#include<iostream>
using namespace std;
int book[1005];
int sb[105];
int main()
{
   int T;
   cin>>T;
   int num=0;
  for(int i=0;i<T;i++)
  {
      cin>>sb[i];
      if(!book[sb[i]])
          num++;
      book[sb[i]]++;
  }
  cout<<num<<endl;
  for(int i=0;i<=1000;i++)
  {
     if(book[i])
        cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
