#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<ctype.h>
#include<string>
#include<list>
#include<iterator>
#include<algorithm>
#define KEY1 "111111"
#define KEY2 "666666"
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define  TITLE  "ѧ����Ϣ����ϵͳ"
#define  AUTHOR "����: b257"
#define  DATE   "����:2018��3��27��"
#define PRINT_HELP cout<<"\t\t\t\t        __  __________    ____     \n""\t\t\t\t       / / / / ____/ /   / __ \    \n""\t\t\t\t      / /_/ / __/ / /   / /_/ /    \n" "\t\t\t\t     / __  / /___/ /___/ ____/     \n" "\t\t\t\t    /_/ /_/_____/_____/_/          "<<endl;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
using namespace std;

enum { //�����������ҵ�ö������
    UP = 72,
    DOWN = 80 ,
    LEFT = 75 ,
    RIGHT = 77 ,
    ENTER = 13 ,
    ESC = 27 ,
};
//Ŀ¼һ ��ʦ�Ľ���
const char *menu_1[] = {
    " ���                    �༶�ɼ�¼��                   ���",
    " ���                    �༶�ɼ�����                   ���",
    " ���                    �༶�ɼ�չʾ                   ���",
    " ���                    �༶�ɼ�ɾ��                   ���",
    " ���                    �༶�ɼ���ѯ                   ���",
    " ���                    �˳�                           ���",

};
//�����ѡ�����
const char *menu_2[] = {
    "1.��ѧ������",
    "2.����������",
    "3.���Ա�����",
    "4.����������",
    "5.����������",
    "6.����ѧ����",
    "7.��Ӣ������",
    "8.���ܷ�����",
    "9.��ƽ��������",
    "10.�˳�ϵͳ",
};
//�޸���Ϣ��ѡ�����
const char *menu_3[] = {
    "1.ѧ��",
    "2.����",
    "3.�Ա�",
    "4.����",
    "5.����",
    "6.��ѧ",
    "7.Ӣ��",
    "8.�˳�",
};
//���ݵ�ѡ�����
const char *menu_4[] = {
    "1.����",
    "2.�ָ�",
    "3.�˳�",
};
//ѧ����ѡ�����
const char *menu_5[] = {
    " ���                   1 �༶�ɼ���ʾ                   ���",
    " ���                   2 �༶�ɼ�����                   ���",
    " ���                   3 �˳�                           ���",
};
const char *menu_6[] = {
    " ��ʦ",
    " ѧ��",
};
struct student {                               /*����ѧ���ṹ��*/
    int  num;                                      //ѧ��
    char name[20] ;                                 //ѧ������
    char sex;                                  //ѧ���Ա�(���޸�Ϊһ���ַ�)
    char address[21];
    double score[3];                                 //ѧ���ɼ� ����������
    double sum;                                      //�ܷ�
    double ave;                                       //ƽ����
    char minzu[15];                                //����
    int age;                                        //����
    struct student *next;
};
struct ROLL {
    FILE *roll_back;
    int reset_flag;//�����Ƿ�Ϊ��
    int reset_year;
    int reset_month;
    int reset_day;
    int reset_hour;
    int reset_min;
    int reset_sec;
} Back[4];
//����������
int ii;
int bfb;
char b = '>';
char c = '%';
//��������������
int Exit_flag = 1;
//int Out_put_num;
//����ṹ��
CONSOLE_CURSOR_INFO cci;
//����Ĭ�ϵ�����λ��
COORD pos = {0,0};
char password[20];//���������õ�������
struct student *head = NULL, *prev = NULL, *tail = NULL;
//���ı��ļ��ж�ȡ�����Լ����ݵ���Ϣ
void s_Init(int init_choice);
void s_Write(int write_choice);
void s_Add(void);
void s_Fix(void);
void s_Fix_detail(struct student *Fix_stu);
void s_Del(void);

void s_Search(void);//glame
void s_Sort(void);//glame

void s_Find_tail(void);
void s_Statistic(void);
void s_Reset(void);
void s_xiaohui(void);//��ӡ��У��
void showmenu(HANDLE hOut ,const char **menu , int size , int index);//��ʾ���˵�
void Password(const char * PW_SAVED);//����


void s_Help(void);
void s_Exit(void);


int (*sort_fc_head)(struct student *A, struct student *B);

int sort_order;

void search_init(void) ;

int cmp1(struct student *A, struct student *B);
int cmp2(struct student *A, struct student *B);
int cmp3(struct student *A, struct student *B);
int cmp4(struct student *A, struct student *B);
int cmp5(struct student *A, struct student *B);
int cmp6(struct student *A, struct student *B);
int cmp7(struct student *A, struct student *B);
int cmp8(struct student *A, struct student *B);
int cmp9(struct student *A, struct student *B);


