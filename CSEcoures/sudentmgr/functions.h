#define  NUM 20

//初始化函数
void s_Init(int init_choice) {
    FILE *init_file;
    switch(init_choice) {
    case 1:
        if((init_file = fopen("stu_data_reset1.txt", "rb")) == NULL) {
            printf("Init Error!\n");
            exit(0);
        }
        break;
    case 2:
        if((init_file = fopen("stu_data_reset2.txt", "rb")) == NULL) {
            printf("Init Error!\n");
            exit(0);
        }
        break;
    case 3:
        if((init_file = fopen("stu_data_reset3.txt", "rb")) == NULL) {
            printf("Init Error!\n");
            exit(0);
        }
        break;
    default:
        if((init_file = fopen("stu_data.txt", "rb")) == NULL) {
            printf("Init Error!\n");
            exit(0);
        }
        break;
    }

//判断是否为空
    prev = (struct student*)malloc(sizeof(struct student));
    if(fread(prev, sizeof(struct student), 1, init_file) != 1) {
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
        tail ->next = NULL;
        // printf("初始化成功！\n");
    }


    //排序初始化

}

//修改信息
void s_Fix(void) {
    int Fix_num;
    if(head != NULL) {
        system("cls");
        printf("请输入修改的学号：\n");
        scanf("%d", &Fix_num);
        getchar();
        struct student *Fix_stu = s_Check(Fix_num);
        if(Fix_stu == NULL) {
            printf("查无此人！请重新输入！\n") ;
            getchar();
        } else {
            s_Fix_detail(Fix_stu);
        }
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
    while(detail_flag == 'y' || detail_flag == 'Y') {
        system("cls");
        s_Output(stu);
        int detail_choice;
        printf("您可修改以下内容：\n1.学号\n2.姓名\n3.性别\n4.民族\n5.语文\n6.数学\n7.英语\n输入‘8’以退出\n");
        scanf("%d", &detail_choice);
        getchar();
        switch(detail_choice) {
        case 1:
            while(1) {
                int detail_new_num;
                printf("请输入新学号(请不要与已有学号重合！)");
                scanf("%d", &detail_new_num);
                if(s_Check(detail_new_num) == NULL) {
                    stu->num = detail_new_num;
                    break;
                }
                printf("该学号已存在！请重新输入!\n");
            }
        case 2:
            printf("请输入新姓名：\n");
            gets(stu->name);
            break;
        case 3:
            printf("请输入新性别：\n") ;
            scanf("%c", &stu->sex);
            break;
        case 4:
            printf("请输入新民族：\n") ;
            gets(stu->minzu);
            break;
        case 5:
            printf("请输入新语文成绩：\n");
            scanf("%lf", &stu->score[0]);
            break;
        case 6:
            printf("请输入新数学成绩：\n");
            scanf("%lf", &stu->score[1]);
            break;
        case 7:
            printf("请输入新英语成绩：\n") ;
            scanf("%lf", &stu->score[2]);
            break;
        case 8:
            return ;
        }
        stu->sum = stu->score[0] + stu->score[1] + stu->score[2];
        stu->ave = stu->sum / 3.0;

    }
}

//打印函数
void s_Output(struct student *Fix_stu) {
    //后续添加另一个参数以输出表头表尾
    if(Fix_stu == NULL) {
        printf("信息为空！\n");
        return ;
    }
    printf("┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆┈━═┈━═┈━═┈━═┈━═☆\n");
    printf("学号       姓名      性别     民族       语文       数学       英语       总分       平均分     \n");


        while(Fix_stu != NULL) {
            printf("%-10d %-9s %c        %-10s %-10.2lf %-10.2lf %-10.2lf %-10.2lf %-10.2lf \n", Fix_stu->num, Fix_stu->name, Fix_stu->sex, Fix_stu->minzu, Fix_stu->score[0], Fix_stu->score[1], Fix_stu->score[2], Fix_stu->sum, Fix_stu->ave) ;
            Fix_stu = Fix_stu -> next;
        }


}

//添加函数
void s_Add(void) {

    if(head == NULL) {
        head = (struct student*)malloc(sizeof(struct student));
        prev = head;
        prev->next = NULL;
    } else {
// TODO (孔振华#1#): 修正“添加两人会覆盖”的bug
        tail->next = (struct student*)malloc(sizeof(struct student));
        prev = tail->next;
        tail = tail->next;
        tail->next = NULL;
    }
    int Add_num, Add_flag = 1;
    while(Add_flag) {
        printf("请输入学生的学号\n");//输入范围？
        scanf("%d", &Add_num);
        getchar();
        if(s_Check(Add_num) != NULL) {
            printf("该学号已存在！\n");
            Add_flag = 0;
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
}

//删除函数
void s_Del(void) {
    int Del_num;
    if(head != NULL) {
        system("cls");
        printf("请输入删除的学号：\n");
        scanf("%d", &Del_num);
        getchar();
        struct student *Del_stu = s_Check(Del_num);
        if(Del_stu == NULL) {
            printf("查无此人！请重新输入！\n") ;
            getchar();
        } else {
            printf("您确定要删除“ %d %s ”的信息吗\n（输入 y or n）\n", Del_stu->num, Del_stu->name);
            char Del_flag;
            scanf("%c", &Del_flag);
            if(Del_flag == 'y' || Del_flag == 'Y') {
                if(Del_stu == head) {
                    head = Del_stu->next;
                } else {
                    struct student *Del_stu_pre = head;
                    while(Del_stu_pre->next != Del_stu) {
                        Del_stu_pre = Del_stu_pre->next;
                    }
                    Del_stu_pre ->next = Del_stu->next;
                    Del_stu ->next = NULL;
                    free(Del_stu);
                }
// TODO (孔振华#9#): 在修改中添加“修复尾指针”函数
                s_Find_tail();
                printf("删除成功！\n");
            }
        }
    } else {
        printf("数据库为空！按任意键返回选择界面\n");
        getchar();
        return ;
    }
}

//写入函数
void s_Write(int write_choice) {
    FILE *write_file;
    struct student *Write_cur = head;
    switch(write_choice) {
    case 1:
        if((write_file = fopen("stu_data_reset1.txt", "w+b")) == NULL) {
            printf("写入失败！\n");
            exit(1);
        }
        break ;
    case 2:
        if((write_file = fopen("stu_data_reset2.txt", "w+b")) == NULL) {
            printf("写入失败！\n");
            exit(1);
        }
        break ;
    case 3:
        if((write_file = fopen("stu_data_reset3.txt", "w+b")) == NULL) {
            printf("写入失败！\n");
            exit(1);
        }
        break ;
    default:
        if((write_file = fopen("stu_data.txt", "w+b")) == NULL) {
            printf("写入失败！\n");
            exit(1);
        }
        break ;
    }
    while(Write_cur != NULL) {
        fwrite(Write_cur, sizeof(struct student), 1, write_file);
        Write_cur = Write_cur->next;
    }
    fclose(write_file);
}

//备份函数
void s_Reset(void) {
    //记录存档记录时间
    FILE *reset_file_r;
    if((reset_file_r = fopen("stu_data_reset_time.txt", "rb")) == NULL) {
        printf("RESET ERROR!\n");
        exit(0);
    }
    struct ROLL *reset_p_r = (struct ROLL*)malloc(sizeof(struct ROLL));
    if(fread(reset_p_r, sizeof(struct ROLL), 1, reset_file_r) != 1) {
        fclose(reset_file_r);
        free(reset_p_r);
        reset_p_r = NULL;
    } else {
        rewind(reset_file_r);
        int reset_file_i;
        for(reset_file_i = 1; reset_file_i < 4; reset_file_i++) {
            fread(&Back[reset_file_i], sizeof(struct ROLL), 1, reset_file_r);
        }
    }
    fclose(reset_file_r);
    int reset_choice;
    if((Back[1].roll_back = fopen("stu_data_reset1.txt", "rb")) == NULL) {
        printf("1 Input Error!\n");
        exit(0);
    }
    if((Back[2].roll_back = fopen("stu_data_reset2.txt", "rb")) == NULL) {
        printf("2 Input Error!\n");
        exit(0);
    }
    if((Back[3].roll_back = fopen("stu_data_reset3.txt", "rb")) == NULL) {
        printf("3 Input Error!\n");
        exit(0);
    }
    struct student *reset_prev = (struct student*)malloc(sizeof(struct student));
    int roll_i ;
    for(roll_i = 1; roll_i < 4; roll_i++) {
        if(fread(reset_prev, sizeof(struct student), 1, Back[roll_i].roll_back) == 1)
            Back[roll_i].reset_flag = 1;
        rewind(Back[roll_i].roll_back);
    }
    free(reset_prev);
    reset_prev = NULL;
    for(roll_i = 1; roll_i < 4; roll_i++) {
        printf("存档%d： ", roll_i);
        if(Back[roll_i].reset_flag == 0)
            printf("空\n");
        else {
            printf("%d/%d/%d %02d:%02d:%02d\n", Back[roll_i].reset_year, Back[roll_i].reset_month, Back[roll_i].reset_day, Back[roll_i].reset_hour, Back[roll_i].reset_min, Back[roll_i].reset_sec);
        }
    }
    do {
        printf("请选择：\n  1.备份\n  2.恢复\n  3.退出\n");
        scanf("%d", &reset_choice);
    } while(reset_choice < 1 || reset_choice > 3);
    switch(reset_choice) {
    case 1:
        system("cls");
        printf("请输入要备份的区域:(1 or 2 or 3)\n");
        int back_up_choice;
        scanf("%d", &back_up_choice);
        s_Write(back_up_choice);
        time_t timep;
        struct tm *tm_p;
        time(&timep);
        tm_p = localtime(&timep);
        Back[back_up_choice].reset_year  =   1900 + tm_p->tm_year;
        Back[back_up_choice].reset_month =   1 + tm_p->tm_mon;
        Back[back_up_choice].reset_day   =   tm_p->tm_mday;
        Back[back_up_choice].reset_hour  =   tm_p->tm_hour;
        Back[back_up_choice].reset_min   =   tm_p->tm_min;
        Back[back_up_choice].reset_sec   =   tm_p->tm_sec;
        break;
    case 2:
        system("cls");
        printf("请输入要恢复的区域(1 or 2 or 3):\n");
        int roll_i;
        scanf("%d", &roll_i);
        //printf("您确定要读取存档%d吗？",roll_i);
        s_clear(head);
        head = NULL;
        tail = NULL; //这里吧？
        s_Init(roll_i);
        break;
    case 3:
        return ;
    }
    FILE *reset_file_w;
    if((reset_file_w = fopen("stu_data_reset_time.txt", "wb")) == NULL) {
        printf("RESET ERROR!\n");
        exit(0);
    }
    fwrite(&Back[1], sizeof(struct ROLL), 3, reset_file_w);
    fclose(reset_file_w);
}

//清空链表
// TODO (孔振华#9#): 升级了清空列表函数
void s_clear(struct student *clr_head) {
    struct student *clr_p = clr_head;
    if( clr_head == NULL)
        return ;
    while( clr_p->next != NULL) {
        struct student *clr_q = clr_p;
        clr_p = clr_p->next;
        free(clr_q);
    }
    free(clr_p);
    clr_p = NULL;
    clr_head  = NULL;
}

//检查函数
struct student* s_Check(int Check_num) {
    struct  student * check_p = head;
    while(check_p != NULL) {
        if(check_p->num == Check_num)
            break;
        check_p = check_p->next;
    }
    return check_p;
}

//修复尾指针
void s_Find_tail(void) {
    struct student *Tail_cur = head;
    while(Tail_cur != NULL && Tail_cur->next != NULL) {
        Tail_cur = Tail_cur->next;
    }
    tail = Tail_cur;
}

//排序函数
void s_Sort(void) {
    // 1.学号\n2.姓名\n3.性别\n4.民族\n5.语文\n6.数学\n7.英语\n输入‘8’以退出\n");
    printf("排序界面：\n");
    printf("请选择排序方式：\n");
    printf("1.按学号排序\n");
    printf("2.按姓名排序\n");
    printf("3.按性别排序\n");
    printf("4.按民族排序\n");
    printf("5.按语文排序\n");
    printf("6.按数学排序\n");
    printf("7.按英语排序\n");
    printf("8.按总分排序\n");

    int sort_choice;
    scanf("%d", &sort_choice);
    printf("正序:1\n");
    printf("逆序:0\n");
    printf("按其他键退出\n");
    scanf("%d", &sort_order);

    int (*sort_p[15])(struct student * A, struct student * B);
    sort_p[1] = cmp1;
    sort_p[2] = cmp2;
    sort_p[3] = cmp3;
    sort_p[4] = cmp4;
    sort_p[5] = cmp5;
    sort_p[6] = cmp6;
    sort_p[7] = cmp7;
    sort_p[8] = cmp8;
    sort_p[9] = cmp9;

    sort_fc_head = sort_p[sort_choice];

    head = sortList(head);
    s_Find_tail();
    s_Output(head);
}

//退出函数
void s_Exit(void) {
    Exit_flag = 0;
}

//查询函数
void s_Search(void) {
    char ch;
    search_choice = 0;
    printf("查询方式：\n");
    printf("1.学号\n2.姓名\n3.性别\n4.民族\n5.语文\n6.数学\n7.英语\n输入‘8’以退出\n");
    printf("(支持组合查询，可在一行内输入不超过五个排序条件的序号)\n");
    int search_num = 0;
    while((ch = getchar()) && ch != '\n') {
        if(!isdigit(ch))
            continue;
        else {
// TODO (孔振华#1#): 组合查询
            /*
            函数应该怎么设计？如何提高代码重用性？
            数据怎么存储？（数组还是链表？） 链表删除是否太过繁琐？数组删除是否不够彻底？是否可以利用已经写成的代码？
            另外修改显示函数可以用带参的宏，即设置默认值的方式来进行
            个数如何统计？
            如何链接各个函数？ (可以遍历数组，逐次执行命令，可是怎么实现通用性呢)
            是否加入条件查询？ （语文成绩>=60？
            还是做成百度搜索那种？（相同的换字体颜色）

            搜索_创建链表
            搜索_加入元素
                            在第一次筛选后的即为链表初始元素，之后只有删除，再无添加
            搜索_删除元素

            */
            search_choice_arr[search_num] = ch - 48;
            search_num++;
        }
    }
    search_init();
    //   s_Output(search_p_head);
    int search_temp_i;
    for(search_temp_i = 0; search_temp_i < search_num; search_temp_i++) {
        //以下两行不用换，已经通用了
        printf("%d\n", search_choice_arr[search_temp_i]);
        printf("请输入%s的信息\n", term[search_choice_arr[search_temp_i] - 1]);

        //是否可以将其用atof/atoi 转换？浮点数的比较如何处理？
        char search_temp[15];
        struct student *search_p_temp = search_p_head;
        struct student *search_p_temp_next = search_p_head;
        gets(search_temp);

        while(search_p_temp != NULL ) {
            search_p_temp_next = search_p_temp->next;
            if(sea[search_choice_arr[search_temp_i]](search_p_temp, search_temp)) {
                search_delete(search_p_temp);
            }
            search_p_temp = search_p_temp_next;
        }
        s_Output(search_p_head);

//
//        printf("%d\n", search_choice_arr[search_temp_i]);
//        printf("请输入%s的信息\n", term[search_choice_arr[search_temp_i] - 1]);
//
//        //是否可以将其用atof/atoi 转换？浮点数的比较如何处理？
//        search_p_temp = search_p_head;
//        search_p_temp_next = search_p_head;
//        gets(search_temp);
//
//        while(search_p_temp != NULL ) {
//            search_p_temp_next = search_p_temp->next;
//            if(strstr(search_p_temp->name, search_temp) == NULL) {
//                search_delete(search_p_temp);
//            }
//            search_p_temp = search_p_temp_next;
//        }
//        s_Output(search_p_head);
//
//
    }
    s_clear(search_p_head);
    search_p_head = NULL;
    search_p_tail = NULL;
}

void search_delete(struct student *sea_del) {
    if(sea_del == search_p_head) {
        search_p_head = search_p_head->next;
    } else {
        struct student *sea_del_pre = search_p_head;
        while(sea_del_pre->next != sea_del) {
            sea_del_pre = sea_del_pre->next;
        }
        sea_del_pre -> next = sea_del -> next;
        sea_del ->next = NULL;
        free(sea_del);
        sea_del = NULL;
    }
}
//负责创建查询链表和初始化函数指针
void search_init(void) {
    if(head != NULL) {
        search_p_head = (struct student *)malloc(sizeof(struct student));
        search_p_tail = search_p_head;
        memcpy(search_p_head, head, sizeof(struct student));
        struct student *search_cur = head;
        struct student *search_add_cur = search_p_head;
        while(search_cur->next != NULL) {
            search_cur = search_cur->next;
            search_add_cur->next = (struct student *)malloc(sizeof(struct student));
            search_add_cur =  search_add_cur->next;
            memcpy(search_add_cur, search_cur, sizeof(struct student));
        }
        search_add_cur->next = NULL;
        search_cur->next = NULL;
        search_p_tail = search_add_cur;
    } else
        printf("链表为空！！！\n");
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

