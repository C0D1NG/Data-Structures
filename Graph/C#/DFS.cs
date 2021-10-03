using System;
using System.Collections.Generic;
using System.Linq;

namespace GraphDSA
{
    public static class DFS
    {
        public static void Execute()
        {
            var graph = CreateGraph();
            PerformDFS(graph, 2);
        }

        private static void PerformDFS(Graph graph, int start)
        {
            if (start >= graph.Vertices) return;

            var visited = new bool[graph.Vertices];
            for (var i = 0; i < graph.Vertices; i++)
            {
                if (!visited[i])
                    DFSUtil(graph, i, visited);
            }
            Console.WriteLine();
        }

        private static void DFSUtil(Graph graph, int idx, bool[] visited)
        {
            visited[idx] = true;
            Console.Write(idx + " ");

            foreach (var node in graph[idx])
            {
                if (!visited[node])
                    DFSUtil(graph, node, visited);
            }
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