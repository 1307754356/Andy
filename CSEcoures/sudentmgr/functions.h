#define  NUM 20

//��ʼ������
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

//�ж��Ƿ�Ϊ��
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
        // printf("��ʼ���ɹ���\n");
    }


    //�����ʼ��

}

//�޸���Ϣ
void s_Fix(void) {
    int Fix_num;
    if(head != NULL) {
        system("cls");
        printf("�������޸ĵ�ѧ�ţ�\n");
        scanf("%d", &Fix_num);
        getchar();
        struct student *Fix_stu = s_Check(Fix_num);
        if(Fix_stu == NULL) {
            printf("���޴��ˣ����������룡\n") ;
            getchar();
        } else {
            s_Fix_detail(Fix_stu);
        }
    } else {
        printf("���ݿ�Ϊ�գ������������ѡ�����\n");
        getchar();
        return ;
    }
}
//�޸�ϸ��
void s_Fix_detail(struct student *stu) {
    char detail_flag;
    printf("��ȷ��Ҫ�޸ġ� %d %s ������Ϣ��\n������ y or n��\n", stu->num, stu->name);
    scanf("%c", &detail_flag);
    while(detail_flag == 'y' || detail_flag == 'Y') {
        system("cls");
        s_Output(stu);
        int detail_choice;
        printf("�����޸��������ݣ�\n1.ѧ��\n2.����\n3.�Ա�\n4.����\n5.����\n6.��ѧ\n7.Ӣ��\n���롮8�����˳�\n");
        scanf("%d", &detail_choice);
        getchar();
        switch(detail_choice) {
        case 1:
            while(1) {
                int detail_new_num;
                printf("��������ѧ��(�벻Ҫ������ѧ���غϣ�)");
                scanf("%d", &detail_new_num);
                if(s_Check(detail_new_num) == NULL) {
                    stu->num = detail_new_num;
                    break;
                }
                printf("��ѧ���Ѵ��ڣ�����������!\n");
            }
        case 2:
            printf("��������������\n");
            gets(stu->name);
            break;
        case 3:
            printf("���������Ա�\n") ;
            scanf("%c", &stu->sex);
            break;
        case 4:
            printf("�����������壺\n") ;
            gets(stu->minzu);
            break;
        case 5:
            printf("�����������ĳɼ���\n");
            scanf("%lf", &stu->score[0]);
            break;
        case 6:
            printf("����������ѧ�ɼ���\n");
            scanf("%lf", &stu->score[1]);
            break;
        case 7:
            printf("��������Ӣ��ɼ���\n") ;
            scanf("%lf", &stu->score[2]);
            break;
        case 8:
            return ;
        }
        stu->sum = stu->score[0] + stu->score[1] + stu->score[2];
        stu->ave = stu->sum / 3.0;

    }
}

//��ӡ����
void s_Output(struct student *Fix_stu) {
    //���������һ�������������ͷ��β
    if(Fix_stu == NULL) {
        printf("��ϢΪ�գ�\n");
        return ;
    }
    printf("�����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T��\n");
    printf("ѧ��       ����      �Ա�     ����       ����       ��ѧ       Ӣ��       �ܷ�       ƽ����     \n");


        while(Fix_stu != NULL) {
            printf("%-10d %-9s %c        %-10s %-10.2lf %-10.2lf %-10.2lf %-10.2lf %-10.2lf \n", Fix_stu->num, Fix_stu->name, Fix_stu->sex, Fix_stu->minzu, Fix_stu->score[0], Fix_stu->score[1], Fix_stu->score[2], Fix_stu->sum, Fix_stu->ave) ;
            Fix_stu = Fix_stu -> next;
        }


}