struct student *search_p_head = NULL;
struct student *search_p_tail = NULL;

void search_add(const struct student *search_p_add);
void search_delete(struct student *search_p_del);



int  get_userinput(int *index , int size);//��ȡ�û�����Ľӿ�






const char  *term[10] = {
    "ѧ��",
    "����",
    "�Ա�",
    "����",
    "����",
    "��ѧ",
    "Ӣ��",
    "�ܷ�",
    "ƽ����",
};
/*ȥ��꺯��*/
void no_text_cursor(void);
void gotoxy(int x, int y);
void showmenu_2(HANDLE hOut ,const char **menu , int size , int index);
void showmenu_3(HANDLE hOut ,const char **menu , int size , int index);

class Student
{
public:
    Student();
    Student(int n,int g,string na,char se,string ad,double sc1,double sc2,double sc3,string mi,int ag)
    {
        num=n;
        group=g;
        name=na;
        sex=se;
        address=ad;
        score[0]=sc1;
        score[1]=sc2;
        score[2]=sc3;
        minzu=mi;
        age=ag;
    }
    void set_Num(int mynum);
    void set_Group(int mygroup);
    void set_Password(string mypassword);
    void set_Sex(char mysex);
    void set_Name(string myname);
    void set_Address(string myaddress);

    //������ֻ��Ҫ���Ʒ����Ϳ��Լ���
    void set_Sum();
    void set_Ave();

    void set_Minzu(string myminzu);
    void set_Age(int myage);
    void set_Score1(double myscore1);
    void set_Score2(double myscore2);
    void set_Score3(double myscore3);

    int get_Num();
    int get_Group();
    char get_Sex();
    string get_Name();
    string get_Address();
    double get_Sum();
    double get_Ave();
    string get_Minzu();
    int get_Age();
    double get_Score1();
    double get_Score2();
    double get_Score3();
    static int get_Classsize();
private:
    int  num;
    int  group;
    string password;
    string name;
    char sex;
    string address;
    double score[3];
    double sum;
    double ave;
    string minzu;
    int age;
    static int class_size;
};
/*The list*/
list<Student> Group;

int search_choice_arr[6];
int search_choice;
void search_init(void);
int(*sea[9])(list<Student>::iterator sea_cur, const char *s);

int Student::class_size=0;
int Student::get_Classsize()
{
    return class_size;
}
Student::Student()
{
    class_size++;
}
int Student::get_Num()
{
    return num;
}
int Student::get_Group()
{
    return group;
}
char Student::get_Sex()
{
    return sex;
}
string Student::get_Name()
{
    return name;
}
string Student::get_Address()
{
    return address;
}
double Student::get_Sum()
{
    set_Sum();
    return sum;
}
double Student::get_Ave()
{
    set_Ave();
    return ave;
}
string Student::get_Minzu()
{
    return minzu;
}
int Student::get_Age()
{
    return age;
}
double Student::get_Score1()
{
    return score[0];
}
double Student::get_Score2()
{
    return score[1];
}
double Student::get_Score3()
{
    return score[2];
}
void Student::set_Num(int mynum)
{
    num=mynum;
}
void Student::set_Group(int mygroup)
{
    group=mygroup;
}
void Student::set_Sex(char mysex)
{
    sex=mysex;
}
void Student::set_Password(string mypassword)
{
    password=mypassword;
}
void Student::set_Name(string myname)
{
    name=myname;
}
void Student::set_Address(string myaddress)
{
    address=myaddress;
}
void Student::set_Sum()
{
    int Sum_sum=0;
    for(int i=0; i<3; i++)
        Sum_sum+=score[i];
    sum=Sum_sum;
}
void Student::set_Ave()
{
    double Ave_sum=0;
    for(int i=0; i<3; i++)
        Ave_sum+=score[i];
    ave=Ave_sum/3.0;
}
void Student::set_Minzu(string myminzu)
{
    minzu=myminzu;
}
void Student::set_Age(int myage)
{
    age=myage;
}
void Student::set_Score1(double myscore1)
{
    score[0]=myscore1;
}
void Student::set_Score2(double myscore2)
{
    score[1]=myscore2;
}
void Student::set_Score3(double myscore3)
{
    score[2]=myscore3;
}
void Pr(Student &pr_tmp)
{
    cout<<pr_tmp.get_Num()<<endl;
}
void s_Init(void);
void s_Add(void);
list<Student>::iterator s_Check(int Check_num);
void s_Output(list<Student>::iterator Fix_stu, int Out_flag);
void s_Del(void);
void s_Exit(int &Exit_flag)
{
    Exit_flag=0;
}


