using System;
using System.Collections.Generic;
using System.Linq;

namespace GraphDSA
{
    public static class BFS
    {
        public static void Execute()
        {
            var graph = CreateGraph();
            PerformBFS(graph, 2);
        }

        private static void PerformBFS(Graph graph, int start)
        {
            if (start >= graph.Vertices) return;
            
            var queue = new Queue<int>();
            var visited = new bool[graph.Vertices];
            for (var i = 0; i < graph.Vertices; i++)
                visited[i] = false;

            visited[start] = true;
            queue.Enqueue(start);

            while (queue.Any())
            {
                var node = queue.Dequeue();
                Console.Write(node + " ");
                
                var list = graph[node]; 
                foreach (var val in list)
                {
                    if (visited[val]) continue;
                    
                    visited[val] = true;
                    queue.Enqueue(val);
                }
            }
            Console.WriteLine();
        }

        private static Graph CreateGraph()
        {
            var graph = new Graph(4);
            graph.AddEdge(0, 1);
            graph.AddEdge(0, 2);
            graph.AddEdge(1, 2);
            graph.AddEdge(2, 0);
            graph.AddEdge(2, 3);
            graph.AddEdge(3, 3);

            return graph;
        }
    }
}