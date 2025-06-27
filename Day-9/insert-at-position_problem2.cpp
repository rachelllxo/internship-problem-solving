#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

// Creating a linked list with user input
void create_list(int numberOfNodes) {
    head = NULL;
    for (int i = 0; i < numberOfNodes; i++) {
        int value;
        cin >> value;

        node* new_node = new node();
        new_node->data = value;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

// Insert new node at given position (0-based index)
void insert_at_position(int position, int value) {
    node* new_node = new node();
    new_node->data = value;
    new_node->next = NULL;

    // If inserting at the head
    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    node* temp = head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Display the linked list
void display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int numberOfNodes;
    cout << "Enter the number of initial elements: ";
    cin >> numberOfNodes;

    cout << "Enter the elements: ";
    create_list(numberOfNodes);

    int position, value;
    cout << "Enter the position to insert at: ";
    cin >> position;

    cout << "Enter the value to insert: ";
    cin >> value;

    insert_at_position(position, value);

    cout << "Final linked list: ";
    display();

    return 0;
}
