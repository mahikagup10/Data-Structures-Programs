#include<stdio.h>
#include "stack_ll_header.h"
#include<stdlib.h>
int main()

{
	int x;
	printf("enter the choice of operation\n");
	do
	{
		int ch;
		printf("1-push\n 2-pop\n 3-display\n 4-peek\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("enter the number to be inserted\n");
				scanf("%d", &x);
				push(x);
				break;
			case 2: printf("deleted\n"); 
				pop();
				break;
			case 3: printf("The eleements are\n");
				display();
				break;
			case 4: printf("top of stack is %d\n", peek());
				break;
			default: printf("enter a valid choice\n");
				break;
		}
	}while(1);
return 0;
}
