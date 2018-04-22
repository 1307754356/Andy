#include <iostream>
#include <string>
using namespace std;
 
int main(void)
{
   char s0[]="This is a string!";
   
   //创建空字符串
   string s1;
   
   //创建时用字符串常量进行初始化
   string s2("Hello!World");
  
   //创建时用另一个string初始化
   string s3(s2);
 
   //创建一个长度为20，每个元素为'h'的字符串
   string s4(20,'h');
  
   //从一个字面量(s0)中从头截取长度为6的字符串
   string s5(s0,6);
   
   //通过指针截取字符串中的某一段
   string s6(s0+1,s0+5);
   
   //从一个对象中(s[3])截取五个长度的字符 
   string s7(s2,3,5);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;
	cout<<s6<<endl;
	cout<<s7<<endl;
   
   return 0;
}