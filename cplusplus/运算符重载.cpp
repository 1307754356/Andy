#include <iostream>
#include <string>
using namespace std;
 
int main(void)
{
   char s0[]="This is a string!";
   
   //�������ַ���
   string s1;
   
   //����ʱ���ַ����������г�ʼ��
   string s2("Hello!World");
  
   //����ʱ����һ��string��ʼ��
   string s3(s2);
 
   //����һ������Ϊ20��ÿ��Ԫ��Ϊ'h'���ַ���
   string s4(20,'h');
  
   //��һ��������(s0)�д�ͷ��ȡ����Ϊ6���ַ���
   string s5(s0,6);
   
   //ͨ��ָ���ȡ�ַ����е�ĳһ��
   string s6(s0+1,s0+5);
   
   //��һ��������(s[3])��ȡ������ȵ��ַ� 
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