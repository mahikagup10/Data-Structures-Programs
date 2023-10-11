#include<stdio.h>
#define max 5
typedef struct CQueue
{
	int q[max];
	int front;
	int rear;
}CQUEUE;

void init(CQUEUE *pcq) 
{
	pcq->rear = max-1;
	pcq->front =max-1;
}
int isfull(CQUEUE *pcq)
{
	return ((pcq->rear+1)%max == pcq->front);
}
int isempty(CQUEUE* pcq)
{
	return (pcq->front == pcq->rear);
} 
void enqueue(CQUEUE *pcq, int ele)
{
	if (isfull(pcq))
		printf("full\n");
	else
	{
		pcq->rear = (pcq->rear+1)%max;
		pcq->q[pcq->rear] = ele;
	}	
}
int dequeue(CQUEUE* pcq)
{
	int ele =-1;
	if (isempty(pcq))
		printf("empty\n");
	else
	{
		pcq->front = (pcq->front+1)%max;
		ele = pcq->q[pcq->front] ;
	}
	return ele;
}
int display(CQUEUE* pcq)
{
	int k;
	if(isempty(pcq))
		printf("empty");
	else
	{
		k = (pcq->front+1)%max;
		while(k!=pcq->rear)	//k<=pcq->rear
		{
			printf("%d\t", pcq->q[k]);
			k = (k+1)%max;
		}
		printf("%d\n", pcq->q[k]);
		
	}
}
int FoQ(CQUEUE* pcq)
{
	return (pcq->q[(pcq->front+1)%max]);
}

int main()
{
	CQUEUE pcq;
	init(&pcq);
	int ch,ele;
	while(1)
	{	printf("enter the operation to be performed:\n");
		printf("1-enqueue\n2-dequeue\n3-display\n4-isempty\n5-ToQ\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("enter the element\n");
				scanf("%d",&ele);
				enqueue(&pcq,ele);
				break;
			
			case 2: ele = dequeue(&pcq);
				printf("deleted element is %d",ele);
				break;

			case 3: printf("the elements are:\n");
				display(&pcq);
				break;

			case 4: if(isempty(&pcq))
					printf("Empty\n");
				else
					printf("!empty\n");	
				break;

			case 5: printf("%d\n",FoQ(&pcq));
				break;
		}
	}
return 0;
}