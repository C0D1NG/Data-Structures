using System;

namespace GraphDSA
{
    class Program
    {
        static void Main(string[] args)
        {
            CreateAndPrintGraph();
            BFS.Execute();
            DFS.Execute();
        }

        static void CreateAndPrintGraph()
        {
            var graph = new Graph(5);
            graph.AddEdge(0, 1);
            graph.AddEdge(0, 2);
            graph.AddEdge(3, 4);
            
            graph.Print();
        }
    }
}