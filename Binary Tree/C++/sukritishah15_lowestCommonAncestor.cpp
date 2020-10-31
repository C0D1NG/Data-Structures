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

node* lowestCommonAncestor(struct node* root, int data1, int data2){
    if(!root)
        return NULL;
    if((root->data == data1) || (root->data == data2))
        return root;
    struct node *l, *r;
    l = lowestCommonAncestor(root->left,data1,data2);
    r = lowestCommonAncestor(root->right,data1,data2);
    if(l && r)
        return root;
    else
        return (l ? l : r);
}

int main(){
    
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    
    cout << lowestCommonAncestor(root,4,5)->data << endl;
    // Output for this function call will be 2
    
    return 0;
}

/*
    Time and Space Complexity : O(n)
    where n is no. of nodes in the tree.
*/