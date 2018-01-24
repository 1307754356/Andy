#ifndef MMMMP_H_INCLUDED
#define MMMMP_H_INCLUDED
#define ROWS 9
#define COLS 21
#define title1 printf("######  #     #  #####  #     #          ######  ####### #     # \n""#     # #     # #     # #     #          #     # #     #  #   #  \n""#     # #     # #       #     #          #     # #     #   # #   \n"
#define title2 "######  #     #  #####  #######          ######  #     #    #    \n""#       #     #       # #     #          #     # #     #   # #   \n""#       #     # #     # #     #          #     # #     #  #   #  \n"
#define title3 "#        #####   #####  #     #          ######  ####### #     # \n");
#define space  printf("              ");
#define cut_off printf("¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù");
#define linefeed printf("\n");
#define levmax 4
  //kuangbin
  //ACdreamers
  //morejarphone
char mapp[4][ROWS][COLS]={
    {
        "###############     ",
        "#             #     ",
        "#O   #    #   #     ",
        "# X  #    #  @#     ",
        "#   X#    #   #     ",
        "#             #     ",
        "#            @#     ",
        "###############     ",
    },{
        "      #####         ",
        "      # @ #         ",
        "####### X #         ",
        "#@ X  O   #####     ",
        "#####     X @ #     ",
        "    # X #######     ",
        "    # @ #           ",
        "    #####           ",

    },{
        "#######             ",
        "# O   #             ",
        "#   XX#             ",
        "#   X #########     ",
        "#####        @#     ",
        "  ###   ##    #     ",
        "  ##    ##    #     ",
        "  ##    #######     ",
        "  #######           ",
    },{
        " ########           ",
        " # O   ##           ",
        " #      ##          ",
        "####  # #######     ",
        "##@#  #  #    #     ",
        "##X    #      #     ",
        "##            #     ",
        "###############     ",

        }  } ;



#endif // MMMMP_H_INCLUDED
