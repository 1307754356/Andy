#include<iostream>
using namespace std;
int main()
{
   double len;
   while(cin>>len&&len-0.00>0.0001)
   {
        double len1=0 ;
        int i=0;
        while(len1<len)
        {
           i++;
           len1+=1.0/(i+1);
        }
        cout<<i<<" card(s)"<<endl;
   }

   return 0;
}
