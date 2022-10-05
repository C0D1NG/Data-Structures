import java.util.*;

class Queue {
    private static int front, rear, capacity;
    private static int queue[];

    Queue(int size) {
        front = rear = 0;
        capacity = size;
        queue = new int[capacity];
    }

    static void queueEnqueue(int item) {
        if (capacity == rear) {
            System.out.printf("\nQueue is full\n");
            return;
        }
        queue[rear] = item;
        rear++;
    }

    static void queueDequeue() {
        if (front == rear) {
            System.out.printf("\nQueue is empty\n");
            return;
        }
        for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        if (rear < capacity)
            queue[rear] = 0;
        rear--;
    }

    static void queueDisplay() {
        int i;
        if (front == rear) {
            System.out.printf("Queue is Empty\n");
            return;
        }
        for (i = front; i < rear - 1; i++) {
            System.out.printf(" %d => ", queue[i]);
        }
        System.out.printf(" %d ", queue[rear - 1]);
        return;
    }

    static void queueReverse() {
        for(int i = front, j = rear - 1; i <= j ; i++, j--){
            int temp = queue[i];
            queue[i] = queue[j];
            queue[j] = temp;
        }
    }
}

class adityarajbhagat2002_reverseQueue {
    public static void main(String args[]) {
        Queue q = new Queue(10);

        q.queueEnqueue(10);
        q.queueEnqueue(20);
        q.queueEnqueue(30);
        q.queueEnqueue(40);
        q.queueEnqueue(50);
        q.queueEnqueue(60);

        System.out.print("\nInitial queue:");
        q.queueDisplay();

        q.queueReverse();

        System.out.print("\nReversed queue:");
        q.queueDisplay();
    }
}