list<Student> Sea_Group;
void s_Sort(void);
bool cmp1(Student &cmp_a,Student &cmp_b);//ѧ��
bool cmp2(Student &cmp_a,Student &cmp_b);//����
bool cmp3(Student &cmp_a,Student &cmp_b);//�Ա�
bool cmp4(Student &cmp_a,Student &cmp_b);//����
bool cmp5(Student &cmp_a,Student &cmp_b);//����
bool cmp6(Student &cmp_a,Student &cmp_b);//����
bool cmp7(Student &cmp_a,Student &cmp_b);//��ɢ
bool cmp8(Student &cmp_a,Student &cmp_b);//�ܷ�
bool cmp9(Student &cmp_a,Student &cmp_b);//����

bool cmp1(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Num() < cmp_b.get_Num();
}
bool cmp2(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Name() < cmp_b.get_Name();
}
bool cmp3(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Sex() < cmp_b.get_Sex();
}
bool cmp4(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Minzu() < cmp_b.get_Minzu();
}
bool cmp5(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Score1() < cmp_b.get_Score1();
}
bool cmp6(Student &cmp_a,Student &cmp_b)
{
    return (cmp_a.get_Score2() < cmp_b.get_Score2());
}
bool cmp7(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Score3() < cmp_b.get_Score3();
}
bool cmp8(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Sum() < cmp_b.get_Sum();
}
bool cmp9(Student &cmp_a,Student &cmp_b)
{
    return cmp_a.get_Ave() < cmp_b.get_Ave();
}

bool (*sort_p[10])(Student &cmp_a,Student &cmp_b);


/*The list*/





void s_Init(void);
void s_Add(void);
list<Student>::iterator s_Check(int Check_num);
void s_Output(list<Student>::iterator Fix_stu, int Out_flag);
void s_Del(void);

void s_Sort(void);
bool cmp1(Student &cmp_a,Student &cmp_b);//ѧ��
bool cmp2(Student &cmp_a,Student &cmp_b);//����
bool cmp3(Student &cmp_a,Student &cmp_b);//�Ա�
bool cmp4(Student &cmp_a,Student &cmp_b);//����
bool cmp5(Student &cmp_a,Student &cmp_b);//����
bool cmp6(Student &cmp_a,Student &cmp_b);//����
bool cmp7(Student &cmp_a,Student &cmp_b);//��ɢ
bool cmp8(Student &cmp_a,Student &cmp_b);//�ܷ�
bool cmp9(Student &cmp_a,Student &cmp_b);//����



//��ʼ������

//�˳�����
void s_Exit(void) {
    Exit_flag = 0;
}

void s_Init(void)
{
    sort_p[1] = cmp1;
    sort_p[2] = cmp2;
    sort_p[3] = cmp3;
    sort_p[4] = cmp4;
    sort_p[5] = cmp5;
    sort_p[6] = cmp6;
    sort_p[7] = cmp7;
    sort_p[8] = cmp8;
    sort_p[9] = cmp9;
    Student a(20174598,7,"���˷�",'m',"����",90,70,60,"��",18);
    Student b(20174626,7,"�ֶ�Ծ",'m',"����",80,100,60,"��",19);
    Student c(20174448,7,"����",'m',"����",100,100,100,"��",18);
    Student d(20170000,0,"�ϴ�",'f',"����",60,60,60,"��",17);
    Student e(20171000,1,"Τ����",'m',"����",70,70,70,"����",19);
    Student f(20172000,2,"����",'m',"�ӱ�",100,80,90,"��",18);
    Group.push_back(a);
    Group.push_back(b);
    Group.push_back(c);
    Group.push_back(d);
    Group.push_back(e);
    Group.push_back(f);

}
void s_Add(void)
{

    string password_1;
    string password_2;
    int Add_num, Add_flag = 1;
    do
    {
        Add_flag=0;
        cout<<"������ѧ����ѧ��"<<endl;//���뷶Χ��
        cin>>Add_num;
        getchar();
        if(s_Check(Add_num)!=Group.end())
        {
            cout<<"��ѧ���Ѵ��ڣ�"<<endl;
            Add_flag = 1;
        }
    }
    while(Add_flag);

    Student Add_stu;
    Add_stu.set_Num(Add_num);



    cout<<"������ѧ���İ༶"<<endl;
    int Add_group;
    cin>>Add_group;
    Add_stu.set_Group(Add_group);

    cin.get();
    cout<<"������ѧ��������"<<endl;
    string Add_name;
    getline(cin,Add_name);
    Add_stu.set_Name(Add_name);

    cout<<"������ѧ�����Ա�(����Ϊ'm',Ů��Ϊ'f')"<<endl;
    char Add_sex;
    cin>>Add_sex;
    Add_stu.set_Sex(Add_sex);

    cout<<"������ѧ��������"<<endl;
    int Add_age;
    cin>>Add_age;
    Add_stu.set_Age(Add_age);

    cin.get();
    cout<<"������ѧ���ļ�ͥסַ(ʡ)"<<endl;
    string Add_address;
    getline(cin,Add_address);
    Add_stu.set_Address(Add_address);

    cout<<"������ѧ��������"<<endl;
    string Add_minzu;
    getline(cin,Add_minzu);
    Add_stu.set_Minzu(Add_minzu);

    cout<<"������ѧ���� ������������ɢ�ɼ�"<<endl;
    int Add_s1,Add_s2,Add_s3;
    cin>>Add_s1>>Add_s2>>Add_s3;
    Add_stu.set_Score1(Add_s1);
    Add_stu.set_Score2(Add_s2);
    Add_stu.set_Score3(Add_s3);

    Group.push_back(Add_stu);
}

