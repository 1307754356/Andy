struct student                                 /*����ѧ���ṹ��*/
    {
        long num;                                      //ѧ��
        char name[20] ;                                 //ѧ������
        char  sex[2];                                  //ѧ���Ա�
        char address[20];                              //ѧ����ͥסַ
        int  score[3];                                 //ѧ���ɼ� ����������
        int  sum;                                      //�ܷ�
        int  ave;                                       //ƽ����
        char minzu[15];                                //����
        int age;                                        //����
        struct student *next;
    };
void Add(void);
void Fix(void);
void Del(void);

void Add(void)
{
    printf("Hello��");

}
void Fix(void)
{
    printf("Hello��");

}
void Del(void)
{
    printf("Hello��");

}
