#include<stdio.h>
#include<stdlib.h>
int* pop(int*,int*);
int* push(int*,int*);
void peek(int*,int);
void display(int*,int);
void main()
{ 
	int top=-1,opt,*stack_ptr=NULL;
	printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit \n");
	while(1)
	{
		printf("Enter option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				stack_ptr=push(stack_ptr,&top);
				break;
			case 2:
				stack_ptr=pop(stack_ptr,&top);
				break;
			case 3:
				peek(stack_ptr,top);
				break;
			case 4:
				display(stack_ptr,top);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice");
		}
	}
}

int* push(int *stack_ptr,int *top)
{
	int *ptr=NULL;
	if(stack_ptr==NULL)
	{
		ptr=(int*)calloc(1,sizeof(int));
	}
	else
	{
		ptr=(int*)realloc(stack_ptr,sizeof(int)*((*top)+1));
	}
	if(ptr==NULL)
	{
		printf("No memory available");
	}
	else
	{
		(*top)=(*top)+1;
		stack_ptr=ptr;
		printf("Enter data:");
		scanf("%d",&stack_ptr[(*top)]);
		return stack_ptr;
	}
}
int* pop(int *stack_ptr,int *top)
{
	int *ptr=NULL;
	if(stack_ptr==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Element will be deleted is %d",stack_ptr[*top]);
		ptr=(int*)realloc(stack_ptr,sizeof(int)*(*top-1));
		stack_ptr=ptr;
		*top=*top-1;
		return stack_ptr;
	}
}	
void peek(int *stack_ptr,int top)
{
	if(stack_ptr==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		printf(" %d ",stack_ptr[top]);
	}
}
void display(int *stack_ptr,int top)
{
	if(stack_ptr==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf(" %d ",stack_ptr[i]);
		}
	}
}