#include"tou.h"
#include"functions.h"
int main() {
    int choice;
    while(1) {

        s_Init();
        printf("«Î—°‘Ò£∫\n");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            s_Add();
            break;
        case 2:
            s_Init();
            break;
        case 3:
            return 0;

//        case 3: s_Del();break;
        case 4: s_Output(head);break;

        case 5: s_Fix();break;
//        case 5: s_Search();break;
//        case 6: s_Sort();break;
//        case 7: s_Statistic();break;
//        case 8: s_Reset();break;
//        case 9: s_Help();break;
//        case 10: s_Exit();break;
        }
    }
    return 0;
}

