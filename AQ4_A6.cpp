#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int val) : data(val), next(nullptr), prev(nullptr), random(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    
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
        newNode->prev = temp;
    }

  
    void display() {
        Node* temp = head;
        cout << "List with Random Pointers:\n";
        while (temp) {
            cout << "Node " << temp->data;
            if (temp->random)
                cout << " -> Random points to " << temp->random->data << endl;
            else
                cout << " -> Random points to NULL\n";
            temp = temp->next;
        }
    }

   
    void correctRandom(int nodeVal, int correctRandomVal) {
        Node *temp = head, *target = nullptr, *correctNode = nullptr;

       
        while (temp) {
            if (temp->data == nodeVal)
                target = temp;
            if (temp->data == correctRandomVal)
                correctNode = temp;
            temp = temp->next;
        }

        ]
        if (target && correctNode) {
            target->random = correctNode;
            cout << "\n Random pointer of node " << nodeVal
                 << " corrected to point to node " << correctRandomVal << endl;
        } else {
            cout << "\n Error: Node(s) not found.\n";
        }
    }
};


int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    
    dll.head->random = dll.head->next->next;      
    dll.head->next->random = dll.head;             
    dll.head->next->next->random = dll.head;      
    dll.head->next->next->next->random = dll.head->next; 

    cout << "Before Correction:\n";
    dll.display();

   
    dll.correctRandom(30, 40);

    cout << "\nAfter Correction:\n";
    dll.display();

    return 0;
}
