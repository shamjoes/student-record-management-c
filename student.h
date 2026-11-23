#include<stdio.h>

struct student
{
int rollno;
char name[50};
float percentage;
struct student *next;
};

void add_record(SLL **);
void delete_record(SLL *);
void show_list(SLL *);
void modify_list(SLL **);
void save_records(SLL *);
void sort_list(SLL *);
void delete_all(SLL *);
void reverse_list(SLL *);

