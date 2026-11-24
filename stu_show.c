#include"header.h"
void stud_show(struct stu *ptr)
{
if(ptr==0)
{
printf("records are not present\n");
return;
}
while(ptr)
{
printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
}