list<Student>::iterator s_Check(int Check_num)
{
    list<Student>::iterator Check_p;
    Check_p=Group.begin();
    while(Check_p!=Group.end())
    {
        if((*Check_p).get_Num()==Check_num)
            break;
        Check_p++;
    }
    return Check_p;
}

void s_Output(list<Student>::iterator Fix_stu, int Out_flag)
{

    if(Fix_stu == Group.end())
    {
        printf("��ϢΪ�գ�\n");
        return ;
    }
    cout<<"�����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T��"<<endl;
    cout<<"ѧ��       ����      �Ա�     ����       ����       ��ѧ       Ӣ��       �ܷ�       ƽ����     "<<endl;
    switch(Out_flag)
    {
    case 1:
        while(Fix_stu != Group.end())
        {
            cout<<setiosflags(ios::left)<<setw(11)<<(*Fix_stu).get_Num()
                <<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Name()
                <<setiosflags(ios::left)<<setw(9)<<(*Fix_stu).get_Sex()
                <<setiosflags(ios::left)<<setw(11)<<(*Fix_stu).get_Minzu()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score1()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score2()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score3()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Sum()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Ave()
                <<endl;

            Fix_stu ++;
        }
        break;
    case 0:
        cout<<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Num()
            <<setiosflags(ios::left)<<setw(9)<<(*Fix_stu).get_Name()
            <<setiosflags(ios::left)<<setw(5)<<(*Fix_stu).get_Sex()
            <<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Minzu()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score1()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score2()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score3()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Sum()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Ave();
        break;
    }
}

void s_Output_sea(list<Student>::iterator Fix_stu, int Out_flag)
{

    if(Fix_stu == Sea_Group.end())
    {
        printf("��ϢΪ�գ�\n");
        return ;
    }
    cout<<"�����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T��"<<endl;
    cout<<"ѧ��       ����      �Ա�     ����       ����       ��ѧ       Ӣ��       �ܷ�       ƽ����     "<<endl;
    switch(Out_flag)
    {
    case 1:
        while(Fix_stu != Sea_Group.end())
        {
            cout<<setiosflags(ios::left)<<setw(11)<<(*Fix_stu).get_Num()
                <<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Name()
                <<setiosflags(ios::left)<<setw(9)<<(*Fix_stu).get_Sex()
                <<setiosflags(ios::left)<<setw(11)<<(*Fix_stu).get_Minzu()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score1()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score2()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Score3()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Sum()
                <<setiosflags(ios::left)<<setw(11)<<setiosflags(ios::fixed)<<setprecision(2)<<(*Fix_stu).get_Ave()
                <<endl;

            Fix_stu ++;
        }
        break;
    case 0:
        cout<<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Num()
            <<setiosflags(ios::left)<<setw(9)<<(*Fix_stu).get_Name()
            <<setiosflags(ios::left)<<setw(5)<<(*Fix_stu).get_Sex()
            <<setiosflags(ios::left)<<setw(10)<<(*Fix_stu).get_Minzu()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score1()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score2()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Score3()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Sum()
            <<setiosflags(ios::left)<<setw(10)<<setprecision(2)<<(*Fix_stu).get_Ave();
        break;
    }
}
void s_Del(void)
{
    int Del_num;
    if(!Group.empty())
    {
        system("cls");
        printf("������ɾ����ѧ�ţ�\n");
        cin>>Del_num;
        cin.get();
        list<Student>::iterator Del_stu = s_Check(Del_num);
        if(Del_stu == Group.end())
        {
            printf("���޴��ˣ����������룡\n");
            getchar();
        }
        else
        {
            cout<<"��ȷ��Ҫɾ���� "<<(*Del_stu).get_Num()<<(*Del_stu).get_Name()<<"������Ϣ��\n������ yȷ�ϣ�������˳���"<<endl;
            char Del_flag;
            cin>>Del_flag;
            if(Del_flag == 'y' || Del_flag == 'Y')
            {
                Group.erase(Del_stu);
                printf("ɾ���ɹ���\n");
            }
        }
    }
    else
    {
        printf("���ݿ�Ϊ�գ������������ѡ�����\n");
        getchar();
        return ;
    }
}

