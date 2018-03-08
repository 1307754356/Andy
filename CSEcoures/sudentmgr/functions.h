//初始化函数
void s_Init(void) {
    FILE *init_file;
    if((init_file = fopen("stu_data.txt", "rb")) == NULL) {
        printf("Init Error!\n");
        exit(0);
    }
    //判断是否为空
    prev = (struct student*)malloc(sizeof(struct student));
    if(!fread(prev, sizeof(struct student), 1, init_file)) {
        fclose(init_file);
        free(prev);
        prev = NULL;
        return ;
    } else {
        head = prev;
        tail = prev;
        prev->next = (struct student*)malloc(sizeof(struct student));
        prev = prev->next;
        while(fread(prev, sizeof(struct student), 1, init_file)) {
            tail = prev;
            prev->next = (struct student*)malloc(sizeof(struct student));
            prev = prev->next;
        }
        fclose(init_file);
        free(prev);
        prev = tail;
        printf("初始化成功！\n");
    }
}

//修改信息
void s_Fix(void) {
    int Fix_num;
    int Fix_flag = 1;
    if(head != NULL) {
        struct student *Fix_cur = head;
        system("cls");
        printf("请输入修改的学号：\n");
        scanf("%d", &Fix_num);
        do {
            if(Fix_num == Fix_cur->num) {
                s_Fix_detail(Fix_cur);
                Fix_flag = 0;
            } else
                Fix_cur = Fix_cur->next;
        } while(Fix_cur != NULL && Fix_flag);
        if(Fix_flag)
            printf("查无此人！请重新输入！\n") ;
    } else {
        printf("数据库为空！按任意键返回选择界面\n");
        getchar();
        return ;
    }
}
//修改细节
void s_Fix_detail(struct student *stu) {
    char detail_flag;
    printf("您确定要修改“ %d %s ”的信息吗\n（输入 y or n）\n", stu->num, stu->name);
    scanf("%c", &detail_flag);
    switch(detail_flag) {
    case 'Y':
    case 'y':
        printf("请输入学生的");
    }
}


//打印函数
void s_Output(struct student *Fix_stu) {
    //后续添加另一个参数以输出表头表尾
    printf("┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆\n");
    printf("学号       姓名      性别     民族       语文       数学       英语     总分    平均分     \n");
    while(Fix_stu != NULL) {
        printf("%-10d %-9s %c        %-10s %-10.2lf %-10.2lf %-10.2lf \n", Fix_stu->num, Fix_stu->name, Fix_stu->sex, Fix_stu->minzu, Fix_stu->score[0], Fix_stu->score[1], Fix_stu->score[2]) ;
        Fix_stu = Fix_stu->next;
    }
}

//添加函数
void s_Add(void) {
    FILE *add_file;
    if((add_file = fopen("stu_data.txt", "ab")) == NULL) {
        printf("input Error!\n");
        exit(0);
    }
    if(head == NULL) {
        head = (struct student*)malloc(sizeof(struct student));
        prev = head;
        prev->next = NULL;
    } else {
        prev->next = (struct student*)malloc(sizeof(struct student));
        tail = prev;
        prev = prev->next;
        prev->next = NULL;
    }
    int Add_num, Add_flag = 1;
    struct student *Add_search;
    while(Add_flag) {
        Add_search = head;
        printf("请输入学生的学号\n");//输入范围？
        scanf("%d", &Add_num);
        getchar();
        while(Add_search != NULL) {
            if(Add_search->num == Add_num) {
                printf("该学号已存在！请重新输入！\n");
                Add_flag = 0;
                break;
            }
            Add_search = Add_search->next;
        }
        if(!Add_flag)
            Add_flag = 1;
        else
            break;
    }
    prev->num = Add_num;
    printf("请输入学生的姓名\n"); //用户可能有空格
    gets(prev->name);
    printf("请输入学生的性别(男生为'm',女生为'f')\n");
    scanf("%c", &prev->sex);
    getchar();
    printf("请输入学生的年龄\n");
    scanf("%d", &prev->age);
    getchar();
    printf("请输入学生的家庭住址(省)\n");//可不输入？
    gets(prev->address);
    printf("请输入学生的民族\n");
    gets(prev->minzu);
    printf("请分别输入学生的高数、英语、离散成绩\n");
    scanf("%lf%lf%lf", &prev->score[0], &prev->score[1], &prev->score[2]);
    prev->sum = prev->score[0] + prev->score[1] + prev->score[2];
    prev->ave = prev->sum / 3.0;
    // rewind(add_file);
    s_Write();
}

//写入函数
void s_Write(void) {
    FILE *write_file;
    struct student *Write_cur = head;
    if((write_file = fopen("stu_data.txt", "wb")) == NULL) {
        printf("写入失败！\n");
        exit(0);
    }
    while(Write_cur != NULL) {
        fwrite(Write_cur, sizeof(struct student), 1, write_file);
        Write_cur = Write_cur->next;
    }
    fclose(write_file);
}
//检查函数
struct student* s_Check(int Check_num)
{
   struct  student * check_p = head;
   while(check_p != NULL)
   {
       if(check_p->num == Check_num)
            break;
   }
    return check_p;
}

void s_Exit(void)
{
   Exit_flag=0;
}
