#include<stdio.h>
int push(char stack[], int top, int max, char ip)
{
	if(top==max-1)
	{	printf("\nstack full. can not insert more");
	}
	else
	{
		stack[++top] = ip;
		//printf("\nenter data: ");
		//scanf("%d",&stack[++top]);
	}
	return top;
}
int pop(char stack[], int top)
{	
	if(top==-1)
		printf("\nstack empty. can not delete more");
	else
	{
		if(stack[top]!='(')
			printf(" %c ",stack[top]);
		top-=1;
	}
	return top;
}
int main()
{
	int max=30,top=-1, c;
	char ip_str[50], stack[30], ip;
	printf("\n enter the infix expression: ");
	scanf("%s",ip_str);
	int i=0;
	while(ip_str[i]!='\0')			//for(int i=0;ip_str[i]!='\0';i++)
	{
		if(ip_str[i]=='+' || ip_str[i]=='-')
		{
			if(top==-1 || stack[top]=='(')			// stack[top] lower precedence
				top=push(stack,top,max,ip_str[i]);
			else if(stack[top]=='+' || stack[top]=='-' ||stack[top]=='*' || stack[top]=='/' || stack[top]=='^')	// stack[top] equal (with same associativity) or higher precedence
			{	top=pop(stack, top);
				i-=1;		// so that it comes to current character need to be processed again
			}
		}
		else if(ip_str[i]=='*' || ip_str[i]=='/')
		{
			if(top==-1 || stack[top]=='(' || stack[top]=='+' || stack[top]=='-')
				top=push(stack,top,max,ip_str[i]);
			else if(stack[top]=='*' || stack[top]=='/' || stack[top]=='^')
			{	top=pop(stack, top);
				i-=1;
			}
		}
		else if(ip_str[i]=='^')
			top=push(stack,top,max,ip_str[i]);		// for right2left associativity and lower precedences
		else if(ip_str[i]=='(')
			top=push(stack,top,max,ip_str[i]);
		else if(ip_str[i]==')')
		{	while(top!=-1 && stack[top]!='(')
				top=pop(stack, top);
			if(top==-1 || stack[top]!='(')
				printf("\nERROR ( missing");
			else
				top=pop(stack, top);
			//i-=1;		// because closing bracket need not be processed again
		}
		else
			printf(" %c ",ip_str[i]);
		i++;
	}
	while(top!=-1)
		top=pop(stack, top);
	printf("\n");
}