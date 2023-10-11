#include<stdio.h>

int main()
{
	int a= 10;
	int* p = &a;

	/*printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", p);
	printf("%d\n", &p);
	printf("%d\n", *p);*/

	/*printf("%d\n", (*p)+1);//11
	printf("%d\n", *p++);	//11
	printf("%d\n", p);*/
	
	/*printf("%d\n", p);
	printf("%d\n", (*p)++);//10
	printf("%d\n", p);
	printf("%d\n", *p);*/

	/*printf("%d\n", p);
	printf("%d\n", ++(*p));//11
	printf("%d\n", p);
	printf("%d\n", *p);*/

	char ch = 'B';
	char* q = &ch;
	printf("%d\n",q);//6422296
	printf("%d\n",q+1);//297
	printf("%d\n",(int*)q-1);
	
		
return 0;
}