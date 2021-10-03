using System;

namespace Heaps
{
    class Program
    {
        static void Main(string[] args)
        {
            var unsorted = new[]{3,2,1,7,8,4,10,16,12};
            var minHeap = new MinHeap(unsorted);
            var maxHeap = new MaxHeap(unsorted);

            var l = minHeap.Length();
            Console.Write("Array in ascending order : ");
            for (var i = 0; i < l; i++)
                Console.Write(minHeap.ExtractMin() + " ");
            Console.WriteLine();
            
            var l1 = maxHeap.Length();
            Console.Write("Array in descending order : ");
            for (var i = 0; i < l1; i++)
                Console.Write(maxHeap.ExtractMax() + " ");
            Console.WriteLine();
        }
    }
}