void s_Sort(void)
{
    cout<<"��������������"<<endl;
    for(int i=0;i<10;i++)
    {

        cout<<menu_2[i]<<endl;
    }
    int Sort_choice;
    cin>>Sort_choice;
    cout<<"0.���� 1.����"<<endl;
    bool Sort_order;
    cin>>Sort_order;
    Group.sort(sort_p[Sort_choice]);
    if(Sort_order)
        Group.reverse();
}

//���뺯��
void Password(const char * PW_SAVED) {
    /*char password[20];*/
    char ch;//����ı������ʱ������ֵ
    int i = 0;
    printf("  \nPlease Enter the Password : \n");
    ch = getch();
    while ( (ch & 0xff) != 13) {
        if ( (ch & 0xff) == 8) {
            printf("%c %c",ch,ch);
            i--;
        } else {
            printf("*");
            password[i] = ch;
            i++;
        }
        ch = getch();
    }
    password[i]='\0';
}
void s_Output(list<Student>::iterator Fix_stu, int Out_flag);
void s_xiaohui(void) {
    printf("                                              `.,:::;;;:;;;';::,,.`                                            \n");
    printf("                                        .:;;:,.                   `.,;;:.                                      \n");
    printf("                                   `,;'.`  ```,;''''''''''''''''';:.`    `:;:`                                 \n");
    printf("                                `:;`   `,''''''''''''''''''''''''''''''':` `  :'.    `                         \n");
    printf("                              `::   `:''''''''''''''''''''''''''''''''''''''';` ` ,'.                          \n");
    printf("                            ,:`  .'''''''''''''''''''''''''''''''''''''''''''''';.   ,:                        \n");
    printf("                          ::   :+''''''''''''''''''''''''+;'''''''''''''''''''''''';` `,;`                     \n");
    printf("                        ::  `;'''''''''''''''''''''''''''` .''''''''''''''''''''''''';.  ,'`                   \n");
    printf("                      ,;` `;+'''''''''''''''''''''''''''     '''''''''''''''''''''''''''.  ::                  \n");
    printf("                     '.  :'''''''''''''';,'''''''''''';       ;'''''''''''',;'''''''''''';` `'`                \n");
    printf("                   .'  `''''''''''''''',   .''''''''':         :'''''''''.   ,''''''''''''',  :,               \n");
    printf("                  .;  ,+''''''''''''''       .''''''.           .''''''.      `''''''''''''';  ,;              \n");
    printf("                 ,:  ;'''''''''''''':          `'''`             `'''`          ''''''''''''''  .;             \n");
    printf("                .;  :'''''''''''''+`             `                 `             ,'''''''''''''  .;            \n");
    printf("               `'  ,''''''''''''':                                                `'''''''''''''  ;,           \n");
    printf("               '` .'''''''''''''.                                                   :''''''''''':  '`          \n");
    printf("              .:  +''''''''''';                                                      .+''''''''''` `;          \n");
    printf("              '  ,'''''''''''.                                                         '''''''''''  '`         \n");
    printf("              '  '''''''''';`                                                           :'''''''''` ,,         \n");
    printf("           ` ,, `''''''''',                                                              .''''''''.  ;         \n");
    printf("             ;` .''''''''                                                                  ;'''''';  '         \n");
    printf("             ;` ,'''''':                                                                    ,''''''  '         \n");
    printf("             ;` .'''''`                                                                      `'''''  '         \n");
    printf("             :. `''':                                                                          ;'';  '         \n");
    printf("             `;  ''.                                                                            .'` .:         \n");
    printf("              '  :            .,:;;'''''''''''';;,,.`                                             ` ;`         \n");
    printf("              :,         ,;'''''''''''''''''''''''''''';:`                                       .  ;          \n");
    printf("               '     .;'''''''';:,.``          ``.:;;''''''';.`                             ` .:'  ,`          \n");
    printf("               .:  ''''''';.`     ```,,,:;;;:,,,`      `,;''''''';,```                ``,;''''''. `,           \n");
    printf("                :. `'';`     ,''''''''''''''''''''''';,     `,'''''''''''++++++++'''''''''''''',  ;            \n");
    printf("                ,  `   `'''''''''''''';;;;;;;;''+'''''''';``    `,;''+'''''''''''''''+';:``   ` '              \n");
    printf("                  ,`  '''''''';:``                  ``:;'''''';;.`       `````````        `.:.  '`             \n");
    printf("                   ,.  '+':``    .,;;'''''''''''';:,`     '''''''''''';;;,,,,,,,,,,;;;''''''. `'`              \n");
    printf("                   .:  ``  .,''''''''''''''''''''''''';,.`''' .:;'''''''''''''''''''''''';  ,;                 \n");
    printf("                     `'`  :'''''''';::,.````````.,,:;''''''''';       ,,::::;;;;;:::,:.``` `;.                 \n");
    printf("                       ,;` `''':.       ````..```       .:'''''''':,.`                .`  :;                   \n");
    printf("                         ,:` `   .,;''+'''''''''''''':,` `  ,'''''''''''''''''+''''''.  ,;                     \n");
    printf("                           .:`  ,''''''''''''''''''''''''+;.`'''` `,,;;''''''''''';` `:;                       \n");
    printf("                             `',  `:''''''''''''''''''''''''''''+`             ``` .'.                         \n");
    printf("                                .':   .;''''''''''''''''''''''''''''''''''';`   ,':`                           \n");
    printf("                                   .:;,   `,;'+''''''''''''''''''''''';,``  .;;.                               \n");
    printf("                                      `.,;;,`   ``.,,;;;;;;;;;,,.``    .:;:.`                                  \n");
    printf("                                            `.;;:;:...```````...:;;;;,``                                       \n");
    printf("                                                     `````````                                                 \n");
    gotoxy(23, 45);
    printf("[");
    gotoxy(87, 45);
    printf("]");
    for(ii = 25; ii <= 85; ii++) {
        gotoxy(ii, 45); /*Ϊ�����ڽ������Ͱٷֱ�֮��䶯*/
        no_text_cursor();
        Sleep(8);/*ǰ������delay��Ϊ���ù������ÿ�������*/
        printf("%c", b);
        Sleep(8);
        gotoxy(45, 47); /*Ϊ�����ڽ������Ͱٷֱ�֮��䶯*/
        bfb = ((ii * 10) / 8.5);
        printf("[ %d", bfb);
        gotoxy(50, 47);
        printf("%% ]");
    }
    gotoxy(40, 48);
    printf("Loading Successful!");
}
int  get_userinput(int *index , int size)//��ȡ�û�����Ľӿ�

