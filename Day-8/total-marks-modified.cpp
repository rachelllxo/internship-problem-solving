#include<iostream>
#include<string>
using namespace std;

// creating a struct that stores data and the link to the next node
struct Student_details {
    string data;                        // to store roll no, name, marks, total etc. (as string)
    Student_details* next;              // pointer to the next node
};

Student_details* head = NULL;           // declaring head as NULL [as it is empty as of now]

int main() {
    int roll_no, mark1, mark2, mark3;   // variables to store integer inputs
    string name;                        // variable to store name input

    // Roll No Node
    cout << "Enter Roll No: ";
    cin >> roll_no;
    Student_details* rollNode = new Student_details();     // creating a new node to store roll no.
    rollNode->data = to_string(roll_no);                   // storing the roll no in the data part of the node (converted to string)
    head = rollNode;                                       // assigning head node to the first node [roll node]

    // Name Node
    cout << "Enter Name: ";
    cin >> name;
    Student_details* nameNode = new Student_details();     // creating a new node to store name
    nameNode->data = name;                                 // storing name directly in the node (already a string)
    rollNode->next = nameNode;                             // linking roll node to name node

    // Mark1 Node
    cout << "Enter Mark1: ";
    cin >> mark1;
    Student_details* mark1Node = new Student_details();    // creating a new node to store mark1
    mark1Node->data = to_string(mark1);                    // converting and storing mark1 in string form
    nameNode->next = mark1Node;                            // linking name node to mark1 node

    // Mark2 Node
    cout << "Enter Mark2: ";
    cin >> mark2;
    Student_details* mark2Node = new Student_details();    // creating a new node to store mark2
    mark2Node->data = to_string(mark2);                    // storing mark2 as string
    mark1Node->next = mark2Node;                           // linking mark1 node to mark2 node

    // Mark3 Node
    cout << "Enter Mark3: ";
    cin >> mark3;
    Student_details* mark3Node = new Student_details();    // creating a new node to store mark3
    mark3Node->data = to_string(mark3);                    // storing mark3 as string
    mark2Node->next = mark3Node;                           // linking mark2 node to mark3 node

    // Total Node
    int total = mark1 + mark2 + mark3;                     // calculating total of all three marks
    Student_details* totalNode = new Student_details();    // creating a new node to store total
    totalNode->data = to_string(total);                    // storing total as string
    mark3Node->next = totalNode;                           // linking mark3 node to total node

    totalNode->next = NULL;                                // marking end of linked list

    // Displaying total
    cout << "Total Marks: " << totalNode->data;            // printing total marks

    return 0;
}
