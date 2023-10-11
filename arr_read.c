#include<stdio.h>
void read_arr(int a[], int n);
void modify_arr(int* a, int n);
void disp_arr(int* a, int n);
int main()
{
	int n,a[10];
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	read_arr(a,n);	//combo
	modify_arr(a,n);
return 0;
}

void read_arr(int a[], int n)
{
	//int i;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void modify_arr(int* a, int n)
{
	for(int i=0;i<n;i++)
		*(a+i) += 2;
		
	disp_arr(a,n);
}

void disp_arr(int* a, int n)
{
	printf("final array\n");
	for(int i=0;i<n;i++)
		printf("%d\t",*(a+i));
}