#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* make_tree()
{
	int n;
	cin>>n;
    
	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-=2 )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}
		
		
		cin>> a >> b >> c;
		
		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

long int sumBT(Node* root);


int main()
{
    int t;cin>>t;while(t--){
    	
    	Node* head = make_tree();
    
        cout<<sumBT(head)<<endl;
    }
	return 1;
}
// } Driver Code Ends
/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree
long int sumBT(Node* root)
{
    //Node *p=root;
    //long int sum=0;
    int x,y;
    if(root!=NULL)
    {
        x=sumBT(root->left);
        y=sumBT(root->right);
        return root->key+x+y;
    }
    //return sum;
    return 0;

}
