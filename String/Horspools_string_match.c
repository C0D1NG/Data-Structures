#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int table[128];
int m,n;
void ShiftTable(char P[m])
{
 int i,j;
 for(i=0; i<128; i++)
    table[i]=m;
for(j=0; j<=m-2; j++)
table[(int)tolower(P[j])]=table[(int)toupper(P[j])]=m-1-j;
}
int Horspool(char T[],char P[])
{
int i,k;
ShiftTable(P);
i=m-1;
while(i<=n-1)
{
k=0;
while(k<=m-1 && (tolower(P[m-1-k])==tolower(T[i-k])))
k++;
if(k==m) //Pattern match found
return i-m+1;
else
i=i+table[(int)T[i]]; //shift amount
}
return -1;
}
int main()
{
    int pos;
char text[100],pattern[25];
printf("Enter the text:\n");
gets(text);
printf("Enter the pattern:\n");
gets(pattern);
n=strlen(text);
m=strlen(pattern);
pos=Horspool(text,pattern);
if(pos==-1)
printf("Pattern not found!!");
else
printf("Pattern %s found at position %d.",pattern,pos+1);
return 0;
}
