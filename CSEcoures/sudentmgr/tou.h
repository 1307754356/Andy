#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>

struct student {                               /*定义学生结构体*/
    int  num;                                      //学号
    char name[20] ;                                 //学生姓名
    char sex;                                  //学生性别(刚修改为一个字符)
    char address[20];
    double score[3];                                 //学生成绩 包含有三项
    double sum;                                      //总分
    double ave;                                       //平均分
    char minzu[15];                                //民族
    int age;                                        //年龄
    struct student *next;
};
struct ROLL {
    FILE *roll_back;
    int reset_flag;
    int reset_year;
    int reset_month;
    int reset_day;
    int reset_hour;
    int reset_min;
    int reset_sec;
} Back[4];

int Exit_flag = 1;
int Out_put_num;
struct student *head = NULL, *prev = NULL, *tail = NULL;

void s_Init(int init_choice);
void s_Write(int write_choice);
void s_Add(void);
void s_Fix(void);
void s_Fix_detail(struct student *Fix_stu);
void s_Del(void);
void s_clear(struct student *clr_head);//清空链表

// TODO (孔振华#1#): 修正此函数，使之更加灵活，为后续查询做准备
void s_Output(struct student *Out_stu, int Out_flag);
void s_Search(void);
void s_Sort(void);
struct student  *sortList(struct student *sort_head) ;
struct student  *sortmerge( struct student *sort_head1, struct student *sort_head2);

void s_Find_tail(void);
void s_Statistic(void);
void s_Reset(void); //TODO: 修正非法输入


// TODO (孔振华#1#): 帮助界面该如何设计？
void s_Help(void);
void s_Exit(void);


int (*sort_fc_head)(struct student *A, struct student *B);

int sort_order;

struct student* s_Check(int Check_num);//频繁调用，故另建为函数
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


int search_choice_arr[6];
int search_choice;

int(*sea[9])(struct student *sea_cur,const char *s);


int sea1(struct student *sea_cur,const char *s)
{
    char sea_num[15];
    itoa(sea_cur->num,sea_num,10);
	return strstr(sea_num, s) == NULL;
}

int sea2(struct student *sea_cur,const char *s)
{
	return strstr(sea_cur->name, s) == NULL;
}

int sea3(struct student *sea_cur,const char *s)
{
    char sea_sex[15];
    sprintf(sea_sex,"%c",sea_cur->sex);
	return strstr(sea_sex, s) == NULL;
}

int sea4(struct student *sea_cur,const char *s)
{

	return strstr(sea_cur->minzu, s) == NULL;
}

int sea5(struct student *sea_cur,const char *s)
{
    char sea_score0[15];
    sprintf(sea_score0,"%-10.2lf",sea_cur->score[0]);
	return strstr(sea_score0, s) == NULL;
}

int sea6(struct student *sea_cur,const char *s)
{
    char sea_score1[15];
    sprintf(sea_score1,"%-10.2lf",sea_cur->score[1]);
	return strstr(sea_score1, s) == NULL;
}

int sea7(struct student *sea_cur,const char *s)
{
    char sea_score2[15];
    sprintf(sea_score2,"%-10.2lf",sea_cur->score[2]);
	return strstr(sea_score2, s) == NULL;
}

int sea8(struct student *sea_cur,const char *s)
{
    char sea_sum[15];
    sprintf(sea_sum,"%-10.2lf",sea_cur->sum);
	return strstr(sea_sum, s) == NULL;
}

int sea9(struct student *sea_cur,const char *s)
{
    char sea_ave[15];
    sprintf(sea_ave,"%-10.2lf",sea_cur->ave);
	return strstr(sea_ave, s) == NULL;
}

char  *term[10] = {
    "学号",
    "姓名",
    "性别",
    "民族",
    "语文",
    "数学",
    "英语",
    "总分",
    "平均分",
};
