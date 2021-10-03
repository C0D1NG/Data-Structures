using System;

namespace Heaps
{
    public class MaxHeap
    {
        private int[] _heap;
        private int _length;

        public MaxHeap(int length)
        {
            _heap = new int[length];
            _length = 0;
        }
        
        public MaxHeap(int[] arr)
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

        public bool Insert(int val)
        {
            if (_length == _heap.Length)
            {
                Console.WriteLine("Heap is full");
                return false;
            }

            _heap[_length] = val;
            BubbleUp(_length);
            _length++;
            return true;
        }
        
        public int ExtractMax()
        {
            if (_length == 0)
            {
                Console.WriteLine("Heap is empty");
                return int.MinValue;
            }

            var max = _heap[0];
            _length--;
            _heap[0] = _heap[_length];
            SinkDown(0);
            return max;
        }

        private void SinkDown(int idx)
        {
            var curr = idx;
            var left = 2 * idx + 1;
            var right = 2 * idx + 2;

            if (left < _length && _heap[left] > _heap[curr])
                curr = left;
            if (right < _length && _heap[right] > _heap[curr])
                curr = right;

            if (curr != idx)
            {
                Swap(curr, idx);
                SinkDown(curr);
            }
        }

        private void BubbleUp(int idx)
        {
            var parent = idx / 2;
            while (idx > 0 && _heap[parent] < _heap[idx])
            {
                Swap(parent, idx);
                idx = parent;
                parent = idx / 2;
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