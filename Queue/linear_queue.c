/**


Algorithm:-
Step 1: Define an array Queue and initialise front and rear to 0
Step 2: Ask user for a choice as an input
Step 3: If the input is 1, call push(), 
    3.1: if the rear is equal to SIZE , then print 
        queue is full.
    3.2: else add an element in the array and increment rear by 1.
Step 4: If the input is 2, call pop(),
    4.1: if rear and front are equal , print the queue
         is empty.
    4.2: if rear is equal to 1, remove the elemnt and make rear as 0
    4.3: else print the element at queue[front], and shift
         an element towards left for all the elements of the queue.
         decrement rear by 1.
Step 5: If input is 3 call display(), print all elements of queue
Step 6: If input is 4 , then stop taking any more inputs
Step 8: If input is anything else , print wring choice.
Step 9: Repeat steps 2 until exit contdition is met
Step 10: Stop

**/


#include<stdio.h>

#define SIZE 5

// define the queue and the front and rear 
int queue[SIZE];
int front=0,rear=0;

// function to handle the push on queue
void push(){
    int item;
    // queue full condition
    if(rear==SIZE){	 	  	 	   	      	     	      	 	
        printf("Queue is full!!\n");
    }
    else{
    printf("Enter an element in the queue:");
    scanf("%d",&item);
    queue[rear]=item;
    rear++;
    }
    
}
// pop function
void pop(){
    int i;
    // queue empty condition
    if(rear==front){
        printf("The Queue is empty!!\n");
    }
    else if(rear==1){
        printf("The element popped is:%d\n",queue[front]);
        rear=0;
    }else{
    printf("The element popped is: %d\n",queue[front]);
    for(i=0;i<rear-1;i++){
        queue[i]=queue[i+1];
    }
    rear--;
    }
}

void display(){
    int i;
    printf("The queue is : ");
    for(i=0;i<rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
    
}	 	  	 	   	      	     	      	 	


int main(){
    
    int i,j,choice;
    do{
    printf("--------------------------------------------------------------\n");
    printf("What do you want to do with the queue?\n1.Push\n2.pop\n3.Display\n4.End Process\n");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: break;
        default:  printf("You have chosen a wrong option !!\n");
            
    }
    }while(choice != 4);
    return 0;
}
    
    
	 	  	 	   	      	     	      	 	
