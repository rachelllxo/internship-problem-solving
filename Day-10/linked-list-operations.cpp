#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Insert node at the end
void insert_node(int value) {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Insert node at the beginning
void insert_at_beginning(int value) {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

// Insert node at a specific position 
void insert_at_position(int position, int value) {
    Node* new_node = new Node();
    new_node->data = value;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        delete new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete node at a specific position 
void delete_node(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
}

// Function to display the list 
void display_list() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
