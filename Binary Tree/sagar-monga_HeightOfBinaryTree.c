#include<stdio.h> 
#include<stdlib.h> 

struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

int maxDepth(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

struct node* newNode(int data)  
{ 
    struct node* node = (struct node*) malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    
    return(node); 
} 
    
int main() 
{ 
    struct node *root = newNode(1); 
  
    root->left = newNode(8); 
    root->right = newNode(9); 
    root->left->left = newNode(5); 
    root->left->right = newNode(6);  
    
    printf("Height of tree is %d", maxDepth(root)); 
    
    return 0; 
} 