//Delete alternative nodes
#include <stdio.h>
#include<stdlib.h>
typedef struct  node_type
{
		int info;
		struct node_type *next;
}node;
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
void deleteAltNode(node **head)
{
	node *cur=(*head)->next,*prev=*head;
	if(*head==NULL)
		{
			return;
		}
	else
	{
		while(cur!=NULL && prev!=NULL)
		{
			prev->next=cur->next;
			free(cur);
			prev=prev->next;
			if(prev!=NULL)
			{
				cur=prev->next;
			}
		}
	}
}
void display(node *head)
{
	if(head==NULL)
		printf("No node availble\n");
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
	deleteAltNode(&head);
	display(head);
	return 0;
}
