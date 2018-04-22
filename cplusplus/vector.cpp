#include<bits/stdc++.h>
using namespace std;
void Show(const int &r)
{
	cout<<r<<" ";
}
int main() {
	vector<int> vec1(10);
	vector<int> vec2(vec1);
	vector<int> vec3(vec1.begin(),vec1.end());
	vector<int>::iterator pd;
	pd=vec3.begin();
	int n=0;
	while(pd!=vec3.end())
	{
		*pd = n++;
		pd++;
	}
	// //置乱
	// random_shuffle(vec3.begin(),vec3.end());
	// //遍历，可用以代替for
	
	// cout<<vec3.front()<<endl;
	// cout<<vec3.back()<<endl;
	for_each(vec1.begin(),vec1.end(),Show);
	cout<<endl;
	return 0;
}
