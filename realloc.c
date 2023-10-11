#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("enter the old value\n");
	int n, ns,i;
	scanf("%d", &n);
	char *x = (char*)malloc(n*sizeof(char));
	if(x==NULL)
		printf("Memory not allocated\n");
	else
	{
		for(i=0;i<n;i++)
			printf("%c\t",*(x+i));
		for( i=0;i<n;i++)
			scanf(" %c",(x+i));
		for(i=0;i<n;i++)
			printf("%c\t",*(x+i));		
	}
	
	printf("enter new value\n");
	scanf("%d", &ns);
	printf("adddress before %d\n", x);
	
	x = (char*) realloc(x, ns*sizeof(char));
	if(x==NULL)
		printf("Memory not allocated\n");
	else
	{
		printf("adddress after %d\n",x);
		for(i=0;i<n;i++)
			printf("%c\t",*(x+i));
		for( i=n;i<ns;i++)
			scanf("%c",(x+i));
		for(i=0;i<ns;i++)
			printf("%c\t",*(x+i));		
	}
	 
}