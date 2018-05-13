#include<iostream>
#include<string>
using namespace std;
class People {
public:
	People(string myid); 
	bool operator ==(const People &b);
	bool operator -(const People &b);  //Is it "="?
private:
	string id;
};
People::People(string myid){
	id = myid;
}
bool People::operator ==(const People &b){
	bool flag=false;
	if(id == b.id)
		flag = true;
	return flag;
}
bool People::operator -(const People &b){
	id=b.id;
}
int main(){
	People a("20174631");
	People b("20174698");
	People c("20174631");
	cout<< boolalpha<<(a==b)<<endl;
	cout<< boolalpha<<(a==c)<<endl;
	b-c;
	cout<<boolalpha<<(a==b)<<endl;
	return 0;
}