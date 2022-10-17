#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};
 
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
 
int addBT(Node* root)
{
    if (root == NULL)
        return 0;
    return (root->key + addBT(root->left) + addBT(root->right));
}
 
int main()
{
    Node* root = newNode(5);
    root->left = newNode(6);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(13);
    root->right->left = newNode(15);
    root->right->right = newNode(21);
    root->right->left->right = newNode(55);
 
    int sum = addBT(root);
    cout << "Sum of all the elements is: " << sum << endl;
 
    return 0;
}
