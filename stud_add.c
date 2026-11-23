#include "student.h"


void add_record(struct student **SLL)
{
	
	struct student *new=*SLL;
	new=malloc(sizeof(struct student));
        if(new==0)
        {
        printf("Memory not allocated\n"); 
        return;
        }

	int roll=1;
	while(1)
	{
		int found=0;
		struct student *temp=*SLL;
		while(temp)
		{
			if(temp->rollno==roll)
			{
				found=1;
				break;
			}
			temp=temp->next;
		}
		if(!found)
			break;

		roll++;
	}
        

        new->rollno=roll;
	printf("Enter name and percentage\n");
	scanf("%s %f",new->name,&new->percentage);
	if(new->percentage < 0.0f || new->percentage > 100.0f)
	{
		printf("Invalid percentage. Enter between 0.00 and 100.00\n");
		free(new);
		return;
	}

	new->next=0;
	if(*SLL==0)
	{
		*SLL=new;
	}
	else
	{
		struct student *last=*SLL;
		while(last->next)
		{
			last=last->next;
		}

		last->next=new;
	}
}
