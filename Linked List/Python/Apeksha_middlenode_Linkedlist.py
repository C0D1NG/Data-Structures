class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList():
    def __init__(self):
        self.head=None

    def push(self,newdata):
        new= Node(newdata)
        new.next=self.head
        self.head=new

    def printmiddle(self):
        slow=self.head
        fast=self.head
        if self.head is not None:

            while(fast is not None and fast.next is not None):
                fast=fast.next.next
                slow=slow.next
        print("middle element", slow.data)

llist=LinkedList()
llist.push(20)
llist.push(4)
llist.push(15)
llist.push(10)
llist.push(6)
llist.printmiddle()

