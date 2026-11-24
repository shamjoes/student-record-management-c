#include "student.h"


void delete_record(struct student **SLL)
{

	if(*SLL==0)
	{
		printf(BOLD RED "Records Not found"RST "\n");
		return;
	}
	int c=0;
	char op;
	printf(
			BOLD GREEN "R/r" RST " : Enter roll number to delete\n"
			BOLD GREEN "N/n" RST " : Enter name to delete\n"
	      );
	scanf(" %c",&op);
	int num;
	char nam[20];
	struct student *del=*SLL;
	struct student *sin=*SLL;
	struct student *curr=*SLL;
	struct student *prev=0;

	switch(op)
{
	case 'R':
	case 'r':
		printf(BOLD CYAN "Enter roll number"RST "\n");
		scanf("%d",&num);
		while(del)
		{
			if(del->rollno==num)
			{
				if(del==*SLL)
				{
					*SLL=del->next;
				}
				else
				{
					prev->next=del->next;
				}
				free(del);
				printf(BOLD GREEN"Record deleted"RST "\n");
				return;
			}
			prev=del;
				del=del->next;         
	        }
                if(del==0)
                printf(BOLD RED "Your record not found"RST "\n");
		break;

	case 'N':
	case 'n':
		printf(BOLD CYAN"Enter Name"RST "\n");
		scanf(" %s",nam);
		while(del)
		{
			if((strcmp(del->name,nam))==0)
			{
				curr=del;
				c++;
				curr=curr->next;
				
			}
                del=del->next;
		}
		if(c>1)
		{  
			struct student *rol=*SLL; 
                        struct student *curr=*SLL;
			while(curr)
			{
				printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",curr->rollno,curr->name,curr->percentage);
				curr=curr->next;
			}
			int no;
			printf(BOLD CYAN"Enter roll number to delete your record"RST "\n");
			scanf("%d",&no);
			while(rol)
			{
				if(rol->rollno==no)
				{
					if(rol==*SLL)
					{
						*SLL=rol->next;
					}
					else
					{
						prev->next=rol->next;
					}
					free(rol);
                                        printf(BOLD GREEN"Record deleted"RST "\n");
					break;
				}
				prev=rol;
				rol=rol->next;
			}
                        if(rol==0)
                        printf(BOLD RED"record not found"RST "\n");
		}           

		else if(c==1)
		{
			while(sin)
			{
				if((strcmp(sin->name,nam))==0)
				{
					if(sin==*SLL)
					{
						*SLL=sin->next;
					}
					else
					{
						prev->next=sin->next;
					}
					free(sin);
					printf(BOLD GREEN"Record deleted"RST "\n");
					break;
				}
				prev=sin;
				sin=sin->next;         
			}
		}
		if(c==0)
			printf(BOLD RED"Records not found"RST "\n");
		break;
	default:printf(BOLD RED"Invalid option"RST "\n");break;
}
}
