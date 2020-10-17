#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    printf("Enter a string to check if it's a palindrome\n");
    gets(a);
    strcpy(b,a);
    strrev(b);
    if(strcmp(a,b)==0)
    {
        printf("string is palindrome.\n");
    }
    else
    {
        printf("string is not a palindrome.\n");
    }
    return 0;
}