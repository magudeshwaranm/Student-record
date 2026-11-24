#include"header.h"
void stud_mod(struct stu**ptr)
{
	struct stu *temp,*mod;
	int f=0,num;
	float percentage;
	char name[16],choice;
	printf("R/r:rollno based\n");
	printf("N/n:name based\n");
	printf("P/p:percentage based\n");
	printf("enter your choice:\n");
	scanf(" %c",&choice);
	mod=*ptr;
	if(choice=='R' ||choice=='r')
	{
		printf("enter your roll no:\n");
		scanf("%d",&num);
		while(mod)
		{f=0;
			if(num==mod->rollno)
			{f=1;
				printf("enter new name and percentage:\n");
				scanf("%s %f",mod->name,&mod->percentage);
				printf("node modified\n");
			}
			mod=mod->next;
		}
		if(f==0)
			printf("roll num not found\n");
	}
	else if(choice=='N' || choice=='n')
	{
		int f=0;
		printf("enter name to modify:\n");
		scanf("%s",name);
		while(mod)
		{
			if(strcmp(name,mod->name)==0)
			{f=1;
				printf("%d %s %f\n",mod->rollno,mod->name,mod->percentage);
			}
			mod=mod->next;
		}
		if(f==0)

		{
			printf("name not found:\n");
			return;
		}
		printf("enter rollno:\n");
		scanf("%d",&num);
		mod=*ptr;
		while(mod)
		{
			if(num==mod->rollno)
			{
				printf("new name and percentage:\n");
				scanf("%s %f",mod->name,&mod->percentage);
				printf("node modified\n");
			}

			mod=mod->next;
		}
	}

	else if(choice=='P' || choice=='p')
	{
		int f=0;
		printf("enter percentage to modify\n");
		scanf("%f",&percentage);
		while(mod)
		{
			if(percentage==mod->percentage)
			{
				f=1;
				printf("%d %s %f\n",mod->rollno,mod->name,mod->percentage);
			}
			mod=mod->next;
		}
		mod=*ptr;
		if(f==0)
		{
			printf("percentage is not found\n");
			return;
		}
		printf("enter rollno:\n");
		scanf("%d",&num);
		while(mod)
		{
			if(num==mod->rollno)
			{
				printf("enter name and percentage:\n");
				scanf("%s %f",mod->name,&mod->percentage);
			}
			mod=mod->next;
		}

	}
	else
		printf("unknown choice\n");
}

