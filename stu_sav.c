#include"header.h"
void exit_menu(struct stu*ptr)
{
	char ch;
	printf("s/S:save and exit\n");
	printf("e/E:exit without saving\n");
	printf("enter your choice\n");
	scanf(" %c",&ch);
	if(ch=='s' || ch=='S')
	{
		stud_save(ptr);
		return;
	}
	else if(ch=='e'|| ch=='E')
	{
		return;//exit(0);
	}
}
/////////////////////////////////////////////////////////////
int count_node(struct stu *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
//////////////////////////////////////////////////////////////
void stud_save(struct stu *ptr)
{
	FILE *fp=fopen("student.dat","w");
	if(fp==0)
	{
		printf("file is not preent\n");
		return;
	}

	struct stu *save;
	save=ptr;
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		//fwrite(save,sizeof(struct stu),1,fp);
		ptr=ptr->next;
	}
	printf("record  saved in file\n");
	fclose(fp);
}
////////////////////////////////////////////////////////
void stud_sort(struct stu *ptr)
{
	int i,j;
	char choice;
	struct stu *p1,*p2,save;
	p1=ptr;
	printf("N/n:sort with name\n");
	printf("P/p:sort with percentage\n");
	printf("enter your choice:\n");
	scanf(" %c",&choice);
	if(choice=='N' || choice=='n')
	{
		for(i=0;p1;i++)
		{
			p2=p1->next;
			for(j=0;p2;j++)
			{
				if(strcmp(p1->name,p2->name) > 0)
				{
					save.rollno=p1->rollno;
					strcpy(save.name,p1->name);
					save.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=save.rollno;
					strcpy(p2->name,save.name);
					p2->percentage=save.percentage;

				}
				p2=p2->next;
			}
			p1=p1->next;
		}
		printf("sorted with name successfully\n");
	}
	else if(choice=='P' || choice=='p')
	{

		for(i=0;p1;i++)
		{
			p2=p1->next;
			for(j=0;p2;j++)
			{
				if(p1->percentage > p2->percentage)
				{
					save.rollno=p1->rollno;
					strcpy(save.name,p1->name);
					save.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=save.rollno;
					strcpy(p2->name,save.name);
					p2->percentage=save.percentage;

				}
				p2=p2->next;
			}
			p1=p1->next;
		}
		printf("sorted with percentage successfully\n");
	}

}
/////////////////////////////////////////////////////////
void stud_del_all(struct stu **ptr)
{
	if(*ptr==0)
	{
		printf("no records found\n");
		return;
	}
	struct stu *del;
	del=*ptr;
	while(del)
	{
		*ptr=del->next;
		free(del);
		printf("node deleted\n");
		sleep(1);
		del=*ptr;
	}
	printf("deleted all Nodes\n");
}
////////////////////////////////////////////////
void stud_rev_links(struct stu **ptr)
{
	if(*ptr==0)
	{
		printf("record are not present\n");
		return;
	}
	int c=count_node(*ptr);
	if(c>1)
	{
		struct stu **arr=malloc(sizeof(struct stu*)*c);
		struct stu *t=*ptr;
		int i=0;
		while(t)
		{
			arr[i++]=t;
			t=t->next;
		}
		for(i=c-1;i>0;i--)
			arr[i]->next=arr[i-1];
		arr[0]->next=0;
		*ptr=arr[c-1];
	}
	printf("links Reversed\n");
}

