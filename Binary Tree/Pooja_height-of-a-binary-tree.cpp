#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->key=key;
        this->left = this->right = NULL;
    }
};

int height(Node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}

int main()
{
    Node* root = NULL;
    root = new Node(20);
    root->left = new Node(16);
    root->right = new Node(22);
    int h = height(root);
    cout<< "The height of the binary tree is : "<<h;
    return 0;
}
