#include"header.h"
void stud_add(struct stu **ptr)
{
	struct stu *new,*temp,*last,*pos;
	new=malloc(sizeof(struct stu));
	int roll=1,found;
	printf("enter name and percentage:\n");
	scanf("%s %f",new->name,&new->percentage);
	while(1)
	{
		found=0;
		temp=*ptr;
		while(temp)
		{
			if(temp->rollno==roll)
			{
				found=1;
				break;
			}
			temp=temp->next;
		}
		if(found==0)
			break;
		roll++;
	}
	new->rollno=roll;
	if((*ptr==0)||(new->rollno <(*ptr)->rollno))
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		pos=*ptr;
		while((pos->next!=0) &&(new->rollno > pos->next->rollno))
			pos=pos->next;
		new->next=pos->next;
		pos->next=new;
	}
}