//��Ӻ���
void s_Add(void) {

    if(head == NULL) {
        head = (struct student*)malloc(sizeof(struct student));
        prev = head;
        prev->next = NULL;
    } else {
// TODO (����#1#): ������������˻Ḳ�ǡ���bug
        tail->next = (struct student*)malloc(sizeof(struct student));
        prev = tail->next;
        tail = tail->next;
        tail->next = NULL;
    }
    int Add_num, Add_flag = 1;
    while(Add_flag) {
        printf("������ѧ����ѧ��\n");//���뷶Χ��
        scanf("%d", &Add_num);
        getchar();
        if(s_Check(Add_num) != NULL) {
            printf("��ѧ���Ѵ��ڣ�\n");
            Add_flag = 0;
        }
        if(!Add_flag)
            Add_flag = 1;
        else
            break;
    }
    prev->num = Add_num;
    printf("������ѧ��������\n"); //�û������пո�
    gets(prev->name);
    printf("������ѧ�����Ա�(����Ϊ'm',Ů��Ϊ'f')\n");
    scanf("%c", &prev->sex);
    getchar();
    printf("������ѧ��������\n");
    scanf("%d", &prev->age);
    getchar();
    printf("������ѧ���ļ�ͥסַ(ʡ)\n");//�ɲ����룿
    gets(prev->address);
    printf("������ѧ��������\n");
    gets(prev->minzu);
    printf("��ֱ�����ѧ���ĸ�����Ӣ���ɢ�ɼ�\n");
    scanf("%lf%lf%lf", &prev->score[0], &prev->score[1], &prev->score[2]);
    prev->sum = prev->score[0] + prev->score[1] + prev->score[2];
    prev->ave = prev->sum / 3.0;

// rewind(add_file);
}

//ɾ������
void s_Del(void) {
    int Del_num;
    if(head != NULL) {
        system("cls");
        printf("������ɾ����ѧ�ţ�\n");
        scanf("%d", &Del_num);
        getchar();
        struct student *Del_stu = s_Check(Del_num);
        if(Del_stu == NULL) {
            printf("���޴��ˣ����������룡\n") ;
            getchar();
        } else {
            printf("��ȷ��Ҫɾ���� %d %s ������Ϣ��\n������ y or n��\n", Del_stu->num, Del_stu->name);
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
// TODO (����#9#): ���޸�����ӡ��޸�βָ�롱����
                s_Find_tail();
                printf("ɾ���ɹ���\n");
            }
        }
    } else {
        printf("���ݿ�Ϊ�գ������������ѡ�����\n");
        getchar();
        return ;
    }
}

