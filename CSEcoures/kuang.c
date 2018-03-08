#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<tou.h>
#define N 20

int main()
{
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: Add();
        case 2: Fix();
        case 3: Del();
    }
     return 0;
}

