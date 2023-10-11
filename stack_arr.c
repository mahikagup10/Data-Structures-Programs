#include<stdio.h>
#define max 10

int S[max];
int top = -1;
void push(int x);
int pop();
void display();
int peek();

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
			case 2: printf("deleted number is %d\n", pop());
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

void push(int x)
{
	if(top == max)
		printf("OVERFLOW\n");
	else
	{
		top++;
		S[top] = x;
	}
}
int pop()
{ int x;
	if(top == -1)
	{
		printf("UNDERFLOW\n");
		return -1;
	}
	else
	{
		x = S[top];
		top--;
		return x;
	}
}
void display()
{
	if(top == -1)
		printf("Stack empty");
	else
	{
		int p = top;
		while(p>-1)
		{
			printf("%d \t", S[p]);
			p--;
		}
		printf("\n");
	}
}

int peek()
{
	printf("Top element is %d\n", S[top]);
}
