#include<stdio.h>
#include<stdlib.h>
void inputrest();
void outputrest();
void insertrear(int);
void insertfront(int);
void deleterear();
void deletefront();
void display();
int choice,value,doqueue[10],i,front=-1,rear=-1,i;
void main()
{
printf("***********MENU**********\n");
printf("1.input restricated\n2.output restricated\n");
printf("enter the choice");
scanf("%d",&choice);
switch(choice)
{
case 1:inputrest();
           break;
case 2:outputrest();
          break;
case 3:exit(0);
          break;
default:printf("invalid");
           break;
}
}
void inputrest()
{
int choice;
do
{
printf("*********MENU**********\n");
printf("input restricated dequeue\n");
printf("1.insert at right\n2.delete at right\n3.delete at left\n4.display\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the value to insert\n");
           scanf("%d",&value);
           insertrear(value);
           break;
case 2:deleterear();
           break;
case 3:deletefront();
            break;
case 4:display();
           break;
case 5:exit(0);
           break;
default:printf("invalid");
           break;
}
}while(1);
}
void  outputrest()
{
int choice;
do
{
printf("***********MENU************/n");
printf("output restricated dequeue\n");
printf("1.insert at right\n2.insert at left\n3.delete at left\n4.display\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the value to insert\n");
           scanf("%d",&value);
            insertrear(value);
           break;
case 2:printf("enter the value to insert\n");
           scanf("%d",&value);
           insertfront(value);
           break;
case 3:deletefront();
            break;
case 4:display();
           break;
case 5:exit(0);
          break;
default:printf("invalid");
           break;
}
}while(1);
}
void insertrear(int value)
{
if((front==0&&rear==9)||(front==rear+1))
{
printf("queue is full\n");
}
if(front==-1)
{
front=0;
rear=0;
}
else
{
if(rear==9)
rear=0;
else
rear=rear+1;
}
doqueue[rear]=value;
}
void insertfront(int value)
{
if((front==0&&rear==9)||(front==rear+1))
{
printf("queue if full\n");
}
if(front==-1)
{
front=0;
rear=0;
}
else
{
if(front==0)
front=9;
else
front=front-1;
}
doqueue[front]=value;
}
void deletefront()
{
if(front==-1)
{
printf("queue underflow\n");
}
printf("deleted element is:%d\n",doqueue[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
if(front==9)
front=0;
else
front=front+1;
}
}
void deleterear()
{
if(front==-1)
{
printf("queue underflow\n");
}
printf("deleted element is:%d\n",doqueue[rear]);
if(rear==front)
{
front=-1;
rear=-1;
}
else
{
if(rear==0)
rear=9;
else
rear=rear-1;
}
}
void display()
{
int left=front,right=rear;
if(left==-1)
{
printf("queue is empty\n");
}
printf("elements of the queue are\n");
if(left<=right)
{
while(left<=right)
{
printf("%d   ",doqueue[left]);
left++;
}
}
else
{
while(left<=9)
{
printf("%d   ",doqueue[left]);
left++;
}
front=0;
while(left<=right)
{
printf("%d    ",doqueue[left]);
left++;
}
}
}
