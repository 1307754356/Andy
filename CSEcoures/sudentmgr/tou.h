#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#define  NUM 20
struct student                                 /*����ѧ���ṹ��*/
{
    int  num;                                      //ѧ��
    char name[20] ;                                 //ѧ������
    char sex;                                  //ѧ���Ա�(���޸�Ϊһ���ַ�)
    char address[20];
    double score[3];                                 //ѧ���ɼ� ����������
    double sum;                                      //�ܷ�
    double ave;                                       //ƽ����
    char minzu[15];                                //����
    int age;                                        //����
    struct student *next;
};
struct ROLL
{
    FILE *roll_back;
    int reset_flag;
    int reset_year;
    int reset_month;
    int reset_day;
    int reset_hour;
    int reset_min;
    int reset_sec;
}Back[4];

int Exit_flag=1;
int Out_put_num;
struct student *head=NULL,*prev=NULL,*tail=NULL;

void s_Init(int init_choice);
void s_Write(int write_choice);
void s_Add(void);
void s_Fix(void);
void s_Fix_detail(struct student *Fix_stu);
void s_Del(void);
void s_clear(struct student *clr_head);//�������

// TODO (����#1#): �����˺�����ʹ֮������Ϊ������ѯ��׼��
void s_Output(struct student *Out_stu);
void s_Search(void);
void s_Sort(void);
struct student  *sortList(struct student *sort_head) ;
struct student  *sortmerge( struct student *sort_head1, struct student *sort_head2);

void s_Find_tail(void);
void s_Statistic(void);
void s_Reset(void); //TODO: �����Ƿ�����


// TODO (����#1#): ��������������ƣ�
void s_Help(void);
void s_Exit(void);


int (*sort_fc_head)(struct student *A,struct student *B);

int sort_order;

struct student* s_Check(int Check_num);//Ƶ�����ã�����Ϊ����
void search_init(void) ;

int cmp1(struct student *A,struct student *B);
int cmp2(struct student *A,struct student *B);
int cmp3(struct student *A,struct student *B);
int cmp4(struct student *A,struct student *B);
int cmp5(struct student *A,struct student *B);
int cmp6(struct student *A,struct student *B);
int cmp7(struct student *A,struct student *B);
int cmp8(struct student *A,struct student *B);
int cmp9(struct student *A,struct student *B);


struct student *search_p_head = NULL;
struct student *search_p_tail = NULL;

void search_add(const struct student *search_p_add);
void search_delete(struct student *search_p_del);


int search_choice_arr[6];
int search_choice;

char  *term[10] = {
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
