#include<iostream>
using namespace std;
int a[25];
int n;
int k;
bool dfs(int step,int sum) {
	if(step == n)
		return sum==k;
	if(sum > k)
		return false;
	if(dfs(step+1,sum+a[step]))
		return true;
	if(dfs(step+1,sum))
		return true;
	return false;
}
int main() {

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	cin>>k;
	if(dfs(0,0))
		cout<<"Yes!"<<endl;
	else
		cout<<"No!"<<endl;

	return 0;
}