#include "student.h"

void modify_list(struct student **SLL)
{

if(*SLL==0)
{
printf("No records found\n");
return;
}

char op;
printf("Enter which record to search for modification\n");
printf("R/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\n");
scanf(" %c",&op);


switch(op)
{

	case 'R':
	case 'r':
		int rol;
		printf("Enter roll number\n");
		scanf("%d",&rol);

		struct student *temp=*SLL;
		while(temp)
		{
			if(temp->rollno==rol)
			{
				printf("Current Details\n");
				printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
				printf("**************************\n");

				scanf("%s %f",temp->name,&temp->percentage);
				printf("Record Updated\n");
                                break;
			}
			temp=temp->next;
                 }
			if(temp==0)
				printf("rollno not found\n");
	
		break;

	case 'N':
	case 'n':
		char nam[20];
                int c=0;
		printf("Enter name\n");
		scanf("%s",nam);
		struct student *temp=*SLL;
		struct student *curr=*SLL;
		while(temp)
		{
			if((strcmp(temp->name,nam))==0)
			{
				curr=temp;
				c++;
				curr=curr->next;
				temp=temp->next;
			}
		}
		if(c>1)
		{
                        struct student *curr=*SLL;
			while(curr)
			{
                                if((strcmp(curr->name,nam))==0)
				printf("%d %s %f\n",curr->rollno,curr->name,curr->percentage);
				curr=curr->next;
			}
			printf("\n");
			int no;
			printf("Enter your rollno\n");
			scanf("%d",&no);
			struct student *temp=*SLL;
			while(temp)
			{
				if(temp->rollno==no)
				{
					printf("Current Details\n");
					printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
					printf("**************************\n");
					printf("Update name and Percentage\n");
                                        
			              
					scanf("%s %f",temp->name,&temp->percentage);
					printf("Record Updated\n");
					break;
				}
				temp=temp->next;
			}
			
		}
		else if(c==1)
		{
			struct student *temp=*SLL;
			while(temp)
			{
				if((strcmp(temp->name,nam))==0)
				{
					printf("Current Details\n");
					printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
					printf("**************************\n");
					printf("Update name and Percentage\n");
                                        
					scanf("%s %f",temp->name,&temp->percentage);
					printf("Record Updated\n");
					return;
				}
				temp=temp->next;
			}
			if(temp==0)
				printf("Your Record not found\n");


		}
		else
		{
			printf("Name not found\n");
		}
		break;
case 'P':
case 'p':
		float fp;
                int c=0;
		printf("Enter percentage\n");
		scanf("%f",&fp);
              
		struct student *temp=*SLL;
		struct student *curr=*SLL;
		while(temp)
		{
			if(temp->percentage==fp)
			{
				curr=temp;
				c++;
				curr=curr->next;
				temp=temp->next;
			}
		}
		if(c>1)
		{ 
                        struct student *curr=*SLL;
			while(curr)
			{
                                if(curr->percentage==fp)
				printf("%d %s %f\n",curr->rollno,curr->name,curr->percentage);
				curr=curr->next;
			}
			printf("\n");
			int no;
			printf("Enter your rollno\n");
			scanf("%d",&no);
			struct student *temp=*SLL;
			while(temp)
			{
				if(temp->rollno==no)
				{
					printf("Current Details\n");
					printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
					printf("**************************\n");
					printf("Update name and Percentage\n");

					scanf("%s %f",temp->name,&temp->percentage);
					printf("Record Updated\n");
					break;
				}
				temp=temp->next;
			}
			
		}
		else if(c==1)
		{
			struct student *temp=*SLL;
			while(temp)
			{
				if(temp->percentage==fp)
				{
					printf("Current Details\n");
					printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
					printf("**************************\n");
					printf("Update name and Percentage\n");

					scanf("%s %f",temp->name,&temp->percentage);
					printf("Record Updated\n");
					break;
				}
				temp=temp->next;
			}
		}
		else
		{
			printf("Percentage not found\n");
		}
		break;
default:printf("Invalid option\n");break;
}
}
