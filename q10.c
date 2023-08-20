#include<stdio.h>
int main()
{
	int i=0,j=0,M=0,N=0,k=0,temp=0;
	printf("Enter size of array 1 : ");
	scanf("%d",&M);
	printf("Enter size of array 2 : ");
	scanf("%d",&N);
	int A[M];
	int B[N];
	for(i=0;i<M;i++)
	{
		printf("Enter A[%d] : ",i);
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++)
	{
		printf("Enter B[%d] : ",i);
		scanf("%d",&B[i]);
	}
	int C[M+N];
	for(i=0;i<M+N;i++)
	{
		if(i<M)
		C[i]=A[i];
		else
		C[i]=B[k++];
	}//merging done
for(i=0;i<M+N;i++)
	{
		for(j=0;j<M+N-i-1;j++)
		{
			if(C[j]>C[j+1])
			{
				temp=C[j];
				C[j]=C[j+1];
				C[j+1]=temp;
			}
		}
	}//sorted
	printf("sorted merged array : \n");
	for(i=0;i<M+N;i++)
	printf("%d\t",C[i]);
}