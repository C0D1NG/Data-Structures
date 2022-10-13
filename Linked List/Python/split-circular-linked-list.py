
class Node:
	
	
	def __init__(self, data):
		self.data = data
		self.next = None



class CircularLinkedList:
	
	
	def __init__(self):
		self.head = None

	
	def push(self, data):
		ptr1 = Node(data)
		temp = self.head
		
		ptr1.next = self.head

		
		if self.head is not None:
			while(temp.next != self.head):
				temp = temp.next
			temp.next = ptr1

		else:
			ptr1.next = ptr1 # For the first node

		self.head = ptr1

	
	def printList(self):
		temp = self.head
		if self.head is not None:
			while(True):
				print ("%d" %(temp.data),end=' ')
				temp = temp.next
				if (temp == self.head):
					break


	
	def splitList(self, head1, head2):
		slow_ptr = self.head
		fast_ptr = self.head
	
		if self.head is None:
			return
		
		
		while(fast_ptr.next != self.head and
			fast_ptr.next.next != self.head ):
			fast_ptr = fast_ptr.next.next
			slow_ptr = slow_ptr.next

		
		if fast_ptr.next.next == self.head:
			fast_ptr = fast_ptr.next

		
		head1.head = self.head

		
		if self.head.next != self.head:
			head2.head = slow_ptr.next

		
		fast_ptr.next = slow_ptr.next
	
		
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

