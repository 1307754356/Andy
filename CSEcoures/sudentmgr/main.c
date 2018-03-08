#include"tou.h"
#include"functions.h"
int main() {
    int choice;
    while(Exit_flag) {
        system("cls");
        s_Init();
        printf("请选择：\n");
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
            break;//目前先打印全部

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
        getchar();
    }
    return 0;
}

