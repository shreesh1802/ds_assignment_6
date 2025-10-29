#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    
    void insert(char val) {
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

  
    bool isPalindrome() {
        if (!head || !head->next) return true; 

       
        Node* tail = head;
        while (tail->next)
            tail = tail->next;

       
        Node* start = head;
        Node* end = tail;
        while (start != end && start->prev != end) {
            if (start->data != end->data)
                return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }

   
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;

   
    dll.insert('A');
    dll.insert('B');
    dll.insert('C');
    dll.insert('B');
    dll.insert('A');

    cout << "Doubly Linked List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << "✅ The list is a palindrome." << endl;
    else
        cout << "❌ The list is NOT a palindrome." << endl;

    
    DoublyLinkedList dll2;
    dll2.insert('A');
    dll2.insert('B');
    dll2.insert('D');
    dll2.insert('C');

    cout << "\nDoubly Linked List: ";
    dll2.display();

    if (dll2.isPalindrome())
        cout << "✅ The list is a palindrome." << endl;
    else
        cout << "❌ The list is NOT a palindrome." << endl;

    return 0;
}
