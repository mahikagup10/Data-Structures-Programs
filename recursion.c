#include<stdio.h>
void odd();
void even();
int n=1;

int main()
{
	odd();
return 0;
}
void odd()
{
	if(n<=6)
	{
		printf("%d\t", n+1);
		n++;
		even();
	}
}
void even()
{
	if(n<=6)
	{
		printf("%d\t", n-1);
		n++;
		odd();
	}
}