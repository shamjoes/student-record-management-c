#include "student.h"


void show_list(struct student *SLL)
{
	struct student *temp=SLL;

	if(temp==0)
	{
		printf("No student records available\n");
		return;
	}
	printf("***********************************\n");
	printf("Roll No.  Name  Percentage\n");
	printf("***********************************\n");
	while(temp)
	{
		printf("%d %s %f\n",temp->rollno,temp->name,temp->percentage);
		temp=temp->next;
	}
	printf("***********************************\n");
}
