#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
}

int treeSum(Node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        return root->key + treeSum(root->left) + treeSum(root->right);
    }
}

int main()
{
    Node* root = NULL;
    root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(25);
    int s = treeSum(root);
    cout<< "The sum of nodes in binary tree : "<<s;
    return 0;
}