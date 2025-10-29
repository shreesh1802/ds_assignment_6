#include <iostream>
using namespace std;


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() : head(nullptr) {}

  
    void insert(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteEvenNodes() {
        DNode* temp = head;
        while (temp) {
            if (temp->data % 2 == 0) {
                DNode* delNode = temp;
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next; 

                if (temp->next)
                    temp->next->prev = temp->prev;

                temp = temp->next;
                delete delNode;
            } else {
                temp = temp->next;
            }
        }
    }

   
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() : head(nullptr) {}

   
    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    
    void deleteEvenNodes() {
        if (!head) return;

        CNode *curr = head, *prev = nullptr;
        bool firstPass = true;

        do {
            if (curr->data % 2 == 0) {
                if (curr == head) {
                 
                    CNode* last = head;
                    while (last->next != head)
                        last = last->next;
                   
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                        return;
                    }
                   
                    head = head->next;
                    last->next = head;
                    delete curr;
                    curr = head;
                    prev = last;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
            firstPass = false;
        } while (curr != head && head != nullptr);
    }

   
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    // Sample Data
    dll.insert(10);
    dll.insert(15);
    dll.insert(20);
    dll.insert(25);
    dll.insert(30);

    cll.insert(5);
    cll.insert(10);
    cll.insert(15);
    cll.insert(20);
    cll.insert(25);

    cout << "Original Lists:\n";
    dll.display();
    cll.display();

    dll.deleteEvenNodes();
    cll.deleteEvenNodes();

    cout << "\nAfter Removing Even Nodes:\n";
    dll.display();
    cll.display();

    return 0;
}
