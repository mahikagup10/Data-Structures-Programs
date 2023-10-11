#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j;
	printf("enter the number of rows and cols\n");
	scanf("%d%d",&r,&c);
	
	int** p;
	p = (int**)malloc(r*sizeof(int*));

	for(i=0;i<r;i++)
		*(p+i) = (int*)malloc(c*sizeof(int));



	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d", (*(p+i)+j));

	for(i=0;i<r;i++)
	{	for(j=0;j<c;j++)
			printf("%d\t", *(*(p+i)+j));
		printf("\n");
	}

return 0;
}