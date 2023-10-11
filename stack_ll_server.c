#include<stdio.h>
#include "stack_ll_header.h"
#include<stdlib.h>

S* top = NULL;
void push(int x)
{
	S* temp = (S*)malloc(sizeof(S));
	if(temp == NULL)
		printf("ERROR\n");
		
	else
	{
		temp->data = x;
		temp->link = NULL;
		
		temp->link = top;
		top = temp;
	}
	
}
void pop()
{ 
	
	S* temp = (S*)malloc(sizeof(S));
	if(temp == NULL)
		printf("ERROR\n");
		
	else
	{
		temp->data = top->data;
		temp->link = NULL;
		top = top->link;
		free(temp);	
	}
}
void display()
{
	if(top == NULL)
		printf("Stack empty");
	else
	{
		S* p = top;
		while(p!=NULL)
		{
			printf("%d \t", p->data);
			p = p->link;
		}
		printf("\n");
	}
}

int peek()
{
	printf("Top element is %d\n", top->data);
}
