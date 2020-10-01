/*
    Program :- Queue using linked list
    Written by :- Sunil Kumar Panda
    Github user name :- Sunil200228
    Github Link :- https://github.com/Sunil200228 
*/

#include<stdio.h>
#include<stdlib.h>
//Structure for creating node of linkedlist
struct node
{
	int info;
	struct node *next;
};
//f for front node and r for rear node
struct node *f,*r;
//Insertion of element in queue
void insert(int ele)
{
	//New node to insert
	struct node *new;
	//Allocation of address
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		//If memory is not present then through Size not allocation statement
		printf("\nSIZE NOT ALLOCATED\n");
		return;
	}
	new->info=ele;
	new->next=NULL;
	if(f==NULL)
		//If 1st element is inserted in linked list
		f=r=new;
	else
	{
		//If one or more element is inserted
		r->next=new;
		r=new;
	}
}
//Deletion of element
int dele()
{
	int del;
	//Temp. variable to store the deleting element 
	struct node *temp;
	del=f->info;
	temp=f;
	if(f==NULL)
	{
		//If queue is empty
		printf("\nQUEUE IS EMPTY\n");
		exit(0);
	}
	if(f->next==NULL)
		//If queue has 1 element
		f=r=NULL;
	else
		//If queue has more than 1 element
		f=f->next;
	free(temp);
	return del;
}
//Display the queue
void display()
{
	struct node *temp;
	if(f==NULL)
	{
		//If queue is empty
		printf("\nQUEUE IS EMPTY\n");
		return;
	}
	//Print the queue
	printf("\nQueue is: ");
	for(temp=f;temp!=NULL;temp=temp->next)
		printf("%d ",temp->info);
	printf("\n");
}
int main()
{
	//Intial stage of f and r
	f=r=NULL;
	//ch-choice and ele for insert of new element
	int ch,ele;
	while(1)
	{
		printf("\n1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the element: ");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2: printf("\nPopped element is: %d",dele());
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("\nEnter correct choice");
		}
	}
	return 0;
}
