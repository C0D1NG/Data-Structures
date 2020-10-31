/*
Contributor : Kshitij Darekar  https://github.com/KshitijDarekar

A menu driven program for the following operations on to Linked List using Stack in C.

a. Push an element .
b. Pop an element .
c. check List is palindrome.
d. Display the status .

Sample Output :

1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 1
Enter the element: a
1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 1
Enter the element: b
1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 1
Enter the element: a
Enter your choice: 1
Enter the element: a
Enter your choice: 2
a is popped
1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 3
The List is : a b a 
1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 4
List is Palindrome
1.Push 2.Pop 3.Display 4. check List Palindrome 5. Exit
Enter your choice: 5
*/
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;    
}Node;

//create head of list
Node *head=NULL;

//Function to check if the list is empty
int isEmpty(){
    if(head==NULL){
        return 1;    
    }
    return 0;
}

//Function to create a node with data - Note : here the return type is Node pointer
Node* createNode(char c){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=c;
    return new_node;
}

// Function to Pop an element 
char pop(){
    // delete from start
      char c;
      Node *temp=head;
      c=temp->data;
      head=temp->next; // temp is used here
      free(temp); // particular node gets deleted  
    return c;
}

//Function to Display elements of the List
void display(Node *head){
    if(isEmpty()){
        printf("List is empty\n");
    }
    else{
        printf("The List is : ");
        while(head->next!=NULL){
            printf("%c ",head->data);
            head=head->next;
        }
        printf("%c \n",head->data);
}
}
// Function to push elemnts in the list/stack
void push(char c){
    //insetion at beginning-> i.e at the top of the stack
    Node *new_node=createNode(c);
    //if no elements in the list
    if(isEmpty()){//if(head==NULL)
        head= new_node;
        head->next=NULL;
    }
    
    // insertion for the already existing list
    else{
        new_node->next=head;
        head=new_node;
    }
}    

// Function to check Palindrome
void isPalindrome(){

    Node * ptr;
     char a[20]; // we have assumed the size
        int flag=1 , n=0;
        ptr=head;
        while(ptr->next!=NULL)// store the data in array
        {
            a[n]=ptr->data;
            n++;
            ptr=ptr->next;
        }
        a[n]=ptr->data;
        a[++n]='\0'; // marks end of the string
        for( int i=(n-1) ; i>=(n+1)/2; i--){ //Compare stack and array
            if(a[i]!= pop()){ // whenever  this function is called element will be popped from the stack
              flag=0;
              break;
            }
          }
          if(flag==1){
            printf("List is Palindrome\n");
          }
          else{
            printf("List is not Palindrome\n");
          }

}


int main(){
    int choice;
    char d;
    char c;
    do{
        printf("1.Push 2.Pop 3.Display 4.Check Palindrome 5.Exit\n");
        printf("Enter your choice :");
    
        scanf("%d",&choice);
        if(choice==5){
            break;
        }
        switch(choice){
            case 1: 
            printf("Enter the element:");
            scanf(" %c",&c);
            push(c);
            break;
            case 2:
            d=pop();
            printf("%c is popped\n",d);
            break;
            case 3:
            display(head);
            break;
            case 4:
            isPalindrome();
            break;
            default:
            printf("Invalid Choice ");
            break;
        }
    }while(choice<5 && choice>=1);

    return 0;
}
