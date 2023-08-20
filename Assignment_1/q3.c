#include <stdio.h>
int main()
{
	int i=0,j=0,k=0;
	int ch=1;
	for(i=1;i<=4;i++)
	{
		for(k=3;k>=i;k--)
		printf(" ");
		
		for(j=1;j<=i;j++)
		printf("%d ",ch++);
		
		printf("\n");
	}
}