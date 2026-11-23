#include "student.h"


void delete_record(struct student **SLL)
{

if(*SLL==0)
{
printf("Records Not found\n");
return;
}
int c=0;
char op;
printf("R/r : Enter roll number to delete\nN/n : Enter name to delete\n");
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
		printf("Enter roll number\n");
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
				printf("Record deleted\n");
				return;
			}
			prev=del;
				del=del->next;         
	        }
                if(del==0)
                printf("Your record not found\n");
		break;

	case 'N':
	case 'n':
		printf("Enter Name\n");
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
				printf("%d %s %.2f\n",curr->rollno,curr->name,curr->percentage);
				curr=curr->next;
			}
			int no;
			printf("Enter roll number to delete your record:\n");
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
                                        printf("Record deleted\n");
					break;
				}
				prev=rol;
				rol=rol->next;
			}
                        if(rol==0)
                        printf("record not found\n");
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
					printf("Record deleted\n");
					break;
				}
				prev=sin;
				sin=sin->next;         
			}
		}
		if(c==0)
			printf("Records not found\n");
		break;
	default:printf("Invalid option\n");break;
}
}
