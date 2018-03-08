#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#define  NUM 20
struct student                                 /*定义学生结构体*/
    {
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

struct student *head=NULL,*prev,*tail;

void s_Init(void);
void s_Write(void);
void s_Add(void);
void s_Fix(void);
void s_Fix_detail(struct student *Fix_stu);
void s_Del(void);
void s_Output(struct student *Out_stu);//待定
void s_Search(void);
void s_Sort(void);
void s_Statistic(void);
void s_Reset(void);
void s_Help(void);
void s_Exit(void);


