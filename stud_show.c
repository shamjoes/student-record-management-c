#include "student.h"


void show_list(struct student *SLL)
{
	struct student *temp=SLL;

	if(temp==0)
	{
		printf(BOLD RED "No student records available"RST" \n");
		return;
	}
	printf("***********************************\n");
	printf("Roll No.  Name  Percentage\n");
	printf("***********************************\n");
	while(temp)
	{
		printf(YELLOW "%d" RST " %s " GREEN "%.2f" RST "\n" ,temp->rollno,temp->name,temp->percentage);
		temp=temp->next;
	}
	printf("***********************************\n");
}
