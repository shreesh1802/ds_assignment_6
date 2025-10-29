#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
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
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    Node* reverseInGroups(Node* head, int k) {
        if (!head) return nullptr;

        Node* current = head;
        Node* newHead = nullptr;
        Node* nextNode = nullptr;
        int count = 0;

        while (current != nullptr && count < k) {
            nextNode = current->next;
            current->next = current->prev;
            current->prev = nextNode;
            newHead = current;
            current = nextNode;
            count++;
        }

       
        if (nextNode != nullptr) {
            Node* rest = reverseInGroups(nextNode, k);
            head->next = rest;
            if (rest)
                rest->prev = head;
        }

       
        return newHead;
    }

    void reverseInGroupsWrapper(int k) {
        head = reverseInGroups(head, k);
    }
};


int main() {
    DoublyLinkedList dll;

   
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.insert(50);
    dll.insert(60);
    dll.insert(70);
    dll.insert(80);

    cout << "Original Doubly Linked List:\n";
    dll.display();

    int k = 3;
    dll.reverseInGroupsWrapper(k);

    cout << "\nAfter Reversing Every " << k << " Nodes:\n";
    dll.display();

    return 0;
}
