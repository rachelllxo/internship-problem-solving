#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head = NULL;

// Function to create a list with N empty nodes (all data = 0)
void create_empty_list(int no_of_nodes) {
    for (int counter = 0; counter < no_of_nodes; counter++) {
        node* new_node = new node;
        new_node->data = 0;         
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

// Function to insert value at a particular position
void insert_at_position(int position, int value) {
    if (position < 1) return;

    node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        temp->data = value;
    }
}

// Function to print the linked list (no labels)
void display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int numberOfNodes, position, value;
	cout<<"Enter the number of nodes to create: ";
    cin >> numberOfNodes;               // number of nodes
    create_empty_list(numberOfNodes);
	cout<<"Enter the position: ";
    cin >> position;
	cout<<"Enter the value to be inserted: ";
	cin>> value;      // position and value to insert
    insert_at_position(position, value);
    display();              // final output
    return 0;
}
