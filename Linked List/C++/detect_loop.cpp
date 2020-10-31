#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

node* insert_at_head(node* &head, int d) {
    if (head == NULL) {
        return head = new node(d);
    }
    
    node* new_head = new node(d);
    new_head->next = head;
    head = new_head;
    return head;
}

bool detect_loop(node* head) {
    node* slow = head;
    node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    node* head = NULL;

    for (int i = 0; i < 10; i++) {
        insert_at_head(head, i);
    }

    // inserting a loop
    head->next->next->next = head->next;

    if (detect_loop(head)) {
        cout << "Loop exists" << endl;
    } else {
        cout << "No loop exists" << endl;
    }

    return 0;
}
