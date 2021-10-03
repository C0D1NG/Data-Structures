using System;
using System.Collections.Generic;

namespace GraphDSA
{
    public class Graph
    {
        private readonly LinkedList<int>[] _adj;
        public int Vertices { get; }

        internal Graph(int length)
        {
            Vertices = length;
            _adj = new LinkedList<int>[length];
            for (var i = 0; i < length; i++)
                _adj[i] = new LinkedList<int>();
        }

        public bool AddEdge(int source, int dest, bool undirected = false)
        {
            if (source >= _adj.Length || dest >= _adj.Length)
                return false;

            _adj[source].AddLast(dest);
            if(undirected)
                _adj[dest].AddLast(source);
            return true;
        }

        public LinkedList<int> this[int index] => _adj[index];

        public void Print()
        {
            for (var i = 0; i < _adj.Length; i++)
            {
                Console.Write($"[ {i} ] -> ");
                foreach (var node in _adj[i])
                {
                    Console.Write($"[ {node} ] -> ");
                }
                Console.WriteLine($"#");
            }
        }
    }
}