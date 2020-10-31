import java.util.Scanner;

class LinkedListDemo {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head; // a head node pointer

    boolean isEmpty() {
        if (head == null) {
            return true;
        }
        return false;
    }

    void add(int data) {
        // If linkedList is Empty , inserting first node
        Node n = new Node(data);
        if (isEmpty()) {
            head = n;
            return;
        }
        // inserting at last ; default way
        else {
            Node tmp = head;
            while (tmp.next != null) {
                tmp = tmp.next;
            }
            tmp.next = n;
        }
        return;
    }

    int kthNode(int k) {
        Node tmp = head;
        int count = 0;
        Node kth = head;
        while (tmp != null) {
            if (count < k) {
                count++;
                tmp = tmp.next;
            } else {
                tmp = tmp.next;
                kth = kth.next;
            }
        }
        return kth.data;
    }
}

public class devmohit_KthNode {
    public static void main(String[] args) {
        LinkedListDemo list = new LinkedListDemo();
        Scanner sc = new Scanner(System.in);
        list.add(7);
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(9);
        list.add(4);
        list.add(5);
        System.out.println("Enter the value of k");
        int k = sc.nextInt();
        sc.close();
        System.out.println(k + "th value from the end in the linked list is : " + list.kthNode(k));
    }
}