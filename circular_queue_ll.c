#include<stdio.h>
#include<stdlib.h>	//imp
typedef struct node
{
	int data;
	struct node* link;
	
}NODE;
NODE* front = NULL;	//making it global 
NODE* rear = NULL;	//to avoid passing as function arguments
;

void display( );
void insert_last();
void delete_beg();

int main()
{
NODE *front, *rear;
front = NULL;		//initially as NULL
rear = NULL;
int n,c,ch;
do
{
	printf("enter the choice :\n 1-display\n 2-insert at last\n 3-delete from beginning \n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("entered choice is 1-display\n");
			display();
			break;
		
		case 2: printf("entered choice is 3-insert at last\n");
			insert_last();
			break;

		
		case 3: printf("entered choice is 5-delete at beginning\n");
			delete_beg();
			break;
	}

}while(1);

return 0;
}
//---------------------------------------------------------------DISPLAY-------------------------

void display()
{
	NODE* temp;
	temp = front;	//first node 
	if((front==NULL)&&(rear==NULL))		//check for only front== NULL only
		printf("Queue is Empty\n");
	else
	{
		do{
			printf("%d\t",temp->data);
			temp = temp->link;
		}while(temp != front);	//inc. temp will again point it back to front as it is CQ
	}
	printf("\n");
}
//--------------------------------------------------------------insert_beg-------------------------

void insert_last()
{
	printf("\nenter the data:\n");
	int value;
	scanf("%d", &value);
		//--------DATA ENQUEUE IN TEMP----------------
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = value;
	temp->link = NULL;

	if (front == NULL && rear == NULL)	//NO NODE
	{
		front = temp;		//both f and r points to temp
		rear = temp;
		rear->link = front;	//rear points back to front as it is CQ
	}

	else			//some node are already there linked
	{
		rear->link = temp;	//change rear->link-- make a connection to existing ll
		rear = temp;		//update rear
		temp->link = front;	//As it is CQ //check for rear->link = front ??
	}	
	
}


//--------------------------------------------------------------delete_beg-------------------------

void delete_beg()
{
	NODE* temp = front;	//points to beginning

	if(front==NULL && rear == NULL)
		printf("list is empty");

	else if(front == rear)	//one node only in ll
	{
		front = NULL;
		rear =NULL;
	}
	else			//multiple nodes
	{
		front = front->link;	//update front
		rear->link = front;	// update rear
	}
printf("\ndeleted node is --- %d\n", temp->data);
		free(temp);
}

