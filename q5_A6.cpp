#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

 
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

  
    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head; // last node points back to head
    }

   
    bool isCircular() {
        if (!head) return true; // empty list is circular by definition

        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }
};

int main() {
    LinkedList list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);

    // Make the list circular
    list1.makeCircular();

    if (list1.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is NOT circular.\n";

   
    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);

    if (list2.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}