//д�뺯��
void s_Write(int write_choice) {
    FILE *write_file;
    struct student *Write_cur = head;
    switch(write_choice) {
    case 1:
        if((write_file = fopen("stu_data_reset1.txt", "w+b")) == NULL) {
            printf("д��ʧ�ܣ�\n");
            exit(1);
        }
        break ;
    case 2:
        if((write_file = fopen("stu_data_reset2.txt", "w+b")) == NULL) {
            printf("д��ʧ�ܣ�\n");
            exit(1);
        }
        break ;
    case 3:
        if((write_file = fopen("stu_data_reset3.txt", "w+b")) == NULL) {
            printf("д��ʧ�ܣ�\n");
            exit(1);
        }
        break ;
    default:
        if((write_file = fopen("stu_data.txt", "w+b")) == NULL) {
            printf("д��ʧ�ܣ�\n");
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

//���ݺ���
void s_Reset(void) {
    //��¼�浵��¼ʱ��
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
        printf("�浵%d�� ", roll_i);
        if(Back[roll_i].reset_flag == 0)
            printf("��\n");
        else {
            printf("%d/%d/%d %02d:%02d:%02d\n", Back[roll_i].reset_year, Back[roll_i].reset_month, Back[roll_i].reset_day, Back[roll_i].reset_hour, Back[roll_i].reset_min, Back[roll_i].reset_sec);
        }
    }
    do {
        printf("��ѡ��\n  1.����\n  2.�ָ�\n  3.�˳�\n");
        scanf("%d", &reset_choice);
    } while(reset_choice < 1 || reset_choice > 3);
    switch(reset_choice) {
    case 1:
        system("cls");
        printf("������Ҫ���ݵ�����:(1 or 2 or 3)\n");
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
        printf("������Ҫ�ָ�������(1 or 2 or 3):\n");
        int roll_i;
        scanf("%d", &roll_i);
        //printf("��ȷ��Ҫ��ȡ�浵%d��",roll_i);
        s_clear(head);
        head = NULL;
        tail = NULL; //����ɣ�
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

//�������
// TODO (����#9#): ����������б���
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

//��麯��
struct student* s_Check(int Check_num) {
    struct  student * check_p = head;
    while(check_p != NULL) {
        if(check_p->num == Check_num)
            break;
        check_p = check_p->next;
    }
    return check_p;
}

//�޸�βָ��
void s_Find_tail(void) {
    struct student *Tail_cur = head;
    while(Tail_cur != NULL && Tail_cur->next != NULL) {
        Tail_cur = Tail_cur->next;
    }
    tail = Tail_cur;
}

//������
void s_Sort(void) {
    // 1.ѧ��\n2.����\n3.�Ա�\n4.����\n5.����\n6.��ѧ\n7.Ӣ��\n���롮8�����˳�\n");
    printf("������棺\n");
    printf("��ѡ������ʽ��\n");
    printf("1.��ѧ������\n");
    printf("2.����������\n");
    printf("3.���Ա�����\n");
    printf("4.����������\n");
    printf("5.����������\n");
    printf("6.����ѧ����\n");
    printf("7.��Ӣ������\n");
    printf("8.���ܷ�����\n");

    int sort_choice;
    scanf("%d", &sort_choice);
    printf("����:1\n");
    printf("����:0\n");
    printf("���������˳�\n");
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

//�˳�����
void s_Exit(void) {
    Exit_flag = 0;
}

//��ѯ����
void s_Search(void) {
    char ch;
    search_choice = 0;
    printf("��ѯ��ʽ��\n");
    printf("1.ѧ��\n2.����\n3.�Ա�\n4.����\n5.����\n6.��ѧ\n7.Ӣ��\n���롮8�����˳�\n");
    printf("(֧����ϲ�ѯ������һ�������벻��������������������)\n");
    int search_num = 0;
    while((ch = getchar()) && ch != '\n') {
        if(!isdigit(ch))
            continue;
        else {
// TODO (����#1#): ��ϲ�ѯ
            /*
            ����Ӧ����ô��ƣ������ߴ��������ԣ�
            ������ô�洢�������黹�������� ����ɾ���Ƿ�̫������������ɾ���Ƿ񲻹����ף��Ƿ���������Ѿ�д�ɵĴ��룿
            �����޸���ʾ���������ô��εĺ꣬������Ĭ��ֵ�ķ�ʽ������
            �������ͳ�ƣ�
            ������Ӹ��������� (���Ա������飬���ִ�����������ôʵ��ͨ������)
            �Ƿ����������ѯ�� �����ĳɼ�>=60��
            �������ɰٶ��������֣�����ͬ�Ļ�������ɫ��

            ����_��������
            ����_����Ԫ��
                            �ڵ�һ��ɸѡ��ļ�Ϊ�����ʼԪ�أ�֮��ֻ��ɾ�����������
            ����_ɾ��Ԫ��

            */
            search_choice_arr[search_num] = ch - 48;
            search_num++;
        }
    }
    search_init();
    //   s_Output(search_p_head);
    int search_temp_i;
    for(search_temp_i = 0; search_temp_i < search_num; search_temp_i++) {
        //�������в��û����Ѿ�ͨ����
        printf("%d\n", search_choice_arr[search_temp_i]);
        printf("������%s����Ϣ\n", term[search_choice_arr[search_temp_i] - 1]);

        //�Ƿ���Խ�����atof/atoi ת�����������ıȽ���δ���
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
//        printf("������%s����Ϣ\n", term[search_choice_arr[search_temp_i] - 1]);
//
//        //�Ƿ���Խ�����atof/atoi ת�����������ıȽ���δ���
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
//���𴴽���ѯ����ͳ�ʼ������ָ��
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

