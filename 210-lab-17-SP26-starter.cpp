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
    int count = 0;

    addNodeTail(head);
    addNodeTail(head);
    addNodeTail(head);

    output(head);

    deleteList(head);

    output(head);

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

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