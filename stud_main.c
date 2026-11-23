#include "student.h"
#include<stdio.h>
int main()
{
struct student *head=0;
char op;
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
case 'E':return 0;
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
