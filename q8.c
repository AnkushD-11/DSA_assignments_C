// Write a program to check whether a string is palindrome or not.

#include<stdio.h>
#include<string.h>
int main(){
    char string[20];
    int len, i;
    printf("Enter a string: ");
    scanf("%s", string);

    len = strlen(string);
    if(len>20)
        return 0;
    
    char string_rev[20];
    for(i= len-1; i>= 0; i--)
    {
        string_rev[len - 1 - i] = string[i];
    }
    if (strcmp(string,string_rev)==0)
    {
        printf("The strings are palindrome");
    }
    else
        printf("Not palindrome");
    
}