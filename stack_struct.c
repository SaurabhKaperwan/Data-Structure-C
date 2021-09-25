#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
	int data;
}stack;
void push(stack[],int*);
void pop(stack[],int*);
void peek(stack[],int);
void display(stack[],int);
void main()
{
	stack arr[10];
	int top=-1,opt;
	printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit \n");
	while(1)
	{
		printf("Enter option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push(arr,&top);
				break;
			case 2:
				pop(arr,&top);
				break;
			case 3:
				peek(arr,top);
				break;
			case 4:
				display(arr,top);
				break;
			case 5:
				exit(0);
			default:
			printf("Invalid choice");
		}
	}
}
void push(stack arr[],int* top)
{
	if(*top==9)
	{
		printf("Stack is full\n");
	}
	else
	{
		*top=*top+1;
		printf("Enter number:");
		scanf("%d",&arr[*top].data);
	}
}
void pop(stack arr[],int* top)
{
	if(*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d is removing\n",arr[*top].data);
		*top=*top-1;
	}
}
void peek(stack arr[],int top)
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d",arr[top].data);
	}
}
void display(stack arr[],int top)
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf(" %d",arr[i].data);
		}
	}
}
