//*
//# *
//# * #
//* # * #
//* # * # *

#include <stdio.h>
int main()
{
	int i=0,j=0,c=0;
	char ch='*';
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(c%2==0)
			ch='*';
			else
			ch='#';
			printf("%c",ch);
			c++;
		}
		printf("\n");
	}
}
