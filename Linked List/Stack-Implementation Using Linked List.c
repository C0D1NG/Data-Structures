//implementing stack using Singly  linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}node;

node* insertatbeg(node *head);

node* createnode(int v);
node* deleteatbeg(node *head);

void peek(node *head);
void print(node *p);
int main(){
	node *head=NULL;
	do{
		
		int choice;
		printf("\n\nMENUE\n\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n\n");
		printf("\nENTER YOUR CHOICE\n");
	    scanf("%d",&choice);
	    switch(choice){
	    	
		 case 1:
	        head=insertatbeg(head);
	        print(head);
	        break;
	  
	    case 2:
	    	head= deleteatbeg(head);
	    	print(head);
	        break;
	    case 3:
	    	peek(head);
	    case 4:
	    	print(head);
	    case 5:
	    	exit(0);
	    default:
	    	printf("\nWrong choice\n");
	    }
	    	
}while(1);
}

node* createnode(int v){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=v;
	newnode->next=NULL;
	return newnode;
	
}
void print(node *p){
	while(p!=NULL){
		printf("-------\n|  %d  |\n-------\n",p->data);
	p=p->next;
	}
}
  
 
 

node* insertatbeg(node *head){
	int val;
	node *p,*newnode;
		char ch='y';
		while(ch=='y'){
		printf("\nEnter element to be pushed into the stack\n");
		scanf("%d",&val);
	    newnode=createnode(val);
		if(head==NULL){
			head=newnode;
		}
			
		else{
			newnode->next=head;
			head=newnode;
			
	}
	printf("\nDo you want to add more nodes\n");
		scanf("\n%c",&ch);
	}
	
	return head;
	
	
}



node* deleteatbeg(node *head){
	node *temp;
	if(head==NULL){
		printf("\nthe list is empty\n");
		return head;
	}
	temp=head;
	head=temp->next;
	free(temp);
	return head;
}
void peek(node *head){
	if(head==NULL){
		printf("\nthe list is empty\n");
		
	}
	else{
		printf("-------\n|  %d  |\n-------\n",head->data);
	}
}


	
