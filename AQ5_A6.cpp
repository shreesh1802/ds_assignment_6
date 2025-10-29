#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val) : data(val), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

class MatrixToDoublyLinkedList {
public:
    Node* convertToLinkedList(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return nullptr;
        int n = matrix[0].size();

       
        vector<vector<Node*>> nodes(m, vector<Node*>(n, nullptr));

      
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nodes[i][j] = new Node(matrix[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)  
                    nodes[i][j]->prev = nodes[i][j - 1];
                if (j < n - 1)
                    nodes[i][j]->next = nodes[i][j + 1];
                if (i > 0)  
                    nodes[i][j]->up = nodes[i - 1][j];
                if (i < m - 1)
                    nodes[i][j]->down = nodes[i + 1][j];
            }
        }

        return nodes[0][0];
    }

   
    void display(Node* head) {
        Node* row = head;
        while (row) {
            Node* col = row;
            while (col) {
                cout << col->data << " ";
                col = col->next;
            }
            cout << endl;
            row = row->down;
        }
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    MatrixToDoublyLinkedList converter;
    Node* head = converter.convertToLinkedList(matrix);

    cout << "2D Doubly Linked List Representation:\n";
    converter.display(head);

    return 0;
}
