#include<iostream> 
#include<queue>
using namespace std;

void printDFS(int** edges, int n,int sv,bool* visited){
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i] == 1){
			if(visited[i]){
				continue;	
			}
		}
		printDFS(edges,n,i,visited);
	}
}

void printBFS(int** edges,int n,int sv){
	queue<int> pendingvertices;
	bool * visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	pendingvertices.push(sv);
	visited[sv] = true;
	while (!pendingvertices.empty()){
		int cv = pendingvertices.front();
		pendingvertices.pop();
		cout<< cv<<endl;
		for(int i=0;i<n;i++){ 
			if(i== cv){
				continue;
			}
			
			if(edges[cv][i] == 1 && !visited[i]){
				pendingvertices.push(i);
				visited[i] = true;
			}
		}
	}
	delete [] visited;
}


int main(){
	int n;//vertices
	int e;//edges
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0 ;
		}
	}
	
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	cout<<"DFS"<<endl;
	printDFS(edges,n,0,visited);
	
	cout<<"BFS"<<endl;
	printBFS(edges,n,0);
	
	delete [] visited;
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	
}
