#include<iostream>
#include<cmath>
#include<cctype>
using namespace std;
int main()
{
   string n;
   int m;
   cin>>n>>m;
   int len=n.size();
   int sum=0;
   for(int i=len-1;i>=0;i--)
   {
       if(isalpha(n[i]))
         sum+=(n[i]-'A'+10)*pow(m,len-1-i);
       else
         sum+=(n[i]-'0')*pow(m,len-1-i);
   }
     cout<<sum<<endl;
   return 0;
}
