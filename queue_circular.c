#include<stdio.h>
int enqueue(int arr[], int front, int rear, int max)
{
	if(rear!=-1 && (rear+1)%max==front)
	{	printf("\nqueue full. can not insert more");
	}
	else
	{
		rear=(rear+1)%max;
		printf("\nenter data: ");
		scanf("%d",&arr[rear]);
		//if(rear==0 && front==-1)
		//	front=0;
	}
	return rear;
}
int dequeue(int arr[], int front, int rear, int max)
{	
	if(front==-1)
		printf("\nqueue empty. can not delete more");
	else
	{
		printf("\nthe data %d is being deleted",arr[front]);
		if(front==rear)
			front=-1;
		else
			front=(front+1)%max;
		//if(front==-1)
		//	rear=-1;
	}
	return front;
}
void peek(int arr[], int front)
{
	if(front==-1)
		printf("\nqueue is empty.");
	else
	{
		printf("\nthe data %d is on front",arr[front]);
	}
	//return top;
}
void display(int arr[], int front, int rear, int max)
{
	if(front==-1)
		printf("\nqueue empty.");
	else
	{
		for(int i=front;i!=rear;i=(i+1)%max)
			printf("\n%d data = %d",i,arr[i]);
		//if(rear!=-1)
		printf("\n%d data = %d",rear,arr[rear]);
	}
}
int main()
{
	int max=3,front=-1, rear=-1, arr[3],c;
	do
	{
		printf("\nwelcome to stack operations");
		printf("\n1. ENQUEUE");
		printf("\n2. DEQUEUE");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n0. Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:break;
			case 1:rear=enqueue(arr,front,rear,max);
				if(rear==0 && front==-1)
					front=0;
				break;
			case 2:front=dequeue(arr,front,rear,max);
				if(front==-1)
					rear=-1;
				break;
			case 3:peek(arr,front);
				break;
			case 4:display(arr,front,rear,max);
				break;
			default:printf("\ninvalid option");
				break;
		}
	}while(c);
}