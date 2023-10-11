#include<stdio.h>

int main()
{
	double *ptr;
	double x = 99;

	/*printf("%d\n", ptr);//garbage
	printf("%d\n", &ptr);//address

	*ptr = x;
	printf("%d\n", ptr);//addres of x
	printf("%d\n", *ptr);//error/address/garbage
*/

	int a =10;
	int* p =&a
	int** pp;
	pp = &p;

	printf("%d\n", a);//10
	printf("%d\n", p);//address of a
	printf("%d\n", **pp);//10

return 0;
}