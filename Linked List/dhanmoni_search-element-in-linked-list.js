// Search Element in Linked List #10

class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  //PUSH ELEMENTS TO THE LINKED-LIST:
  push(val) {
    let newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }

  //GET THE ELEMENT IN THE INDEX PASSED AS AN ARGUMENT:
  search(index) {
    if (index < 0 || index >= this.length) return null;
    let counter = 0;
    let current = this.head;

    while (counter !== index) {
      current = current.next;
      counter++;
    }
    return current;
  }
}

let list = new SinglyLinkedList();
list.push(20);
list.push(67);
list.push(28);
list.push(22);
list.push(99);
list.push(60);

console.log(list.search(2));
/*result==
 Node {
  val: 28,
  next: Node { val: 22, next: Node { val: 99, next: [Node] } }
}
*/

/*
  Time complexity---
  Insertion-- O(1)
  Searching-- O(n)
*/
