
#include<stdio.h>
#include<stdlib.h>
void bubble(int ar[],int n);
void selection(int ar[],int n);
void insertion(int ar[],int n);
void display(int ar[],int n);
int i,j,temp;
int main(){
	int ar[100],n;
		printf("enter number of elements in a array:");
				scanf("%d",&n);
				printf("enter array elements:");
				for(i=0;i<n;i++)
				  scanf("%d",&ar[i]);
				  
	do{ 
	    int choice;  
		printf("\n\n......Main Menu......\n\nEnter 1 for SELECTION SORT\n\nEnter 2 for BUBBLE SORT\n\nEnter 3 INSERTION SORT\n\nEnter 4 for EXIT");
		printf("\n\nEnter your Choice\n\n");
		scanf("%d",&choice);
		switch(choice)
		{  
		case 1:{
			    selection(ar,n);
			    
	            break;
		}
		case 2:{
			bubble(ar,n);
			
			break;
		}
			
			
	case 3:
		{
			insertion(ar,n);
			break;
		}
	case 4:{
	
		printf("bye!bye you exit\n");
	    exit(0);
	}
		default:
		printf("\nno matches found\n");
}
}while(1);
}
void selection(int ar[],int n){//selection 
	int min;
	for(i=0;i<n-1;i++){
		
				  min=i;
				for(j=i+1;j<n;j++)
				{
					if(ar[j]<ar[min])
						min=j;
				}
			
		      
						temp=ar[min];
						ar[min]=ar[i];
						ar[i]=temp;
					
				}
				display(ar,n);
}
void display(int ar[],int n){
	printf("\nARRAY AFTER SORTING\n");
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
	
}
void bubble(int ar[],int n){//bubble
	int f=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(ar[j]>ar[j+1]){
				f=1;
				temp=ar[j+1];
				ar[j+1]=ar[j];
				ar[j]=temp;
			}
		}
		
			if(f==0)
				break;
		
		}
		
	display(ar,n);
}
void insertion(int ar[],int n){
	int key;
	for(i=1;i<n-1;i++){//we will consider first element sorted start our loop from 1
		key=ar[i];//we wil store value of the hole or ith element in key
		j=i;//set j=i
		while(j-1>=0&&ar[j-1]>key){//now if j>0 means the their are space in sorted part
			ar[j]=ar[j-1];
			j=j-1;
		}
		ar[j]=key;
		
		
	}
	display(ar,n);
} 

