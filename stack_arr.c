#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int push(int[],int);
int pop(int[],int);
void display(int[],int);
void peek(int[],int);
int main()
{
    int a[MAX],top=-1,opt;
    printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            top=push(a,top);
            break;
        case 2:
            top=pop(a,top);
            break;
        case 3:
            peek(a,top);
            break;
        case 4:
            display(a,top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!!!");
        }
    }
    return 0;
}
int push(int a[],int top)
{
    if(top==MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
        top=top+1;
        printf("Enter data:");
        scanf("%d",&a[top]);
        return top;
    }
}
int pop(int a[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Element will be deleting is %d \n",a[top]);
        top=top-1;
        return top;
    }

}
void display(int a[],int top)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
void peek(int a[],int top)
{
    printf("%d ",a[top]);
}
