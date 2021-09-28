#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int enqueue(int front,int rear,int a[])
{
	if(rear==MAX-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		rear=rear+1;
		printf("Enter data:");
		scanf("%d",&a[rear]);
		return rear;
	}
}
int dequeue(int front,int rear,int a[])
{
	if(front==-1 || front>rear)
		printf("Queue is empty");
	else
	{
		printf("Element deleting is:%d\n",a[front]);
		front=front+1;
		return front;
	}
}
void peek(int front,int rear,int a[])
{
	
	if(front==-1 || front>rear)
		printf("Queue is empty");
	else
	{
		printf("%d",a[front]);
	}
}
	
	
void display(int front,int rear,int a[])
{
	if(rear<front || front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is:\n");
		for(int i=front;i<=rear;i++)
			printf(" %d",a[i]);
	}
}
int main()
{
	int front=-1,rear=-1,a[MAX],opt;
	printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit");
	while(1)
	{
		printf("\nEnter option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				rear=enqueue(front,rear,a);
				if(rear==0)
					front=0;
				break;
			case 2:
				front=dequeue(front,rear,a);
				if(front>rear)
				{
					rear=-1;
					front=-1;
				}
				break;
			case 3:
				peek(front,rear,a);
				break;				
			case 4:
				display(front,rear,a);
				break;
			case 5:
				printf("Goodbye\n");
				exit(0);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

