#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char element);
char pop();
int isoperator(char symbol);
int precedence(char symbol);
void InfixToPrefix(char infix_exp[], char prefix_exp[]);


void main()
{
    int ch;
    char infix[SIZE], prefix[SIZE];
    printf("\n\n Enter Infix expression : ");
    gets(infix);
    printf("By which method,do you want to evaluate?\n");
    printf("Enter 1 for Prefix \n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        InfixToPrefix(infix,prefix);
        printf("\n Prefix Expression: ");
        puts(prefix);
        break;

    default:
        printf("Invalid Choice\n");
        break;    
    }
}

void InfixToPrefix(char infix_exp[], char prefix_exp[])
{
    int i, j, k, pos, len;
    char element, x, rev[SIZE];
    pos=0;
    len=strlen(infix_exp);
    for(k=len-1;k>=0;k--)
       {
           rev[pos]=infix_exp[k];
           pos++;
       }
    rev[pos]='\0';
    strcpy(infix_exp,rev);
    for(i=0; infix_exp[i]!='\0'; i++)
        {
            if(infix_exp[i] == ')')
            infix_exp[i] = '(';
            else if(infix_exp[i] == '(')
            infix_exp[i] = ')';
        }
    push('(');
    strcat(infix_exp,")");
    i=0;
    j=0;
    element=infix_exp[i];
while(element != '\0')
{
if(element == '(')
{
push(element);
}
else if( isdigit(element) || isalpha(element))
{
prefix_exp[j] = element;
j++;
}
else if(isoperator(element) == 1)
{
x=pop();
while(isoperator(x) == 1 && precedence(x)>= precedence(element))
{
prefix_exp[j] = x;
j++;
x = pop();
}
push(x);
push(element);
}
else if(element == ')')
{
x = pop();
while(x != '(')
{
prefix_exp[j] = x;
j++;
x = pop();
}
}
else
{
printf("\nInvalid Infix Expression.\n");
break;
}
i++;
element = infix_exp[i];
} 
if(top > 0)
printf("\n Invalid infix Expression.");
prefix_exp[j] = '\0';
pos=0;
len=strlen(prefix_exp);
for(k=len-1;k>=0;k--)
{
rev[pos]=prefix_exp[k];
pos++;
}
rev[pos]='\0';
strcpy(prefix_exp,rev);
}

void push(char element)
{
if(top >= SIZE-1)
printf("\n Stack Overflow.");
else
{
top++;
stack[top] = element;
}
}


char pop()
{
char element;
element='\0';
if(top < 0)
printf("\n Stack Underflow.");
else
{
element = stack[top];
top--;
}
return element;
}

int isoperator(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
return 1;
else
return 0;
}

int precedence(char symbol)
{
if(symbol == '^')
return(5);
else if(symbol == '/')
return(4);
else if(symbol == '*')
return(3);
else if(symbol == '+')
return(2);
else if(symbol == '-')
return(1);
else
return(0);
}
