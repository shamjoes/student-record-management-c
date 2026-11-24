#include "student.h"


void save_records(struct student *SLL)
{
	if(SLL==0)
	{
		printf(BOLD RED"Records Not found"RST "\n");
		return;
	}
	FILE *fp=fopen("student.dat","w");
	if(fp==0)
	{
		return;
	}
	struct student *temp=SLL;

	while(temp)
	{
		fprintf(fp,"%d %s %.2f\n",temp->rollno,temp->name,temp->percentage);
		temp=temp->next;
	}
        printf(BOLD GREEN"Records Saved Successfully"RST "\n");
	fclose(fp);

}
