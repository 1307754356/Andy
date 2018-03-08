#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1100005;
int dp[maxn];
char s[maxn];
int main (void)
{
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    for(int k=1;k<=n;++k)
    {
        scanf("%s",s);
        stack<int>st;
        int len=strlen(s);
        for(int i=0;i<len;++i)
        {
            if(s[i]==')')
            {
                if(st.empty())
                    continue;
                int tmp=st.top();
                st.pop();
                if(tmp!=0)
                    dp[i]=dp[tmp-1]+1;
                else
                    dp[i]=1;
            }
            else
                st.push(i);
        }
        ll ans=0;
        for(int i=0;i<len;++i)
        {
            ans+=dp[i];
            dp[i]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
