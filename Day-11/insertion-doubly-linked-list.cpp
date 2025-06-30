#include<iostream>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
};

node* head = NULL;
node* tail = NULL;

int insert_linkedList(int value) {
	node* new_node = new node();
	new_node->data = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (head == NULL) {
		head = new_node;
		tail = new_node;
	} else {
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
	return 0;
}

int display_linkedList() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

int main() {
    int noOfnodes, val;
    cout << "Enter the number of nodes: ";
    cin >> noOfnodes;
    cout << "Enter the linked list: ";
    for (int counter = 0; counter < noOfnodes; counter++) {
        cin >> val;
        insert_linkedList(val);
    }

    cout << "The linked list is: ";
    display_linkedList();

    return 0;
}
