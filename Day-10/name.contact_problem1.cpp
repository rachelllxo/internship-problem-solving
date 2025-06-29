#include <iostream>
using namespace std;

// Structure to store contact details
struct Contact {
    char name[50];         // Character array for name
    int phone_number;      // Integer for phone number
    Contact* next;         // Pointer to next contact node
};

Contact* head = NULL;      // Start with an empty list

// Function to add a contact to the end of the list
void add_contact(char name[], int phone_number) {
    Contact* new_node = new Contact();

    // Copy name character by character
    int count = 0;
    while (name[count] != '\0') {
        new_node->name[count] = name[count];
        count++;
    }
    new_node->name[count] = '\0';  // Null-terminate the string

    new_node->phone_number = phone_number;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;  // First node
    } else {
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;  // Link the last node to new one
    }
}

// Function to display all contacts
void display_contacts() {
    if (head == NULL) {
        cout << "No contacts to display.\n";
        return;
    }

    Contact* temp = head;
    cout << "\nStored Contacts:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Phone Number: " << temp->phone_number << endl;
        temp = temp->next;
    }
}

int main() {
    int noOfContacts;
    cout << "How many contacts do you want to store? ";
    cin >> noOfContacts;

    for (int count = 0; count < noOfContacts; count++) {
        char name[50];
        int phone;

        cout << "\nEnter name: " << count + 1 << ": ";
        cin >> name;  

        cout << "Enter phone number: " << count + 1 << ": ";
        cin >> phone;

        add_contact(name, phone);
    }

    display_contacts();  // Show all saved contacts
    return 0;
}
