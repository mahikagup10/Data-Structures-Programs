#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
typedef struct node NODE;

NODE* start= NULL;

void display(NODE* );
NODE* insert_beg(NODE*);	//where ever the start might change return it back
NODE* insert_last(NODE*);
NODE* insert_index(NODE*, int);
NODE* delete_beg(NODE* );
void delete_last(NODE*);
NODE* delete_key(NODE*, int);
NODE* delete_all(NODE*);

int main()
{
int n,c,ch;
do
{
	printf("enter the choice :\n 1-display\n 2-insert at beginning\n 3-insert at last\n 4-insert at a given position\n 5-delete from beginning \n 6-delete from last\n 7-delete a particular node\n 8-delete entire list\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("entered choice is 1-display\n");
			display(start);
			break;
		
		case 2: printf("entered choice is 2-insert at beginning\n");
			start = insert_beg(start);
			break;

		case 3: printf("entered choice is 3-insert at last\n");
			start = insert_last(start);
			break;

		case 4: printf("entered choice is 4-insert at an index\n");
			printf("enter the index location after which you want to insert\n");
			int index;
			scanf("%d", &index);
			start = insert_index(start,index);
			break;
		
		case 5: printf("entered choice is 5-delete at beginning\n");
			start = delete_beg(start);
			break;

		case 6: printf("entered choice is 6-delete from last\n");
			delete_last(start);
			break;

		case 7: printf("entered choice is 7-delete a key\n");
			printf("enter the key");
			int key;
			scanf("%d", &key);
			start = delete_key(start,key);
			break;
	
		case 8: printf("entered choice is 8-delete entire list\n");
			start = delete_all(start);
			break;
	}

//printf("enter loop condition\n ");

//scanf("%d", &c);
}while(c!=0);

return 0;
}
//---------------------------------------------------------------DISPLAY-------------------------

void display(NODE* start)
{
	NODE* p = start;printf("\nstart.... = %d\n", start);
	if(p==NULL)
		printf("\nnoitems\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d-->", p->data);
			p = p->link;
		}	
		printf("\n");
	}
}
//--------------------------------------------------------------insert_beg-------------------------

NODE* insert_beg(NODE* start)
{
	printf("\nenter the data:");
	int value;
	scanf("%d", &value);
	if (start == NULL)
	{
		start = (NODE*)malloc(sizeof(NODE));
		start->data = value;
		start->link = NULL;
	}

	else
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = value;
		temp->link = start;
		start = temp;
	}	
	return start;
}
//--------------------------------------------------------------insert_last-------------------------

NODE* insert_last(NODE* start)
{
	printf("\nenter the data:");
	int value;
	scanf("%d", &value);
	printf("\nstart = %d\n", start);
	if (start == NULL)
	{
		start = (NODE*)malloc(sizeof(NODE));
		start->data = value;
		start->link = NULL;printf("\nstart. = %d\n", start);
	}

	else
	{	
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = value;
		temp->link = NULL;
		NODE* p = start;
		NODE* befp = NULL;
	
		while(p->link!=NULL)
		{	
			p = p->link;
		}

		p->link = temp;	
	}
return start;
}

//--------------------------------------------------------------insert_index-------------------------

NODE* insert_index(NODE* start, int index)
{
	printf("\nenter the data:");
	int value;
	scanf("%d", &value);
	
	if (start == NULL)
	{
		printf("No items, where to insert?\n");
	}

	else
	{	
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = value;
		temp->link = NULL;
		
		NODE* p = start;
		NODE* befp = NULL;
		int count = 1;
		while(p!=NULL && count<=index)
		{	
			befp = p;
			p = p->link;
			count++;
			printf("Count = %d\n", count);
		}

		temp->link = p;
		befp->link = temp;	
	}
return start;
}

//--------------------------------------------------------------delete_beg-------------------------

NODE* delete_beg(NODE* start)
{
	if(start == NULL)
		printf("list is empty");
	else
	{
		NODE* p = start;
		p->data = start->data;
		p->link = start->link;
	
		start = p->link;
		printf("\ndeleted node is --- %d\n", p->data);
		free(p);
	}
return start;
}

//--------------------------------------------------------------delete_last-------------------------

void delete_last(NODE* start)
{
	NODE* p = start;
	//printf("\nstart.... = %d\n", start);
	if(start==NULL)
		printf("\nnoitems\n");
	else
	{
		NODE *befp = NULL;
		
		while(p->link!=NULL)
		{
			befp = p;
			p = p->link;
		}
		befp->link = NULL;
		
		free(p);
	}
//return start;	
}

//--------------------------------------------------------------delete_key-------------------------

NODE* delete_key(NODE* start, int k)
{
	if(start == NULL)
		printf("list is empty");
	else if(start->data == k)
	{
		/*NODE* p = start;
		p->data = start->data;
		p->link = start->link;
	
		start = p->link;
		printf("\ndeleted node is --- %d\n", p->data);
		free(p);//doing same thing as delete_beg*/
		start = delete_beg(start); //good way
	}
	else
	{
		NODE* p = start;
		NODE* befp = NULL;
		while(p!=NULL && p->data!=k)
		{
			befp = p;
			p = p->link;
		}

		befp->link = p->link;
		
		printf("\ndeleted node is --- %d\n", p->data);
		free(p);
	}
return start;
}

//--------------------------------------------------------------delete_all------------------------

NODE* delete_all(NODE* start)
{
	if(start == NULL)
		printf("list is empty");
	else
	{
		NODE* p = start;
		NODE* befp = NULL;
		while(p!=NULL)
		{
			befp = p;
			printf("deleted node is %d\n", befp->data);
			p = p->link;
			free(befp);
		}
		start = NULL;
	}
return start;
}
