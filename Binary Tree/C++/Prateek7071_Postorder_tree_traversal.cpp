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

void TravPost(Node* root)
{

    if (root == nullptr) {
        return;
    }

    TravPost(root->left);
    TravPost(root->right);
    cout << root->data << " ";
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);

    TravPost(root);

    return 0;
}
