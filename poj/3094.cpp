#include<iostream>
#include<string>
using namespace std;
int main()
{
  string word;
  while(getline(cin,word)&&word!="#")
  {
      int len=word.size();
      long long sum=0;
      for(int i=0;i<len;i++)
        {
            //cout<<word[i]<<" "<<endl;
            if(word[i]!=' ')
            sum+=(i+1)*(word[i]-'A'+1);
        }
     cout<<sum<<endl;
  }

  return 0;
}
