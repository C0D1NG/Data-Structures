//prefix evaluation

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
void push(int[],char);
int pop(int[]);
int main()
{
	int stack[10],op1,op2,val;
	int i=0;
	char exp[10];
	printf("enter the expression: ");
    gets(exp);
    strrev(exp);
    
while(exp[i]!='\0')
   {
       if(exp[i]>='0' && exp[i]<='9')  
       {
        	push(stack,(exp[i]-48));
	   }
	   else
	 {
	   	op2=pop(stack);
	   	op1=pop(stack);
	   
	   switch(exp[i])
	   {
	   	 case '+':
	   	 	val=op2+op1;
	   	 	break;
	   	 	
	   	 case '-':
	   	 	val=op2-op1;
	   	 	break;
	   	 	
	   	 case '*':
	   	 	val=op2*op1;
	   	 	break;
	   	 	
	   	 case '/':
	   	 	val=op2/op1;
	   	 	break;
	   	 	
	   	 case '^':
	   	 	val=op2^op1;
	   	 	break;
		}
		push(stack,val);
     }
       i++;
   }   
       
     printf("value of expression=%d",pop(stack));
}

void push(int stack[],char exp)
{

    if(top==MAX-1)
    {
        printf("\n overflow ");
    }
    else
    {
        top=top+1;
        stack[top]=exp;
    }
}

int pop(int stack[])
{
    int x;
    if(top==-1)
    {
        printf("\n empty ");
    }
    else
    {
        x=stack[top];
        top=top-1;
    }
    return x;
    
}


