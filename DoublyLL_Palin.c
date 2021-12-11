//Check whether is doubly linked list is palindrome or not
#include<stdio.h>
#include<stdlib.h>
typedef struct doubly_node
{
	int info;
	struct doubly_node *next;
	struct doubly_node *prev;
}node;
void lastInsert(node **head,node **tail,int data)
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
		ptr->prev=NULL;
		if(*head==NULL)
		{
			*head=*tail=ptr;
		}
		else
		{
			ptr->prev=*tail;
			(*tail)->next=ptr;
			*tail=ptr;
		}
	}
}
void checkPalin(node *head,node *tail)
{
	int count=0;
	if(head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		while(head!=tail)
		{
			if(head->info!=tail->info)
			{
				count++;
				break;
			}
			head=head->next;
			tail=tail->prev;
		}
		if(count != 0)
		{
			printf("\nNot palindrome");
		}
		else
		{
			printf("\nIt is palindrome");
		}
	}
}
void display(node *head)
{
	if(head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else 
	{
		while(head!=NULL)
		{
			printf(" %d",head->info);
			head=head->next;
		}
	}
}
int main()
{
	node *head=NULL,*tail=NULL;
	lastInsert(&head,&tail,1);
	lastInsert(&head,&tail,0);
	lastInsert(&head,&tail,1);
	display(head);
	checkPalin(head,tail);
	return 0;
}
