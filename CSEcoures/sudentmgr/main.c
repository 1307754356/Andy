#include"tou.h"
#include"functions.h"
int main() {
    system("color 0A");
    int choice;
    s_Init();
    while(Exit_flag) {
        system("cls");
        printf("��ѡ��\n");
        scanf("%d", &choice);

        getchar();
        switch(choice) {
        case 1:
            s_Add();
            break;
        case 2:
            s_Init();
            break;
//        case 3: s_Del();break;
        case 4:
            s_Output(head);
            printf("%d\n",Out_put_num);
            break;//Ŀǰ�ȴ�ӡȫ��

        case 5:
            s_Fix();
            break;
        //  case 6: break;
//        case 5: s_Search();break;
//        case 6: s_Sort();break;
//        case 7: s_Statistic();break;
//        case 8: s_Reset();break;
//        case 9: s_Help();break;
        case 10:
            s_Exit();
            break;
        }
        s_Write();
        getchar();
    }
    return 0;
}

