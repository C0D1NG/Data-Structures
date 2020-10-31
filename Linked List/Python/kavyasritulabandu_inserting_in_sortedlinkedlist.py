# Python program to insert in a sorted list


class Node:

    # initializing the node object
    def __init__(self, data):
        self.data = data
        self.next = None


class SortedLinkedList:

    # Function to initialize head
    def __init__(self):
        self.head = None

    def sortedInsert(self, new_node):

        # if linked list is empty
        if self.head is None:
            new_node.next = self.head
            self.head = new_node

        # insertion at beginning
        elif self.head.data >= new_node.data:
            new_node.next = self.head
            self.head = new_node

        else:

            # Traversing in the list to find the appropriate position
            current = self.head
            while current.next is not None and current.next.data < new_node.data:
                current = current.next

            new_node.next = current.next
            current.next = new_node

    #  printing the LinkedList
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.next


if __name__ == "__main__":
    llist = SortedLinkedList()
    new_node = Node(15)
    llist.sortedInsert(new_node)
    new_node = Node(20)
    llist.sortedInsert(new_node)
    new_node = Node(1)
    llist.sortedInsert(new_node)
    new_node = Node(31)
    llist.sortedInsert(new_node)
    new_node = Node(8)
    llist.sortedInsert(new_node)
    new_node = Node(12)
    llist.sortedInsert(new_node)
    print("Elements in the Linkedlist:")
    llist.printList()
