#include "student.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct student *head=0;
	char op;
	load_file(&head);
	while(1)
	{
		printf("****** STUDENT RECORD MENU ******\n");
		printf("a/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\n");
		printf("Enter your choice:\n");
		scanf(" %c",&op);
		switch(op)
		{
			case 'a':
			case 'A':add_record(&head);break;
			case 'd':
			case 'D':delete_record(&head);break;
			case 's':
			case 'S':show_list(head);break;
			case 'm':
			case 'M':modify_list(&head);break;
			case 'v':
			case 'V':save_records(head);break;
			case 'e':
			case 'E':Exit(head);break;
			case 't':
			case 'T':sort_list(&head);break;
			case 'l':
			case 'L':delete_all(&head);break;
			case 'r':
			case 'R':reverse_list(&head);break;
			default:printf("Inavlid choice. Please try again.\n");break;
		}
	}
}


void reverse_list(struct student **SLL)
{
	if(*SLL==0)
	{
		printf("Not found\n");
		return;
	}
	if((*SLL)->next==0)
	{
		printf("List reversed\n");
		return;
	}
	struct student *curr=*SLL;       
	struct student *prev=0;
	struct student *temp=0;

	while(curr)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	*SLL=prev;
		printf("List reversed\n");
}

int count_node(struct student *SLL)
{
	if(SLL==0)
	{
		printf("Not found\n");
		return 0;
	}
	int c=0;
	struct student *temp=SLL;
	while(temp)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

void sort_list(struct student **SLL)
{
	if(*SLL==0)
	{
		printf("Record not found\n");
		return;
	}
	char op;
	int i,j,c=count_node(*SLL);
	printf("N/n : sort with name\nP/p : sort with percentage\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'N':
		case 'n':

			struct student *temp1,*temp2;
			struct student  t;
			for(i=0;i<c;i++)
			{
				temp2=*SLL;
					for(j=0;j<c-1-i;j++)
					{
						if(temp1==0 || temp1->next==0)
						{
							break;
						}
						temp2=temp1->next;
						if((strcmp(temp1->name,temp2->name))>0)
						{
							t.rollno=temp1->rollno;
							strcpy(t.name,temp1->name);
							t.percentage=temp1->percentage;

							temp1->rollno=temp2->rollno;
							strcpy(temp1->name,temp2->name);
							temp1->percentage=temp2->percentage;

							temp2->rollno=t.rollno;
							strcpy(temp2->name,t.name);
							temp2->percentage=t.percentage;

							temp2=temp2->next;
						}
						temp1=temp1->next;
					}
				printf("Records sorted\n");
			}
			break;

		case 'P':
		case 'p':
			struct student *tem1,*tem2;
			struct student p;
			for(i=0;i<c;i++)
			{
				tem1=*SLL;
				for(j=0;j<c-1-i;j++)
				{
					if(tem1==0 || tem1->next==0)
					{
						break;
					}
					tem2=tem1->next;

					if(tem1->percentage < tem2->percentage)
					{
						p.rollno=tem1->rollno;
						strcpy(p.name,tem1->name);
						p.percentage=tem1->percentage;

						tem1->rollno=tem2->rollno;
						strcpy(tem1->name,tem2->name);
						tem1->percentage=tem2->percentage;

						tem2->rollno=p.rollno;
						strcpy(tem2->name,p.name);
						tem2->percentage=p.percentage;
                                                
					}
					tem1=tem1->next;
				}
                           }
				printf("Records sorted\n");
		 		break;

		default:printf("Invalid option\n");break;
	}
}


void Exit(struct student *SLL)
{
	char op;
	printf("S/s : Save and exit\nE/e : Exit without saving\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'S':
		case 's':
			save_records(SLL);
			struct student *temp=SLL;
                      
			while(temp)
			{
				struct student *next=temp->next;
				free(temp);
				temp=next;
			}
			printf("Records Saved\n");
			exit(0);

		case 'E':
		case 'e':
			struct student *tem=SLL;
			while(tem)
			{
				struct student *next=tem->next;
				free(tem);
				tem=next;
			}
			printf("Exit without Saving\n");
			exit(0);

		default:printf("Invalid option\n");break;
	}
}



void load_file(struct student **SLL)
{

	FILE  *fp=fopen("student.dat","r");
	if(fp==0)
	{
		return;
	}

	struct student *new=*SLL;
	while(1)
	{
		new=malloc(sizeof(struct student));
                if(new==0)
                {
                        break;
                }

		if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage))!=3)
		{
                        free(new);
			break;
		}
		else
		{
			new->next=0;
			if(*SLL==0)
			{
				*SLL=new;
			}
			else
			{
				struct student *last=*SLL;
				while(last->next)
					last=last->next;

				last->next=new;
			}
		}
	}
        fclose(fp);
}

void delete_all(struct student **SLL)
{
	if(*SLL==0)
	{
		printf("No records found\n");
		return;
	}

	struct student *del=*SLL;

	while(del)
	{
		*SLL=del->next;
		free(del);
		del=*SLL;
	}
	*SLL=NULL;
	printf("All Records Deleted Successfully\n");
}


