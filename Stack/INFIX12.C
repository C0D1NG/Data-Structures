/*Successfull implementation of Infix to postfix expression
Code done by Parshwa Shah*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[20],infix[20],sym,post[20];
int top=-1,i=0,j=0;
int pre(char s)
{
if(s=='^'){return 3;}
else if(s=='*' || s=='/'){return 2;}
else if(s=='+' || s=='-'){return 1;}
else{return 0;}
}
void main()
{
clrscr();
printf("Enter the expression ending with #\n");
scanf("%s",infix);
while(infix[i]!='#')
{
sym=infix[i];
if(sym=='(')
{
top++;
stack[top]=sym;
}
else if(sym>='a' && sym<='z')
{
post[j]=sym;
j++;
}
else if(sym=='+' || sym=='-' || sym=='*' || sym=='/' || sym=='^')
{
if(pre(sym)<=pre(stack[top]) && top!=-1)
{
post[j]=stack[top];
j++;
stack[top]=sym;
}
else
{
top++;
stack[top]=sym;
}
}
else if(sym==')')
{
while(stack[top]!='(')
{
post[j]=stack[top];
j++;
top--;
}
top--;
}
i++;
}
if(top!=-1)
{
while(top!=-1)
{
post[j]=stack[top];
j++;
top--;
}
}
puts(post);
getch();
}

