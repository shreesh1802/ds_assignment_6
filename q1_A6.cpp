struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at beginning
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

    // Insert at end
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

    // Insert after a specific node
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

    // Delete a specific node
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

        // If only one node
        if (curr->next == head && prev == nullptr) {
            head = nullptr;
            delete curr;
            return;
        }

        // If head node to delete
        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
            delete curr;
        } else if (curr->next == head) { // last node
            prev->next = head;
            delete curr;
        } else { // middle node
            prev->next = curr->next;
            delete curr;
        }
    }

    // Search a node
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

    // Display list
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
