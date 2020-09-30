// Author : Utkarsh Goel
// Github : https://github.com/UtkarshGoel22

// Output :
// The Linked List is : 1->2->3->4->5->6->7->8->9->10->
// The Linked List is : 10->9->8->7->6->5->4->3->2->1->

#include <bits/stdc++.h>
using namespace std;

struct listnode {
	int data;
	listnode *next;
};

listnode *head = NULL;

// Function to insert a node in linked list
void insert(int data) {
	listnode *p, *q, *newnode;
	newnode = new listnode();
	newnode->data = data;
	if(head == NULL){
		head = newnode;
		return;
	}
	p = head;
	while(p!=NULL){
		q = p;
		p = p->next;
	}
	q->next = newnode;
	newnode->next = p;
	return;
}

// Function to reverse the linked list
void reverse() { 
    listnode* current = head; 
    listnode *prev = NULL, *next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    head = prev; 
} 

// Function to display the linked list
void display() {
	listnode *temp = head;
	cout<<"\nThe Linked List is : ";
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

int main() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	insert(10);
	display();
	reverse();
	display();
	return 0;
}
