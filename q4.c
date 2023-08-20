// 1 + 1 + 4+ 9 + 25

#include <stdio.h>
int main()
{
	int n=0;
	printf("Enter N : ");
	scanf("%d",&n);
	int i=0,j=0,sum=2,sq=0;
	int a=1,b=1,c=0;
	for(int i=3;i<=n;i++)
	{
		c=a+b;
		sq=c*c;
		sum+=sq;
		a=b;
		b=c;
	}
	printf("The sum of series : %d",sum);
}