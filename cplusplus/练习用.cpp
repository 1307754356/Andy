#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void out(const int &a) {
	cout<<a<<endl;
}
void char_out(const char &a)
{
	cout<<a<<endl;
}
bool eq(int i)
{
	return (i==4)?true:false;
}
bool cmp(int a,int b)
{
	return a>b;
}
// bool cmp(char a, char b)
// {
	// return a>b;
// }
int main() {
	vector<int> s;
	for(int i=0; i<5; i++)
		s.push_back(i);
	vector<int> c;
	for(int i=0; i<3; i++)
		c.push_back(9);
	/*

	vector<int> s;
	for(int i=0;i<5;i++)
		s.push_back(i);
	cout<<"Before insert"<<endl;
	for_each(s.begin(),s.end(),out);
	s.insert(s.begin(),1);
	cout<<"After insert:"<<endl;
	for_each(s.begin(),s.end(),out);

	vector<int> c;
	for(int i=0;i<3;i++)
		c.push_back(9);
	s.insert(s.begin(),c.begin(),c.end());
	cout<<"After another insert"<<endl;
	for_each(s.begin(),s.end(),out);

	*/


	/* 
	s.swap(c);
	for_each(s.begin(),s.end(),out); 
	
	*/
	
	/* 
	cout<<find_if(s.begin(),s.end(),eq) - s.begin()<<endl; 
	*/
	
	// sort(s.begin(),s.end(),cmp);
	// for_each(s.begin(),s.end(),out);
	vector <char >ch;
	for(int i=0;i<3;i++)
		ch.push_back('A'+i);
	sort(ch.begin(),ch.end(),cmp);
	for_each(ch.begin(),ch.end(),char_out);
	return 0;
}