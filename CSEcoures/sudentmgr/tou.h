#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
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

struct student *head=NULL,*prev,*tail;

void s_Init(void);
void s_Write(void);
void s_Add(void);
void s_Fix(void);
void s_Fix_detail(struct student *Fix_stu);
void s_Del(void);
void s_Output(struct student *Out_stu);//����
void s_Search(void);
void s_Sort(void);
void s_Statistic(void);
void s_Reset(void);
void s_Help(void);
void s_Exit(void);


