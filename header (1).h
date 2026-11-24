#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
struct stu
{
int rollno;
char name[20];
float percentage;
struct stu *next;
};


void stud_add(struct stu **);
void stud_del(struct stu **);
void stud_show(struct stu *);
void stud_mod(struct stu **);
void stud_save(struct stu *);
void stud_sort(struct stu *);
void exit_menu(struct stu *);
void stud_del_all(struct stu **);
void stud_rev_links(struct stu **);
int count_node(struct stu *ptr);

