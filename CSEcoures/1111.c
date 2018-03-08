#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 20
struct student                                 /*定义学生结构体*/
{
long num;
char name[20];
char sex[2];
char address[20];
int  score[3];
int  sum;
int  ave;
};
struct student stu[N];
 int t=1,pl=0;
 void enter();
 void input();
 void display();
 void add();
 void delet();
 void amend();
 void preside();
 void fint();
 void output();
 void main()
 {
    int password;
	int i;
	printf("\n\n\n\n\t\t\t欢迎进入学生信息管理系统\n");           /*初始界面   输入验证密码*/
	for(i=1;i<=3;i++)
	{
		printf("\n\n\t\t\t请输入密码:");
		scanf("%d",&password);
		if(password==000000)
		{
			enter();
			break;
		}
		printf("error!please input again!");
	}
	printf("密码输入三次有误！系统锁定！");

}
void enter()                                  /*进入主菜单函数*/

{
	int choice,w;
	char k;
	system("cls");
	printf("\t\t\t学生信息管理系统\n\n");
	printf("\t\t1. 录入.\t2. 显示.\t3. 增项.\t4. 删项.\n\t\t5. 修改.\t6. 统计.\t7. 查找.\t8.退出.\n");
	printf("\n 输入序号执行相应功能:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: input();break;
	case 2: display(); break;
	case 3: add();break;
	case 4: delet();break;
	case 5: amend();break;
	case 6: preside(); break;
	case 7: fint(); break;
	case 8: output();break;
	default: w=1;
	}
	if(w==1)
	{
		printf("输入有误,按任意键重新选怿.\n");
		k=getchar();
		getch();
		enter();
	}
}
void input()                             /*学生信息录入的函数*/
{
	int x,count=0,i;
	char w,r[20],o;
	struct student *p;
	p=stu;
	system("cls");
	printf("\t\t\t 学生信息的录入.\n");
	do
	{
		pl++;
		printf("请输入第%d 个学生的信息.\n\n",t);
		printf("学号:\n");
 		scanf("%ld",&p->num);
		printf("姓名:\n");
		scanf("%s",&p->name);
		printf("\n");
    	printf("性别:\n");
		gets(r);
		gets(&p->sex);
		printf("\n");
		printf("地区:\n");
		scanf("%s",&p->address);
		printf("\n");
		printf("三门成绩:1.语文.2.数学.3.英语.\n");
		for(i=0;i<3;i++)
		scanf("%d",&p->score[i]);
		p->sum = p->score[0] + p->score[1] + p->score[2];
		p->ave = p->sum/3;
		printf("\n\n 是否要继续输入下一个学生信息,如果是请按 y;不是请按 n.\n");
		o=getchar();
		w=getchar();
		if(w=='y' || w=='Y')
		{

			t++;
			x=1;
			p++;
		}
		else

			x=0;
	}
		while(x==1);
		if(w=='n' || w=='N')
				printf("按任意键返回.\n");
				getch();
				enter();

}
void display()                        /*显示学生信息*/
{
	int i,j;
	system("cls");
	printf("\t\t\t 学生信息显示.\n\n");
	for(j=0;j<t;j++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n\n","学号","姓名","性别","地区","语文","数学","英语","平均分","总分");
		printf("%ld\t%s\t%s\t%s\t",stu[j].num, stu[j].name, stu[j].sex,stu[j].address);
	for(i=0;i<3;i++)
	printf("%d\t", stu[j].score[i]);
	printf("%d\t", stu[j].ave);
	printf("%d\t", stu[j].sum);
	printf("\n\n");
	}
	printf("\n 按任意键返回.\n");
	getch();
	enter();
}
 void add()                             /*学生信息的增加*/
 {
	  int i,x;
	  char a, w;
	  struct student *p;
	  p=stu+t;
                                                                    system("cls");
	  printf("\n\t\t\t增加学生信息.\n");
      do
	  {
		  printf("请输入第%d 个学生的信息.\n\n",t+1);
		  printf("学号:\n");
		  scanf("%ld",&p->num);
		  printf("\n");
		  printf("姓名:\n");
		  scanf("%s",p->name);
		  printf("\n");
		  printf("性别:\n");
		  scanf("%s",p->sex);
		  printf("\n");
		  printf("地区:\n");
		  scanf("%s",p->address);
		  printf("\n");
		  printf("三门成绩:1.语文.2.数学.3.英语.\n");
		  for(i=0;i<3;i++)
			  scanf("%d",&p->score[i]);
		  for(i=0;i<3;i++)
			  p->sum = p->score[0] + p->score[1] + p->score[2];
		  p->ave = p->sum/3;
		  a=getchar();
	  printf("\n 是否要继续输入学生信息,如果是请按 y;不是请按 n.\n\n");
		  w=getchar();
		  p++;
		  t++;
		  if(w=='y'||w=='Y')
		  {
			  x=1;
		  }
		  if(w=='n'||w=='N')
		  {
			  x=0;
			  break;
		  }
	  }while(x==1) ;

	  if(x==0)
	  {
		  printf("\n");
		  printf("按任意键返回.\n");
		  getch();
		  enter();
	  }
  }
  void delet()                           /*学生信息的删除*/
 {
	 long b;
	 int z,j;
	 int r=t;
	 char c,x;
	 struct student *p;
                                    system("cls");
	 printf("\n\t\t\t删除学生信息\n");
	 printf(" 请输入要删除学生的学号:\n\n");
	 scanf("%ld",&b);
	 for(p=stu;p<stu+t;p++)
		 if(p->num==b)
			 break;
		 else
			 r--;
		 if(r==0)
		 {
	printf("你要删除的学生不存在,请按任意键返回.\n");
			 getch();
			 enter();
		 }
		 printf("\n 你要删除的学生为:\n");
		 printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","学号","姓名","性别","地区","语文 ","数学","英语","平均分","总分");
		 printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
		 for(j=0;j<3;j++)
			 printf("%-8d",p->score[j]);
		 printf("%-8d",p->ave);
		 printf("%-8d",p->sum);
		printf("\n你确定要删除吗?如是请输入 y;不是请输入 n.\n");
		 x=getchar();
		 c=getchar();
		 if(c=='y'||c=='Y')
		 {
			 for(p=stu;p<stu+t;p++)
				 *p=*(p+1);
			 t--;
		printf("系统已为你删除信息，请按任意键返回.\n");
			 getch();
			 enter();
		 }
		 if(c=='n'||c=='N')
		 {
			 printf("删除信息取消！按任意键返回.\n");
			 getch();
			 enter();
		 }
  }
  void amend()                         /*学生信息的修改*/
  {
	  long j;
	  int i,z,r=t;
	  char c,d,e,f,q,u,l,v,m,k,h1,h2,h3,h4;
	  struct student *p;
	  system("cls");
	  printf("\n\t\t\t修改学生信息\n");
	  printf(" 请输入要修改学生的学号:\n\n");
	  scanf("%ld",&j);
	  for(p=stu;p<stu+t;p++)
		  if(p->num==j)
			  break;
		  else
			  r--;
		  if(r==0)
		  {
	printf("你输入的学生不存在,请按任意键返回.\n");
			  getch();
			  enter();
		  }
		  printf("\n 你要修改的学生为:\n");
		  printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","学号","姓名","性别","地区","语文 ","数学","英语","平均分","总分");
		  printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
		  for(j=0;j<3;j++)
			  printf("%-8d",p->score[j]);
		  printf("%-8d",p->ave);
		  printf("%-8d",p->sum);
		printf("\n\n 是否要修改学号:是请按 y;不是请按 n.\n\n");
		  l=getchar();
		  c=getchar();
		  if(c=='y'||c=='Y')
		  {
			  printf("请输入正确的学号：\n\n");
			  scanf("%ld",&p->num);
		  }
		  if(c=='n'||c=='N')
			  z=1;
	printf("是否要修改姓名：是请按 y;不是请按 n.\n\n");
		  q=getchar();
		  d=getchar();
		  m=getchar();
		  if(d=='y'||d=='Y')
		  {
			  printf("请输入正确的姓名：\n");
			  scanf("%s",p->name);
			 u=getchar();
		  }
		  if(d=='n'||c=='N')
			  z++;
	printf("\n 是否要修改性别：是请按 y;不是请按n.\n\n");
		  e=getchar();
		  k=getchar();
		  if(e=='y'||e=='Y')
		  {
			  printf("请输入正确的性别：\n");
			  scanf("%s",p->sex);
		  }
		  if(e=='N'||e=='n')
			  z++;
		  printf("\n 是否要修改地区：是请按 y;不是请按 n.\n\n");
		  h3=getchar();
		  h4=getchar();
		  if(h3=='y'||h3=='Y')
		  {
			  printf("请输入正确的地区：\n");
			  scanf("%s",p->address);
		  }
		  if(h3=='N'||h3=='n')
			  z++;
	printf("\n 是否要修改三门成绩：是请按 y;不是请按 n.\n\n");
		  f=getchar();
		  if(f=='y'||f=='Y')
		  {
			  printf("请输入正确的三门成绩：");
			  for(i=0;i<3;i++)
				  scanf("%d",&p->score[i]);
			  p->sum = p->score[0] + p->score[1] + p->score[2];
			  p->ave = p->sum/3;
		  }
		  v=getchar();
		  if(f=='n'||f=='N')
		  {
			  printf("请按任意键返回.\n");
			  getch();
			  enter();
		  }
}
void preside()                         /*学生信息的统计*/
{
	int i,j,o=0,b=10,r=60;
	struct student *p;
	system("cls");
	printf("\n\t\t\t 学生信息统计.\n");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","学号","姓名","性别","地区","语文 ","数学","英语","平均分","总分");
	 for(p=stu;p<stu+t;p++)
	 {
		 printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
		 for(j=0;j<3;j++)
			 printf("%-8d",p->score[j]);
		 printf("%-8d",p->ave);
		 printf("%-8d",p->sum);
		 printf("\n\n");
	 }
	 printf("\n\n\n");
	 for(p=stu;p<stu+t;p++)
	 {
		 for(i=0;i<3;i++)
			 if(p->score[i]<r)
			 {
				 b=b-1;o=o+1;
				 printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","学号","姓名","性别","地区","语文 ","数学","英语","平均分","总分");
 			     printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
				 for(j=0;j<3;j++)
					 printf("%-8d",p->score[j]);
				 printf("%-8d",p->ave);
				 printf("%-8d",p->sum);
				 printf("\n\n");
				 break;
			 }
	 }
	 if(b==10)
		 printf("\n\n 班上所有的人都通过考试.\n\n");
	 else if(b<10)
		printf("\n 以上为不及格的同学,全班不及格的人数为：%d 人.\n\n",o);
	 printf("\n");
	 printf("统计完成,请按任意键返回.\n");
	 getch();
	enter();

 }
 void fint()                      /*查找学生信息*/
 {
	 int i,j=t;
	 long num_a;
	 struct student *p;
	 char a,b;
	 system("cls");
	 printf("\n\t\t\t查找学生信息\n");
	 printf("\t\t\t 请输入要查找的学生学号:\n");
	 scanf("%ld",&num_a);
	 for(p=stu;p<stu+t;p++)
	 {
		 j--;
		 if(p->num==num_a)
			 break;
		 if(j==0)
		 {
			 printf("不存在该学生,请按任意键返回.\n\n");
			 a=getchar();
			 getch();
			 enter();
		 }
	 }
	 printf("\n 你要查找的学生为:\n\n");
	            printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","学号","姓名","性别","地区","语文 ","数学","英语","平均分","总分");
 	 printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
	 for(i=0;i<3;i++)
		 printf("%-8d",p->score[i]);
	 printf("%-8d",p->ave);
	 printf("%-8d",p->sum);
	 printf("\n\n 查找完成,请按任意键返回.");
	 b=getchar();
	 getch();
	 enter();

 }
 void output()                     /*退出系统*/
 {
	 system("cls");
	 exit(0);
 }

