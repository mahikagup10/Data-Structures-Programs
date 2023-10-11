
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *link;
};

typedef struct stack S;


void push(int);
void pop();
void display();
int peek();