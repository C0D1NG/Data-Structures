#include <iostream>
using namespace std;

class Node {
   public:
      int data;
      Node *left, *right;
   
      Node(int data) {
         this->data = data;
         this->left = NULL;
         this->right = NULL;
      }
};

int findMaxNode(Node* root) {
   
   if (root == NULL)
      return -100;

   int maxVal = root->data;
   int leftMaxVal = findMaxNode(root->left);
   int rightMaxVal = findMaxNode(root->right);
   if (leftMaxVal > maxVal)
      maxVal = leftMaxVal;
   if (rightMaxVal > maxVal)
      maxVal = rightMaxVal;
   return maxVal;
}

int main() {
   
   Node* NewRoot = NULL;
   Node* root = new Node(5);
   root->left = new Node(6);
   root->right = new Node(2);
   root->left->left = new Node(12);
   root->left->right = new Node(83);
   root->right->left = new Node(64);
   root->right->right = new Node(91);
   cout<<"The Maximum element of Binary Tree is "<<findMaxNode(root) << endl;
   return 0;
}
