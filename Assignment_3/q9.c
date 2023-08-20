// Write a program to find frequency of a given number 'k'.

#include<stdio.h>
int main(){
    int i, count = 0, num, size;
    int arr[10];

    printf("Enter size of the array: ");
    scanf("%d", &size);
    for(i=0; i<size; i++){
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    for ( i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\nFrequency digit: ");
    scanf("%d", &num);
    for ( i = 0; i < size; i++)
    {
        if(arr[i]==num)
            count++;
    }

    printf("The frequency of %d in the array is %d", num, count);

}
