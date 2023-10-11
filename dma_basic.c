#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*MALLOC_CALLOC
	
	//int *p = (int*)malloc(sizeof(int));
	int *p = (int*)calloc(1,sizeof(int));
	*p = 10;
	int i;
	printf("%d %d\n",p,*p);
*/
	//int *x = (int*)malloc(5*sizeof(int));
	int *x = (int*)calloc(5,sizeof(int));
	if(x==NULL)
		printf("Memory not allocated\n");
	else
	{
		for(i=0;i<5;i++)
			printf("%d\t",*(x+i));
		for( i=0;i<5;i++)
			scanf("%d",(x+i));
		for(i=0;i<5;i++)
			printf("%d\t",*(x+i));		
	}
	

return 0;
}