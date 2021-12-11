//Queue using linked list
#include <stdio.h>
#include<stdlib.h>
typedef struct  node_type
{
		int info;
		struct node_type *next;
}node;
void display(node *head)
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		while(head!=NULL)
		{
			printf(" %d",head->info);
			head=head->next;
		}
	}
	printf("\n");
}
void lastInsert(node **head,int data)
{
	node *ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("No space availble\n");
		return;
	}
	else
	{
		if(*head==NULL)
		{
			*head=ptr;
			ptr->next=NULL;
			ptr->info=data;
		}
		else
		{
			node *temp=*head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			ptr->info=data;

		}
	}
}
void begDelete(node **head)
{
	if(*head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else if((*head)->next==NULL)
	{
		*head=NULL;
	}
	else
	{
		node *temp=*head;
		*head=(*head)->next;
		free(temp);
	}
}
int main()
{
	node *head=NULL;
	lastInsert(&head,1);
	lastInsert(&head,2);
	lastInsert(&head,3);
	lastInsert(&head,4);
	lastInsert(&head,5);
	lastInsert(&head,6);
	lastInsert(&head,7);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	return 0;
}