{
    int ch ;
    ch = getch();
    switch(ch) {
    //��
    //���ѡ���ϣ���ô��������ƶ�
    case UP :
        if(*index > 0)  *index -= 1 ;
        break;
    //��
    //���ѡ���£���ô��������ƶ�
    case DOWN :
        if(*index < size -1)  *index += 1 ;
        break;
    //��
//    case LEFT:
    case 97:
        return 0 ;
    //��
//    case RIGHT:
//        return 0 ;
    //�س�
    case ENTER:
        return ENTER ;
    //ESC
    case ESC:
        return ESC ;
    }
    return 0 ;
}
void showmenu(HANDLE hOut ,const char **menu , int size , int index) {
    int i ;
    system("cls");
    //������ʾ���ı�����ɫ
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);
    //��ʼ������̨��ʾ��X,Y�������
    pos.X = 52;
    pos.Y = 0 ;
    //������ʾ������̨�ն˵ľ���λ��
    SetConsoleCursorPosition(hOut,pos);
    for(i = 0 ; i < size ; i++) {
        //���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
        //���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ�������
        if(i == index) {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);
            printf("%s",menu[i]);
        }
        //������ʾΪ��ɫ
        else {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);    //���ù������
            printf("%s",menu[i]);
        }
    }
    //ˢ�±�׼���������
    fflush(stdout);
}
void showmenu_2(HANDLE hOut ,const char **menu , int size , int index) {
    int i ;
    system("cls");
    int  roll_i;
    for(roll_i = 1; roll_i < 4; roll_i++) {
        gotoxy(0,roll_i);
        printf("�浵%d�� ", roll_i);
        if(Back[roll_i].reset_flag == 0) {
            gotoxy(28,roll_i);
            printf("��\n");
        } else {
            gotoxy(28,roll_i);
            printf("%d/%d/%d %02d:%02d:%02d\n", Back[roll_i].reset_year, Back[roll_i].reset_month, Back[roll_i].reset_day, Back[roll_i].reset_hour, Back[roll_i].reset_min, Back[roll_i].reset_sec);

        }
    }
    //������ʾ���ı�����ɫ
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);
    //��ʼ������̨��ʾ��X,Y�������
    pos.X = 52;
    pos.Y = 0 ;
    //������ʾ������̨�ն˵ľ���λ��
    SetConsoleCursorPosition(hOut,pos);
    for(i = 0 ; i < size ; i++) {
        //���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
        //���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ�������
        if(i == index) {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);
            printf("%s",menu[i]);
        }
        //������ʾΪ��ɫ
        else {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);    //���ù������
            printf("%s",menu[i]);
        }
    }
    //ˢ�±�׼���������
    fflush(stdout);
}
void showmenu_3(HANDLE hOut ,const char **menu , int size , int index) {
    int i ;
    //������ʾ���ı�����ɫ
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);
    //��ʼ������̨��ʾ��X,Y�������
    pos.X = 52;
    pos.Y = 0 ;
    //������ʾ������̨�ն˵ľ���λ��
    SetConsoleCursorPosition(hOut,pos);
    for(i = 0 ; i < size ; i++) {
        //���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
        //���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ�������
        if(i == index) {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);
            printf("%s",menu[i]);
        }
        //������ʾΪ��ɫ
        else {
            //��ɫ
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pos.X = 30;
            pos.Y = 5+i;
            //���ù������
            SetConsoleCursorPosition(hOut,pos);    //���ù������
            printf("%s",menu[i]);
        }
    }
    //ˢ�±�׼���������
    fflush(stdout);
}
void no_text_cursor(void) {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y) { //��λ����y�еĵ�x��

    HANDLE hOutput;
    COORD loc;
    loc.X = x;
    loc.Y=y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
    return;
}

