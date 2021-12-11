//Stack using Linked List
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
void begInsert(node **head,int data)
{
	node *ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("No space availble\n");
	}
	else
	{
		if(*head==NULL)
		{
			*head=ptr;
			ptr->info=data;
			ptr->next=NULL;
		}
		else
		{
			ptr->next=*head;
			*head=ptr;
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
	begInsert(&head,1);
	begInsert(&head,2);
	begInsert(&head,3);
	begInsert(&head,4);
	begInsert(&head,5);
	begInsert(&head,6);
	begInsert(&head,7);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	begDelete(&head);
	display(head);
	return 0;
}
