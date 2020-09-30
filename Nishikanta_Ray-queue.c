//Name-Nishikanta Ray
//github link-https://github.com/NishikantaRay
//Program name-Queue using c
#include<stdio.h>
#include<stdlib.h>
#define size 100
int front=0,rear=-1;
int q[size];
//Function for insert
void insert(int q[],int ele)
{
	if(rear==size-1)
	{
		printf("over flow");
		return;
	}
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
	}
	else
	{
		rear++;
		q[rear]=ele;
	}
}
//Function of delete
int delete(int q[])
{
	int x;
	if(front==-1)
	{
		printf("underflow");
		exit(0);
	}
	x=q[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}
	return x;
}
//Function of display
void display(int q[])
{
	int i;
	if(front==-1)
	{
		printf("empty");
		return;
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf(",%d",q[i]);
		}
	}
}
//Main function
main()
{
	int i,ch,ele,x;
	while(1)
	{
        //Menu driven program
		printf("\n1:insert\n2:delete\n3:display\n4:exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element to be inserted");
				scanf("%d",&ele);
				insert(q,ele);
				break;
			case 2:
				printf("deleted element is:");
				x=delete(q);
				printf("%d",x);
				break;
			case 3:
				printf("The element are");
				display(q);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("you enter the invalid choice");
		}
	}
}