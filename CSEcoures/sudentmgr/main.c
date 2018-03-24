#include"tou.h"
#include"functions.h"
#include"mergesort.h"
int main() {
    system("color 0A");
    int choice;
    s_Init(0);
    while(Exit_flag) {
        system("cls");
        printf("«Î—°‘Ò£∫\n");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
        case 1:
            s_Add();
            break;
        case 2:
            s_Init(0);
            break;
        case 3:
            s_Sort();
            break;
        case 4:
            s_Output(head, 1);
            break;
        case 5:
            s_Fix();
            break;
        case 6:
            s_Del();
            break;
        case 7:
            s_Search();
            break;
        case 8:
            s_Reset();
            break;
        case 9:
            s_Statistic();
            break;
//        case 9: s_Help();break;
        case 10:
            s_Exit();
            break;
        }
        s_Write(0);
        getchar();
    }
    return 0;
}

