#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*link;
int priority;
}
*front=NULL;
void insert(int,int);
void delete();
void display();
int choice,priority,value,i,priqueue[10],p,y,q;
void main()
{
do
{
printf("************MENU**********\n");
printf("1.insert\n2.delete\n3.display\n4.exit\n");
printf("enter the choice");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the value to insert");
          scanf("%d",&value);
          printf("enter the priority");
          scanf("%d",&priority);
          insert(value,priority);
          break;
case 2:delete();
         break;
case 3:display();
         break;
case 4:exit(0);
         break;
default:printf("invalid");
          break;
}
}
while(1);
}
void insert(int value,int priority)
{
struct node *newnode,*q;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->priority=priority;
newnode->link=NULL;
if(front==NULL||priority<front->priority)
{
newnode->link=front;
front=newnode;
}
else
{
q=front;
while(q->link!=NULL&&q->link->priority<=priority)
q=q->link;
newnode->link=q->link;
q->link=newnode;
}
}
void delete()
{
struct node *temp;
if(front==NULL)
{
printf("queue underflow");
}
else
{
temp=front;
printf("deleted item  is %d\n",temp->data);
front=front->link;
free(temp);
}
}
void display()
{
struct node *p;
p=front;
if(front==NULL)
{
printf("queue if empty");
}
else
{
while(p!=NULL)
{
printf("priority:%d  data:%d \n",p->priority,p->data);
p=p->link;
}
}
}








