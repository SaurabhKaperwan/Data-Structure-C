#include<stdio.h>
int main()
{
	int n,count,scount=0;
	printf("Enter the limit:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the numbers:");
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j] && i!=j)
			{
				count++;
				break;
			}
		}
		if(count==0)
		{
			scount++;
		}
		if(scount==2)
		{
			printf("%d",a[i]);
			break;
		}
	}
}
