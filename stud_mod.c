#include "student.h"

void modify_list(struct student **SLL)
{

	if(*SLL==0)
	{
		printf(BOLD RED"No records found"RST "\n");
		return;
	}

	char op;
	printf(BOLD CYAN"Enter which record to search for modification"RST "\n");
	printf(BOLD GREEN "R/r" RST " : Search by roll number\n" BOLD GREEN "N/n" RST " : Search by name\n"BOLD GREEN "P/p" RST " : Search by percentage\n");
	scanf(" %c",&op);


	switch(op)
	{

		case 'R':
		case 'r':
			int rol;
			printf(BOLD CYAN"Enter roll number"RST "\n");
			scanf("%d",&rol);

			struct student *new=*SLL;
			while(new)
			{
				if(new->rollno==rol)
				{
					printf("**************************\n");
					printf("Current Details\n");
					printf(YELLOW "%d" RST " %s " GREEN "%.2f" "\n",new->rollno,new->name,new->percentage);
					printf("**************************\n");

					printf(BOLD CYAN "Update name and Percentage"RST "\n");
					scanf("%s %f",new->name,&new->percentage);

					if(new->percentage < 0.0f || new->percentage > 100.0f)
					{
						printf(BOLD RED "Invalid percentage. Enter between 0.00 and 100.00"RST "\n");
						free(new);
						return;
					}
					printf(BOLD GREEN "Record Updated"RST "\n");
					break;
				}
				new=new->next;
			}
			if(new==0)
				printf(BOLD RED "rollno not found"RST "\n");

			break;

		case 'N':
		case 'n':
			char nam[20];
			int u=0;
			printf(BOLD CYAN "Enter name"RST "\n");
			scanf("%s",nam);
			struct student *tem=*SLL;
			struct student *cur=*SLL;
			while(tem)
			{
				if((strcmp(tem->name,nam))==0)
				{
					cur=tem;
					u++;
					cur=cur->next;
					
				}
                        tem=tem->next;
			}
			if(u>1)
			{
				struct student *cu=*SLL;
				while(cu)
				{
					if((strcmp(cu->name,nam))==0)
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",cu->rollno,cu->name,cu->percentage);
					cu=cu->next;
				}
				printf("\n");
				int no;
				printf(BOLD CYAN "Enter your rollno"RST "\n");
				scanf("%d",&no);
				struct student *t=*SLL;
				while(t)
				{
					if(t->rollno==no)
					{
						printf("**************************\n");
						printf("Current Details\n");
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",t->rollno,t->name,t->percentage);
						printf("**************************\n");
						printf(BOLD CYAN"Update name and Percentage"RST "\n");


						scanf("%s %f",t->name,&t->percentage);

						if(t->percentage < 0.0f || t->percentage > 100.0f)
						{
							printf(BOLD RED "Invalid percentage. Enter between 0.00 and 100.00"RST "\n");
							return;
						}
						printf(BOLD GREEN "Record Updated"RST "\n");
						break;
					}
					t=t->next;
				}

			}
			else if(u==1)
			{
				struct student *l=*SLL;
				while(l)
				{
					if((strcmp(l->name,nam))==0)
					{
						printf("**************************\n");
						printf("Current Details\n");
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",l->rollno,l->name,l->percentage);
						printf("**************************\n");
						printf(BOLD CYAN "Update name and Percentage"RST "\n");

						scanf("%s %f",l->name,&l->percentage);

						if(l->percentage < 0.0f || l->percentage > 100.0f)
						{
							printf(BOLD RED "Invalid percentage. Enter between 0.00 and 100.0"RST "\n");
							return;
						}
						printf(BOLD GREEN "Record Updated"RST "\n");
						break;
					}
					l=l->next;
				}

			}
			else
			{


				printf(BOLD RED "Name not found"RST "\n");
			}
			break;
		case 'P':
		case 'p':
			float fp;
			int c=0;
			printf(BOLD CYAN "Enter percentage"RST "\n");
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
					
				}
                        temp=temp->next;
			}
			if(c>1)
			{ 
				struct student *curr=*SLL;
				while(curr)
				{
					if(curr->percentage==fp)
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",curr->rollno,curr->name,curr->percentage);
					curr=curr->next;
				}
				printf("\n");
				int no;
				printf(BOLD CYAN "Enter your rollno"RST "\n");
				scanf("%d",&no);
				struct student *temp=*SLL;
				while(temp)
				{
					if(temp->rollno==no)
					{
						printf("**************************\n");
						printf("Current Details\n");
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",temp->rollno,temp->name,temp->percentage);
						printf("**************************\n");
						printf(BOLD CYAN "Update name and Percentage"RST "\n");

						scanf("%s %f",temp->name,&temp->percentage);

						if(temp->percentage < 0.0f || temp->percentage > 100.0f)
						{
							printf(BOLD RED "Invalid percentage. Enter between 0.00 and 100.00"RST "\n");
							return;
						}
						printf(BOLD GREEN "Record Updated"RST "\n");
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
						printf("**************************\n");
						printf("Current Details\n");
						printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n",temp->rollno,temp->name,temp->percentage);
						printf("**************************\n");
						printf(BOLD CYAN "Update name and Percentage"RST "\n");

						scanf("%s %f",temp->name,&temp->percentage);

						if(temp->percentage < 0.0f || temp->percentage > 100.0f)
						{
							printf(BOLD RED"Invalid percentage. Enter between 0.00 and 100.00"RST "\n");
							return;
						}
						printf(BOLD GREEN "Record Updated"RST "\n");
						break;
					}
					temp=temp->next;
				}
			}
			else
			{
				printf(BOLD RED "Percentage not found"RST "\n");
			}
			break;
		default:printf(BOLD RED "Invalid option"RST "\n");break;
	}
}
