#include<stdio.h>
#define max 15

typedef struct queue
{
	int q[max];
	int front;
	int rear;
}QUEUE;

void init(QUEUE* pq)
{
	pq->rear = -1;
	pq->front = 0;
}

int isempty(QUEUE* pq)
{
	return (pq->front > pq->rear);
}

int isfull(QUEUE* pq)
{
	return (pq->rear == max-1);
}
void enqueue(QUEUE* pq, int ele)//500
{
	if(isfull(pq))
		printf("full queue\n");
	else
	{
		pq->rear++;
		pq->q[pq->rear] = ele;
	}

}
int dequeue(QUEUE*pq)
{
	int ele;
	if(isempty(pq))
	{
		printf("empty queue\n");
		ele = -1;
	}
	else
	{
		ele = pq->q[pq->front];
		pq->front++;
	}
	return ele;
}
void display(QUEUE* pq)
{
	int k = pq->front;
	while(k<=pq->rear)
	{
		printf("%d\t", pq->q[k]);
		k++;
	}
	
}
int FoQ(QUEUE* pq)
{
	return (pq->q[pq->front]);
}

int main()
{
	QUEUE pq;
	init(&pq);
	int ch,ele;
	while(1)
	{	printf("enter the operation to be performed:\n");
		printf("1-enqueue\n2-dequeue\n3-display\n4-isempty\n5-ToQ\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("enter the element\n");
				scanf("%d", &ele);
				enqueue(&pq,ele);
				break;
			case 2: ele = dequeue(&pq);
				printf("deleted element is %d\n", ele);
				break;
			case 3: printf("Queue contents are:\n");
				display(&pq);
				break;
			case 4: if(isempty(&pq))
					printf("empty queue\n");
				else
					printf("Not empty queue\n");
				break;
			case 5: printf("front value= %d\n", FoQ(&pq));
				break;
				
		}
	}
return 0;
}