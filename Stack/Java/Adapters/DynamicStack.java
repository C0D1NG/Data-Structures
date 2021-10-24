
public class DynamicStack2 {
    private class Node {
        int data;
        Node next;

        Node() {

        }

        Node(int data) {
            this.data = data;
        }
    }

    private Node head, tail;
    private int size;

    DynamicStack2() {
        intiallize();
    }

    protected void intiallize() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public int getSize() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.getSize() == 0;
    }

    private void stackIsEmpty() throws Exception {
        if (this.isEmpty())
            throw new Exception("Undeflow Error: Stack is Empty");
    }

    private int removeFirst() {
        Node currhead = this.head;
        int data = currhead.data;
        if (this.size == 1) {
            this.head = this.tail = null;
        } else {
            Node forw = currhead.next;
            this.head.next = null;
            this.head = forw;
        }

        this.size--;
        return data;
    }

    private void addFirst(Node node) {
        if (this.head == null) {
            this.head = this.tail = node;
        } else {
            node.next = this.head;
            this.head = node;
        }
        this.size++;
    }

    public void push(int data) {
        addFirst(new Node(data));
    }

    public int pop() throws Exception {
        stackIsEmpty();
        return removeFirst();
    }

    public int peek() throws Exception {
        isEmpty();
        return this.head.data;

    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node curr = this.head;
        int[] temp = new int[this.size];
        int i = this.size - 1;
        // to get the element in reverse order : default print behaviour of stack
        while (curr != null) {
            // sb.append(curr.data + ", ");
            temp[i--] = curr.data;
            curr = curr.next;
        }

        sb.append('[');

        for (int idx = 0; idx < temp.length - 1; idx++)
            sb.append(temp[idx] + ", ");
            
        sb.append(temp[temp.length - 1]);

        sb.append(']');
        return sb.toString();
    }

}
