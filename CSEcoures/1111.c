#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 20
struct student                                 /*����ѧ���ṹ��*/
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
	printf("\n\n\n\n\t\t\t��ӭ����ѧ����Ϣ����ϵͳ\n");           /*��ʼ����   ������֤����*/
	for(i=1;i<=3;i++)
	{
		printf("\n\n\t\t\t����������:");
		scanf("%d",&password);
		if(password==000000)
		{
			enter();
			break;
		}
		printf("error!please input again!");
	}
	printf("����������������ϵͳ������");

}
void enter()                                  /*�������˵�����*/

{
	int choice,w;
	char k;
	system("cls");
	printf("\t\t\tѧ����Ϣ����ϵͳ\n\n");
	printf("\t\t1. ¼��.\t2. ��ʾ.\t3. ����.\t4. ɾ��.\n\t\t5. �޸�.\t6. ͳ��.\t7. ����.\t8.�˳�.\n");
	printf("\n �������ִ����Ӧ����:");
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
		printf("��������,�����������ѡ��.\n");
		k=getchar();
		getch();
		enter();
	}
}
void input()                             /*ѧ����Ϣ¼��ĺ���*/
{
	int x,count=0,i;
	char w,r[20],o;
	struct student *p;
	p=stu;
	system("cls");
	printf("\t\t\t ѧ����Ϣ��¼��.\n");
	do
	{
		pl++;
		printf("�������%d ��ѧ������Ϣ.\n\n",t);
		printf("ѧ��:\n");
 		scanf("%ld",&p->num);
		printf("����:\n");
		scanf("%s",&p->name);
		printf("\n");
    	printf("�Ա�:\n");
		gets(r);
		gets(&p->sex);
		printf("\n");
		printf("����:\n");
		scanf("%s",&p->address);
		printf("\n");
		printf("���ųɼ�:1.����.2.��ѧ.3.Ӣ��.\n");
		for(i=0;i<3;i++)
		scanf("%d",&p->score[i]);
		p->sum = p->score[0] + p->score[1] + p->score[2];
		p->ave = p->sum/3;
		printf("\n\n �Ƿ�Ҫ����������һ��ѧ����Ϣ,������밴 y;�����밴 n.\n");
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
				printf("�����������.\n");
				getch();
				enter();

}
void display()                        /*��ʾѧ����Ϣ*/
{
	int i,j;
	system("cls");
	printf("\t\t\t ѧ����Ϣ��ʾ.\n\n");
	for(j=0;j<t;j++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n\n","ѧ��","����","�Ա�","����","����","��ѧ","Ӣ��","ƽ����","�ܷ�");
		printf("%ld\t%s\t%s\t%s\t",stu[j].num, stu[j].name, stu[j].sex,stu[j].address);
	for(i=0;i<3;i++)
	printf("%d\t", stu[j].score[i]);
	printf("%d\t", stu[j].ave);
	printf("%d\t", stu[j].sum);
	printf("\n\n");
	}
	printf("\n �����������.\n");
	getch();
	enter();
}
 void add()                             /*ѧ����Ϣ������*/
 {
	  int i,x;
	  char a, w;
	  struct student *p;
	  p=stu+t;
                                                                    system("cls");
	  printf("\n\t\t\t����ѧ����Ϣ.\n");
      do
	  {
		  printf("�������%d ��ѧ������Ϣ.\n\n",t+1);
		  printf("ѧ��:\n");
		  scanf("%ld",&p->num);
		  printf("\n");
		  printf("����:\n");
		  scanf("%s",p->name);
		  printf("\n");
		  printf("�Ա�:\n");
		  scanf("%s",p->sex);
		  printf("\n");
		  printf("����:\n");
		  scanf("%s",p->address);
		  printf("\n");
		  printf("���ųɼ�:1.����.2.��ѧ.3.Ӣ��.\n");
		  for(i=0;i<3;i++)
			  scanf("%d",&p->score[i]);
		  for(i=0;i<3;i++)
			  p->sum = p->score[0] + p->score[1] + p->score[2];
		  p->ave = p->sum/3;
		  a=getchar();
	  printf("\n �Ƿ�Ҫ��������ѧ����Ϣ,������밴 y;�����밴 n.\n\n");
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
		  printf("�����������.\n");
		  getch();
		  enter();
	  }
  }
  void delet()                           /*ѧ����Ϣ��ɾ��*/
 {
	 long b;
	 int z,j;
	 int r=t;
	 char c,x;
	 struct student *p;
                                    system("cls");
	 printf("\n\t\t\tɾ��ѧ����Ϣ\n");
	 printf(" ������Ҫɾ��ѧ����ѧ��:\n\n");
	 scanf("%ld",&b);
	 for(p=stu;p<stu+t;p++)
		 if(p->num==b)
			 break;
		 else
			 r--;
		 if(r==0)
		 {
	printf("��Ҫɾ����ѧ��������,�밴���������.\n");
			 getch();
			 enter();
		 }
		 printf("\n ��Ҫɾ����ѧ��Ϊ:\n");
		 printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","ѧ��","����","�Ա�","����","���� ","��ѧ","Ӣ��","ƽ����","�ܷ�");
		 printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
		 for(j=0;j<3;j++)
			 printf("%-8d",p->score[j]);
		 printf("%-8d",p->ave);
		 printf("%-8d",p->sum);
		printf("\n��ȷ��Ҫɾ����?���������� y;���������� n.\n");
		 x=getchar();
		 c=getchar();
		 if(c=='y'||c=='Y')
		 {
			 for(p=stu;p<stu+t;p++)
				 *p=*(p+1);
			 t--;
		printf("ϵͳ��Ϊ��ɾ����Ϣ���밴���������.\n");
			 getch();
			 enter();
		 }
		 if(c=='n'||c=='N')
		 {
			 printf("ɾ����Ϣȡ���������������.\n");
			 getch();
			 enter();
		 }
  }
  void amend()                         /*ѧ����Ϣ���޸�*/
  {
	  long j;
	  int i,z,r=t;
	  char c,d,e,f,q,u,l,v,m,k,h1,h2,h3,h4;
	  struct student *p;
	  system("cls");
	  printf("\n\t\t\t�޸�ѧ����Ϣ\n");
	  printf(" ������Ҫ�޸�ѧ����ѧ��:\n\n");
	  scanf("%ld",&j);
	  for(p=stu;p<stu+t;p++)
		  if(p->num==j)
			  break;
		  else
			  r--;
		  if(r==0)
		  {
	printf("�������ѧ��������,�밴���������.\n");
			  getch();
			  enter();
		  }
		  printf("\n ��Ҫ�޸ĵ�ѧ��Ϊ:\n");
		  printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","ѧ��","����","�Ա�","����","���� ","��ѧ","Ӣ��","ƽ����","�ܷ�");
		  printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
		  for(j=0;j<3;j++)
			  printf("%-8d",p->score[j]);
		  printf("%-8d",p->ave);
		  printf("%-8d",p->sum);
		printf("\n\n �Ƿ�Ҫ�޸�ѧ��:���밴 y;�����밴 n.\n\n");
		  l=getchar();
		  c=getchar();
		  if(c=='y'||c=='Y')
		  {
			  printf("��������ȷ��ѧ�ţ�\n\n");
			  scanf("%ld",&p->num);
		  }
		  if(c=='n'||c=='N')
			  z=1;
	printf("�Ƿ�Ҫ�޸����������밴 y;�����밴 n.\n\n");
		  q=getchar();
		  d=getchar();
		  m=getchar();
		  if(d=='y'||d=='Y')
		  {
			  printf("��������ȷ��������\n");
			  scanf("%s",p->name);
			 u=getchar();
		  }
		  if(d=='n'||c=='N')
			  z++;
	printf("\n �Ƿ�Ҫ�޸��Ա����밴 y;�����밴n.\n\n");
		  e=getchar();
		  k=getchar();
		  if(e=='y'||e=='Y')
		  {
			  printf("��������ȷ���Ա�\n");
			  scanf("%s",p->sex);
		  }
		  if(e=='N'||e=='n')
			  z++;
		  printf("\n �Ƿ�Ҫ�޸ĵ��������밴 y;�����밴 n.\n\n");
		  h3=getchar();
		  h4=getchar();
		  if(h3=='y'||h3=='Y')
		  {
			  printf("��������ȷ�ĵ�����\n");
			  scanf("%s",p->address);
		  }
		  if(h3=='N'||h3=='n')
			  z++;
	printf("\n �Ƿ�Ҫ�޸����ųɼ������밴 y;�����밴 n.\n\n");
		  f=getchar();
		  if(f=='y'||f=='Y')
		  {
			  printf("��������ȷ�����ųɼ���");
			  for(i=0;i<3;i++)
				  scanf("%d",&p->score[i]);
			  p->sum = p->score[0] + p->score[1] + p->score[2];
			  p->ave = p->sum/3;
		  }
		  v=getchar();
		  if(f=='n'||f=='N')
		  {
			  printf("�밴���������.\n");
			  getch();
			  enter();
		  }
}
void preside()                         /*ѧ����Ϣ��ͳ��*/
{
	int i,j,o=0,b=10,r=60;
	struct student *p;
	system("cls");
	printf("\n\t\t\t ѧ����Ϣͳ��.\n");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","ѧ��","����","�Ա�","����","���� ","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
				 printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","ѧ��","����","�Ա�","����","���� ","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
		 printf("\n\n �������е��˶�ͨ������.\n\n");
	 else if(b<10)
		printf("\n ����Ϊ�������ͬѧ,ȫ�಻���������Ϊ��%d ��.\n\n",o);
	 printf("\n");
	 printf("ͳ�����,�밴���������.\n");
	 getch();
	enter();

 }
 void fint()                      /*����ѧ����Ϣ*/
 {
	 int i,j=t;
	 long num_a;
	 struct student *p;
	 char a,b;
	 system("cls");
	 printf("\n\t\t\t����ѧ����Ϣ\n");
	 printf("\t\t\t ������Ҫ���ҵ�ѧ��ѧ��:\n");
	 scanf("%ld",&num_a);
	 for(p=stu;p<stu+t;p++)
	 {
		 j--;
		 if(p->num==num_a)
			 break;
		 if(j==0)
		 {
			 printf("�����ڸ�ѧ��,�밴���������.\n\n");
			 a=getchar();
			 getch();
			 enter();
		 }
	 }
	 printf("\n ��Ҫ���ҵ�ѧ��Ϊ:\n\n");
	            printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n\n","ѧ��","����","�Ա�","����","���� ","��ѧ","Ӣ��","ƽ����","�ܷ�");
 	 printf("%-8ld%-8s%-8s%-8s",p->num,p->name,p->sex,p->address);
	 for(i=0;i<3;i++)
		 printf("%-8d",p->score[i]);
	 printf("%-8d",p->ave);
	 printf("%-8d",p->sum);
	 printf("\n\n �������,�밴���������.");
	 b=getchar();
	 getch();
	 enter();

 }
 void output()                     /*�˳�ϵͳ*/
 {
	 system("cls");
	 exit(0);
 }

