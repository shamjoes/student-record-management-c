#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RST "\033[0m"

#define BOLD "\033[1m"
#define UND "\033[4m"


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
void Exit(struct student *);
void load_file(struct student **);
int count_node(struct student *);
