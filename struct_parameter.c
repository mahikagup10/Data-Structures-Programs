#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	int rno;
	int marks;
}s1={"shruti",23,88};

typedef struct student ST;
void modify_N(int x);
void modify_S(ST* s);
int main()
{
	printf("size = %d\n", sizeof(struct student));
	ST s2 =  {"shruti",23,88};
	
	s1 = s2;

	ST s3;
	printf("enter the details of s3\n");
	scanf("%s%d%d", s3.name,&s3.rno, &s3.marks);
	printf("%s\t%d\t%d", s3.name,s3.rno, s3.marks);
	
	modify_N(s3.rno);
	printf("%s\t%d\t%d\n", s3.name,s3.rno, s3.marks);
	
	modify_S(&s3);
	printf("%s\t%d\t%d\n", s3.name,s3.rno, s3.marks);
}

void modify_N(int x)
{
	x = 100;
}

void modify_S(ST* s)
{
	strcpy(s->name,"Jack");
	s->rno = 10;
	s->marks = 99;
	
}

