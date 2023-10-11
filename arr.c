#include<stdio.h>

int main()
{
	int n,a[10];
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	//int i;
	for(int i=0;i<n;i++)
		scanf("%d",(a+i));

	printf("the array is");
	for(int i=0;i<n;i++)
		printf("%d\t",*(a+i));

	//using pointers
	int* p = a;
int i;
	for(i=0;i<n;i++)
		scanf("%d",(p+i));
int i;
	printf("the array is");
	for(i=0;i<n;i++)
		printf("%d\t",*(p+i));



return 0;
}