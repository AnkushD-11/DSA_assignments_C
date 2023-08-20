//  A
// B B
//C C C
//D D D D

#include <stdio.h>
int main()
{
	int i=0,j=0,k=0;
	char ch='A';
	for(i=1;i<=4;i++)
	{
		for(k=3;k>=i;k--)
		printf(" ");
		
		for(j=1;j<=i;j++)
		printf("%c ",ch);
		
		ch++;
		printf("\n");
	}
}
