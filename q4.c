// Sparse matrix

#include<stdio.h>
int main(){
    int row, col, count=0;
    int i, j, arr[5][5];

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter number of column: ");
    scanf("%d", &col);

    printf("Enter the Matrix: ");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Output the matrix:\n");
    for(i=0; i<row ; i++){
        for(j = 0; j< col; j++ ){
            printf("%d", arr[i][j]);
        }
    }

    for(i=0; i<row ; i++){
        for(j = 0; j< col; j++ )
        {
            if(arr[i][j]==0)
                count++;
        }
    }

    if(count > (row * col)/2)
    {
        printf("\nIt is a sparse matrix");
    }
    else{
        printf("Not sparse matrix");
    }


}