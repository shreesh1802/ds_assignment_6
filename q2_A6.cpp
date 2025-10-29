#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    
    void displayWithRepeat() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head node at the end
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);

    cll.displayWithRepeat();
    return 0;
}
