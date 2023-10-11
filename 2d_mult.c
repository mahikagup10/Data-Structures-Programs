#include<stdio.h>    
#include<stdlib.h>  
int main()
{  
	int p[10][10],q[10][10],r[10][10],r1,c1,r2,c2,i,j,k;    
	printf("enter the number of row and column of p matrix=\n");    
	scanf("%d%d",&r1,&c1);    
	printf("enter the number of row and column of q matrix=\n");    
	scanf("%d%d",&r2,&c2);    
	printf("enter the p matrix =\n");    

	if(c1!=r2)
		exit(1);
	for(i=0;i<r1;i++)    
	{    
		for(j=0;j<c1;j++)    
		{    
			scanf("%d",&p[i][j]);    
	}    
	}    
	printf("enter the q matrix =\n");    
	for(i=0;i<r2;i++)    
	{    
		for(j=0;j<c2;j++)    
		{    
		scanf("%d",&q[i][j]);    
		}    
	}    
    
	printf("multiply of the matrix=\n");    
	for(i=0;i<r1;i++)    
	{    
		for(j=0;j<c2;j++)    
		{    
			r[i][j]=0;    
			for(k=0;k<c1;k++)    
			{    
				r[i][j]+=p[i][k]*q[k][j];    
			}    
		}    
	}    
	//for printing result    
	for(i=0;i<r1;i++)    
	{    
		for(j=0;j<c2;j++)    
		{    
			printf("%d\t",r[i][j]);    
		}    
		printf("\n");    
	}    
return 0;  
} 