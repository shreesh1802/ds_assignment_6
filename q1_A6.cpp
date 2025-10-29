int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    int choice, type, val, key;
    while (true) {
        cout << "\n=== LINKED LIST MENU ===\n";
        cout << "1. Use Doubly Linked List\n";
        cout << "2. Use Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> type;

        if (type == 3) break;

        while (true) {
            cout << "\n1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert After Node\n";
            cout << "4. Delete a Node\n";
            cout << "5. Search a Node\n";
            cout << "6. Display\n";
            cout << "7. Go Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 7) break;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    (type == 1) ? dll.insertAtBeginning(val) : cll.insertAtBeginning(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    (type == 1) ? dll.insertAtEnd(val) : cll.insertAtEnd(val);
                    break;
                case 3:
                    cout << "Insert after which node? ";
                    cin >> key;
                    cout << "Enter new value: ";
                    cin >> val;
                    (type == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                    break;
                case 4:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    (type == 1) ? dll.deleteNode(val) : cll.deleteNode(val);
                    break;
                case 5:
                    cout << "Enter value to search: ";
                    cin >> val;
                    (type == 1) ? dll.search(val) : cll.search(val);
                    break;
                case 6:
                    (type == 1) ? dll.display() : cll.display();
                    break;
                default:
                    cout << "Invalid option!\n";
            }
        }
    }
    return 0;
}
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

   
    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

   
    void insertAtEnd(int val) {
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

   
    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

   
    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;

       
        if (temp->data == key) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }

    
    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

  
    void display() {
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
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

   
    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    
    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    
    void deleteNode(int key) {
        if (!head) return;

        CNode *curr = head, *prev = nullptr;
        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Node " << key << " not found.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

      
        if (curr->next == head && prev == nullptr) {
            head = nullptr;
            delete curr;
            return;
        }

     
        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
            delete curr;
        } else if (curr->next == head) { 
            prev->next = head;
            delete curr;
        } else { 
            prev->next = curr->next;
            delete curr;
        }
    }

   
    void search(int key) {
        if (!head) return;
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Circular Linked List: ";
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


    
    

