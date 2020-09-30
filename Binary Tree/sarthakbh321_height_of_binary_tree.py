from collections import deque

#BFS Function to calculate height
def BFS(graph, start, numOfNodes):
    q = deque([start])
    visited = [False]*(numOfNodes+1)

    heights = [0]*(numOfNodes+1)

    while(q):
        current = q.popleft()
        visited[current] = True

        for i in graph[current]:
            if(not visited[i]):
                heights[i] = heights[current] + 1 #The depth of child node is the depth current node + 1
                q.append(i)

    return max(heights)



numOfNodes = int(input())
edges = int(input())

graph = {}

for i in range(1, numOfNodes+1):
    graph[i] = []

for i in range(edges):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


print(BFS(graph, 1, numOfNodes)) #Assuming 1 to be the starting node