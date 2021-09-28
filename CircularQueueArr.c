#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int enqueue(int front,int rear,int a[])
{
	if((rear+1)%MAX==front)
		printf("Queue is full");
	else
	{
		rear=(rear+1)%MAX;
		printf("Enter element:");
		scanf("%d",&a[rear]);
		return rear;
	}
}
int dequeue(int front,int dequeue,int a[])
{
	if(front==-1 && rear==-1 || )
		printf("Stack is empty");
	else
	{
		printf("Deleting number is:%d",a[front]);
		front=(front+1)%MAX;
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