int sea1(list<Student>::iterator sea_cur, const char *s) {
    char sea_num[15];
    itoa((*sea_cur).get_Num(), sea_num, 10);
    return strstr(sea_num, s) == NULL;
}

int sea2(list<Student>::iterator sea_cur, const char *s) {
    return strstr((*sea_cur).get_Name().c_str(), s) == NULL;
}

int sea3(list<Student>::iterator sea_cur, const char *s) {
    char sea_sex[15];
    sprintf(sea_sex, "%c", (*sea_cur).get_Sex());
    return strstr(sea_sex, s) == NULL;
}

int sea4(list<Student>::iterator sea_cur, const char *s) {

    return strstr((*sea_cur).get_Minzu().c_str(), s) == NULL;
}

int sea5(list<Student>::iterator sea_cur, const char *s) {
    char sea_score0[15];
    sprintf(sea_score0, "%-10.2lf", (*sea_cur).get_Score1());
    return strstr(sea_score0, s) == NULL;
}

int sea6(list<Student>::iterator sea_cur, const char *s) {
    char sea_score1[15];
    sprintf(sea_score1, "%-10.2lf", (*sea_cur).get_Score2());
    return strstr(sea_score1, s) == NULL;
}

int sea7(list<Student>::iterator sea_cur, const char *s) {
    char sea_score2[15];
    sprintf(sea_score2, "%-10.2lf", (*sea_cur).get_Score3());
    return strstr(sea_score2, s) == NULL;
}

int sea8(list<Student>::iterator sea_cur, const char *s) {
    char sea_sum[15];
    sprintf(sea_sum, "%-10.2lf", (*sea_cur).get_Sum());
    return strstr(sea_sum, s) == NULL;
}

int sea9(list<Student>::iterator sea_cur, const char *s) {
    char sea_ave[15];
    sprintf(sea_ave, "%-10.2lf", (*sea_cur).get_Ave());
    return strstr(sea_ave, s) == NULL;
}
void s_Search(void) {
    char ch;
    int return_flag=1;
    search_choice = 0;
    cout<<"��ѯ��ʽ��"<<endl;
    cout<<"1.ѧ��\n2.����\n3.�Ա�\n4.����\n5.����\n6.��ѧ\n7.Ӣ��\n8.�ܷ�\n0��9�˳�\n������ϲ�ѯ�������Կո�����"<<endl;
    int search_num = 0;
    while((ch = getchar()) && ch != '\n') {
        if(ch=='9'||ch=='0') {
            return_flag=0;
            break;
        }
        if(!isdigit(ch))
            continue;
        else {
            search_choice_arr[search_num] = ch - 48;
            search_num++;
        }
    }
    search_init();
    //   s_Output(search_p_head);
    if(return_flag) {
        for(int search_temp_i = 0; search_temp_i < search_num; search_temp_i++) {
            //�������в��û����Ѿ�ͨ����
            printf("������%s����Ϣ\n", term[search_choice_arr[search_temp_i] - 1]);

            //�Ƿ���Խ�����atof/atoi ת�����������ıȽ���δ���
            char search_temp[15];
            list<Student>::iterator search_p_temp = Group.begin();
            list<Student>::iterator search_p_temp_next = Group.begin();
			cin>>search_temp;
            while(search_p_temp != Group.end() ) {
                search_p_temp_next++;
                if(sea[search_choice_arr[search_temp_i]](search_p_temp, search_temp)) {
                    Sea_Group.erase(search_p_temp);
                }
                search_p_temp = search_p_temp_next;
            }

        }
        swap(Sea_Group,Group);
		s_Output_sea(Sea_Group.begin(),1);
		cin.get();

    }
}

