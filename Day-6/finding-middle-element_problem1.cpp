#include <iostream>
using namespace std;

struct node; // globally declaring the node

node* head_node = NULL;     // globally declaring the head_node as NULL as it is empty now
node* pointer1 = NULL;      // pointer1 is NULL 
node* pointer2 = NULL;      // pointer2 is NULL

struct node {               // creating a node with data_node and address of the next_node
    int data_node;
    node* next_node;
    node(int value);        // the node takes in the input values 
};

node::node(int value) {     // creating a constructor outside the node
    data_node = value;      // the data_node now stores the value
    next_node = nullptr;    // the next_node points to NULL

    if (head_node == NULL) { // if the head_node is empty, the head_node stores the current node
        head_node = this;
    } else {                
        node* temp = head_node; // else it stores the head_node's address within the temporary node
        while (temp->next_node != NULL) { 
            temp = temp->next_node;
        }
        temp->next_node = this; // if the temporary node has an address then it stores the current node
    }
}

int find_middle_element() { // finding the middle element in the linked list 
    pointer1 = head_node;   // pointing both the pointer nodes to the head_node 
    pointer2 = head_node;

    while (pointer2 != NULL && pointer2->next_node != NULL) { 
        pointer1 = pointer1->next_node;               // pointer1 traverses one node at a time
        pointer2 = pointer2->next_node->next_node;    // pointer2 traverses two nodes at a time
    }

    if (pointer1 != NULL) {
        return pointer1->data_node; // returns the middle element
    }

    return -1; // if list is empty
}

int main() {
    int data_node, size;
    cout << "Enter the size of the linked list: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> data_node;
        new node(data_node); // creating nodes as user inputs data
    }

    int middle_element = find_middle_element(); // calling the function to find middle
    cout << "Middle element is: " << middle_element << endl;

    return 0;
}
