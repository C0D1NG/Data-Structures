#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct infix
{
  char target[50];
  char stack[50];
  char s[50];
  char t[50];
  int top;
};
void initinfix(struct infix *p);
void setexpr(struct infix*p,char*a);
void push(struct infix*p,char a);
char pop(struct infix *p);
int priority(char e);
void convert (struct infix *p);
void show(struct infix p);
int main()
{
  char inexpr[50];
    struct infix p;
 initinfix(&p);
  printf("Enter an expression in infix form:\n"); 
  scanf("%s",inexpr); 
  setexpr(&p,inexpr);
  convert(&p);
  printf("The postfix expression is:\n");
  show(p);
  return 0;
}


void initinfix(struct infix *p)
{;
  
  p->top=-1;
 strcpy(p->target,"");
 strcpy(p->stack,"");
 *(p->t)=*(p->target);
 strcpy(p->s,"");
 
}

void setexpr(struct infix*p,char*a)
{
  
  strcpy(p->s,a);
  
}

void push(struct infix*p,char a)
{
  
  p->top++;
  p->stack[p->top]=a;
  p->stack[p->top+1]='\0';
  
}

char pop(struct infix *p)
{
  
  char c;
  c=p->stack[p->top];
  p->top--;
  return c;
}

int priority(char e)
{

  if(e=='$')
  return 3;
  else if(e=='*'||e=='/'||e=='%')
  return 2;
  else if(e=='+'||e=='-')
  return 1;
  else
  return 0;
}

void convert (struct infix *p)
{  
  
  char c,temp;
  int i,flag=1,j=0;
  while(*(p->s+j)!='\0')
  {
      if(isdigit(*(p->s+j))||isalpha(*(p->s+j)))
      {
          temp=*(p->s+j);
          strcat(p->t,&temp);
          
      }
      else if(*(p->s+j)=='(')
      {
          push(p,*(p->s+j));
      }
      else if(*(p->s+j)=='*'||*(p->s+j)=='/'||*(p->s+j)=='-'||*(p->s+j)=='+'||*(p->s+j)=='$')
      {
          if(strcmp(p->stack,"")==0)
          {
              push(p,*(p->s+j));
          }
          else
          {
              while(flag==1)
              {
                  c=pop(p);
                  if(priority(c)>=priority(*(p->s+j)))
                  {
                      flag=1;
                      strncat(p->t,&c,1);
                  }
                  else
                  flag=0;
              }
              push(p,c);
              push(p,*(p->s+j));
              flag=1;
          }
      }
      else if(*(p->s+j)==')')
      {
          while(flag==1)
          {
              c=pop(p);
              if(c!='(')
              {
                  strncat(p->t,&c,1);
              }
              else
              flag=0;
          }
          
      }
      j++;
      
      
  }
  for(i=p->top;i>=0;i--)
  {
      strcat(p->t,&p->stack[i]);
  }
}
     
void show(struct infix p)
{
    
    printf("%s",p.t);
}


