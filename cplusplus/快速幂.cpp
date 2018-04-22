#include<bits\stdc++.h>
using namespace std;
unsigned long long pwd(int a,int b)
{
	int base = a;
	unsigned long long ans=1;
	while(b!=0)
	{
		if(b&1!=0)
			ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;	
}
int main()
{	
	int a,b;
	cin>>a>>b;
	cout<<pwd(a,b)<<endl;
	return 0;
}