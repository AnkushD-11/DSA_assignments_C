//Write a program to print the sum of the diagonal element of the M*N square matrix.

#include<stdio.h>
int main(){
    int i, j, k, m, n;
    static int arr[10][10];
    int sum = 0;

    printf("Enter order of matrix:\n    ");
    scanf("%d %d", &m ,&n);
    if(m==n)
    {
    printf("Enter array elements: ");
    
    for( i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++){
            printf("Enter arr[%d][%d]: ",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n printing the elements ....\n");     
    for(i=0;i<m;i++)    
    {    
        printf("\n");    
        for (j=0;j< n;j++)    
        {    
            printf("%d\t",arr[i][j]);    
        } 
        printf("\n");   
    }

    for(i = 0; i < m; i++)
    {
        sum = sum+ arr[i][i];
    } 
    printf("The sum is %d", sum);
}
}

