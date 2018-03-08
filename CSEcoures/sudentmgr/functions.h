//��ʼ������
void s_Init(void) {
    FILE *init_file;
    if((init_file = fopen("stu_data.txt", "rb")) == NULL) {
        printf("Init Error!\n");
        exit(0);
    }
    //�ж��Ƿ�Ϊ��
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
        printf("��ʼ���ɹ���\n");
    }
}

//�޸���Ϣ
void s_Fix(void) {
    int Fix_num;
    int Fix_flag = 1;
    if(head != NULL) {
        struct student *Fix_cur = head;
        system("cls");
        printf("�������޸ĵ�ѧ�ţ�\n");
        scanf("%d", &Fix_num);
        do {
            if(Fix_num == Fix_cur->num) {
                s_Fix_detail(Fix_cur);
                Fix_flag = 0;
            } else
                Fix_cur = Fix_cur->next;
        } while(Fix_cur != NULL && Fix_flag);
        if(Fix_flag)
            printf("���޴��ˣ����������룡\n") ;
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
    switch(detail_flag) {
    case 'Y':
    case 'y':
        printf("������ѧ����");
    }
}


//��ӡ����
void s_Output(struct student *Fix_stu) {
    //���������һ�������������ͷ��β
    printf("�����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T����T�����T�����T�����T�����T��\n");
    printf("ѧ��       ����      �Ա�     ����       ����       ��ѧ       Ӣ��     �ܷ�    ƽ����     \n");
    while(Fix_stu != NULL) {
        printf("%-10d %-9s %c        %-10s %-10.2lf %-10.2lf %-10.2lf \n", Fix_stu->num, Fix_stu->name, Fix_stu->sex, Fix_stu->minzu, Fix_stu->score[0], Fix_stu->score[1], Fix_stu->score[2]) ;
        Fix_stu = Fix_stu->next;
    }
}

//��Ӻ���
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
        printf("������ѧ����ѧ��\n");//���뷶Χ��
        scanf("%d", &Add_num);
        getchar();
        while(Add_search != NULL) {
            if(Add_search->num == Add_num) {
                printf("��ѧ���Ѵ��ڣ����������룡\n");
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
    s_Write();
}

//д�뺯��
void s_Write(void) {
    FILE *write_file;
    struct student *Write_cur = head;
    if((write_file = fopen("stu_data.txt", "wb")) == NULL) {
        printf("д��ʧ�ܣ�\n");
        exit(0);
    }
    while(Write_cur != NULL) {
        fwrite(Write_cur, sizeof(struct student), 1, write_file);
        Write_cur = Write_cur->next;
    }
    fclose(write_file);
}
//��麯��
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
