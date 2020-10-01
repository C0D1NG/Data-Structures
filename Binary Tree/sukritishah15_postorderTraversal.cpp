#include <iostream>
using namespace std;

/*
    Binary Tree looks like:
    
             1
           /  \
         2     3
        / \   / \
       4   5 6   7
       
*/

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* newnode(int data){
    struct node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
}

void postorderTraversal(struct node* temp) { 
    if (temp == NULL) 
        return; 
    postorderTraversal(temp->left); 
    postorderTraversal(temp->right);
    cout << temp->data << " "; 
} 

int main(){
    
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    
    postorderTraversal(root); 
    //Output will be : 4 5 2 6 7 3 1
    
    return 0;
}

/*
    Time and Space Complexity : O(n)
    where n is no. of nodes in the tree.
*/