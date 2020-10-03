// Date: 01-10-2020
// Hacktober 2020

// BFS using STL in C++

#include <bits/stdc++.h>
#define N 5
using namespace std;

// Graph
    
    // 0______1
    // |      |
    // 5      2
    // |      |
    // 4______3

//

int addEdge(vector < int > * list, int v1, int v2) {
    list[v1].push_back(v2);
    list[v2].push_back(v1);
}

int visited[N] = {0};

void BFS(vector < int > * list, int v) {
    visited[v] = 1;
    int u = v;
    
    queue < int > q;
    
    while(true) {
        
        for(auto x : list[u]) {
            if(visited[x] == 0) {
                visited[x] = 1;
                cout<<x<<" ";
                q.push(x);
            }
        }
        
        if(!q.empty()) {
            u = q.front();
            q.pop();
        }
        else
        return;
    }
}

int main() {
    // an array of pointers (in C) or vectors (in C++)
    vector < int > adjacency_list[N];
    int i;

    // Representing graph using adjacency list
    for(i = 0; i<=N; i++) {
        
    int vertex1 = i;
    int vertex2 = (i+1)%5;
    
    // edge between a and b as well as b to a
    addEdge(adjacency_list, vertex1, vertex2);
    
    }
    
    BFS(adjacency_list, 0);
    
	return 0;
}