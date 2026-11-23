#include "student.h"


void save_records(struct student *SLL)
{
	if(SLL=0)
	{
		printf("Records Not found\n");
		return;
	}
	FILE *fp=fopen("student.dat","w");
	if(fp==0)
	{
		printf("Not found\n");
		return;
	}
	struct student *temp=SLL;

	while(temp)
	{
		fprintf(fp,"%d %s %f\n",temp->rollno,temp->name,temp->percentage);
		temp=temp->next;
	}
	fclose(fp);

}
