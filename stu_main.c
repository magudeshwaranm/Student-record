#include"header.h"
int main()
{
        int c=0;
        char op;
        struct stu *headptr=0;
        while(1)
        {
                printf("|-----------------------------|\n");
                printf("|*****STUDENT RECORD MENU*****|\n");
                printf("|-----------------------------|\n");
                printf("|a/A:add new record           |\n");
                printf("|d/D:delete a record          |\n");
                printf("|s/S:show the list            |\n");
                printf("|m/M:modify a record          |\n");
                printf("|v/V:save                     |\n");
                printf("|e/E:exit                     |\n");
                printf("|t/T:sort the list            |\n");
                printf("|l/L:delete all records       |\n");
                printf("|r/R:reverse the list         |\n");
                printf("|-----------------------------|\n");
                printf("enter your choice\n");
                scanf(" %c",&op);
                printf("\n\n");
        //      printf("op=%c",op);
                switch(op)
                {
                        case 'a':
                        case 'A':
                         stud_add(&headptr);break;
                        case 'd':
                        case 'D':
                         stud_del(&headptr);break;
                        case 's':
                        case 'S':
                         stud_show(headptr);break;
                        case 'm':
                        case 'M':
                         stud_mod(&headptr);break;
                        case 'v':
                        case 'V':
                         stud_save(headptr);break;
                        case 'e':
                        case 'E':
                        exit_menu(headptr);break;
                        case 't':
                        case 'T':
                          stud_sort(headptr);break;
                        case 'l':
                        case 'L':
                         stud_del_all(&headptr);break;
                        case 'r':
                        case 'R':
                         stud_rev_links(&headptr);break;
                        default:printf("unknown option:\n");
                }
        }
}

 
