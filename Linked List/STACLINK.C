#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Node
{
int data;
struct Node *link;
}node;
 node *top,*p;
void push()
{
p=( node*)malloc(sizeof( node));
printf("Enter the number\n");
scanf("%d",&p->data);
p->link=NULL;
if(top==NULL)
{
top=p;
}
else
{
p->link=top;
top=p;
}
}
void pop()
{
if(top==NULL)
{
printf("Deletion impossible\n");
}
else
{
top=top->link;
p->link=NULL;
free(p);
}
}
void display()
{
node *temp;
temp=top;
if(temp==NULL)
{
printf("Stack is empty\n");
}
else
{
printf("Stack:\n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
}
void main()
{
int ch,ch2;
clrscr();
do
{
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
default:
printf("Wrong Choice\n");
break;
}
printf("Continue?press 1\n");
scanf("%d",&ch2);
}
while(ch2==1);
getch();
}
