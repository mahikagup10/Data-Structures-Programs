//DE_QUEUE USING DOUBLY LL

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link,*prev;
}NODE;

typedef struct DEqueue
{
	NODE *rear, *front;
}DQUEUE;

void init(DQUEUE* pdq)
{
	pdq->rear = NULL;
	pdq->front = NULL;
}
void display(DQUEUE* pdq )
{
	NODE* i = pdq->front;
	if(pdq->front == NULL)
		printf("empty queue\n");
	else
	{
		while(i!=pdq->rear)
		{
			printf("%d\t", i->data);
			i=i->link;
		}
		printf("%d\n", i->data);
	}
}
void insert_beg(DQUEUE* pdq, int ele)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = ele;
	temp->link = NULL;
	temp->prev = NULL;
	
	if(pdq->front == NULL)
	{
		pdq->front = temp;
		pdq->rear = temp;
	}
	else
	{
		temp->link = pdq->front;
		pdq->front->prev = temp;
		pdq->front = temp;
	}

}
void insert_last(DQUEUE* pdq, int ele)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = ele;
	temp->link = NULL;

	if(pdq->rear == NULL)
	{
		pdq->front = temp;
		pdq->rear = temp;
	}
	else
	{
		pdq->rear->link = temp;
		temp->prev = pdq->rear;
		pdq->rear = temp;
	}
}
int delete_beg(DQUEUE* pdq)
{
	int ele;
	NODE* temp;
	if(pdq->front == NULL)	//NO NODE
	{
		ele =-1;
		return ele;
	}
	temp = pdq->front;
	ele = temp->data;
	
	if(pdq->front == pdq->rear)		//ONLY ONE NODE
	{
		pdq->front = NULL;
		pdq->rear = NULL;
	}
	else
	{
		pdq->front = temp->link;
		pdq->front->prev = NULL;
	}
	free(temp);
	return ele;
}

int delete_last(DQUEUE* pdq)
{
	int ele;
	NODE* temp;
	if(pdq->front == NULL)	//NO NODE
	{
		ele =-1;
	}
	temp = pdq->rear;
	ele = temp->data;
	
	if(pdq->front == pdq->rear)		//ONLY ONE NODE
	{
		pdq->front = NULL;
		pdq->rear = NULL;
	}
	else
	{
		pdq->rear = temp->prev;// can i write rear->prev
		pdq->rear->link= NULL;
	}
	free(temp);
	return ele;
}

int main()
{
	int k,x,ch;
	DQUEUE pdq;
	init(&pdq);
	printf("enter the operation to be performed\n");
	
	do
	{
	printf("1-insert beg\n 2-insert last\n 3-delete beg\n 4-delete last\n 5- display\n ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("enter the value\n");
			scanf("%d", &x);
			insert_beg(&pdq, x);
			break;

		case 2: printf("enter the value\n");
			scanf("%d", &x);
			insert_last(&pdq, x);
			break;
		case 3: k = delete_beg(&pdq);
			printf("ELEMENT DELETED = %d\n", k);
			break;
		case 4: k = delete_last(&pdq);
			printf("ELEMENT DELETED = %d\n", k);
			break;
		case 5: display(&pdq);
			break;
	}
	}while(1);
	
	


return 0;
}