#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

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


    void display(Node* start) {
        if (!start) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = start;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << endl;
    }

 
    void splitList(Node** head1_ref, Node** head2_ref) {
        if (!head) return;

        Node *slow = head, *fast = head;

        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

       
        if (fast->next->next == head)
            fast = fast->next;

   
        *head1_ref = head;
        *head2_ref = slow->next;

     
        slow->next = *head1_ref;

     
        fast->next = *head2_ref;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.insert(50);

    Node *head1 = nullptr, *head2 = nullptr;
    cll.splitList(&head1, &head2);

    cout << "First Circular Linked List: ";
    cll.display(head1);

    cout << "Second Circular Linked List: ";
    cll.display(head2);

    return 0;
}
