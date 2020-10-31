using System;

namespace BinaryTreeHeight
{
	class Program
	{
		static void Main(string[] args){
			// CB 2020-10-04 Creating the initial root (the height will currently be -1)
			Node root = null;

			// CB 2020-10-04 Store all the data values of the nodes in an array
			var nodeDataArray = GetData();

			// CB 2020-10-04 Loop through all the node values and add the nodes to the tree
			for (int i = 0; i < nodeDataArray.Length; i++){
				root = AddToTree(root, nodeDataArray[i]);
			}

			// CB 2020-10-04 Calculate the max of the tree and output
			var height = CalculateMax(root);
			Console.WriteLine("The max in the binary tree is: " + height);
		}

		// CB 2020-10-04 Creating an array that will contain all of the values that will be in the nodes
		static int[] GetData(){
			Console.Write("How many nodes will there be in the binary tree? ");
			var size = Convert.ToInt32(Console.ReadLine());

			var nodeDataArray = new int[size];

			// CB 2020-10-04 Retrieving the values of all the nodes
			for (int i = 1; i <= size; i++){
				Console.Write("Please insert node " + i + "'s value: ");
				nodeDataArray[i-1] = Convert.ToInt32(Console.ReadLine());
			}

			// CB 2020-10-04 Returning the final array of node values to the main program
			return nodeDataArray;
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
		static int CalculateMax(Node root){
			if (root == null){
				return int.MinValue;
			}
			
			var overallMax = root.data;
			
			// CB 2020-10-04 Using recursion to identify the max value on the left side of the tree
			var leftMax = CalculateMax(root.left);
			// CB 2020-10-04 Using recursion to identify the max value on the right side of the tree
			var rightMax = CalculateMax(root.right);
			
			// CB 2020-10-04 Checks if the max on the left is greater than the overall max, overallMax's value changes to leftMax if so
			if (leftMax > overallMax){
				overallMax = leftMax;
			}
			
			// CB 2020-10-04 Checks if the max on the right is greater than the overall max, overallMax's value changes to rightMax if so
			if (rightMax > overallMax){
				overallMax = rightMax;
			}
			
			return overallMax;
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
