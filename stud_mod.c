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

			struct student *new=*SLL;
			while(new)
			{
				if(new->rollno==rol)
				{
					printf("Current Details\n");
					printf("%d %s %.2f\n",new->rollno,new->name,new->percentage);
					printf("**************************\n");

					scanf("%s %f",new->name,&new->percentage);

					if(new->percentage < 0.0f || new->percentage > 100.0f)
					{
						printf("Invalid percentage. Enter between 0.00 and 100.00\n");
						free(new);
						return;
					}
					printf("Record Updated\n");
					break;
				}
				new=new->next;
			}
			if(new==0)
				printf("rollno not found\n");

			break;

		case 'N':
		case 'n':
			char nam[20];
			int u=0;
			printf("Enter name\n");
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
					tem=tem->next;
				}
			}
			if(u>1)
			{
				struct student *cu=*SLL;
				while(cu)
				{
					if((strcmp(cu->name,nam))==0)
						printf("%d %s %.2f\n",cu->rollno,cu->name,cu->percentage);
					cu=cu->next;
				}
				printf("\n");
				int no;
				printf("Enter your rollno\n");
				scanf("%d",&no);
				struct student *t=*SLL;
				while(t)
				{
					if(t->rollno==no)
					{
						printf("Current Details\n");
						printf("%d %s %f\n",t->rollno,t->name,t->percentage);
						printf("**************************\n");
						printf("Update name and Percentage\n");


						scanf("%s %f",t->name,&t->percentage);

						if(t->percentage < 0.0f || t->percentage > 100.0f)
						{
							printf("Invalid percentage. Enter between 0.00 and 100.00\n");
							free(t);
							return;
						}
						printf("Record Updated\n");
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
						printf("Current Details\n");
						printf("%d %s %.2f\n",l->rollno,l->name,l->percentage);
						printf("**************************\n");
						printf("Update name and Percentage\n");

						scanf("%s %f",l->name,&l->percentage);

						if(l->percentage < 0.0f || l->percentage > 100.0f)
						{
							printf("Invalid percentage. Enter between 0.00 and 100.00\n");
							free(l);
							return;
						}
						printf("Record Updated\n");
						break;
					}
					l=l->next;
				}

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
						printf("%d %s %.2f\n",curr->rollno,curr->name,curr->percentage);
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

						if(temp->percentage < 0.0f || temp->percentage > 100.0f)
						{
							printf("Invalid percentage. Enter between 0.00 and 100.00\n");
							free(temp);
							return;
						}
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
						printf("%d %s %.2f\n",temp->rollno,temp->name,temp->percentage);
						printf("**************************\n");
						printf("Update name and Percentage\n");

						scanf("%s %f",temp->name,&temp->percentage);

						if(temp->percentage < 0.0f || temp->percentage > 100.0f)
						{
							printf("Invalid percentage. Enter between 0.00 and 100.00\n");
							free(temp);
							return;
						}
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
