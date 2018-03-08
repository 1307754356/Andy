#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {

	// //**********读取单个字符********************
	// char ch;
	// int cnt = 0;
	// while(cin.get(ch)&&ch!='#') {
	// cout<<ch;
	// ++cnt;
	// }
	// cout<<endl<<"The number is "<<cnt<<endl;


	// //***********输入中的回车问题****************
	// char name[100];
	// char address[1000];
	// cout<<"Enter your name "<<endl;
	// //若无后面的get()，则回车会使地址的输入为空（即不能读取这个回车符）
	// cin.get(name,20).get();
	// cout<<"Your address "<<endl;
	// cin.get(address,50);
	// cout<<"The name : "<<name<<endl;
	// cout<<"The address : "<<address<<endl;


	// //***********输入中的EOF（1）*********************
	// char ch;
	// int cnt =0;
	// //cin在被当作判断条件的时候，自动转换成布尔变量
	// while(cin.get(ch)) //此处也可写成先读取，然后判断(!cin.fail())
	// {
	// cout<<ch;
	// ++cnt;
	// }
	// cout<<endl<<"The number is "<<cnt<<endl;



	// //***********输入中的EOF（2）*********************
	//书上说EOF定义在iostream里，但是测试了一下发现并没有。。。（？）存疑
	//int  ch;//这里使用char也并未发现什么问题,但书上指出，若将-1赋值给一个字符变量会出错误。
	//int cnt =0;
	//这里右值是一个字符，而cin.get(char)返回的是一个对象
	// while((ch=cin.get())!=EOF) {
		// cout.put(ch);
		// ++cnt;	
	// cout<<"Number: "<<cnt<<endl;
	// double num;
	// num=1000.135;
	// cout<<num<<endl;
	//
	cout<<int('W')<<endl;
	cout<<static_cast<int >('W')<<endl;2
	return 0;

}