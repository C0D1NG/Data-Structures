
class Node:
	
	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.next = None


# Class to create a new Circular Linked list
class CircularLinkedList:
	
	# Constructor to create a empty circular linked list
	def __init__(self):
		self.head = None

	# Function to insert a node at the beginning of a
	# circular linked list
	def push(self, data):
		ptr1 = Node(data)
		temp = self.head
		
		ptr1.next = self.head

		# If linked list is not None then set the next of
		# last node
		if self.head is not None:
			while(temp.next != self.head):
				temp = temp.next
			temp.next = ptr1

		else:
			ptr1.next = ptr1 # For the first node

		self.head = ptr1

	# Function to print nodes in a given circular linked list
	def printList(self):
		temp = self.head
		if self.head is not None:
			while(True):
				print ("%d" %(temp.data),end=' ')
				temp = temp.next
				if (temp == self.head):
					break


	# Function to split a list (starting with head) into
	# two lists. head1 and head2 are the head nodes of the
	# two resultant linked lists
	def splitList(self, head1, head2):
		slow_ptr = self.head
		fast_ptr = self.head
	
		if self.head is None:
			return
		
		# If there are odd nodes in the circular list then
		# fast_ptr->next becomes head and for even nodes
		# fast_ptr->next->next becomes head
		while(fast_ptr.next != self.head and
			fast_ptr.next.next != self.head ):
			fast_ptr = fast_ptr.next.next
			slow_ptr = slow_ptr.next

		# If there are even elements in list then
		# move fast_ptr
		if fast_ptr.next.next == self.head:
			fast_ptr = fast_ptr.next

		# Set the head pointer of first half
		head1.head = self.head

		# Set the head pointer of second half
		if self.head.next != self.head:
			head2.head = slow_ptr.next

		# Make second half circular
		fast_ptr.next = slow_ptr.next
	
		# Make first half circular
		slow_ptr.next = self.head




head = CircularLinkedList()
head1 = CircularLinkedList()
head2 = CircularLinkedList()

head.push(12)
head.push(56)
head.push(2)
head.push(11)

print ("Original Circular Linked List")
head.printList()


head.splitList(head1 , head2)

head1.printList()
head2.printList()

