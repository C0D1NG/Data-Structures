#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define MAX 20
void push(int);
char pop();
void infix_to_prefix();
int precedence (char);
char stack[20],infix[20],prefix[20];
int top = -1;

int main()
{
printf("\nINPUT THE INFIX EXPRESSION : ");
scanf("%s",infix);
infix_to_prefix();
return 0;
}
// method that pushes the elements onto the character stack
void push(int pos)
{
if(top == MAX-1)
{
printf("\nSTACK OVERFLOW\n");
}
else {
top++;
stack[top] = infix[pos];
}}

// method that removes character from stack and returns them
char pop()
{
char ch;
if(top < 0)
{
printf("\nSTACK UNDERFLOW\n");
exit(0);
}
else
{
ch = stack[top];
stack[top] = '\0';
top--;
return(ch);
}
return 0;
}
// method that converts String from infix to prefix
// all the strings are assumed to be valid expressions

void infix_to_prefix()
{
int i = 0,j = 0;
strrev(infix); // Reverse the infix expression
while(infix[i] != '\0')
{
// if an alphabet is found then copy it to the output string
if(infix[i] >= 'a' && infix[i] <= 'z')
{
prefix[j] = infix[i];
j++;
i++;
}
// In the reversed string, closing bracket will be found first so put it in the stack
else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
{
push(i);
i++;
}
// if an opening bracket is found, then
else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '[') /* when closing bracket is found */
{
if(infix[i] == '(')
{
while(stack[top] != ')') /* pop till opening bracket is found */
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '[')
{
while(stack[top] != ']') /* pop till corresponding opening bracket is found */
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '{')
{
while(stack[top] != '}') /*pop till corresponding opening bracket is found*/
{
prefix[j] = pop();
j++;
}
pop();
i++;
}}
else
{
// if the stack if empty, then we simply put the operator in stack
if(top == -1)
{
push(i);
i++;
}
// if the precedence of operator is less than the stack top then
else if( precedence(infix[i]) < precedence(stack[top]))
{
prefix[j] = pop();  // pop the stack top and add it to the prefix string
j++;
// if you have an operator that has precedence greater than operator
while(precedence(stack[top]) > precedence(infix[i])){
prefix[j] = pop();    // Pop the operator
j++;
if(top < 0) {
break;
}}
push(i);
i++;
}
// if the precedence of operator is greater than or equal to the stack top 
else if(precedence(infix[i]) >= precedence(stack[top]))
{
push(i);  //  Push it onto the stack
i++;
}}}
// At the end remove all the operators from the stack
while(top != -1)
{
prefix[j] = pop();
j++;
}
// Reverse the final string before output
strrev(prefix);
prefix[j] = '\0';
printf("EQUIVALENT PREFIX NOTATION : %s ",prefix);
}

/* Function to return precedence of operators */
int precedence(char alpha)
{
if(alpha == '+' || alpha =='-')
{
return(1);
}
if(alpha == '*' || alpha =='/')
{
return(2);
}
return 0;
}
// contribution by RaghavKaushal03
