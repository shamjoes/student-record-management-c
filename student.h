#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct student
{
int rollno;
char name[50];
float percentage;
struct student *next;
};

void add_record(struct student **);
void delete_record(struct student **);
void show_list(struct student *);
void modify_list(struct student **);
void save_records(struct student *);
void sort_list(struct student **);
void delete_all(struct student **);
void reverse_list(struct student **);

