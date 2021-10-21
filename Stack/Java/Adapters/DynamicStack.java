public class DynamicStack {
    private class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private int size, front, rear;
    Node head, tail;

    DynamicStack () {
        initialize();
    }

    private void initialize() {
        this.size = 0;
        this.head = this.tail = null;
        this.front = this.rear = 0;
    }

    public int getSize() {
        return this.size;

    }

    public boolean isEmpty() {
        return this.getSize() == 0;

    }

    public void add(int data) {
        addLast(new Node(data));
    }

    private void addLast(Node node) {
        if (this.getSize() == 0) {
            this.head = this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }

        this.size++;

    }

    private void QisEMptyException() throws Exception {
        if (this.isEmpty())
            throw new Exception("Underflow occured : Queue is Empty");
    }

    public int remove() throws Exception {
        QisEMptyException();
        return removeFirst();
    }

    private int removeFirst() {
        int data = this.head.data;
        if (this.getSize() == 1) {
            this.head = this.tail = null;
        } else {
            Node forw = this.head.next;
            this.head.next = null;
            this.head = forw;
        }

        this.size--;
        return data;
    }

    public int peek() throws Exception {
        QisEMptyException();
        return this.head.data;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node curr = this.head;
        int size = this.size;
        sb.append('[');
        for (int i = 0; i < size; i++) {
            sb.append(curr.data);
            curr = curr.next;
            if (i != size - 1)
                sb.append(", ");
        }

        sb.append(']');
        return sb.toString();
    }

}
