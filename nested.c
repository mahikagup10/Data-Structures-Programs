#include<stdio.h>
#include<string.h>

struct name
	{
		char fname[20];
		char lname[20];
	}NAME;
struct student
{
	struct name NAME;
	int rno;
	int marks;
};

typedef struct student ST;

int main()
{
	printf("size = %d\n", sizeof(struct student));
	
	ST s;
	printf("\n enter the details\n");
	scanf("%s%s%d%d", s.NAME.fname,s.NAME.lname,&s.rno,&s.marks);
	printf("\n%s\t%s\t%d\t%d", s.NAME.fname,s.NAME.lname,s.rno,s.marks);
}