//���𴴽���ѯ����ͳ�ʼ������ָ��
void search_init(void) {
    if(!Group.empty()) {
        Sea_Group=Group;

    } else
        printf("����Ϊ�գ�����\n");
        sea[1] = sea1;
    sea[2] = sea2;
    sea[3] = sea3;
    sea[4] = sea4;
    sea[5] = sea5;
    sea[6] = sea6;
    sea[7] = sea7;
    sea[8] = sea8;
    sea[9] = sea9;
}



int main() {
    system("color 0A");
    s_Init();
    s_xiaohui();
    getch();
    system("cls");
    system("color 0A");
    puts("\t\t\t����������������������������������������������������������������������������������������������������������������");
    puts("\t\t\t                ��ӭ����ѧ���ɼ�����ϵͳ\n");
    int ret ;
    int i_index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(TITLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hOut, &cci);
    cci.dwSize = 1;
    cci.bVisible =  0;
    SetConsoleCursorInfo(hOut, &cci);
    while(1) {
        showmenu_3(hOut , menu_6 , NR(menu_6) , i_index);
        ret = get_userinput(&i_index , NR(menu_6));
        if(ret == ESC)
            break ;
        if(ret == ENTER) {
            if(i_index==0) {
                puts("\n");
                int j;
                for(j=0; j<=2; ++j) { /*��ѭ��ʹֻ�������������*/
                    Password(password);
                    if(strcmpi(password,KEY1)==0) { /*..��ȷʱ�� �����..*/
                        printf("\n����ϵͳ");
                        break;
                    }
                    printf("\n");
                    if(j==3&&strcmp(password,KEY1)!=0) {
                        printf("�����㲻�Ǳ��ˣ����˳�\n");
                        exit(0);
                    }

                }
                int ret ;
                int index = 0 ;
                HANDLE hOut;
                SetConsoleTitleA(TITLE);
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                GetConsoleCursorInfo(hOut, &cci);
                cci.dwSize = 1;
                cci.bVisible =  0;
                SetConsoleCursorInfo(hOut, &cci);
                while(1) {
                    showmenu(hOut , menu_1 , NR(menu_1) , index);
                    ret = get_userinput(&index , NR(menu_1));
                    if(ret == ESC)
                        break ;
                    if(ret == ENTER) {
                        switch(index) {
                        case 0:
                            system("cls");
                            s_Add();
                            break ;   //ѧ����Ϣ���
                case 1:
                            system("cls");
                            s_Sort();
                            break ;   //ѧ����Ϣ����
                        case 2:
                            system("cls");
                            s_Output(Group.begin(),1);
                            break ;   //ѧ����Ϣչʾ
                        case 3:
                            system("cls");
                            s_Del();
                            break ;   //ɾ��ָ��ѧ���ɼ�
                        case 4:
                            system("cls");//��ѯָ��ѧ���ɼ� ����ϲ�ѯ
                            s_Search();
                            break;
                        case 5:
                            system("cls");
                            exit(0);
                            break ;
                        }
                        getchar();
                    }
                }
            }

            else if(i_index==1) {
                puts("\n");
                int j;
                for(j=0; j<=2; ++j) { /*��ѭ��ʹֻ�������������*/
                    Password(password);
                    if(strcmpi(password,KEY2)==0) { /*..��ȷʱ�� �����..*/
                        printf("\n����ϵͳ");
                        break;
                    }
                    printf("\n");
                    if(j==3&&strcmp(password,KEY2)!=0) {
                        printf("�����㲻�Ǳ��ˣ����˳�\n");
                        exit(0);
                    }

                }
                int ret ;
                int index = 0 ;
                HANDLE hOut;
                SetConsoleTitleA(TITLE);
                //��ȡ��ǰ�ľ��---����Ϊ��׼������
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                //��ȡ�����Ϣ
                GetConsoleCursorInfo(hOut, &cci);
                //���ù���С
                cci.dwSize = 1;
                //���ù�겻�ɼ� FALSE
                cci.bVisible =  0;
                //����(Ӧ��)�����Ϣ
                SetConsoleCursorInfo(hOut, &cci);
                while(1) {
                    showmenu(hOut , menu_5 , NR(menu_5) , index);
                    ret = get_userinput(&index , NR(menu_5));
                    if(ret == ESC)
                        break ;
                    if(ret == ENTER) {
                        switch(index) {
                        case 0:
                            system("cls");
                            s_Output(Group.begin(), 1);
                            getch();
                            break ;   //ѧ����Ϣ��ӡ
                        case 1:
                            system("cls");
                            s_Search();
                            getch();
                            break;
                        case 2:
                            system("cls");
                            exit(0);
                            break ;   //ѧ����Ϣ����
                        }
                    }
                }
            }
        }
    }

    return 0;
}


