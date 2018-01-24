#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"mmmmp.h"

    int flag=1;
     //GAME STAR!
    int lev;
    int RENROW;
    int RENCOL;
    int ROW_N;
    int COL_N;
    //THE MAN`S PLACE
    int i,j,k=0;
    int POINUM;
    //THE BOX'S AND THE POINT'S PLACE
    char map[ROWS][COLS];

void manmove(int RR,int RC,int row,int col);
int main(void)
{
        system("cls");
        cut_off cut_off
        linefeed
        title1 title2 title3
        cut_off cut_off
        linefeed
        space space
        printf("WELCOME TO THIS GAME\n");
        space
        printf("    Please enter a number(1~3) to select a level ");
        scanf("%d",&lev);
        lev--;
        while(lev<=levmax)
        {
            POINUM=0;
      for(i=0;i<ROWS;i++)
         for(j=0;j<COLS;j++)
            {
                map[i][j]=mapp[lev][i][j];
                if(map[i][j]=='O')
                {
                    RENROW=i;
                    RENCOL=j;
                }
                if(map[i][j]=='@')
                    POINUM++;
            }
          flag=1;

    while(flag)
    {

        system("cls");

        char INPUT;
        while(1)
    {
        printf("level %d\n",lev+1);
        printf("Total time = %.0lf s\n", clock()*1.0/1000);
        for(i=0;i<ROWS;i++)
        printf("%s\n",map[i]);
            cut_off printf("¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n");
        printf("'X' means the man,and 'O' means the box(es)\n""A:Left   D:Right   W:Up   S:Down  Q:next R:reset\nYour steps are %d\n",k);

        Sleep(100);
        system("cls");

    if(kbhit())
        {
        INPUT=getch();
        if(INPUT)
        break;
        }
    }
        k++;
    //receive the keyboard input
    switch(INPUT){
    case 'A':
    case 'a': ROW_N=RENROW;
              COL_N=RENCOL-1;

              manmove(ROW_N,COL_N,0,-1);
              break;
    case 'D':
    case 'd': ROW_N=RENROW;
              COL_N=RENCOL+1;

              manmove(ROW_N,COL_N,0,1);
              break;
    case 'W':
    case 'w': ROW_N=RENROW-1;
              COL_N=RENCOL;

              manmove(ROW_N,COL_N,-1,0);
              break;
    case 'S':
    case 's': ROW_N=RENROW+1;
              COL_N=RENCOL;

              manmove(ROW_N,COL_N,1,0);
              break;
    case 'Q':
    case 'q': flag=0;
               //GAME OVER
               printf("\nGAME OVER\nBYE!\n");
               break;
    case 'r':
    case 'R': POINUM=0;
        for(i=0;i<ROWS;i++)
          for(j=0;j<COLS;j++)
            {
                map[i][j]=mapp[lev][i][j];
                if(map[i][j]=='O')
                {
                    RENROW=i;
                    RENCOL=j;
                }
                if(map[i][j]=='@')
                    POINUM++;
            }
    break;
    default:        printf("level %d\n",lev+1);
        printf("Total time = %.0lf s\n", clock()*1.0/1000);
        for(i=0;i<ROWS;i++)
        printf("%s\n",map[i]);
            cut_off printf("¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n");
        printf("'X' means the man,and 'O' means the box(es)\n""A:Left   D:Right   W:Up   S:Down  Q:next R:reset\nYour steps are %d\n",k);

        printf("Input error!\n");getch();
    }

   }
   lev++;
 }
   return 0;
}

void manmove(int RR,int RC,int row,int col)
{
     if(map[RR][RC]==' ')
     {   map[RR][RC]='O';
         map[RENROW][RENCOL]=' ';
         RENROW=ROW_N;
         RENCOL=COL_N;
     }
     else if(map[RR][RC]=='X'&&map[RR+row][RC+col]!='#'&&map[RR+row][RC+col]!='X')
     {
         map[RR][RC]='O';
         map[RENROW][RENCOL]=' ';
         RENROW=ROW_N;
         RENCOL=COL_N;

       if(map[RR+row][RC+col]!='@')
            map[RR+row][RC+col]='X';
       else{
            map[RR+row][RC+col]='$';POINUM--;}
             if(!POINUM)
             {
            system("cls");
           for(i=0;i<ROWS;i++)
            printf("%s\n",map[i]);
            cut_off printf("¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n");
            printf("Congratulation!Your total steps are %d !\n",k);
            printf("MISSION COMPLETE!\n");
            flag=0;
             }
     }
}
