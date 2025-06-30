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
int insert_node(int value) {
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
    return 0;
}

// Insert node at the beginning
int insert_at_beginning(int value) {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return 0;
}

// Insert node at a specific position 
int insert_at_position(int position, int value) {
    Node* new_node = new Node();
    new_node->data = value;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return 0;
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
        return -1;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return 0;
}

// Delete node at a specific position 
int delete_node(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return 0;
    }

    Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        cout << "Position out of range" << endl;
        return -1;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
    return 0;
}

// Reverse the linked list
int reverse_list() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return 0;
}

// Display the list 
int display_list() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

// Menu-driven interface without using break
int menu() {
    int choice = 0;

    while (choice != 5) {
        cout << "\nChoose an option:\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Reverse List\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value, pos;

        if (choice == 1) {
            int sub_choice;
            cout << "\n1. Insert at end\n2. Insert at beginning\n3. Insert at position\nChoose: ";
            cin >> sub_choice;
            cout << "Enter value: ";
            cin >> value;

            if (sub_choice == 1) {
                insert_node(value);
            } else if (sub_choice == 2) {
                insert_at_beginning(value);
            } else if (sub_choice == 3) {
                cout << "Enter position: ";
                cin >> pos;
                insert_at_position(pos, value);
            } else {
                cout << "Invalid insertion choice.\n";
            }

        } else if (choice == 2) {
            cout << "Enter position to delete: ";
            cin >> pos;
            delete_node(pos);

        } else if (choice == 3) {
            reverse_list();
            cout << "List reversed.\n";

        } else if (choice == 4) {
            cout << "Current List: ";
            display_list();

        } else if (choice == 5) {
            cout << "Exiting...\n";

        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}

// Main function
int main() {
    int noOfnodes, val;
    cout << "Enter the number of nodes: ";
    cin >> noOfnodes;
    cout << "Enter the linked list: ";
    for (int counter = 0; counter < noOfnodes; counter++) {
        cin >> val;
        insert_node(val);
    }

    menu();

    return 0;
}
