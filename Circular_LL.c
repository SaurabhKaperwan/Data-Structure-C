//Circular Queue
#include<stdio.h>
#include<stdlib.h>
typedef struct circular_node
{
	int info;
	struct circular_node *next;
}node;
void lastInsert(node **tail,int data)
{
	node *ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("No space available\n");
	}
	else
	{
		ptr->info=data;
		ptr->next=NULL;
		if((*tail)==NULL)
		{
			*tail=ptr;
			ptr->next=*tail;
		}
		else
		{
			ptr->next=(*tail)->next;
			(*tail)->next=ptr;
			*tail=ptr;
		}
	}
}
void display(node *tail)
{
	if(tail==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		node *temp=tail->next;
		while(temp !=tail)
		{
			printf(" %d",temp->info);
			temp=temp->next;
		}
		printf(" %d",temp->info);
	}
}
int main()
{
	node *tail=NULL;
	lastInsert(&tail,1);
	lastInsert(&tail,2);
	lastInsert(&tail,3);
	display(tail);
	return 0;
}
