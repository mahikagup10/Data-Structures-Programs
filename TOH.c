#include<stdio.h>
void TH(int n, char src, char dest, char aux);
int main()
{
	printf("enter the no. of disks\n");
	int n;
	scanf("%d", &n);
	TH(n,'A','B','C');
return 0 ;
}
void TH(int n, char src, char dest, char aux)
{
	if(n==1)
	{
		printf("MOve 1 from %c to %c\n",src,dest);
		return;
	}

	TH(n-1,src,aux,dest);
	printf("Move disk %d from %c to %c\n",n,src,dest);
	TH(n-1,aux,dest,src);

}