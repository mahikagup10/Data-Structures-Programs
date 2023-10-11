#include<stdio.h>

int main()
{
	int i,j,r,c,a[10][10], b[10][10];
	printf("enter the no. of rows and columns\n");
	scanf("%d%d",&r, &c);
	
	printf("Enter array a:");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d", (*(a+i)+j));

	printf("Enter array b:");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d", (*(b+i)+j));
	

	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		(*(*(b+i)+j)) = (*(*(a+i)+j))+ (*(*(b+i)+j));

	for(i=0;i<r;i++)
	{	for(j=0;j<c;j++)
			printf("%d\t",(*(*(b+i)+j)));
		printf("\n");
	}
return 0;
}