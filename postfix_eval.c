#include <stdio.h>
int push(int stack[], int top, int max, char ip)
{
	if(top==max-1)
	{	printf("\nstack full. can not insert more");
	}
	else
	{
		stack[++top] = ip-48;
		//printf("\nenter data: ");
		//scanf("%d",&stack[++top]);
	}
	return top;
}
int pop(int stack[], int top, char operator)
{	
	if(top==-1)
		printf("\nstack empty. can not delete more");
	else if(top<1)
	{	printf("\ninsufficient operands\n");
	}
	else
	{
		switch(operator)
		{
			case '+':stack[top-1]+=stack[top];
					top-=1;
					break;
			case '-':stack[top-1]-=stack[top];
					top-=1;
					break;
			case '*':stack[top-1]*=stack[top];
					top-=1;
					break;
			case '/':stack[top-1]/=stack[top];
					top-=1;
					break;
			case '^':;int temp=stack[top-1];
					for(int i=1;i<stack[top];i++)
						stack[top-1]*=temp;
					top-=1;
					break;
			default:printf("\nInvalid operator\n");
					break;
		}
	}
	return top;
}
int main()
{
	char ip_postfix[50]="12-3+";
	int stack[35], top=-1, max=35;
	for(int i=0;ip_postfix[i]!='\0';i++)
	{
		if(ip_postfix[i]>='0' && ip_postfix[i]<='9')
			top = push(stack, top, max, ip_postfix[i]);
		else
			top = pop(stack, top, ip_postfix[i]);
	}
	printf("\nThe evaluation value at stack[%d] = %d %d\n",top, stack[top], stack[0]);
	return 0;
}