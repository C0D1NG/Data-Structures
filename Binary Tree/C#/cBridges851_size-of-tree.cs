using System;
using System.Collections;
using System.Collections.Generic;

namespace BinaryTreeHeight
{
	class Program
	{
		static void Main(string[] args){
			// CB 2020-10-04 Creating the initial root (the height will currently be -1)
			Node root = null;
			
			// CB 2020-10-04 Store all the data values of the nodes in an array
			var nodeDataList = GetData();
			
			// CB 2020-10-04 Loop through all the node values and add the nodes to the tree
			for (int i = 0; i < nodeDataList.Count; i++){
				root = AddToTree(root, nodeDataList[i]);
			}
			
			// CB 2020-10-04 Calculate the size of the tree and output
			var size = CalculateSize(root);
			Console.WriteLine("The size of the binary tree is: " + size);
		}
		
		// CB 2020-10-04 Creating an array that will contain all of the values that will be in the nodes
		static List<int> GetData(){
			var nodeDataList = new List<int>();
			
			// CB 2020-10-04 Retrieving the values of all the nodes
			var isFinishedInputting = false;
			
			while (!isFinishedInputting){
				Console.Write("Please insert a value: ");
				var currentValue = Convert.ToInt32(Console.ReadLine());
				nodeDataList.Add(currentValue);
				
				Console.Write("Would you like to input another value? y/n ");
				var valueInput = Console.ReadLine();
				
				if (valueInput.ToLower() == "n" || valueInput.ToLower() == "no"){
					isFinishedInputting = true;
				}
				
			}
			
			// CB 2020-10-04 Returning the final array of node values to the main program
			return nodeDataList;
		}
		
		static Node AddToTree (Node root, int data){
			// CB 2020-10-04 If the root is null, create a new node with the passed in data and return it
			if (root == null){
				return new Node(data);
			} else{
				// CB 2020-10-04 Create a node that will represent the current node
				Node current;
				
				// CB 2020-10-04 If the value of the data is less than or equal to the root's data, add a new node to the left
				if (data <= root.data){
					current = AddToTree(root.left, data);
					root.left = current;
				} else{
					// CB 2020-10-04 Add to the right otherwise
					current = AddToTree(root.right, data);
					root.right = current;
				}
				
				// CB 2020-10-04 Once the nodes have been created and connected, the root will be returned
				return root;
			}
			
		}
		
		// CB 2020-10-04 The height is the distance between the root and the leaf that is furthest away
		static int CalculateSize(Node root) {
			
			// CB 2020-10-10 Create a new queue which will store the nodes
			var queue = new Queue<Node>();
			// CB 2020-10-10 Variable to store the sum
			var size = 0;
			
			// CB 2020-10-10 Check that the root is not null
			if (root != null)
			{
				// CB 2020-10-10 Put the root in the queue
				queue.Enqueue(root);
				
				// CB 2020-10-10 Loop while the the size of the queue is not 0
				while (queue.Count != 0)
				{
					// CB 2020-10-10 Store the current node
					Node current = queue.Dequeue();
					
					// CB 2020-10-10 Add the data of the node to the sum
					size++;
					
					// CB 2020-10-10 If the left node exists, add it to the queue
					if (current.left != null)
					{
						queue.Enqueue(current.left);
					}
					
					// CB 2020-10-10 If the right node exists, add it to the queue
					if (current.right != null)
					{
						queue.Enqueue(current.right);
					}
					
				}
			}
			
			return size;
		}
	}
	
	// CB 2020-10-04 A class for the nodes
	class Node {
		// CB 2020-10-04 The nodes that will be on the left and right of the created node
		public Node left;
		public Node right;
		// CB 2020-10-04 The value of the node
		public int data;
		
		public Node (int data){
			this.data = data;
			// CB 2020-10-04 Initial value of left and right nodes will be null, so the node will be a leaf (it has no children)
			left = right = null;
		}
	}
}