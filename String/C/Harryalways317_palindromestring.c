//A palindrome string is one that reads the same backward as well as forward eg: LEVEL

#include<stdio.h>
#include<string.h>
int check_palindrom(char *);
int main()
{
        char s1[20];
        printf("Enter the string...\n");
        gets(s1);

        int x;
        x=check_palindrom(s1);
        x?printf("Palindrom\n"):printf("Not Palindrom\n");
}
int check_palindrom(char *s)
{
        int i,j;
        for(i=0;s[i];i++);

        for(i=i-1,j=0;i>j;i--,j++)
                if(s[i]!=s[j])
                        return 0;
        if(s[i]==s[j])
                return 1;
}