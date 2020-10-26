// Input:
// 3
// 2 1
// 0 1
// 4 3
// 0 1 1 2 2 3
// 5 4
// 0 1 2 3 3 4 4 2

// Output:
// 0
// 0
// 1

#include<bits/stdc++.h>
using namespace std;

bool checkcycle(vector<int> g[], vector<bool> &vis, int i, int parent)
{
    
    if(vis[i]==true) //end condition that checks if loop is there or not
    return true;
    
    vis[i]=true;
    
    for(auto j:g[i])
    {
        if(j!=parent)
            if(checkcycle(g,vis,j,i))
                return true;
    }
    
    return false;
}

bool isCyclic(vector<int> g[], int n)
{
   vector<bool> vis(n,false);
   
   for(int i=0;i<n;i++) // applying this loop because the graph may be broken
   {
       if(vis[i]==false and checkcycle(g,vis,i,-1))
           return true;
   }
   
   return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
