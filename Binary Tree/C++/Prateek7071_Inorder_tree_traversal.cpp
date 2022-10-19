#include <iostream>
using namespace std;
 

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
void Trav(Node* root)
{

    if (root == nullptr) {
        return;
    }
    Trav(root->left);
    cout << root->data << " ";
    Trav(root->right);
}
 
int main()
{
 
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(41);
    root->right->left = new Node(11);
    root->right->right = new Node(9);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(6);
    root->right->left->right->left = new Node(8);
 
    Trav(root);
 
    return 0;
}
