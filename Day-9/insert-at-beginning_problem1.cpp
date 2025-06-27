#include<iostream>
using namespace std;

struct node {                         // creating a node that stores data and link to next
    int data;
    node* next;
};

node* head = NULL;                    // head initially NULL (list is empty for now )

// function to insert node at the end of the list
void insert(int value) {
    node* new_node = new node;
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

// function to insert node at the beginning
void insert_at_beginning(int value) {
    node* insert_new_node = new node;
    insert_new_node->data = value;
    insert_new_node->next = head;		//points to the first node as head points to the first node 
    head = insert_new_node;
}

// function to display the list
void display() {
    node* temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int number_of_nodes, value;

    cout << "How many numbers do you want to enter?: ";
    cin >> number_of_nodes;

    for (int count = 0; count < number_of_nodes; count++) {
        cout << "Enter value " << count + 1 << ": ";
        cin >> value;
        insert(value);                 // building the list at the end
    }

    cout << "Enter a number to insert at the beginning: ";
    cin >> value;
    insert_at_beginning(value);              // inserting at the beginning

    display();                               // final list is displayed 
    return 0;
}
