// Input
// 2
// 6 6
// 5 0 5 2 2 3 4 0 4 1 1 3
// 3 4
// 3 0 1 0 2 0

// Output:
// 1
// 1

#include <bits/stdc++.h>
using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

void toposortUtil(int vertex,vector<bool> &visited, vector<int> g[], stack<int> &s)
{
    visited[vertex] = true;
    
    for(auto i:g[vertex])
    if(visited[i]==false)
    toposortUtil(i,visited,g,s);
    
    s.push(vertex);
}

vector<int> topoSort(int n, vector<int> g[]) 
{
    vector<bool> visited(n,false);
    
    stack<int> s;
    
    for(int i=0;i<n;i++)
    if(visited[i]==false)
    toposortUtil(i,visited,g,s);
    
    vector<int> vans;
    
    while(!s.empty())
    {
        vans.push_back(s.top());
        s.pop();
    }
    
    return vans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}
