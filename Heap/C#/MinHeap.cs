using System;

namespace Heaps
{
    class MinHeap
    {
        private int[] _heap;
        private int _length;

        public MinHeap(int size)
        {
            _length = 0;
            _heap = new int[size];
        }
        
        public MinHeap(int[] arr)
        {
            _heap = new int[arr.Length];
            foreach (var item in arr)
                Insert(item);
        }
        
        public int Length() => _length;

        public void Print()
        {
            var level = 0;
            var maxAtThisLevel = 1 << level;
            for (var i = 0; i < _length; i++)
            {
                if (i == maxAtThisLevel)
                {
                    Console.WriteLine();
                    level++;
                    maxAtThisLevel += 1 << level;
                }
                Console.Write(" " + _heap[i]);
            }
            Console.WriteLine();
        }

        public bool Insert(int num)
        {
            if (_length == _heap.Length)
            {
                Console.WriteLine("Heap is full");
                return false;
            }

            _heap[_length] = num;
            BubbleUp(_length);
            _length++;
            return true;
        }

        public int ExtractMin()
        {
            if (_length == 0)
            {
                Console.WriteLine("Heap is empty");
                return int.MaxValue;
            }
            var min = _heap[0];
            _length--;
            _heap[0] = _heap[_length];
            SinkDown(0);
            
            return min;
        }

        private void BubbleUp(int idx)
        {
            var parent = idx / 2;
            while (idx > 0 && _heap[parent] > _heap[idx])
            {
                Swap(parent, idx);
                idx = parent;
                parent = idx / 2;
            }
        }
        
        private void SinkDown(int start)
        {
            if (_length == 0) return; // if heap is empty
            var curr = start;
            var leftChild = 2 * curr + 1;
            var rightChild = 2 * curr + 2;

            if (leftChild <= _length && _heap[leftChild] < _heap[curr])
                curr = leftChild;
            if (rightChild <= _length && _heap[rightChild] < _heap[curr])
                curr = rightChild;
            if (curr != start) // we found someone smaller
            {
                Swap(curr, start);
                SinkDown(curr);
            }
        }

        private void Swap(int idx1, int idx2)
        {
            var temp = _heap[idx1];
            _heap[idx1] = _heap[idx2];
            _heap[idx2] = temp;
        }
    }
}