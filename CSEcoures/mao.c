struct student                                 /*定义学生结构体*/
    {
        long num;                                      //学号
        char name[20] ;                                 //学生姓名
        char  sex[2];                                  //学生性别
        char address[20];                              //学生家庭住址
        int  score[3];                                 //学生成绩 包含有三项
        int  sum;                                      //总分
        int  ave;                                       //平均分
        char minzu[15];                                //民族
        int age;                                        //年龄
        struct student *next;
    };
void Add(void);
void Fix(void);
void Del(void);

void Add(void)
{
    printf("Hello！");

}
void Fix(void)
{
    printf("Hello！");

}
void Del(void)
{
    printf("Hello！");

}
