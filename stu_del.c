#include"header.h"
void stud_del(struct stu **ptr)
{
	int num,f=0;
	char name[16],choice;
	struct stu *del,*prev,*last;
	printf("R/r:based on rollno\n");
	printf("N/n:based on name\n");
	printf("enter your choice:\n");
	scanf(" %c",&choice);
	del=*ptr;
	if(choice=='n' ||choice=='N')
	{
		printf("enter name:\n");
		scanf("%s",name);
		f=0;
		while(del)
		{

			if(strcmp(name,del->name)==0)
			{f=1;
				printf("%d %s %f\n",del->rollno,del->name,del->percentage);
			}
			del=del->next;
		}
		if(f==0)
		{
			printf("name not found\n");
			return;
		}
		del=*ptr;
		printf("enter rollno:\n");
		scanf("%d",&num);
		while(del)
		{       if(num==del->rollno)
			{
				if(*ptr==del)
				{
					*ptr=del->next;
				}
				else
				{
					prev->next=del->next;
				}
				free(del);
				printf("node deleted\n");
			}
			prev=del;
			del=del->next;
		}
	}
	else if(choice=='R' || choice=='r')
	{
		printf("enter rollno:\n");
		scanf("%d",&num);
		f=0;
		while(del)
		{
			if(num==del->rollno)
			{f=1;
				printf("%d %s %f\n",del->rollno,del->name,del->percentage);
			}
			del=del->next;
		}
		del=*ptr;
		if(f==0)
		{
			printf("rollno not found\n");
			return;
		}
		while(del)
		{
			if(del->rollno==num)
			{

				if(*ptr==del)
				{
					*ptr=del->next;
				}
				else
				{
					prev->next=del->next;
				}
				free(del);
				printf("node deleted\n");
			}

			prev=del;
			del=del->next;
		}
	}

	else
		printf("unknown choice\n");
}

