#include<stdio.h>

int main()
{
	int arr[5] = {10,20,30,40,50};
	int *p;
	int i;
	p = arr;

	for(i=0;i<5;i++)
		printf("%d", *++p);	//10,20,30,40,50

	

	
return 0 ;
}