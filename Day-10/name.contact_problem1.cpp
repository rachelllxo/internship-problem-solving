#include <iostream>
#include <string>
using namespace std;

// Structure to store contact
struct Contact {
    string name;        // using string for name
    int phone_number;   // int for phone number
    Contact* next;      // pointer to next contact
};

Contact* head = NULL;  // start with empty list

// Function to add a contact to the end
void add_contact(string name, int phone_number) {
    Contact* new_node = new Contact();
    new_node->name = name;
    new_node->phone_number = phone_number;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;  // first contact
    } else {
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // move to last node
        }
        temp->next = new_node;  // link new contact
    }
}

// Function to print all contacts
void display_contacts() {
    if (head == NULL) {
        cout << "No contacts to display.\n";
        return;
    }

    cout << "\nStored Contacts:\n";
    Contact* temp = head;
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Phone Number: " << temp->phone_number << endl;
        temp = temp->next;
    }
}

int main() {
    int n;
    cout << "How many contacts do you want to store? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int phone;

        cout << "\nEnter name for contact " << i + 1 << ": ";
        cin >> name;  // use underscore if there's a space

        cout << "Enter phone number for contact " << i + 1 << ": ";
        cin >> phone;

        add_contact(name, phone);
    }

    display_contacts();
    return 0;
}
