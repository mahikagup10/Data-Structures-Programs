#include<stdio.h>
#include<string.h>

union student
{	
	char name[20];
	int rno;
	int marks;
};

typedef union student ST;
enum year
{
	first, second=-1, third, forth
}

int main()
{
	printf("size = %d\n", sizeof(union student));
	
	ST s;
	//printf("\n enter the details\n");
	//scanf("%s%d%d", s.name,&s.rno,&s.marks);
	//printf("\n%s\t%d\t%d", s.name,s.rno,s.marks);

		

	//Jack 65 65
}