// COMSC-210-5293 | Lab 17 | Yuyi Chen

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototype
void output(Node *);
// Additional function prototypes
void addNodeFront(Node *&);
void addNodeTail(Node *&);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;
    int choice;

    do {
        cout << "\nLinked List Menu\n";
        cout << "1. Add a node to the front\n";
        cout << "2. Add a node to the tail\n";
        cout << "3. Delete a node\n";
        cout << "4. Insert a node\n";
        cout << "5. Delete the list\n";
        cout << "6. Output the list\n";
        cout << "7. Exit\n";
        cout << "Choice --> ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNodeFront(head);
                break;
            case 2:
                addNodeTail(head);
                break;
            case 3:
                deleteNode(head);
                break;
            case 4:
                insertNode(head);
                break;
            case 5:
                deleteList(head);
                break;
            case 6:
                output(head);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// addNodeFront() adds a new node to the front of the linked list
// arguments: head pointer passed by reference
// returns: none
void addNodeFront(Node *&head) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// addNodeTail() adds a new node to the end of the linked list
// arguments: head pointer passed by reference
// returns: none
void addNodeTail(Node *&head) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node *current = head;

    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
}

// deleteNode() deletes a selected node from the linked list
// arguments: head pointer passed by reference
// returns: none
void deleteNode(Node *&head) {
    cout << "Which node to delete? " << endl;
    output(head);

    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // Traverse to the selected node
    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // Delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // Deleting the head node
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current;
        current = nullptr;
    }
}

// insertNode() inserts a new node after a selected node
// arguments: head pointer passed by reference
// returns: none
void insertNode(Node *&head) {
    cout << "After which node to insert 10000? " << endl;
    output(head);

    int entry;
    cout << "Choice --> ";
    cin >> entry;

    Node *current = head;
    Node *prev = nullptr;

    // Traverse to the selected position
    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // Insert a new node between prev and current
    Node *newNode = new Node;
    newNode->value = 10000;
    newNode->next = current;

    if (prev == nullptr) {
        // Inserting before the head
        head = newNode;
    }
    else {
        prev->next = newNode;
    }
}

// deleteList() deletes all nodes from the linked list
// arguments: head pointer passed by reference
// returns: none
void deleteList(Node *&head) {
    Node *current = head;

    while (current) {
        head = current->next;
        delete current;
        current = head;
    }

    head = nullptr;
}